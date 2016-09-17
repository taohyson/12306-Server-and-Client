#include "mytcpserver.h"
#include "train.h"
#include <QTcpsocket>
#include <QTextCodec>
#include <QByteArray>
#include <Qqueue>
#include <QString>
#include <QStringList>
QQueue<QTcpSocket*> q;
MyTcpServer::MyTcpServer(QObject *parent)
	: QTcpServer(parent)
{
	resetStatus();
	connect(this,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
}
void MyTcpServer::onNewConnection()
{
	QTcpSocket *client=nextPendingConnection();
	emit newdebug(QString("accept connection from %1").arg(client->socketDescriptor()));
	//client->write("LinkSuccess");
	connect(client,SIGNAL(readyRead()),this,SLOT(readClient()));
	connect(client,SIGNAL(disconnected()),this,SLOT(clientDisconnected()));
	_clients.append(client);

}
void MyTcpServer::Write(QString str)
{
	QByteArray a=str.toUtf8();
	if (q.isEmpty())
	{
		emit newdebug("no descriptor to send info!");
		return ;
	}
	//int d=q.takeFirst();
	//for (int i=0;i<_clients.count();i++)
	//{
	//	if (_clients.at(i)->socketDescriptor()==d)
	//	{
	//		QByteArray a=str.toUtf8();
	//		emit newdebug(QString("send %1 to %2").arg(str).arg(_clients.at(i)->socketDescriptor()));
	//		_clients.at(i)->write(a);
	//		return ;
	//	}
	//}
	QTcpSocket *target=q.takeFirst();
	if (!_clients.contains(target))
	{
		emit newdebug("user missing!");
		return;
	}
	target->write(a);
	emit newdebug(QString("send %1 to %2").arg(str).arg(target->socketDescriptor()));
}
void MyTcpServer::Write(QString str,int _d)
{
	//emit newdebug("Write2 running");
	for (int i=0;i<_clients.count();i++)
	{
		if (_clients.at(i)->socketDescriptor()==_d)
		{
			QByteArray a=str.toUtf8();
			emit newdebug(QString("send %1 to %2").arg(str).arg(_clients.at(i)->socketDescriptor()));
			_clients.at(i)->write(a);
			return ;
		}
	}
	emit newdebug("descriptor not found!");
}
void MyTcpServer::readClient()
{
	QTcpSocket *target=(QTcpSocket *)sender();
	QByteArray temp=target->readAll();
	QTextCodec *tc = QTextCodec::codecForName("UTF-8");
	QString str = tc->toUnicode(temp);

	emit newdebug(QString("%1: %2").arg((int)target->socketDescriptor()).arg(str));//收到信息
	
	if (str.contains("login")) IsLogin=true;
	if (str.contains("register")) IsRegister=true;
	if (str.contains("ticketbought")) IsTicketBought=true;
	if (str.contains("searchtrain")) IsSearchTrain=true;
	if (str.contains("returnticket")) IsReturn=true;
	if (str.contains("midstation")) IsMidQuery=true;
	if (str.contains("pay")) IsPay=true;
	if (str.contains("updateinfo")) IsUpdateInfo=true;
	if (str.contains("buyticket")) IsBuyTicket=true;
	if (str.contains("updateadmininfo")) IsUpdateAdmininfo=true;
	if (str.contains("updatetraininfo")) IsUpdateTrainInfo=true;
	if (str.contains("addtrain")) IsAddTrainInfo=true;
	if (str.contains("logout")) IsUserLogOut=true;
	if (str.contains("seatbought")) IsSeatBought=true;
	if (str.contains("deletetrain")) IsDeleteTrain=true;
	if (str.contains("-")) 
	{
		currentSocket=target;
		if (IsLogin)//login
		{
			emit newdebug("login");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=2)
			{
				Write("server not understand");
				resetStatus();
				return ;
			}
			QString name=parts[0].trimmed();
			QString password=parts[1].trimmed();
			emit newUser(name,password);
			resetStatus();
			return ;
		}
		if(IsRegister)//注册
		{
			emit newdebug("register");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=9)
			{
				Write("server not understand");
				resetStatus();
				return ;
			}
			QString UserId=parts[0].trimmed();
			QString PassWord=parts[1].trimmed();
			QString name=parts[2].trimmed();
			QString sex=parts[3].trimmed();
			QString nation=parts[4].trimmed();
			QString credencial=parts[5].trimmed();
			QString contact=parts[6].trimmed();
			QString identity=parts[7].trimmed();
			QString addition=parts[8].trimmed();
			emit newRegister(UserId,PassWord,name,sex,nation,credencial,contact,identity,addition);
			resetStatus();
			return;
		}
		if (IsTicketBought)//查看买票信息。
		{
			emit newdebug("ticketbought");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=2)
			{
				Write("server not understand");
				resetStatus();
				return ;
			}
			QString UserId=parts[1].trimmed();
			emit ticketQuery(UserId);
			resetStatus();
			return;
		}
		if (IsSearchTrain)//查询车次。
		{
			emit newdebug("querycar");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=5 && length!=4)
			{
				Write("server not understand!");
				resetStatus();
				return ;
			}
			if (length==5)
			{
				Train temp;
				temp.Origin=parts[0].trimmed();
				temp.Destination=parts[1].trimmed();
				temp.StartTime=parts[2].trimmed();
				temp.EndTime=parts[3].trimmed();
				temp.TrainType=parts[4].trimmed();
				emit trainQuery(temp);
			}
			if (length==4)
			{
				Train temp;
				temp.Origin=parts[0].trimmed();
				temp.Destination=parts[1].trimmed();
				temp.StartTime=parts[2].trimmed();
				temp.EndTime=parts[3].trimmed();
				temp.TrainType="0";
				emit trainQuery(temp);
			}
			resetStatus();
			return ;
		}
		if (IsReturn)//退票
		{
			emit newdebug("returnticket");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=3)
			{
				Write("server not understand");
				resetStatus();
				return ;
			}
			Ticket temp;
			temp.UserId=parts[0].trimmed();
			temp.TrainId=parts[1].trimmed();
			temp.StartTime=parts[2].trimmed();
			emit returnTicket(temp);
			resetStatus();
			return ;
		}
		if (IsMidQuery)//中间站查询
		{
			emit newdebug("midstationquery");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=3)
			{
				emit newdebug("not understand midquery");
				Write("server not understand");
				resetStatus();
				return ;
			}
			Train t;
			t.TrainId=parts[1].trimmed();
			t.StartTime=parts[2].trimmed();
			emit MidStationQuery(t);
			resetStatus();
			return ;
		}
		if (IsPay)//充值
		{
			emit newdebug("pay");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=3)
			{
				emit newdebug("not understand pay");
				Write("server not understand");
				resetStatus();
				return ;
			}
			UserClass u;
			u.UserId=parts[1].trimmed();
			u.addmoney=parts[2].trimmed().toDouble();
			//emit newdebug(QString("%1:%2").arg(u.UserId).arg(u.addmoney));
			emit userAddMoney(u);
			resetStatus();
			return ;
		}
		if (IsUpdateInfo)//updateInfo
		{
			emit newdebug("updateuserinfo");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=9)
			{
				emit newdebug("not understand updateuserinfo");
				Write("server not understand");
				resetStatus();
				return ;
			}
			UserClass u;
			u.UserId=parts[0].trimmed();
			u.password=parts[1].trimmed();
			u.name=parts[2].trimmed();
			if (parts[3].trimmed().contains("Ma"))
				u.sex=1;
			if (parts[3].trimmed().contains("Fe"))
				u.sex=2;
			u.nation=parts[4].trimmed();
			u.credentials=parts[5].trimmed();
			u.contact=parts[6].trimmed();
			u.identity=parts[7].trimmed();
			u.addtion=parts[8].trimmed();
			emit updateUserInfo(u);
			resetStatus();
			return ;
		}
		if (IsBuyTicket)//buyticket
		{
			emit newdebug("buy ticket");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=9 && length!=8)
			{
				emit newdebug("not understand buy ticket");
				Write("server not understand");
				resetStatus();
				return ;
			}
			if (length==9)
			{
				Ticket t;
				t.UserId=parts[0].trimmed();
				t.TrainId=parts[1].trimmed();
				t.StartTime=parts[2].trimmed();
				t.Origin=parts[3].trimmed();
				t.Destination=parts[4].trimmed();
				t.Seat=parts[5].trimmed().toInt();
				t.Tickettype=parts[6].trimmed().toInt();
				//emit newdebug(QString("%1").arg(t.Tickettype));
				t.price=parts[7].trimmed().toDouble();
				t.Buyer=parts[8].trimmed();
				emit buyTicket(t);
			}
			if (length==8)
			{
				Ticket t;
				t.UserId=parts[0].trimmed();
				t.TrainId=parts[1].trimmed();
				t.StartTime=parts[2].trimmed();
				t.Origin=parts[3].trimmed();
				t.Destination=parts[4].trimmed();
				t.Seat=parts[5].trimmed().toInt();
				t.Tickettype=parts[6].trimmed().toInt();
				//emit newdebug(QString("%1").arg(t.Tickettype));
				t.price=parts[7].trimmed().toDouble();
				t.Buyer=t.UserId;
				emit buyTicket(t);
			}
			resetStatus();
			return ;
		}
		if(IsUpdateAdmininfo)
		{
			emit newdebug("update admininfo");
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=5)
			{
				emit newdebug("not understand update admininfo");
				Write("server not understand");
				resetStatus();
				return ;
			}
			admin a;
			a.userid=parts[0].trimmed();
			a.password=parts[1].trimmed();
			a.name=parts[2].trimmed();
			a.contact=parts[3].trimmed();
			a.position=parts[4].trimmed();

			emit updateAdminInfo(a);
			resetStatus();
			return ;
		}
		if (IsAddTrainInfo)//添加列车
		{
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=11)
			{
				emit newdebug("not understand add train");
				Write("server not understand");
				resetStatus();
				return ;
			}
			Train traintarget;
			traintarget.TrainId=parts[1].trimmed();
			traintarget.StartTime=parts[2].trimmed();
			traintarget.EndTime=parts[3].trimmed();
			traintarget.Origin=parts[4].trimmed();
			traintarget.Destination=parts[5].trimmed();
			traintarget.carType=parts[6].trimmed().toInt();
			traintarget.length=parts[7].trimmed().toInt();
			traintarget.StationId=parts[8].trimmed().toInt();
			traintarget.addType=parts[9].trimmed().toInt();
			traintarget.addDays=parts[10].trimmed().toInt();
			emit addTrainInfo(traintarget);
			resetStatus();
			return ;
		}
		if (IsUpdateTrainInfo)//修改列车
		{
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=10)
			{
				emit newdebug("not understand update train");
				Write("server not understand");
				resetStatus();
				return ;
			}
			emit newdebug("update train info");
			Train t;
			t.TrainId=parts[1].trimmed();
			t.StartTime=parts[2].trimmed();
			t.EndTime=parts[3].trimmed();
			t.Origin=parts[4].trimmed();
			t.Destination=parts[5].trimmed();
			t.carType=parts[6].trimmed().toInt();
			//t.length=parts[7].trimmed().toInt();
			t.StationId=parts[7].trimmed().toInt();
			t.addType=parts[8].trimmed().toInt();
			t.addDays=parts[9].trimmed().toInt();
			emit updateTrainInfo(t);
			resetStatus();
			return ;
		}
		if(IsUserLogOut)//用户登出
		{
			QString UserId=str.split("-")[1].trimmed();
			//q.append(target);
			emit userLogOut(UserId);
			resetStatus();
			return;
		}
		if(IsDeleteTrain)//删除列车
		{
			QStringList parts=str.split("-");
			int length=parts.length();
			q.append(target);
			if (length!=5)
			{
				emit newdebug("not understand update train");
				Write("server not understand");
				resetStatus();
				return ;
			}
			Train t;
			t.TrainId=parts[1].trimmed();
			t.StartTime=parts[2].trimmed();
			t.addType=parts[3].trimmed().toInt();
			t.addDays=parts[4].trimmed().toInt();
			emit deleteTrain(t);
			resetStatus();
			return ;
		}
	}
}
void MyTcpServer::clientDisconnected()
{
	QTcpSocket *target=(QTcpSocket *)sender();
	emit newdebug(QString("a client disconnected!"));
	_clients.removeOne(target);
	emit update();
}
MyTcpServer::~MyTcpServer()
{
	qDeleteAll(_clients);
	_clients.clear();
}
void MyTcpServer::resetStatus()
{
	IsLogin=false;
	IsRegister=false;
	IsTicketBought=false;
	IsMidQuery=false;
	IsSearchTrain=false;
	IsBuyTicket=false;
	IsReturn=false;
	IsPay=false;
	IsUpdateInfo=false;
	IsUpdateAdmininfo=false;
	IsDeleteTrain=false;
	IsUpdateTrainInfo=false;
	IsAddTrainInfo=false;
	IsUserLogOut=false;
	IsSeatBought=false;
}
