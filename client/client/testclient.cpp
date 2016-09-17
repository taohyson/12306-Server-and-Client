#include "testclient.h"
#include <QHostAddress>  
#include <QTime>
#include <qcoreapplication.h>
#include <iostream>
#include <stdio.h>
TestClient::TestClient(QObject *parent)
	: QTcpSocket(parent)
{
	connect(this,SIGNAL(readyRead()),this,SLOT(OnReadyRead()));
	connect(this,SIGNAL(connected()),this,SLOT(OnConnected()));
}

TestClient::~TestClient()
{

}

bool TestClient::Write(QString s){
	QByteArray a=s.toUtf8();
	write(a);
	return true;
}

void TestClient::ConnectToServer(const char *ip,int _port)
{
	connectToHost(QHostAddress(ip),_port);
}

void TestClient::Close()
{
	disconnectFromHost();
	close();
}

bool TestClient::WriteData(const char *data)
{
	return WriteData(data,strlen(data)+1);
}
bool TestClient::WriteData(const char *data,int len)
{
	if (data==NULL || len<=0)
		return false;
	if (writeData(data,len)<=0)
		return false;
	waitForBytesWritten(-1);
	std::cout<<"send data!"<<data<<std::endl;
	waitForBytesWritten(-1);
	return true;
}
void TestClient::ParseData(QString _str)
{
	//std::cout<<"receive data"<<data<<std::endl;
    char ss[1024];
    strcpy(ss,_str.toLatin1().data());
    printf("%s\n",ss);
}
void TestClient::OnReadyRead()
{
	printf("OnReadyRead is running!\n");
	QString str=readAll();
	currentMessage=str;
	if (currentMessage=="Disconnected") emit forceLogout();
	//emit newMessage();

	//if (len<=0)
	//	return ;

	ParseData(str);
}
void TestClient::OnConnected()
{
	printf( "connected: %d !\n", socketDescriptor() ); 
}
void TestClient::sleep(unsigned int msec)
{
	QTime dieTime=QTime::currentTime().addMSecs(msec);
	while (QTime::currentTime()<dieTime)
		QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}
