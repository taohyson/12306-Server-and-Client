#include "client.h"
#include <QHostAddress>  
#include <QTime>
#include <qcoreapplication.h>

Client::Client(QObject *parent):QTcpSocket(parent){
	connect(this,SIGNAL(readyRead()),this,SLOT(OnReadyRead()));
	connect(this,SIGNAL(connected()),this,SLOT(OnConnected()));
}

Client::~Client(){
	Close();
}

bool Client::Write(QString s){
	QByteArray a=s.toUtf8();
	qDebug()<<s;
	write(a);
	return true;
}

void Client::ConnectToServer(QString ip,int port){
	connectToHost(QHostAddress(ip),port);
}

void Client::Close(){
	disconnectFromHost();
	close();
}

void Client::OnReadyRead()
{
	QString str=readAll();
	currentMessage=str;
	if (currentMessage=="Disconnected") emit forceLogout();
	qDebug()<<str;
}

void Client::OnConnected(){
	qDebug()<<"connected:"<<socketDescriptor();
}

void Client::sleep(unsigned int msec){
	QTime dieTime=QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime()<dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
