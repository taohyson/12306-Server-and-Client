#ifndef TESTCLIENT_H
#define TESTCLIENT_H

#include <QTcpSocket>
#include <qthread.h>

class TestClient : public QTcpSocket
{
	Q_OBJECT
public:
	TestClient(QObject *parent=0);
	~TestClient();

	void ConnectToServer(const char *ip,int _port);
	void Close();
	bool WriteData(const char *data);
	bool WriteData(const char *data,int len);
	bool Write(QString s);
	void sleep(unsigned int msec);
	QString getCurrentMessage(){return currentMessage;}

protected:
	void ParseData(QString _str);

private slots:
	void OnConnected();
	void OnReadyRead();

signals:
	void forceLogout();

private:
	enum{BUFFERSIZE_MAX=1024};
	QString currentMessage;
	
};

#endif // TESTCLIENT_H
