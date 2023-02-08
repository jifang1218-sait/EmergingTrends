#ifndef _HOUR_ITEM_
#define _HOUR_ITEM_

#include <QString>

class HourItem {
private:
	QString utcTime;
	double temperature;
	double humidity;
	double windSpeed;
	QString weatherCondition;

public:
	HourItem();
	HourItem(const QString &utcTime, 
			double temperature, 
			double humidity, 
			double windSpeed, 
			const QString &weatherCondition);
	HourItem(const HourItem &);
	HourItem &operator=(const HourItem &);
	
public:
	const QString &GetUtcTime() const {
		return utcTime;
	}

	double GetTemperature() const {
		return temperature;
	}

	double GetHumidity() const {
		return humidity;
	}

	double GetWindSpeed() const {
		return windSpeed;
	}

	const QString &GetWeatherCondition() const {
		return weatherCondition;
	}

};

#endif // _HOUR_ITEM_

