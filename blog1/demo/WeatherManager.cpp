#include "WeatherManager.h"
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QEventLoop>
#include <QDebug>

WeatherManager *WeatherManager::mgr = NULL;

WeatherManager::WeatherManager() {
	naMgr = new QNetworkAccessManager(this);
	QMetaObject::Connection conn = QObject::connect(naMgr, SIGNAL(finished(QNetworkReply *)), 
			this, SLOT(requestFinished(QNetworkReply *)));
}

WeatherManager::~WeatherManager() {
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

#if !_SYNCHRONIZED_
	QNetworkReply *reply = naMgr->get(req);
#else
	// code below will make the request synchronously in this thread.
	QNetworkAccessManager *synchronizedMgr = new QNetworkAccessManager(this);
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
		qDebug()<<reply->readAll();
	}
}

void WeatherManager::PrevDay() {
}

void WeatherManager::NextDay() {
}

void WeatherManager::Today() {
}

