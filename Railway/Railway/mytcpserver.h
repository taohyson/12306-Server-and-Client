#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>
#include <qtcpsocket.h>
#include <qlist.h>
#include "train.h"
#include "ticket.h"
#include "user.h"
#include "admin.h"
enum type
{
	UserId=1,
	Identity=2,
	Descriptor=3,
};

class MyTcpServer
	: public QTcpServer
{
	Q_OBJECT

public:
	MyTcpServer(QObject *parent=0);
	QList<QTcpSocket*> _clients;
	~MyTcpServer();
	QTcpSocket *currentSocket;
signals:
	void newdebug(const QString&);
	void newUser(QString,QString);
	void newRegister(QString,QString,QString,QString,QString,QString,QString,QString,QString);
	void update();
	void ticketQuery(QString);
	void trainQuery(Train t);
	void returnTicket(Ticket t);
	void MidStationQuery(Train t);
	void userAddMoney(UserClass u);
	void updateUserInfo(UserClass u);
	void updateAdminInfo(admin);
	void buyTicket(Ticket);
	void addTrainInfo(Train);
	void updateTrainInfo(Train);
	void userLogOut(QString);
	void deleteTrain(Train t);

public slots:
	void onNewConnection();
	void readClient();
	void clientDisconnected();
	void Write(QString);
	void Write(QString,int);
private:
	void resetStatus();
	bool IsLogin;
	bool IsRegister;
	bool IsTicketBought;
	bool IsSearchTrain;
	bool IsReturn;
	bool IsMidQuery;
	bool IsPay;
	bool IsUpdateInfo;
	bool IsBuyTicket;
	bool IsUpdateAdmininfo;
	bool IsDeleteTrain;
	bool IsUpdateTrainInfo;
	bool IsAddTrainInfo;
	bool IsUserLogOut;
	bool IsSeatBought;

};

#endif // MYTCPSERVER_H
