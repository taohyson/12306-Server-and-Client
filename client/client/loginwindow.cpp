#include "loginwindow.h"
#include "client.h"
#include "qmessagebox.h"
#include "mainwindow.h"
#include "adminwindow.h"
#include "qmovie.h"

LoginWindow::LoginWindow(Client *client):client(client)
{
	w1=NULL;w2=NULL;
	ui.setupUi(this);
	QMovie *movie=new QMovie(":/Resources/train3.gif");
	ui.background->setMovie(movie);
	movie->start();
	this->setWindowTitle(QStringLiteral("12306++铁路票务系统"));
	RegisterWindow *r=new RegisterWindow(this,client);
	connect(ui.bRegister,SIGNAL(clicked()),r,SLOT(show()));
	connect(ui.bRegister,SIGNAL(clicked()),this,SLOT(hide()));
	connect(ui.bLogin,SIGNAL(clicked()),this,SLOT(login()));
}

void LoginWindow::login(){
	QString username=ui.lUsername->text();
	QString password=ui.lPassword->text();
	client->Write("login");
	client->sleep(20);
	client->Write(username+"-"+password);
	client->waitForReadyRead(-1);
	//connect(client,SIGNAL(newMessage()),this,SLOT(loginDeliver()));
	QString s=client->getCurrentMessage();
	QStringList slist0=s.split(";");
	QStringList slist=slist0[0].split("-");
	if (slist[0]=="success"){
		/*client->waitForReadyRead(-1);
		QString info=client->getCurrentMessage();*/
		if (slist[1]=="User"){
			if (w1!=NULL) {delete w1; w1=NULL;}
			if (w2!=NULL) {delete w2; w2=NULL;}
			w1=new MainWindow(this,client,slist0[1]);
			this->close();
			w1->show();
		} else if (slist[1]=="Administrator"){
			if (w1!=NULL) {delete w1; w1=NULL;}
			if (w2!=NULL) {delete w2; w2=NULL;}
			w2=new AdminWindow(this,client,slist0[1]);
			this->close();
			w2->show();
		}
	} else if (slist[0]=="xuser"){
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("用户名不存在！"));
		msgBox.setWindowTitle(QStringLiteral("Error"));
		msgBox.exec();
	} else if (slist[0]=="xpasswd"){
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("密码错误！"));
		msgBox.setWindowTitle(QStringLiteral("Error"));
		msgBox.exec();
	} else {
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("服务器错误！"));
		msgBox.setWindowTitle(QStringLiteral("Error"));
		msgBox.exec();
	}
}

LoginWindow::~LoginWindow(){

}

