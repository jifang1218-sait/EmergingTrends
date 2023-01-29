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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), central(NULL)
{
	constructUI(parent);
}

MainWindow::~MainWindow()
{
}

void MainWindow::constructUI(QWidget *parent) {
	central = new QWidget(parent);

	QVBoxLayout *vlayout = new QVBoxLayout();
	QTableView *table = createTable();
	vlayout->addWidget(table, 1);

	QHBoxLayout *hlayout = new QHBoxLayout();
	hlayout->addStretch();
	QPushButton *button = new QPushButton("Update");
	hlayout->addWidget(button);
	hlayout->addStretch();

	vlayout->addLayout(hlayout);
	central->setLayout(vlayout);
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
	model->setItem(0, 0, item);
	item = new QStandardItem("bbb");
	model->setItem(0, 1, item);
	item = new QStandardItem("aaa");
	model->setItem(1, 0, item);
	item = new QStandardItem("bbb");
	model->setItem(1, 1, item);

	ret->setModel(model);

	// set table style:
	// center for header, column stretchable, hide line no
	ret->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
	ret->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ret->verticalHeader()->hide();

	// set table attributes:
	// no edit
	ret->setSelectionBehavior(QAbstractItemView::SelectColumns);
	ret->setEditTriggers(QAbstractItemView::NoEditTriggers);

	return ret;
}

