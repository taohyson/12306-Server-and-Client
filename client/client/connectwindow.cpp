#include "connectwindow.h"
#include "loginwindow.h"
#include <qmessagebox.h>
#include <qmovie.h>

ConnectWindow::ConnectWindow(Client *client)
	:client(client)
{
	ui.setupUi(this);
	this->setWindowTitle("Welcome!");
	QMovie *movie=new QMovie(":/Resources/train2.gif");
	ui.background->setMovie(movie);
	movie->start();
	connect(ui.bSubmit,SIGNAL(clicked()),this,SLOT(connectToServer()));
}

void ConnectWindow::connectToServer(){
	QString ip=ui.lIP->text();
	int port=ui.sPort->value();
	client->ConnectToServer(ip,port);
	if (client->waitForConnected(1000)){
		client->Write("Hello");
		QMessageBox msg;
		msg.setText(QStringLiteral("连接成功！"));
		msg.exec();
		this->close();
		LoginWindow *w=new LoginWindow(client);
		w->show();
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("连接失败！"));
		msg.exec();
	}
}

ConnectWindow::~ConnectWindow(){}