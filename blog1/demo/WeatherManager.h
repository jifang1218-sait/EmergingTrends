#ifndef WEATHER_MANAGER_H_
#define WEATHER_MANAGER_H_

#include <QObject>
#include <QList>

class HourItem;
class QNetworkReply;
class QNetworkAccessManager;
class QByteArray;
class WeatherInfoCallback;
class WeatherManager : public QObject {
	Q_OBJECT
	private:
		static WeatherManager *mgr;
		QNetworkAccessManager *naMgr;
		QList<WeatherInfoCallback *> callbacks;

	private:
		WeatherManager();
		WeatherManager(const WeatherManager&) = delete;
		WeatherManager(const WeatherManager&&) = delete;
		const WeatherManager& operator=(const WeatherManager &) = delete;
		const WeatherManager&& operator=(const WeatherManager&&) = delete;

	public:
		~WeatherManager();

	public:
		static WeatherManager *GetInstance();

	public:
		void addObserver(WeatherInfoCallback *observer);
		void FetchWeather();
		void PrevDay();
		void NextDay();
		void Today();
		QList<HourItem> parseWeatherData(const QByteArray &);

	public slots:
		void requestFinished(QNetworkReply *reply);
};


#endif // WEATHER_MANAGER_H_
