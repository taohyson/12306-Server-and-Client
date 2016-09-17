#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <qwidget.h>
#include "ui_mainwindowadmin.h"
#include "loginwindow.h"
#include "client.h"
#include "admin.h"
#include "addTrainWindow.h"
#include "edittrainwindow.h"
#include "train.h"
#include "ui_deletetrain.h"

class Admin;
class AddTrainWindow;
class AdminWindow: public QMainWindow{
	Q_OBJECT
public:
	AdminWindow(LoginWindow *parent, Client *client, QString userinfo);
	Ui::adminWindow ui;
	Ui::deleteWindow ui2;
	Train*& getTrain(int x){return TrainList[x];}
private:
	LoginWindow *parent;
	Client *client;
	void setupPersonalInfo(QString userinfo);
	Admin *u;
	AddTrainWindow *addTrainW;
	EditTrainWindow *editTrainW;
	vector<Train*> TrainList;
	bool checkTrainEditable(int x);
	bool checkTime(int x);
	QWidget *deleteW;
public slots:
	void searchTrain();
private slots:
	void exitProgram();
	void logout();
	void onForceLogout();
	void showAddWindow();
	void deleteTrain();
	void editTrain();
	void sendDeleteMsgPer();
	void sendDeleteMsgTem();
	void askDetail(int row, int column);
};


#endif