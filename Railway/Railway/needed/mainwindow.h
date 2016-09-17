#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <Qstring>
#include "mytcpserver.h"
#include "ui_mainwindow.h"
#include "mydatabase.h"
class mainwindow : public QWidget
{
	Q_OBJECT

public:
	mainwindow(int port,QString databaseAd,QWidget *parent = 0);
	~mainwindow();
signals:
	void serverWrite(QString);
	void serverWrite(QString,int _d);
public slots:
	void Mydebug(const QString&);
	void onNewUser(int,QString,int,QStringList a=QStringList());
	void onSendClicked();
	void onInfoClicked();
	void onDeleteClicked();
	void updateCurrentUser();
	void onRegisterUser(int);
	void onTicketInfo(QStringList);
	void onTrainInfo(QStringList);
	void onMidStationInfo(QStringList);
	void onReturnDeleteResult(int);
	void onUserAddMoneyResult(int);
	void onUserUpdateInfoResult(int);
	void onBuyTicketResult(int);
	void onAdminUpdateInfoResult(int);
	void onAddTrainResult(int);
	void onTrainUpdateResult(int);
	void onUserLogOut(QString);
	void onDeleteTrainResult(int);

private:
	Ui::mainwindow ui;
	int getRow(QTableWidget *,int);
	int getRow(QTableWidget *);
	void addUserInfo(QString,int,int);//userid and identity
	void addUserInfo(int);//descriptor
	bool IsLogin(const QString& UserId);

	MyTcpServer server;
	MyDataBase database;
};

#endif // MAINWINDOW_H
