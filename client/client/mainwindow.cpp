#include "mainwindow.h"
#include "qmessagebox.h"
#include "qtablewidget.h"
#include "qdialog.h"
#include "ui_pay.h"
#include "ui_traindetail.h"
#include "user.h"
#include "qwidget.h"

MainWindow::MainWindow(LoginWindow *parent, Client *client, QString userinfo):parent(parent),client(client){
	ui.setupUi(this);
	this->setWindowTitle(QStringLiteral("12306++铁路票务系统"));
	ui.dDate->setDate(QDate::currentDate());
	setupPersonalInfo(userinfo);
	setupBuyButton();
	setupTicketInfo();
	ui.bEditCancel->hide();
	ui.bEditComplete->hide();
	ui.lEmpty->hide();
	connect(ui.bEdit,SIGNAL(clicked()),u,SLOT(editPersonalInfoEnabled()));
	connect(ui.bEditComplete,SIGNAL(clicked()),u,SLOT(updatePersonalInfo()));
	connect(ui.bEditCancel,SIGNAL(clicked()),u,SLOT(showPersonalInfo()));
	connect(ui.bEditCancel,SIGNAL(clicked()),u,SLOT(editPersonalInfoDisabled()));
	connect(ui.bRefresh,SIGNAL(clicked()),this,SLOT(setupTicketInfo()));
	connect(client,SIGNAL(forceLogout()),this,SLOT(onForceLogout()));
	connect(ui.bLogout,SIGNAL(clicked()),this,SLOT(logout()));
	connect(ui.bExit,SIGNAL(clicked()),this,SLOT(exitProgram()));
	connect(ui.bSearch,SIGNAL(clicked()),this,SLOT(searchTrain()));
	connect(ui.bPay,SIGNAL(clicked()),this,SLOT(triggerPay()));
	connect(ui.bBuy,SIGNAL(clicked()),this,SLOT(triggerBuy()));
	connect(ui.bBuyStudent,SIGNAL(clicked()),this,SLOT(triggerBuyStudent()));
	connect(ui.bBuyOther,SIGNAL(clicked()),this,SLOT(triggerBuyOther()));
	connect(ui.ticketTable,SIGNAL(cellDoubleClicked(int, int)),u,SLOT(returnTicket(int, int)));
	connect(ui.bReturn,SIGNAL(clicked()),this,SLOT(triggerReturnTicket()));
	connect(ui.trainTable,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(askDetail(int,int)));
}

MainWindow::~MainWindow(){}

void MainWindow::setupBuyButton(){
	if (u->tType==Student) {
		ui.bBuy->setText(QStringLiteral("购买成人票"));
		ui.bBuyStudent->show();
		ui.bBuyOther->setGeometry(590,460,121,41);
	}
	else {
		ui.bBuy->setText(QStringLiteral("购买"));
		ui.bBuyStudent->hide();
		ui.bBuyOther->setGeometry(720,460,121,41);
	}
}

void MainWindow::triggerPay(){
	payWindow=new QDialog(this);
	uiPay.setupUi(payWindow);
	payWindow->show();
	connect(uiPay.okButton,SIGNAL(clicked()),this,SLOT(payCheck()));
	connect(this,SIGNAL(pay(int)),u,SLOT(pay(int)));
}

void MainWindow::payCheck(){
	QString temp=uiPay.lineEdit->text();
	bool ok;
	int x=temp.toInt(&ok,10);
	if (ok) emit pay(x);
	else {
		QMessageBox msg;
		msg.setText(QStringLiteral("输入格式错误！"));
		msg.setWindowTitle(QStringLiteral("Error"));
		msg.exec();
	}
}

void MainWindow::searchTrain(){
	if (ui.lStart->text()=="" || ui.lDes->text()=="") {
		QMessageBox msg;
		msg.setText(QStringLiteral("请输入出发站与到达站！"));
		msg.exec();
		return;
	}
	for (int i=0;i<TrainList.size();i++)
		delete TrainList[i];
	TrainList.clear();
	QString type=ui.cType->currentText();
	if (type==QStringLiteral("全部")) type="0";
	QString m=ui.lStart->text()+"-"+ui.lDes->text()+"-"+ui.dDate->text()+" "+ui.time1->text()+"-"+ui.dDate->text()+" "+ui.time2->text()+"-"+type;
	client->Write("searchtrain");
	client->sleep(20);
	client->Write(m);
	ui.trainTable->clear();
	ui.trainTable->setColumnCount(9);
	ui.trainTable->setRowCount(0);
	ui.trainTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QStringLiteral("列车编号")));
	ui.trainTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QStringLiteral("始发站")));
	ui.trainTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QStringLiteral("始发时间")));
	ui.trainTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QStringLiteral("到达站")));
	ui.trainTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QStringLiteral("到达时间")));
	ui.trainTable->setHorizontalHeaderItem(5,new QTableWidgetItem(QStringLiteral("铺位类型")));
	ui.trainTable->setHorizontalHeaderItem(6,new QTableWidgetItem(QStringLiteral("列车类型")));
	ui.trainTable->setHorizontalHeaderItem(7,new QTableWidgetItem(QStringLiteral("票价")));
	ui.trainTable->setHorizontalHeaderItem(8,new QTableWidgetItem(QStringLiteral("余票")));
	ui.trainTable->setColumnWidth(0,70);
	ui.trainTable->setColumnWidth(2,165);
	ui.trainTable->setColumnWidth(4,165);
	ui.trainTable->setColumnWidth(5,80);
	ui.trainTable->setColumnWidth(6,80);
	ui.trainTable->setColumnWidth(7,70);
	ui.trainTable->horizontalHeader()->show();
	client->waitForReadyRead(-1);
	m=client->getCurrentMessage();
	QStringList mList=m.split(";");
	int cnt=mList[0].toInt();
	if (cnt==0) ui.lEmpty->show(); else ui.lEmpty->hide();
	for (int i=0;i<cnt;i++){
		QString mc=mList[i+1].mid(1);
		QStringList md=mc.split("-");
		Train* temp=new Train(this,md[0],md[1],md[2],md[3],md[4],md[5].toInt(),md[6].toInt(),md[7].toInt(),md[8].toInt(),md[9].toInt());
		TrainList.push_back(temp);
		TrainList[i]->show(i);
	}
}

void MainWindow::askDetail(int row, int column){
	Train *curr=TrainList[row];
	client->Write("midstation-"+curr->getTrainName()+"-"+curr->getSTime());
	client->waitForReadyRead(-1);
	QWidget *detailWindow=new QWidget();
	Ui::trainDetail ui;
	ui.setupUi(detailWindow);
	detailWindow->show();
	QString m=client->getCurrentMessage();
	QStringList ml=m.split(";");
	ui.label->setText(curr->getTrainName()+QStringLiteral("次列车运行时刻表"));
	ui.detailTable->setColumnCount(2);
	ui.detailTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QStringLiteral("途径站点")));
	ui.detailTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QStringLiteral("到达时间")));
	ui.detailTable->setColumnWidth(0,100);
	int cnt=ml[0].toInt();
	for (int i=1;i<=cnt;i++){
		QStringList t=ml[i].mid(1).split("-");
		ui.detailTable->setRowCount(i);
		ui.detailTable->setItem(i-1,0,new QTableWidgetItem(t[1]));
		ui.detailTable->setItem(i-1,1,new QTableWidgetItem(t[3]));
	}
	QStringList t=ml[cnt].mid(1).split("-");
	ui.detailTable->setRowCount(cnt+1);
	ui.detailTable->setItem(cnt,0,new QTableWidgetItem(t[2]));
	ui.detailTable->setItem(cnt,1,new QTableWidgetItem(t[4]));
}

void MainWindow::setupPersonalInfo(QString userinfo){
	QStringList us=userinfo.split("-");
	if (us[7]=="Adult") u=new User(client,this,us[0],us[1],us[2],(us[3]=="1"?Male:Female),us[4],us[5],us[6],Adult,us[9].toInt());
	else {
		QStringList u2=us[8].split(",");
		if (u2.size()==2)
			u=new User(client,this,us[0],us[1],us[2],(us[3]=="1"?Male:Female),us[4],us[5],us[6],Student,us[9].toInt(),u2[0],u2[1]);
		else 
			u=new User(client,this,us[0],us[1],us[2],(us[3]=="1"?Male:Female),us[4],us[5],us[6],Student,us[9].toInt(),u2[0],"");
	}
	u->showPersonalInfo();
}

void MainWindow::setupTicketInfo(){
	for (int i=0;i<u->ticketList.size();i++){
		delete u->ticketList[i];
	}
	u->ticketList.clear();

	ui.ticketTable->clear();
	ui.ticketTable->setRowCount(0);
	ui.ticketTable->setColumnCount(10);
	ui.ticketTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QStringLiteral("列车编号")));
	ui.ticketTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QStringLiteral("始发站")));
	ui.ticketTable->setHorizontalHeaderItem(2,new QTableWidgetItem(QStringLiteral("始发时间")));
	ui.ticketTable->setHorizontalHeaderItem(3,new QTableWidgetItem(QStringLiteral("到达站")));
	ui.ticketTable->setHorizontalHeaderItem(4,new QTableWidgetItem(QStringLiteral("到达时间")));
	ui.ticketTable->setHorizontalHeaderItem(5,new QTableWidgetItem(QStringLiteral("铺位类型")));
	ui.ticketTable->setHorizontalHeaderItem(6,new QTableWidgetItem(QStringLiteral("列车类型")));
	ui.ticketTable->setHorizontalHeaderItem(7,new QTableWidgetItem(QStringLiteral("座位")));
	ui.ticketTable->setHorizontalHeaderItem(8,new QTableWidgetItem(QStringLiteral("票价")));
	ui.ticketTable->setHorizontalHeaderItem(9,new QTableWidgetItem(QStringLiteral("旅客类型")));
	ui.ticketTable->horizontalHeader()->show();
	ui.ticketTable->verticalHeader()->show();
	ui.ticketTable->setColumnWidth(0,70);
	ui.ticketTable->setColumnWidth(2,165);
	ui.ticketTable->setColumnWidth(4,165);
	ui.ticketTable->setColumnWidth(5,70);
	ui.ticketTable->setColumnWidth(6,70);
	ui.ticketTable->setColumnWidth(7,70);
	ui.ticketTable->setColumnWidth(8,70);
	ui.ticketTable->setColumnWidth(9,70);

	client->Write("ticketbought-"+u->getUsername());
	client->waitForReadyRead(-1);
	QString q=client->getCurrentMessage();
	QStringList ql=q.split(";");
	int cnt=ql[0].toInt();
	for (int i=0;i<cnt;i++){
		QString q=ql[i+1].mid(1);
		QStringList ql=q.split("-");
		Ticket *t=new Ticket(this,ql[0],ql[1],ql[2],ql[3],ql[4],ql[5].toInt()==0?Stand:Sleep,ql[6].toInt(),
			ql[7].toInt(),ql[8].toInt()==0?Adult:Student);
		u->addTicket(t);
		u->showTicket(i);
	}
}

void MainWindow::logout(){
	client->Write("logout-"+u->getUsername());
	this->close();
	parent->show();
	parent->ui.lPassword->clear();
}

void MainWindow::onForceLogout(){
	client->Write("logout-"+u->getUsername());
	this->close();
	parent->show();
	parent->ui.lPassword->clear();
	QMessageBox msg;
	msg.setText(QStringLiteral("您已被管理员踢下线…"));
	QPushButton *btn=msg.addButton(QStringLiteral("我好惨"),QMessageBox::ButtonRole::AcceptRole);
	msg.exec();
}

void MainWindow::triggerReturnTicket(){
	int row=ui.ticketTable->currentRow();
	int column=ui.ticketTable->currentColumn();
	if (row<0) {
		QMessageBox msg;
		msg.setText(QStringLiteral("未选中任何列车"));
		msg.exec();
	} else u->returnTicket(row,column);
}

void MainWindow::triggerBuy(){
	int row=ui.trainTable->currentRow();
	if (row>=0){
		u->buy(row);
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("未选中任何列车！"));
		msg.exec();
	}
}

void MainWindow::triggerBuyStudent(){
	int row=ui.trainTable->currentRow();
	if (row>=0){
		u->buyStudent(row);
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("未选中任何列车！"));
		msg.exec();
	}
}

void MainWindow::triggerBuyOther(){
	int row=ui.trainTable->currentRow();
	if (row>=0){
		u->buyOther(row);
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("未选中任何列车！"));
		msg.exec();
	}
}

void MainWindow::exitProgram(){
	QMessageBox msgBox;
	msgBox.setText(QStringLiteral("您确定要退出吗？"));
	QPushButton *bYes=msgBox.addButton(QStringLiteral("是"),QMessageBox::ButtonRole::NoRole);
	QPushButton *bNo=msgBox.addButton(QStringLiteral("否"),QMessageBox::ButtonRole::NoRole);
	connect(bYes,SIGNAL(clicked()),&msgBox,SLOT(close()));
	connect(bYes,SIGNAL(clicked()),this,SLOT(close()));
	connect(bNo,SIGNAL(clicked()),&msgBox,SLOT(close()));
	msgBox.exec();
}