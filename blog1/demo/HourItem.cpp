#include "HourItem.h"

HourItem::HourItem() {
	temperature = 0;
	humidity = 0;
	windSpeed = 0;
}

HourItem::HourItem(const QString &utcTime, 
		double temperature, 
		double humidity, 
		double windSpeed, 
		const QString &weatherCondition) {
	this->utcTime = utcTime;
	this->temperature = temperature;
	this->humidity = humidity;
	this->windSpeed = windSpeed;
	this->weatherCondition = weatherCondition;
}

HourItem::HourItem(const HourItem &item) {
	this->utcTime = item.utcTime;
	this->temperature = item.temperature;
	this->humidity = item.humidity;
	this->windSpeed = item.windSpeed;
	this->weatherCondition = item.weatherCondition;
}

HourItem &HourItem::operator=(const HourItem &item) {
	this->utcTime = item.utcTime;
	this->temperature = item.temperature;
	this->humidity = item.humidity;
	this->windSpeed = item.windSpeed;
	this->weatherCondition = item.weatherCondition;

	return *this;
}

