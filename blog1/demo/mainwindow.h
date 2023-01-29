#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QWidget;
class QTableView;
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	QWidget *central;

public:
	void constructUI(QWidget *parent);
	QTableView *createTable();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
