#include "WorkerThread.h"
#include "WeatherManager.h"

WorkerThread::WorkerThread(QObject *parent) : QThread(parent) {
}

WorkerThread::~WorkerThread() {
}

void WorkerThread::run() {
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->FetchWeather();
}

