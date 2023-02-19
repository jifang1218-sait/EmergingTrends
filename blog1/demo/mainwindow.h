#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WeatherManagerCallbacks.h"

class QWidget;
class QTableView;
class QStandardItemModel;
class QString;

#if _USE_CUSTOMIZED_THREAD
	class WorkerThread;
#endif

class MainWindow : public QMainWindow, public WeatherInfoCallback
{
    Q_OBJECT

private:
	QStandardItemModel *model;
	QWidget *central;
#if _USE_CUSTOMIZED_THREAD
	WorkerThread *workerThread;
#endif

public slots:
	void updateClicked();

#if !_USE_CUSTOMIZED_THREAD
private:
#endif
	
	void fillWeatherData(const QString &city, 
			const QString &condition, 
			const QString &temperature, 
			const QString &humidity, 
			const QString &windSpeed);

private:
	void constructUI(QWidget *parent);
	QTableView *createTable(QWidget *parent);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
	// inherite from base class.
	virtual void UpdateWeatherInfo(const QString &city, 
			const QString &condition, const QString &temperature, 
			const QString &humidity, const QString &windSpeed);
};
#endif // MAINWINDOW_H
