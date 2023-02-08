#include "WeatherManager.h"
#include "HourItem.h"
#include "WeatherManagerCallbacks.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QEventLoop>
#include <QDebug>
#include <QThread>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

WeatherManager *WeatherManager::mgr = NULL;

WeatherManager::WeatherManager() {
	naMgr = new QNetworkAccessManager(this);
	QMetaObject::Connection conn = QObject::connect(naMgr, SIGNAL(finished(QNetworkReply *)), 
			this, SLOT(requestFinished(QNetworkReply *)));
}

WeatherManager::~WeatherManager() {
}

void WeatherManager::addObserver(WeatherInfoCallback *observer) {
	if (observer == NULL) {
		return;
	}

	if (!callbacks.contains(observer)) {
		callbacks.append(observer);
	}
}

WeatherManager *WeatherManager::GetInstance() {
	if (mgr == NULL) {
		mgr = new WeatherManager();
	}

	return mgr;
}

void WeatherManager::FetchWeather() {

	QNetworkRequest req;

	QUrl url("https://api.met.no/weatherapi/locationforecast/2.0/compact");
	QUrlQuery query;
	// hardcode calgary location
	query.addQueryItem("lat", "50.9804");
	query.addQueryItem("lon", "-114.1015");
	url.setQuery(query);
	
	// explaination of the api restriction 
	/**
	 * AUTHENTICATION
	 *
	 * Due to poor adherence to the identification requirements in the Terms of Service, 
	 * we have implemented more stringent checks on sending a unique identifier in the User-Agent header. 
	 * Any requests with a prohibited or missing User-Agent will receive a 403 Forbidden error.
	 *
	 * Examples of banned User-Agents include:
	 *
	 *     okhttp
	 *     Dalvik
	 *     fhttp
	 *     Java
	 *
	 */
	// build user agent
	QString agent = "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/76.0.3809.132 Safari/537.36";
	req.setHeader(QNetworkRequest::UserAgentHeader, agent);
	req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	qDebug()<<url.url();
	req.setUrl(url);

#if !_USE_CUSTOMIZED_THREAD
	// this line will use Qt's asynchronous mechanism,
	// WeatherManager::requestFinished will be invoked in a sub thread. 
	QNetworkReply *reply = naMgr->get(req);
#else
	// code below will make the request synchronously in this thread.
	// WeatherManager::requestFinished will run in the same thread.
	// as the ui will be blocked by the task, so we use our user-customized thread, 
	// workerThread to run WeatherManager::FetchWeather. 
	
	// in order to demonstrate worker thread more clearly, we delay 10 seconds.
	QThread::msleep(10000);

	// as now we are in worker thread, QNetworkAccessManager will be created in worker thread. 
	// "this"(WeatherManager) is created in ui thread, 
	// so we can't set "this" as the parent object of network access manager. 
	// to resolve the problem, we have 2 ways:
	// 1. switch to ui thread;
	// 2. simply pass NULL to network access manager. we choose 2. 
	QNetworkAccessManager *synchronizedMgr = new QNetworkAccessManager(NULL);

	// we use a local event loop to make QNetworkAccessManager::get() synchronize, 
	// otherwise it is asynchronized. 
	// in practice, we don't have to do so, here we use the trick to demonstrate the usage of thread.
	QEventLoop eventLoop;
	QObject::connect(synchronizedMgr, SIGNAL(finished(QNetworkReply *)), &eventLoop, SLOT(quit()));
	QNetworkReply *reply = synchronizedMgr->get(req);
	eventLoop.exec();
	requestFinished(reply);
#endif
}

void WeatherManager::requestFinished(QNetworkReply *reply) {
	QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
	if (statusCode.isValid()) {
		qDebug()<<"status code="<<statusCode.toInt();
	}

	QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
	if (reason.isValid()) {
		qDebug()<<"reason="<<reason.toString();
	}

	QNetworkReply::NetworkError err = reply->error();
	if (err != QNetworkReply::NoError) {
		qDebug()<<"Failed:"<<reply->errorString();
	} else {
		QList<HourItem> items = parseWeatherData(reply->readAll());
		const HourItem &item = items[0];
		// broadcast
		for (QList<WeatherInfoCallback *>::iterator pos=callbacks.begin(); 
				pos!=callbacks.end(); ++pos) {
			(*pos)->UpdateWeatherInfo("Calgary", 
					item.GetWeatherCondition(), QString::number(item.GetTemperature()), 
					QString::number(item.GetHumidity()), QString::number(item.GetWindSpeed()));
		}
	}
}

QList<HourItem> WeatherManager::parseWeatherData(const QByteArray &jsonData) {
	QList<HourItem> hourItems;
	QJsonParseError err_rpt;
	QJsonDocument  root_Doc = QJsonDocument::fromJson(jsonData, &err_rpt);
	if(err_rpt.error != QJsonParseError::NoError) {
		qDebug() << "Invalid Json format.";
		return hourItems;
	} else { // parse json.
		QJsonObject root_Obj = root_Doc.object();
		QJsonObject node = root_Obj.value("properties").toObject();
		QJsonValue value = node.value("timeseries");
		if (value.isArray()) {
			QJsonArray arr = value.toArray();
			for (int i=0; i<arr.size(); ++i) {
				QJsonObject objRoot = arr[i].toObject();
				QString time = objRoot["time"].toString();
				// data->instant->details
				QJsonObject obj = objRoot["data"].toObject()["instant"]
					.toObject()["details"]
					.toObject();
				double temperature = obj["air_temperature"].toDouble();
				double humidity = obj["relative_humidity"].toDouble();
				double windSpeed = obj["wind_speed"].toDouble();

				// data->next_1_hours->summary->symbol_code
				QString weatherCondition = objRoot["data"].toObject()["next_1_hours"]
					.toObject()["summary"]
					.toObject()["symbol_code"].toString();
				HourItem item(time, temperature, humidity, windSpeed, weatherCondition);
				hourItems.append(item);
			}
		}
	}

	return hourItems;
}

void WeatherManager::PrevDay() {
}

void WeatherManager::NextDay() {
}

void WeatherManager::Today() {
}

