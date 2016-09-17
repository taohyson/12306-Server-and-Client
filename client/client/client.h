#ifndef TESTCLIENT_H
#define TESTCLIENT_H

#include <QTcpSocket>
#include <qthread.h>

class Client: public QTcpSocket{
	Q_OBJECT
public:
	Client(QObject *parent=0);
	~Client();

	void ConnectToServer(QString ip,int port);
	void Close();
	bool Write(QString s);
	void sleep(unsigned int msec);
	QString getCurrentMessage(){return currentMessage;}
private slots:
	void OnConnected();
	void OnReadyRead();
signals:
	void forceLogout();
private:
	QString currentMessage;
};

#endif 
