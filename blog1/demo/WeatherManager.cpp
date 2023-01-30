#include "WeatherManager.h"
#include <stdio.h>

WeatherManager *WeatherManager::mgr = NULL;

WeatherManager::WeatherManager() {
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
}

void WeatherManager::PrevDay() {
}

void WeatherManager::NextDay() {
}

void WeatherManager::Today() {
}

