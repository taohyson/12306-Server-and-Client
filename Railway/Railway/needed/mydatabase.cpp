#include "mydatabase.h"
#include <Qfile>
#include "train.h"
#include<cmath>
#include <cstdlib>
#include <ctime>
enum cartype
{
	sitseat=120,
	sleepseat=60,
};
const int days=10;//添加数据大小
const double sitPricePerkm=0.5;
const double sleepPricePerkm=0.6;

//initial operation
MyDataBase::MyDataBase(QObject *parent)
	: QObject(parent)
{
}
bool MyDataBase::createConnection(QString _name)
{
	DateBaseName=_name;
	if (!QFile::exists(DateBaseName))
		emit newdebug(QStringLiteral("正在创建数据库..."));
	else
	{
		emit newdebug(QStringLiteral("正在加载已有数据库..."));
	}
	db=QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(DateBaseName);
	if (!db.open())
	{
		emit newdebug("Fatal Error!unable to link database!");
		return false;
	}
	return true;
}
bool MyDataBase::createTables()
{
	QSqlQuery query(db);
	query.prepare("create table IF NOT EXISTS USER"
				"(UserId VARCHAR PRIMARY KEY,PassWord TEXT,Name VARCHAR,Sex INT,"
				"Credentials TEXT,Contact TEXT,Nation TEXT,Identity TEXT, Addition TEXT)");
	if(!query.exec())
	{
		emit newdebug("Fatal error!Failed to create table USER!");
		return false;
	}
	query.prepare("create table IF NOT EXISTS Administrator"
				"(UserId VARCHAR PRIMARY KEY,PassWord TEXT,Name VARCHAR,"
				"Contact TEXT,Position TEXT)");
	if (!query.exec())
	{
		emit newdebug("Fatal error!Failed to create table Administrator!");
		return false;
	}
	query.prepare("create table IF NOT EXISTS Ticket"
		"(TrainId VARCHAR,StartTime DateTime,Origin TEXT,Destination TEXT,Seat VARCHAR,UserId VARCHAR,TicketType int,Price DECIMAL,primary key(TrainId,Origin,Seat))");
	if (!query.exec())
	{
		emit newdebug("Fatal error!Failed to create table Ticket!");
		return false;
	}
	query.prepare("create table IF NOT EXISTS Train"
		"(TrainId VARCHAR, StartTime DateTime,EndTime DateTime,Origin VARCHAR,Destination VARCHAR, CarType int, Price int,StationId int, primary key(TrainId,StartTime))");
	if (!query.exec())
	{
		emit newdebug("Fatal error!Failed to create table Train!");
		return false;
	}
	query.prepare("create table IF NOT EXISTS cartype"
		"(CarType INT PRIMARY KEY, SeatNum INT) ");
	if (!query.exec())
	{
		emit newdebug("Fatal error!Failed to create table cartype!");
		return false;
	}
	query.prepare("create table IF NOT EXISTS Account"
		"(UserId INT PRIMARY KEY, Money Decimal) ");
	if (!query.exec())
	{
		emit newdebug("Fatal error!Failed to create table Account!");
		return false;
	}
	return true;
}
MyDataBase::~MyDataBase()
{

}
bool MyDataBase::queryAll(QString table)
{
	QSqlQuery query(db);
	if (!query.exec("select * from ('"+table+"')"))
		return false;
	QSqlRecord rec=query.record();
	qDebug()<<table+".count"<<rec.count();
	while(query.next())
	{
		for (int index=0;index<7;index++)
			qDebug()<<query.value(index)<<" ";
		qDebug()<<"\n";
	}
	return true;
}
bool MyDataBase::addTrain(QString date)//包括train和cartype的信息。
{
	int itemNum=0;
	bool flag1=true,flag2=true;
	QSqlQuery query(db);
	QList<Train> result=aux_getRegularTrain();
	QString p;
	itemNum=aux_getItemNumber("train");
	//if (itemNum>=days*result.length())//已添加。
	//	flag1=false;
	itemNum=aux_getItemNumber("cartype");
	if (itemNum>=2)//已添加。
		flag2=false;
	if (flag1)
	{
	QString buffer1;
	QString Mydate,Mydate2;
	Train target;
	
	for (int i=0;i<days;i++)
	{
		for (int j=0;j<result.length();j++)
		{
			Train t=result.at(j);
			if (t.StartTime>t.EndTime)//认为隔天
			{
				Mydate=QDateTime::fromString(date,"yyyy-MM-dd").addDays(i).toString("yyyy/MM/dd");
				t.StartTime=Mydate+" "+t.StartTime;
				Mydate2=QDateTime::fromString(date,"yyyy-MM-dd").addDays(i+1).toString("yyyy/MM/dd");
				t.EndTime=Mydate2+" "+t.EndTime;
			}
			else
			{
				Mydate=QDateTime::fromString(date,"yyyy-MM-dd").addDays(i).toString("yyyy/MM/dd");
				t.StartTime=Mydate+" "+t.StartTime;
				t.EndTime=Mydate+" "+t.EndTime;
			}
			aux_addTrain(t);
		}
	}
	}
	if (flag2)
	{
		p=QString("insert into cartype values(0,%1,%2)").arg(sitseat).arg(sitPricePerkm);
		query.prepare(p);
		if (!query.exec())
		{
			emit newdebug("add cartype error!");
			QSqlError lastError=query.lastError();
			emit newdebug(lastError.text());
		}
		p=QString("insert into cartype values(1,%1,%2)").arg(sleepseat).arg(sleepPricePerkm);
		query.prepare(p);
		if (!query.exec())
		{
			emit newdebug("add cartype error!");
			QSqlError lastError=query.lastError();
			emit newdebug(lastError.text());
		}

	}
	return true;
}
bool MyDataBase::deleteTrain(QString date)
{
	QSqlQuery query(db);
	QString content=QString("delete"
							" from train"
							" where StartTime<'%1'").arg(date);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return false;
	}
	return true;
}
bool MyDataBase::deleteTicket(QString date)
{
	QSqlQuery query(db);
	QString content=QString("delete"
							" from ticket"
							" where StartTime<'%1'").arg(date);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return false;
	}
	return true;
}

//slots
void MyDataBase::onTicketQuery(QString Userid)
{
	QStringList result=queryUserTicketInfo(Userid);
	emit userTicketInfo(result);
}
void MyDataBase::onTrainQuery(Train t)
{
	QStringList result=queryTrainInfo(t);
	emit trainInfo(result);
}
void MyDataBase::onTicketReturn(Ticket t)
{
	int flag=ticketReturn(t);
	emit returndeleteResult(flag);
}
void MyDataBase::onMidStationQuery(Train t)
{
	//int num=aux_getStationNum(t);
	//emit newdebug(QString("%1").arg(num));
	QStringList result=queryMidStationInfo(t);
	emit midStationInfo(result);
}
void MyDataBase::registerNewUser(QString UserId,QString PassWord,QString name,QString sex,
						QString nation,QString credencial,QString contact,QString identity,QString addition)
{
	int flag=addUser(UserId,PassWord,name,sex,nation,credencial,contact,identity,addition);
	emit registerUser(flag);
}
void MyDataBase::checkNewUser(QString name,QString password)
{
	//emit newdebug("checking!");
	int flag1=query("USER",name,password);
	int flag2=query("Administrator",name,password);
	if (flag1==2)
	{
		QStringList temp=queryInfo("USER",name);
		//emit newdebug(QString("%1").arg(name));
		emit newUser(2,name,User,temp);
		return ;
	}
	if (flag2==2)
	{
		QStringList temp=queryInfo("Administrator",name);
		emit newUser(2,name,Admin,temp);
		return ;
	}
	if (flag1==1 && flag2==1)//xuser
	{
		emit newUser(1,name,User);
		return ;
	}
	if (flag1==-1 || flag2==-1)//Query error!
	{
		emit newUser(-1,name,User);
		return ;
	}
	emit newUser(0,name,User);//xpassword
}
void MyDataBase::onUserAddMoney(UserClass u)
{
	if (u.UserId=="")
	{
		emit userAddMoneyResult(-1);
		return ;
	}
	int flag=addUserMoney(u);
	emit userAddMoneyResult(flag);
}
void MyDataBase::onUserUpdateInfo(UserClass u)
{
	int flag=updateUserInfo(u);
	emit userUpdateInfoResult(flag);
}
void MyDataBase::onBuyTicket(Ticket t)
{
	int flag=addTicket(t);
	emit buyTicketResult(flag);
}
void MyDataBase::onUpdateAdminInfo(admin a)
{
	int flag=updateAdminInfo(a);
	emit adminUpdateInfoResult(flag);
}
void MyDataBase::onAddTrainInfo(Train t)
{
	int flag=addTrain(t);
	emit addTrainResult(flag);
}
void MyDataBase::onUpdateTrainInfo(Train t)
{
	int flag=updateTrainInfo(t);
	emit trainUpdateResult(flag);
}
void MyDataBase::onDeleteTrain(Train t)
{
	int flag=deleteTrain(t);
	emit deleteTrainResult(flag);
}

//operations on slots
int MyDataBase::ticketReturn(Ticket t)
{
	int itemNum1,itemNum2;

	//钱还给人家
	QSqlQuery query(db);
	double addmoney=aux_getPrice(t);
	//QString buyer=aux_getBuyer(t);
	QString temp=QString("delete from ticket where UserId='%1' and TrainId='%2' and Starttime='%3'")
		.arg(t.UserId).arg(t.TrainId).arg(t.StartTime);
	itemNum1=aux_getItemNumber("ticket");
	query.prepare(temp);
	if (!query.exec())
	{
		emit newdebug("ticket return error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
	}
	itemNum2=aux_getItemNumber("ticket");
	if (itemNum2!=-1 && itemNum1!=-1)
	{
		if (itemNum1==itemNum2+1)//删除成功
		{
			addUserMoney(addmoney,t.UserId);
			return 1;
		}
		if (itemNum1>itemNum2+1)//多删了
			return 2;
		if (itemNum1<itemNum2+1)//没删
			return 0;
	}
	else
	{
		return -1;//这属于莫名其妙。
	}
}
QStringList MyDataBase::queryTrainInfo(Train t)
{
	QStringList result;result.clear();
	Train target;
	//for (int i=0;i<trainNum;i++)//对每一辆车,计算余量
	//{
	//	Train target;
	//	target.TrainId=trainids.at(i);
	//	target.maxSeatNum=aux_getSeatNum(target);
	//	QStringList result =aux_getTrainTicketInfo(target);
	//	//emit newdebug(QString("%1:%2").arg(target.TrainId).arg(target.maxSeatNum));
	//}
	QSqlQuery query(db);
	//emit newdebug(t.EndTime);
	if (t.TrainType=="0")
		t.TrainType="";//全都可以
	QString date=QDateTime::fromString(t.EndTime,"yyyy/MM/dd ss:mm").toString("yyyy/MM/dd");//这qdatetime不能24:00什么情况啊
	//emit newdebug(date);
	QString temp=QString("select a.trainid,a.Origin,b.Destination,a.StartTime,b.EndTime,a.CarType,(a.StationId<>0),"
						" (select MAX(StationId) from Train where TrainId=a.TrainId)!=b.StationId,a.stationid,b.stationid"
						" from train as a,train as b"
						"  where a.Starttime>='%1' and a.Starttime<='%2' and "
						" (select min(endtime) from train where trainid=a.TrainId and starttime>=a.StartTime and stationid="
						" (select MAX(StationId) from Train where TrainId=a.TrainId))>=b.EndTime"
						" and b.EndTime>=a.starttime "
						" and a.trainid=b.trainid and a.origin like '%3%' and b.destination like '%4%' and a.trainid like '%5%'"
						" order by a.starttime asc")
						.arg(t.StartTime).arg(t.EndTime).arg(t.Origin).arg(t.Destination).arg(t.TrainType);
	//emit newdebug(temp);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return result;
	}
	query.last();int num=query.at()+1;
	query.first();query.previous();
	result.append(QString("%1;").arg(num));
	QSqlRecord rec=query.record();
	while(query.next())//每个都是一辆车
	{
		for (int i=0;i<rec.count();i++)
		{
			if (i==0) target.TrainId=query.value(i).toString();
			if (i==1) target.Origin=query.value(i).toString();
			if (i==2) target.Destination=query.value(i).toString();
			if (i==3) target.StartTime=query.value(i).toString();
			if (i==4) target.EndTime=query.value(i).toString();
			if (i==5) target.carType=query.value(i).toInt();
			if (i==6) target.flag1=query.value(i).toBool();
			if (i==7) target.flag2=query.value(i).toBool();
			if (i==8) target.originStationId=query.value(i).toInt();
			if (i==9) target.endStationId=query.value(i).toInt();
		}
		target.maxSeatNum=aux_getSeatNum(target);
		target.leftSeat=aux_getLeftTicket(target);//计算余票
		int price=floor(aux_getTrainPrice(target));
		result.append(target.TrainId);
		result.append(target.Origin);
		result.append(target.Destination);
		result.append(target.StartTime);
		result.append(target.EndTime);
		result.append(QString("%1").arg(target.carType));
		result.append(QString("%1").arg(price));
		result.append(QString("%1").arg(target.leftSeat));
		result.append(QString("%1").arg(target.flag1));
		result.append(QString("%1").arg(target.flag2));
		result.append(";");
	}
	return result;
}
QStringList MyDataBase::queryInfo(QString table,QString UserId)
{
	QStringList temp;temp.clear();
	QSqlQuery query(db);
	QString content;
	if (table=="USER")
		content=QString("select a.*,b.money from %1 as a, account as b WHERE a.UserId='%2' and b.UserId='%2'").arg(table).arg(UserId);
	if (table=="Administrator")
		content=QString("select * from %1 WHERE UserId='%2'").arg(table).arg(UserId);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
	}
	QSqlRecord rec=query.record();
	if (!rec.count())
	{
		emit newdebug("queryInfo error!");
	}
	while(query.next())
	{
		for (int i=0;i<rec.count();i++)
		{
			if (query.value(i).toString().isEmpty()|| query.value(i).toString()==",")
				temp.append("null");
			else 
				temp.append(query.value(i).toString());
		}
	}
	return temp;
}
QStringList MyDataBase::queryUserTicketInfo(QString UserId)
{
	QStringList result;result.clear();
	QSqlQuery query(db);
	Ticket t;
	QString temp=QString("select trainid,starttime,origin,destination,seat,price,tickettype "
						" from ticket" 
						" where userid='%1'")
						.arg(UserId);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return result;
	}
	query.last();int num=query.at()+1;
	query.first();query.previous();
	result.append(QString("%1;").arg(num));
	QSqlRecord rec=query.record();
	while(query.next())
	{
		for (int i=0;i<rec.count();i++)
		{
			if(i==0) t.TrainId=query.value(i).toString();
			if (i==1) t.StartTime=query.value(i).toString();
			if (i==2) t.Origin=query.value(i).toString();
			if (i==3) t.Destination=query.value(i).toString();
			if (i==4) t.Seat=query.value(i).toInt();
			if (i==5) t.price=query.value(i).toDouble();
			if (i==6) t.Tickettype=query.value(i).toInt();
		}
		Train train;train.TrainId=t.TrainId;train.StartTime=t.StartTime;
		t.cartype=aux_getType(train);
		t.EndTime=aux_getEndTime(t);
		result.append(t.TrainId);
		result.append(t.Origin);
		result.append(t.Destination);
		result.append(t.StartTime);
		result.append(t.EndTime);
		result.append(QString("%1").arg(t.cartype));
		result.append(QString("%1").arg(t.Seat));
		result.append(QString("%1").arg(t.price));
		result.append(QString("%1").arg(t.Tickettype));
		result.append(";");
	}
	return result;
}
QStringList MyDataBase::queryMidStationInfo(Train t)
{
	QStringList result;result.clear();
	QSqlQuery query(db);
	QString originTime=aux_getOriginTime(t);
	QString endTine=aux_getEndTime(t);
	QString date=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
	QString temp=QString("select trainId, origin, destination, starttime,endtime,stationid"
						 " from train"
						 " where trainid='%1' and starttime >= '%2' and starttime<='%3'" 
						 " order by stationid asc").arg(t.TrainId).arg(originTime).arg(endTine);
	//emit newdebug(temp);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return result;
	}
	query.last();int num=query.at()+1;
	query.first();query.previous();
	result.append(QString("%1;").arg(num));
	QSqlRecord rec=query.record();
	while(query.next())
	{
		for (int i=0;i<rec.count();i++)
		{
			if (query.value(i).toString().isEmpty()|| query.value(i).toString()==",")
				result.append("null");
			else 
				result.append(query.value(i).toString());
		}
		result.append(";");
	}
	return result;
}
int MyDataBase::addUser(QString UserId,QString PassWord,QString name,QString sex,
						QString nation,QString credencial,QString contact,QString identity,QString addition)
{
	QSqlQuery query(db);
	QSqlRecord rec;
	QString temp;
	temp=QString ("select * from USER where UserId='%1'").arg(UserId);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	rec=query.record();
	if (query.next())//找到userid=target
	{
		return 1;
	}

	temp=QString ("select * from USER where Credentials='%1'").arg(credencial);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		//emit newdebug("2");
		return -1;
	}
	rec=query.record();
	if (query.next())//找到身份证=target
		return 0;
	
	if (sex.contains("Male"))
		sex="1";
	else if (sex.contains("Fe"))
		sex="2";
	else
		sex="null";
	temp=QString("insert into USER values('%1','%2','%3',%4,'%5','%6','%7','%8','%9')")
		.arg(UserId).arg(PassWord).arg(name).arg(sex).arg(credencial).arg(contact).arg(nation).arg(identity).arg(addition);
	//emit newdebug(temp);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		//emit newdebug("3");
		return -1;
	}
	
	//加入一个新的account;
	temp=QString("insert into account values('%1',0)").arg(UserId);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	return 2;
}
int MyDataBase::query(QString table,QString UserId,QString Password)
{
	QSqlQuery query(db);
	QString TruePassword;
	if (table=="USER" || table=="Administrator")
	{
		QString content=QString("select * from %1 WHERE UserId='%2'").arg(table).arg(UserId);
		query.prepare(content);
		if (!query.exec())
		{
			QSqlError lastError=query.lastError();
			emit newdebug(lastError.text());
			return -1;
		}
		QSqlRecord rec=query.record();
		if (!query.next())//没找到，xuser
			return 1;
		query.previous();
		while(query.next())
		{
			TruePassword=query.value("PassWord").toString();
			//emit newdebug(TruePassword);
		}
		
		if (TruePassword==Password)
			return 2;
		else
			return 0;
	}
	return -1;
}
int MyDataBase::addUserMoney(UserClass u)
{
	QSqlQuery query(db);
	double premoney=aux_getCurrentMoney(u);
	addUserMoney(u.addmoney,u.UserId);
	double currentmoney=aux_getCurrentMoney(u);
	if (abs(currentmoney-premoney-u.addmoney)<1e-2)
		return 1;//更新成功
	return 0;
}
int MyDataBase::updateUserInfo(UserClass u)
{
	QSqlQuery query(db);
	QString content=QString("update user"
							" set password='%1',name='%2',sex=%3,credentials='%4',"
							" contact='%5',nation='%6',identity='%7',addition='%9'"
							" where userid='%8'").arg(u.password).arg(u.name).arg(u.sex).arg(u.credentials)
							.arg(u.contact).arg(u.nation).arg(u.identity).arg(u.UserId).arg(u.addtion);
	emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return 0;
	}
	return 1;
}
int MyDataBase::addTicket(Ticket t)
{
	QSqlQuery query(db);
	if (!aux_IsExists("account",t.UserId))
		return 0;
	int maxSeat=aux_getSeatNum(t.TrainId);
	//emit newdebug(QString::number(maxSeat));
	if (maxSeat==-1)
	{
		emit newdebug("cannnot get maxseat in addTicket!");
		return -1;
	}

	if (t.Seat==120)
		t.Seat=rand()%(maxSeat-1);
	
	QString temp=QString("insert into ticket values('%1','%2','%3','%4',%5,'%6','%7','%8','%9')")
		.arg(t.TrainId).arg(t.StartTime).arg(t.Origin).arg(t.Destination).arg(t.Seat)
		.arg(t.UserId).arg(t.Tickettype).arg(t.price).arg(t.Buyer);
	//emit newdebug(temp);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	if (addUserMoney(-t.price,t.Buyer))
		return 1;
	return -1;
}
int MyDataBase::updateAdminInfo(admin a)
{
	QSqlQuery query(db);
	QString content=QString("update administrator"
							" set password='%2',name='%3',contact='%4',position='%5'"
							" where userid='%1'").arg(a.userid).arg(a.password).arg(a.name)
							.arg(a.contact).arg(a.position);
	emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return 0;
	}
	return 1;
}
int MyDataBase::addTrain(Train t)
{
	if (t.addType==0)//永久添加
	{
		QSqlQuery query(db);
		QString starttime=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("hh:mm");
		QString endtime=QDateTime::fromString(t.EndTime,"yyyy/MM/dd hh:mm").toString("hh:mm");
		QString temp=QString("select * from regulartrain where trainid='%1' and starttime='%2'")
			.arg(t.TrainId).arg(starttime);
		//emit newdebug(temp);
		query.prepare(temp);
		if(!query.exec())
		{
			QSqlError lastError=query.lastError();
			emit newdebug(lastError.text());
			return -1;
		}
		if (query.next())
			return 0;

		QString Mydate1,Mydate2;
		temp=QString("insert into regularTrain values('%1','%2','%3','%4','%5',%6,%7, %8)")
			.arg(t.TrainId).arg(starttime).arg(endtime).arg(t.Origin).arg(t.Destination)
			.arg(t.carType).arg(t.length).arg(t.StationId);
		//emit newdebug(temp);
		query.prepare(temp);
		if (!query.exec())
		{
			QSqlError lastError=query.lastError();
			emit newdebug(lastError.text());
			return -1;
		}
		for (int i=0;i<days;i++)
		{
			Train t2=t;
			t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			aux_addTrain(t2);
		}
		return 1;
	}
	if (t.addType==1)//临时添加
	{
		QSqlQuery query(db);
		QString temp=QString("select * from train where trainid='%1' and starttime='%2'")
			.arg(t.TrainId).arg(t.StartTime);
		//emit newdebug(temp);
		query.prepare(temp);
		if(!query.exec())
		{
			QSqlError lastError=query.lastError();
			emit newdebug(lastError.text());
			return -1;
		}
		if (query.next())
			return 0;

		for (int i=0;i<t.addDays;i++)
		{
			Train t2=t;
			t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			aux_addTrain(t2);
		}
		return 1;
	}
	return -1;
}
int MyDataBase::updateTrainInfo(Train t)
{
	if(t.addType==1)//临时修改
	{
		for (int i=0;i<t.addDays;i++)
		{
			Train t2=t;
			QString starttime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
			t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			if (!aux_IsExists("train",t2.TrainId,starttime,t.Origin))
				return 1;
			if(!aux_updateTrainInfo("train",t2))
				return -1;
		}
		return 1;
	}
	if (t.addType==0)//永久修改
	{
		Train t2=t;
		t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").toString("hh:mm");
		t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").toString("hh:mm");
		for (int i=0;i<days;i++)
		{
			Train t2=t;
			QString starttime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
			t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			if (!aux_IsExists("train",t2.TrainId,starttime,t.Origin))
				break;
			if(!aux_updateTrainInfo("train",t2))
				return -1;
		}
		if (!aux_IsExists("regulartrain",t.TrainId,"0",t2.Origin))
			return 0;
		if (!aux_updateTrainInfo("regulartrain",t2))
			return -1;
		return 1;
	}
}
int MyDataBase::deleteTrain(Train t)
{
	if(t.addType==1)//临时删除
	{
		//emit newdebug(QString("addDays=%1").arg(t.addDays));
		for (int i=0;i<t.addDays;i++)
		{
			Train t2=t;
			t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			//t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			if (!aux_IsExists("train",t2.TrainId,t2.StartTime))
				return 1;
			if(!aux_deleteTrain("train",t2))
				return -1;
		}
		return 1;
	}
	if (t.addType==0)//永久删除
	{
		Train t2=t;
		t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").toString("hh:mm");
		for (int i=0;i<days;i++)
		{
			Train t2=t;
			t2.StartTime=QDateTime::fromString(t2.StartTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			t2.EndTime=QDateTime::fromString(t2.EndTime,"yyyy/MM/dd hh:mm").addDays(i).toString("yyyy/MM/dd hh:mm");
			if (!aux_IsExists("train",t2.TrainId,t2.StartTime))
				break;
			if(!aux_deleteTrain("train",t2))
				return -1;
		}
		if (!aux_IsExists("regulartrain",t.TrainId,t2.StartTime))
			return 0;
		if (!aux_deleteTrain("regulartrain",t2))
			return -1;
		return 1;
	}
	return -1;
}

//aux fuctions
int MyDataBase::aux_getLeftTicket(Train t)
{
	//emit newdebug(QString("%1:%2").arg(t.originStationId).arg(t.endStationId));
	int statioNum=aux_getStationNum(t);
	int leftTicket=t.maxSeatNum;
	bool ** m;//开始构建二维动态数组
	m=new bool*[t.maxSeatNum+1];
	for(int i=0;i<t.maxSeatNum+1;i++)
		m[i]=new bool[statioNum];
	for (int i=0;i<t.maxSeatNum+1;i++)
		for (int j=0;j<statioNum;j++)
			m[i][j]=true;
	QSqlQuery query(db);
	if (t.TrainId=="0"|| t.StartTime=="0")
	{
		emit newdebug("getLeftTicket error!");
		return -1;
	}
	//QString date=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
	QString p=QString("select trainid,starttime,origin,destination,seat"
					" from ticket"
					" where trainid='%1' and starttime >= '%2' and starttime<='%3'").arg(t.TrainId).arg(t.StartTime).arg(t.EndTime);
	//emit newdebug(p);
	query.prepare(p);//查询购买此车的人的票
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	QSqlRecord rec=query.record();
	Ticket target;
	while (query.next())
	{
		for (int i=0;i<rec.count();i++)
		{
			if (i==0) target.TrainId=query.value(i).toString();
			if (i==1) target.StartTime=query.value(i).toString();
			if (i==2) target.Origin=query.value(i).toString();
			if (i==3) target.Destination=query.value(i).toString();
			if (i==4) target.Seat=query.value(i).toInt();
		}
		target.OriginStationId=aux_getOriginStationId(target);
		target.DestinationStaionId=aux_getDestinationStationId(target);
		for (int i=target.OriginStationId;i<=target.DestinationStaionId;i++)
			m[target.Seat][i]=false;
	}
	bool flag;//记录每一个座位是否有人坐
	for (int i=0;i<t.maxSeatNum;i++)
	{
		flag=false;
		for (int j=t.originStationId;j<=t.endStationId;j++)
			if (m[i][j]==false)
				flag=true;
		if (flag)
			leftTicket--;
	}

	delete[] m;
	return leftTicket;
}
int MyDataBase::aux_getStationNum(Train t)
{
	int stationNum=0;
	QSqlQuery query(db);
	if (t.TrainId=="0"|| t.StartTime=="0")
	{
		emit newdebug("getStationNum error!");
		return -1;
	}
	QString date=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
	QString p=QString("select MAX(StationId)+1 from Train "
		" where TrainId='%1' and starttime like '%2%'").arg(t.TrainId).arg(date);
	//emit newdebug(p);
	query.prepare(p);//查询train里的条目数
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while (query.next())
		stationNum=query.value(0).toInt();
	return stationNum;
}
QStringList MyDataBase::aux_getTrains(Train t)
{
	QStringList result;result.clear();
	QSqlQuery query(db);
	QString temp=QString("select distinct a.trainid"
						" from train as a,train as b"
						" where a.Starttime>='%1' and a.Starttime<='%2'"
						" and a.trainid=b.trainid and a.origin like '%3%' and b.destination like '%4%' "
						" order by a.starttime asc").arg(t.StartTime).arg(t.EndTime).arg(t.Origin).arg(t.Destination);
	//emit newdebug(temp);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return result;
	}
	QSqlRecord rec=query.record();
	while(query.next())
	{
		result.append(query.value(0).toString());
	}
	return result;
}
int MyDataBase::aux_getSeatNum(Train t)
{
	QString p;
	QSqlQuery query(db);
	if (t.TrainId=="0")//这就查不了了。
	{
		emit newdebug("getSeatNum error!");
		return -1;
	}
	int type=t.carType;
	if (type==-1)//type还是空的。
	{
		type=aux_getType(t);
	}

	int seatnum=0;
	p=QString("select seatnum from cartype where cartype = %1").arg(type);
		query.prepare(p);//查询train里的条目数
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while (query.next())
		seatnum=query.value(0).toInt();
	return seatnum;

}
int MyDataBase::aux_getType(Train t)
{
	if (t.TrainId=="0")
	{
		emit newdebug("getType error!");
		return -1;
	}
	int type=0;
	QSqlQuery query(db);
	QString p=QString("select distinct cartype from train where trainid = '%1'").arg(t.TrainId);
	query.prepare(p);//查询train里的条目数
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while (query.next())
		type=query.value(0).toInt();//获取type
	return type;
}
int MyDataBase::aux_getItemNumber(QString table)
{
	/*获取条目数方法1*/
	//query.last();int num=query.at()+1;
	//query.first();query.previous();
	//emit newdebug(QString("%1").arg(num));
	//emit newdebug(QString("%1,%2").arg(query.numRowsAffected()).arg(query.size()));//这个没用，不支持。
	int itemNum=0;
	QSqlQuery query(db);
	QString p=QString("select count(*) from %1").arg(table);
	query.prepare(p);//查询train里的条目数
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while (query.next())
		itemNum=query.value(0).toInt();
	return itemNum;
}
int MyDataBase::aux_getOriginStationId(Ticket t)
{
	int stationId=0;
	QSqlQuery query(db);
	if (t.TrainId==""|| t.StartTime=="")
	{
		emit newdebug("getOriginStation error!");
		return -1;
	}
	//QString date=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
	QString p=QString(	"select distinct a.StationId"
						" from train as a"
						" where a.TrainId='%1' and a.origin='%2'").arg(t.TrainId).arg(t.Origin);
	//emit newdebug(p);
	query.prepare(p);//查询购买此车的人的票
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while (query.next())
		stationId=query.value(0).toInt();//获取stationid
	return stationId;
}
int MyDataBase::aux_getDestinationStationId(Ticket t)
{
	int stationId;
	QSqlQuery query(db);
	if (t.TrainId==""|| t.StartTime=="")
	{
		emit newdebug("getDestinationStation error!");
		return -1;
	}
	//QString date=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
	QString p=QString(	"select distinct a.StationId"
						" from train as a"
						" where a.TrainId='%1' and a.destination='%2'").arg(t.TrainId).arg(t.Destination);
	//emit newdebug(p);
	query.prepare(p);//查询购买此车的人的票
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while (query.next())
		stationId=query.value(0).toInt();//获取type
	return stationId;
}
QStringList MyDataBase::aux_getTrainTicketInfo(Train t)
{
	QStringList result;result.clear();
	QSqlQuery query(db);
	QString temp=QString("select distinct a.trainid"
						" from train as a,train as b"
						" where a.Starttime>'%1' and a.Starttime<'%2'"
						" and a.trainid=b.trainid and a.origin like '%3%' and b.destination like '%4%' "
						" order by a.starttime asc").arg(t.StartTime).arg(t.EndTime).arg(t.Origin).arg(t.Destination);
	//emit newdebug(temp);
	query.prepare(temp);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return result;
	}
	QSqlRecord rec=query.record();
	while(query.next())
	{
		result.append(query.value(0).toString());
	}
	return result;
}
void MyDataBase::aux_addTrain(const Train& t)
{
	QSqlQuery query(db);
	QString p=QString("INSERT INTO train "
					" (trainid,starttime,endtime,origin,destination,cartype,length,stationid)"
					" SELECT '%1', '%2', '%3','%4','%5',%6,%7,%8"
					" WHERE not exists (select trainid,starttime from train where trainid='%1' and starttime='%2')")
					.arg(t.TrainId).arg(t.StartTime).arg(t.EndTime)
					.arg(t.Origin).arg(t.Destination).arg(t.carType).arg(t.length).arg(t.StationId);
	query.prepare(p);
	if (!query.exec())
	{
		emit newdebug("add train error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
	}
}
double MyDataBase::aux_getCurrentMoney(UserClass u)
{
	double money=0;
	QSqlQuery query(db);
	QString content=QString("select money from account WHERE UserId='%1'").arg(u.UserId);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	QSqlRecord rec=query.record();
	if (!query.next())//没找到，xaccount
		return -1;
	query.previous();
	while(query.next())
		money=query.value(0).toDouble();
	return money;
}
double MyDataBase::aux_getPrice(Ticket t)
{
	QSqlQuery query(db);
	double price=0;
	if (t.UserId=="0" || t.StartTime=="0")
	{
		emit newdebug("aux_getprice error!");
		return -1;
	}
	QString content=QString("select price"
							" from ticket"
							" where userid='%1' and starttime='%2' and trainid='%3'")
							.arg(t.UserId).arg(t.StartTime).arg(t.TrainId);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		price=query.value(0).toDouble();
	return price;
}
int MyDataBase::addUserMoney(double money,QString userid)
{
	QSqlQuery query(db);
	QString content=QString("update account"
							" set money=money+%1"
							" where userid='%2'").arg(money).arg(userid);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return 0;
	}
	return 1;
}
QString MyDataBase::aux_getOriginTime(Train t)
{
	QSqlQuery query(db);
	QString starttime;
	if (t.TrainId=="0" || t.StartTime=="0")
	{
		emit newdebug("aux_getorigin error!");
		return -1;
	}
	QString content=QString("select max(starttime) "
							" from train as a"
							" where a.TrainId='%1' and a.starttime<='%2' and stationid=0")
							.arg(t.TrainId).arg(t.StartTime);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		starttime=query.value(0).toString();
	return starttime;
}
QString MyDataBase::aux_getEndTime(Train t)
{
	QSqlQuery query(db);
	QString endtime;
	if (t.TrainId=="0" || t.StartTime=="0")
	{
		emit newdebug("aux_getend error!");
		return -1;
	}
	QString content=QString("select min(endtime)"
							" from train as a"
							" where a.TrainId='%1' and a.StartTime>='%2' and stationid="
							" (select MAX(StationId) from Train where TrainId=a.TrainId)")
							.arg(t.TrainId).arg(t.StartTime);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		endtime=query.value(0).toString();
	return endtime;
}
QString MyDataBase::aux_getEndTime(Ticket t)
{
	QSqlQuery query(db);
	QString endtime;
	if (t.TrainId=="0" || t.StartTime=="0"|| t.Destination=="0")
	{
		emit newdebug("aux_getendtime ticket error!");
		return -1;
	}
	QString content=QString("select min(endtime)"
							" from train"
							" where TrainId='%1' and StartTime>='%2' and destination='%3'")
							.arg(t.TrainId).arg(t.StartTime).arg(t.Destination);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		endtime=query.value(0).toString();
	return endtime;
}
double MyDataBase::aux_getTrainPrice(const Train& t)
{
	QSqlQuery query(db);
	double price;
	int length;
	double pricePerKm;
	if (t.TrainId=="0" || t.StartTime=="0")
	{
		emit newdebug("aux_gettrainprice error!");
		return -1;
	}
	QString content=QString("select sum(distinct a.Length)"
							" from train as a"
							" where a.StationId>=%1 and a.StationId<=%2 and a.TrainId='%3'")
							.arg(t.originStationId).arg(t.endStationId).arg(t.TrainId);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		length=query.value(0).toInt();//计算总长

	content= QString("select PricePerKm from cartype where cartype= %1").arg(t.carType);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		pricePerKm=query.value(0).toDouble();//计算总长
	price=pricePerKm*length;
	//emit newdebug(QString("%1:%2").arg(pricePerKm).arg(length));
	return price;
}
QList<Train> MyDataBase::aux_getRegularTrain()
{
	QSqlQuery query(db);
	Train target;
	QList<Train> result;
	QString content=QString("select * from regulartrain");
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return result;
	}
	QSqlRecord rec=query.record();
	while(query.next())
	{
		for (int i=0;i<rec.count();i++)
		{
			if (i==0) target.TrainId=query.value(i).toString();
			if (i==1) target.StartTime=query.value(i).toString();
			if (i==2) target.EndTime=query.value(i).toString();
			if (i==3)  target.Origin=query.value(i).toString();
			if (i==4) target.Destination=query.value(i).toString();
			if (i==5) target.carType=query.value(i).toInt();
			if (i==6) target.length=query.value(i).toInt();
			if (i==7) target.StationId=query.value(i).toInt();
		}
		result.append(target);
	}
	return result;
}
bool MyDataBase::aux_IsExists(QString table,QString TrainId,QString Starttime,QString Origin)
{
	QSqlQuery query(db);
	QString content;
	if (table=="train")
	{
		content=QString("select * from %1 where trainid='%2' and starttime like '%3%' and origin='%4'")
		.arg(table).arg(TrainId).arg(Starttime).arg(Origin);
	}
	if (table=="regulartrain")
	{
		content=QString("select * from %1 where trainid='%2' and origin='%3'")
		.arg(table).arg(TrainId).arg(Origin);
	}
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		emit newdebug("isExists error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return false;
	}
	if (query.next())
		return true;
	else
	{
		return false;
	}
}
int MyDataBase::aux_updateTrainInfo(QString table,Train t)
{
	QSqlQuery query(db);
	QString starttime=QDateTime::fromString(t.StartTime,"yyyy/MM/dd hh:mm").toString("yyyy/MM/dd");
	QString content=QString("update %7"
							" set starttime='%3', endtime='%4',cartype=%5,"
							"  stationid=%6"
							" where trainid='%1' and starttime like '%2%' and origin='%8'").arg(t.TrainId).arg(starttime)
							.arg(t.StartTime).arg(t.EndTime).arg(t.carType).arg(t.StationId).arg(table).arg(t.Origin);
	emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		emit newdebug("update train error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return 0;
	}
	return 1;
}
bool MyDataBase::aux_IsExists(QString table,QString TrainId,QString Starttime)
{
	QSqlQuery query(db);
	QString content=QString("select * from %1 where trainid='%2' and starttime='%3'")
		.arg(table).arg(TrainId).arg(Starttime);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		emit newdebug("isExists error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return false;
	}
	if (query.next())
		return true;
	else
	{
		return false;
	}
}
int MyDataBase::aux_deleteTrain(QString table, Train t)
{
	QSqlQuery query(db);
	QString content=QString("delete from %1 where Trainid='%2' and starttime= '%3'").arg(table).arg(t.TrainId)
		.arg(t.StartTime);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		emit newdebug("delete train error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return 0;
	}
	return 1;
}
bool MyDataBase::aux_IsExists(QString table,QString UserId)
{
	QSqlQuery query(db);
	QString content;
	content=QString("select * from %1 where userid='%2'")
			.arg(table).arg(UserId);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		emit newdebug("isExists error!");
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return false;
	}
	if (query.next())
		return true;
	else
	{
		return false;
	}
}
QString MyDataBase::aux_getBuyer(Ticket t)
{
	QSqlQuery query(db);
	QString buyer;
	if (t.UserId=="0" || t.StartTime=="0")
	{
		emit newdebug("aux_getprice error!");
		return -1;
	}
	QString content=QString("select price"
							" from ticket"
							" where userid='%1' and starttime='%2' and trainid='%3'")
							.arg(t.UserId).arg(t.StartTime).arg(t.TrainId);
	//emit newdebug(content);
	query.prepare(content);
	if (!query.exec())
	{
		QSqlError lastError=query.lastError();
		emit newdebug(lastError.text());
		return -1;
	}
	while(query.next())
		buyer=query.value(0).toDouble();
	return buyer;
}