#ifndef WEATHER_MANAGER_H_
#define WEATHER_MANAGER_H_

#include <QObject>

class QNetworkReply;
class QNetworkAccessManager;
class WeatherManager : public QObject {
	Q_OBJECT
	private:
		static WeatherManager *mgr;
		QNetworkAccessManager *naMgr;

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
		void FetchWeather();
		void PrevDay();
		void NextDay();
		void Today();

	public slots:
		void requestFinished(QNetworkReply *reply);
};


#endif // WEATHER_MANAGER_H_
