#ifndef ADDTRAINWINDOW_H
#define ADDTRAINWINDOW_H

#include "ui_addtrain.h"
#include <vector>

class Client;
class AdminWindow;
class AddTrainWindow:public QWidget{
	Q_OBJECT
private:
	Ui::addTrain ui;
	Client *client;
	AdminWindow *parent;
	std::vector<QDateTimeEdit*> time;
	int lastRowCnt;
	bool check();
signals:
	void addFinish();
private slots:
	void sendNewTrainInfo();
	void setupTable();
	void daysBoxEnabled(int x);
public:
	AddTrainWindow(Client *client, AdminWindow *parent);

};

#endif