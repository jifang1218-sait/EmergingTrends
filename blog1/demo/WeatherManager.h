#ifndef WEATHER_MANAGER_H_
#define WEATHER_MANAGER_H_

class WeatherManager {
	private:
		static WeatherManager *mgr;
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
};


#endif // WEATHER_MANAGER_H_
