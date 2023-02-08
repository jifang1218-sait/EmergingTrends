#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "WeatherManagerCallbacks.h"

class QWidget;
class QTableView;
class QStandardItemModel;
class QString;
class MainWindow : public QMainWindow, public WeatherInfoCallback
{
    Q_OBJECT

private:
	QStandardItemModel *model;
	QWidget *central;

public slots:
	void updateClicked();
	void prevClicked();
	void nextClicked();
	void todayClicked();

private:
	void fillWeatherData(const QString &city, 
			const QString &condition, 
			const QString &temperature, 
			const QString &humidity, 
			const QString &windSpeed);
	void constructUI(QWidget *parent);
	QTableView *createTable();

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
