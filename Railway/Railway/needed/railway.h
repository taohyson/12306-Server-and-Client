#ifndef RAILWAY_H
#define RAILWAY_H

#include <QtWidgets/QMainWindow>
#include "ui_railway.h"

class Railway : public QMainWindow
{
	Q_OBJECT

public:
	Railway(QWidget *parent = 0);
	~Railway();
private slots:
	void onclicked();
private:
	Ui::RailwayClass ui;
	bool flag;
};

#endif // RAILWAY_H
