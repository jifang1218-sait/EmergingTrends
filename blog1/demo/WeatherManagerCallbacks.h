#ifndef _WEATHER_MANAGER_CALLBACKS_
#define _WEATHER_MANAGER_CALLBACKS_

class QString;
class WeatherInfoCallback {
	public:
		virtual ~WeatherInfoCallback() {
		}

	public:
		virtual void UpdateWeatherInfo(const QString &city, 
				const QString &condition, const QString &temperature, 
				const QString &humidity, const QString &windSpeed) = 0; 
};

#endif // _WEATHER_MANAGER_CALLBACKS_
