#include "mainwindow.h"
#include "WeatherManager.h"

#if _USE_CUSTOMIZED_THREAD
	#include "WorkerThread.h"
	#include <QMetaObject>
#endif

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QList>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), central(NULL), model(NULL)
{
	constructUI(parent);
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->addObserver(this);

#if !_USE_CUSTOMIZED_THREAD
	mgr->FetchWeather();
#else
	// create a worker thread. it is used to fetch weather data.
	workerThread = new WorkerThread(this);
	workerThread->start();
#endif
}

MainWindow::~MainWindow()
{
}

void MainWindow::constructUI(QWidget *parent) {
	central = new QWidget(this);

	// main horizontal layout
	QHBoxLayout *hlayout = new QHBoxLayout();

	// left button group layout
	QVBoxLayout *leftLayout = new QVBoxLayout();
	leftLayout->addStretch();
	hlayout->addLayout(leftLayout);

	QVBoxLayout *rightLayout = new QVBoxLayout();
	QTableView *table = createTable(central);
	rightLayout->addWidget(table, 1);

	// bottom layout (update button).
	QHBoxLayout *bottomLayout = new QHBoxLayout();
	bottomLayout->addStretch();

	QPushButton *button = new QPushButton("Update", central);
	connect(button, SIGNAL(clicked()), this, SLOT(updateClicked()));
	bottomLayout->addWidget(button);

	bottomLayout->addStretch();
	rightLayout->addLayout(bottomLayout);
	hlayout->addLayout(rightLayout);

	central->setLayout(hlayout);
	setCentralWidget(central);
}

QTableView *MainWindow::createTable(QWidget *parent) {
	using namespace std;

	QTableView *ret = new QTableView(parent);
	model = new QStandardItemModel(parent);

	// add header
	QList<QString> days{"City", "Condition", "Temperature C", "Humidity %", "Wind Speed km/h"};
	model->setColumnCount(days.size());
	for (int i=0; i<days.size(); ++i) {
		model->setHeaderData(i, Qt::Horizontal, days[i]);
	}

	// set column width
	for (int col=0; col<model->columnCount(); ++col) {
		   ret->setColumnWidth(col,200);
	}

	// set row height
	for (int row=0; row<10; ++row) {
		ret->setRowHeight(row, 200);
	}

	// fill data, N/A by default, will refresh after getting the data.
	fillWeatherData("Calgary", "N/A", "N/A", "N/A", "N/A");
	ret->setModel(model);

	// set table style:
	// center for header, column stretchable, hide line no
	ret->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ret->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ret->verticalHeader()->hide();

	// set table attributes:
	// column select, no edit, 
	ret->setSelectionBehavior(QAbstractItemView::SelectColumns);
	ret->setEditTriggers(QAbstractItemView::NoEditTriggers);

	return ret;
}

void MainWindow::fillWeatherData(const QString &city, 
		const QString &condition, const QString &temperature, 
		const QString &humidity, const QString &windSpeed) {
	QStandardItem *item = new QStandardItem(city);
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 0, item); // city
	item = new QStandardItem(condition);
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 1, item); // condition
	item = new QStandardItem(temperature);
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 2, item); // temperature
	item = new QStandardItem(humidity);
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 3, item); // humidity
	item = new QStandardItem(windSpeed);
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 4, item); // wind speed
}

void MainWindow::updateClicked() {
#if !_USE_CUSTOMIZED_THREAD
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->FetchWeather();
#else
	if (workerThread->isFinished()) {
		workerThread->start();
	}
#endif
}

void MainWindow::UpdateWeatherInfo(const QString &city, const QString &condition, 
		const QString &temperature, const QString &humidity, const QString &windSpeed) {
#if !_USE_CUSTOMIZED_THREAD
	// as we are in ui thread(qt internally switched to ui thread.
	// we can update ui directly. 
	fillWeatherData(city, condition, temperature, humidity, windSpeed);
#else 
	// as we are in our own work thread, so we have to switch to main thread to update ui. 
	// we use signal-slot mechanism as a bridge to switch to ui thread. 
	QMetaObject::invokeMethod(this, "fillWeatherData", 
			Q_ARG(const QString&, city), 
			Q_ARG(const QString&, condition), 
			Q_ARG(const QString&, temperature), 
			Q_ARG(const QString&, humidity), 
			Q_ARG(const QString&, windSpeed));
#endif
}

