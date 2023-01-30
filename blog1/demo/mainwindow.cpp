#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <vector>
#include <string>
#include "WeatherManager.h"

#if DEBUG
#include <iostream>
using namespace std;
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), central(NULL)
{
	constructUI(parent);
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->FetchWeather();
}

MainWindow::~MainWindow()
{
}

void MainWindow::constructUI(QWidget *parent) {
	central = new QWidget(parent);

	// main horizontal layout
	QHBoxLayout *hlayout = new QHBoxLayout();

	// left button group layout
	QVBoxLayout *leftLayout = new QVBoxLayout();
	leftLayout->addStretch();
	
	// prev button
	QPushButton *prev = new QPushButton("Prev");
	connect(prev, SIGNAL(clicked()), this, SLOT(prevClicked()));
	leftLayout->addWidget(prev);

	leftLayout->addStretch();

	// today button
	QPushButton *today = new QPushButton("Today");
	connect(today, SIGNAL(clicked()), this, SLOT(todayClicked()));
	leftLayout->addWidget(today);

	leftLayout->addStretch();

	// next button
	QPushButton *next = new QPushButton("Next");
	connect(next, SIGNAL(clicked()), this, SLOT(nextClicked()));
	leftLayout->addWidget(next);

	leftLayout->addStretch();
	hlayout->addLayout(leftLayout);

	QVBoxLayout *rightLayout = new QVBoxLayout();
	QTableView *table = createTable();
	rightLayout->addWidget(table, 1);

	// bottom layout (update button).
	QHBoxLayout *bottomLayout = new QHBoxLayout();
	bottomLayout->addStretch();

	QPushButton *button = new QPushButton("Update");
	connect(button, SIGNAL(clicked()), this, SLOT(updateClicked()));
	bottomLayout->addWidget(button);
	
	bottomLayout->addStretch();
	rightLayout->addLayout(bottomLayout);
	hlayout->addLayout(rightLayout);

	central->setLayout(hlayout);
	setCentralWidget(central);
}

QTableView *MainWindow::createTable() {
	using namespace std;

	QTableView *ret = new QTableView();
	QStandardItemModel *model = new QStandardItemModel();

	// add header
	vector<string> days{"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	model->setColumnCount(days.size());
	for (int i=0; i<days.size(); ++i) {
		model->setHeaderData(i, Qt::Horizontal, days[i].c_str());
	}

	// fill data
	QStandardItem *item = new QStandardItem("aaa");
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 0, item);
	item = new QStandardItem("bbb");
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(0, 1, item);
	item = new QStandardItem("aaa");
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(1, 0, item);
	item = new QStandardItem("bbb");
	item->setTextAlignment(Qt::AlignCenter);
	model->setItem(1, 1, item);

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

void MainWindow::prevClicked() {
#if DEBUG
	cout<<"prev clicked."<<endl;
#endif
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->PrevDay();
}

void MainWindow::todayClicked() {
#if DEBUG
	cout<<"today clicked."<<endl;
#endif
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->Today();
}

void MainWindow::nextClicked() {
#if DEBUG
	cout<<"next clicked."<<endl;
#endif
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->NextDay();
}

void MainWindow::updateClicked() {
#if DEBUG
	cout<<"update clicked."<<endl;
#endif
	WeatherManager *mgr = WeatherManager::GetInstance();
	mgr->FetchWeather();
}

