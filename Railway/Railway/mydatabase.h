#ifndef MYDATABASE_H
#define MYDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSQlQuery>
#include <QTime>
#include <QSqlError>
#include <QtDebug>
#include <QSqlDriver>
#include <QSqlRecord>
#include "train.h"
#include "ticket.h"
#include "user.h"
#include "admin.h"
enum id
{
	User=1,
	Admin=2,
};
class MyDataBase : public QObject
{
	Q_OBJECT

public:
	MyDataBase(QObject *parent=0);
	~MyDataBase();
	bool createConnection(QString);
	bool createTables();
	bool queryAll(QString);//查询所有信息
	QStringList queryInfo(QString table,QString UserId);//在table里找到对应用户名的全部信息
	bool addTrain(QString date);
	bool deleteTrain(QString date);//过了今天就把这车删了.
	bool deleteTicket(QString date);//过了今天就把票也删了.
	QString date;//今天

signals:
	void newdebug(const QString&);
	void newUser(int,QString,int,QStringList a=QStringList());
	void registerUser(int);
	void userTicketInfo(QStringList);
	void trainInfo(QStringList);
	void returndeleteResult(int);
	void midStationInfo(QStringList);
	void userAddMoneyResult(int);
	void userUpdateInfoResult(int);
	void buyTicketResult(int);
	void adminUpdateInfoResult(int);
	void addTrainResult(int);
	void trainUpdateResult(int);
	void deleteTrainResult(int);

public slots:
	void checkNewUser(QString,QString);
	void registerNewUser(QString,QString,QString,QString,QString,QString,QString,QString,QString);//接收一堆
	void onTicketQuery(QString);
	void onTrainQuery(Train t);
	void onTicketReturn(Ticket t);
	void onMidStationQuery(Train t);
	void onUserAddMoney(UserClass t);
	void onUserUpdateInfo(UserClass u);
	void onBuyTicket(Ticket);
	void onUpdateAdminInfo(admin);
	void onAddTrainInfo(Train);
	void onUpdateTrainInfo(Train);
	void onDeleteTrain(Train);

private:
	QString DateBaseName;
	QSqlDatabase db;
	QString tranlateDate(QString);
	void aux_addTrain(const Train& t);
	int addUser(QString,QString,QString,QString,QString,QString,QString,QString,QString);//往数据库里加user
	int query(QString table,QString UserId,QString);//在table里查询用户名密码是否匹配。
	QStringList queryUserTicketInfo(QString UserId);//在ticket里找到用户购买票的信息。
	QStringList queryTrainInfo(Train t);//在train里找到制定要求的train
	QStringList queryMidStationInfo(Train t);//在train里找到train的所有中间站
	QStringList aux_getTrains(Train t);//找到所有符合条件的车次名
	int ticketReturn(Ticket t);//返回ticketreturn的结果。
	int addUserMoney(UserClass u);
	int aux_getItemNumber(QString table);//获取table中数条目数
	int aux_getStationNum(Train t);//找到火车t(在某天)的所有车站数。
	int aux_getSeatNum(Train t);//根据trainid找到他的座位数
	int aux_getType(Train t);//根据id找到type
	int aux_getLeftTicket(Train t);
	int aux_getOriginStationId(Ticket t);
	int aux_getDestinationStationId(Ticket t);
	double aux_getCurrentMoney(UserClass u);
	double aux_getPrice(Ticket t);
	QStringList aux_getTrainTicketInfo(Train t);
	int addUserMoney(double money,QString user);
	int updateUserInfo(UserClass u);
	int addTicket(Ticket t);
	QString aux_getOriginTime(Train t);
	QString aux_getEndTime(Train t);
	QString aux_getEndTime(Ticket t);//找到这张票destination对应的时间
	double aux_getTrainPrice(const Train& t);
	int updateAdminInfo(admin a);
	QList<Train> aux_getRegularTrain();//从regulartrain里读数据出来存到Qlist
	int addTrain(Train);
	int updateTrainInfo(Train t);
	bool aux_IsExists(QString table,QString TrainId,QString Starttime,QString Origin);
	bool aux_IsExists(QString,QString,QString);
	int aux_updateTrainInfo(QString table,Train t);
	int deleteTrain(Train t);
	int aux_deleteTrain(QString table,Train t);
	bool aux_IsExists(QString table,QString UserId);
	QString aux_getBuyer(Ticket t);
};

#endif // MYDATABASE_H
