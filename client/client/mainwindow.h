#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ui_mainwindow.h"
#include "ui_pay.h"
#include "qwidget.h"
#include "client.h"
#include "loginwindow.h"
#include "user.h"
#include "ticket.h"
#include <vector>
#include "enum.h"
#include "train.h"
using namespace std;

class LoginWindow;
class MainWindow:public QMainWindow{
	Q_OBJECT
public:
	MainWindow(LoginWindow *parent, Client *client, QString userinfo);
	~MainWindow();
	Ui::MainWindow ui;
	QDialog *payWindow;
	Train*& getTrain(int x){return TrainList[x];}
	void setupBuyButton();
private slots:
	void triggerPay();
	void triggerBuy();
	void triggerBuyStudent();
	void triggerReturnTicket();
	void triggerBuyOther();
	void payCheck();
	void askDetail(int row, int column);
public slots:
	void logout();
	void onForceLogout();
	void exitProgram();
	void setupTicketInfo();
	void searchTrain();
signals:
	void pay(int x);
private:
	Ui::Pay uiPay;
	Client *client;
	LoginWindow *parent;
	User *u;
	void setupPersonalInfo(QString userinfo);
	vector<Train*> TrainList;
};

#endif