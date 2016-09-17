#include "adminwindow.h"
#include "qmessagebox.h"
#include "ui_deletetrain.h"
#include "ui_traindetail.h"

AdminWindow::AdminWindow(LoginWindow *parent, Client *client, QString userinfo)
	:parent(parent),client(client)
{
	ui.setupUi(this);
	this->setWindowTitle(QStringLiteral("12306++铁路票务系统"));
	setupPersonalInfo(userinfo);
	addTrainW=NULL;
	editTrainW=NULL;
	ui.dDate->setDate(QDate::currentDate());
	connect(ui.bNewTrain,SIGNAL(clicked()),this,SLOT(showAddWindow()));
	connect(ui.bExit,SIGNAL(clicked()),this,SLOT(exitProgram()));
	connect(ui.bLogout,SIGNAL(clicked()),this,SLOT(logout()));
	connect(client,SIGNAL(forceLogout()),this,SLOT(onForceLogout()));
	connect(ui.bEdit,SIGNAL(clicked()),u,SLOT(editPersonalInfoEnabled()));
	connect(ui.bEditCancel,SIGNAL(clicked()),u,SLOT(editPersonalInfoDisabled()));
	connect(ui.bEditCancel,SIGNAL(clicked()),u,SLOT(showPersonalInfo()));
	connect(ui.bEditComplete,SIGNAL(clicked()),u,SLOT(updatePersonalInfo()));
	connect(ui.bSearch,SIGNAL(clicked()),this,SLOT(searchTrain()));
	connect(ui.bDeleteTrain,SIGNAL(clicked()),this,SLOT(deleteTrain()));
	connect(ui.bEditTrain,SIGNAL(clicked()),this,SLOT(editTrain()));
	connect(ui.trainTable,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(askDetail(int,int)));
}

void AdminWindow::onForceLogout(){
	client->Write("logout-"+u->getUsername());
	this->close();
	parent->show();
	parent->ui.lPassword->clear();
	QMessageBox msg;
	msg.setText(QStringLiteral("您已被管理员踢下线…"));
	QPushButton *btn=msg.addButton(QStringLiteral("我好惨"),QMessageBox::ButtonRole::AcceptRole);
	msg.exec();
}

void AdminWindow::askDetail(int row, int column){
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

void AdminWindow::editTrain(){
	int x=ui.trainTable->currentRow();
	if (x==-1){
		QMessageBox msg;
		msg.setText(QStringLiteral("未选中任何列车！"));
		msg.exec();
	/*} else if (!checkTrainEditable(x)){
		QMessageBox msg;
		msg.setText(QStringLiteral("车票已卖出，该列车无法修改！"));
		msg.exec();*/
	} else if (!checkTime(x)){
		QMessageBox msg;
		msg.setText(QStringLiteral("列车已经驶离，无法修改！"));
		msg.exec();
	} else {
		if (editTrainW!=NULL) delete editTrainW;
		editTrainW=new EditTrainWindow(this,client);
		editTrainW->show();
	}
}

void AdminWindow::deleteTrain(){
	int x=ui.trainTable->currentRow();
	if (x==-1){
		QMessageBox msg;
		msg.setText(QStringLiteral("未选中任何列车！"));
		msg.exec();
	} else if (!checkTrainEditable(x)){
		QMessageBox msg;
		msg.setText(QStringLiteral("车票已卖出，该列车无法删除！"));
		msg.exec();
	} else if (!checkTime(x)){
		QMessageBox msg;
		msg.setText(QStringLiteral("列车已经驶离，无法修改！"));
		msg.exec();
	} else {
		deleteW=new QWidget();
		ui2.setupUi(deleteW);
		QString temp=QStringLiteral("您是否确认删除于");
		temp+=TrainList[x]->getSTime()+QStringLiteral("始发的");
		temp+=TrainList[x]->getTrainName()+QStringLiteral("次列车?");
		ui2.msg->setText(temp);
		connect(ui2.bCancel,SIGNAL(clicked()),deleteW,SLOT(close()));
		connect(ui2.bDeletePer,SIGNAL(clicked()),this,SLOT(sendDeleteMsgPer()));
		connect(ui2.bDeleteTem,SIGNAL(clicked()),this,SLOT(sendDeleteMsgTem()));
		deleteW->show();
	}
}

bool AdminWindow::checkTime(int x){
	QDateTime temp=QDateTime::fromString(TrainList[x]->getSTime(),"yyyy/MM/dd hh:mm");
	int sec=-temp.secsTo(QDateTime::currentDateTime());
	if (sec<0) return false; else return true;
}

void AdminWindow::sendDeleteMsgPer(){
	int x=ui.trainTable->currentRow();
	QString temp="midstation-";
	int flag=0; //0正常，1删除了临时列车，2失败
	temp+=TrainList[x]->getTrainName()+"-";
	temp+=TrainList[x]->getSTime();
	client->Write(temp);
	client->waitForReadyRead(-1);
	QString m=client->getCurrentMessage();
	QStringList mlist=m.split(";");
	int cnt=mlist[0].toInt();
	for (int i=1;i<=cnt;i++){
		QString t="deletetrain-";
		QStringList ulist=mlist[i].mid(1).split("-");
		t+=TrainList[x]->getTrainName()+"-";
		t+=ulist[3]+"-0-1";
		qDebug()<<t;
		client->Write(t);
		client->waitForReadyRead();
		QString m=client->getCurrentMessage();
		if (m!="success"){
			if (m=="success but xpermanent") flag=1; else flag=2;
		}
	}
	if (flag==0){
		QMessageBox msg;
		msg.setText(QStringLiteral("删除成功！"));
		msg.exec();
		deleteW->close();
		delete deleteW;
		searchTrain();
	} else if (flag==1){
		QMessageBox msg;
		msg.setText(QStringLiteral("删除成功！"));
		msg.setInformativeText(QStringLiteral("您使用永久删除功能删除了一列临时列车orz…然而机智我们帮你完成了正确的操作~"));
		QPushButton *btn1=msg.addButton(QStringLiteral("太机智了"),QMessageBox::ButtonRole::AcceptRole);
		msg.exec();
		deleteW->close();
		delete deleteW;
		searchTrain();
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("服务器错误！"));
		msg.exec();
	}
}

void AdminWindow::sendDeleteMsgTem(){
	int x=ui.trainTable->currentRow();
	QString temp="midstation-";
	int flag=0; //0正常，2失败
	temp+=TrainList[x]->getTrainName()+"-";
	temp+=TrainList[x]->getSTime();
	client->Write(temp);
	client->waitForReadyRead(-1);
	QString m=client->getCurrentMessage();
	QStringList mlist=m.split(";");
	int cnt=mlist[0].toInt();
	for (int i=1;i<=cnt;i++){
		QString t="deletetrain-";
		QStringList ulist=mlist[i].mid(1).split("-");
		t+=TrainList[x]->getTrainName()+"-";
		t+=ulist[3]+"-1-";
		t+=QString::number(ui2.sDaysCnt->value());
		qDebug()<<t;
		client->Write(t);
		client->waitForReadyRead();
		QString m=client->getCurrentMessage();
		if (m!="success") flag=2;
	}
	if (flag==0){
		QMessageBox msg;
		msg.setText(QStringLiteral("删除成功！"));
		msg.exec();
		deleteW->close();
		delete deleteW;
		searchTrain();
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("服务器错误！"));
		msg.exec();
	}
}

bool AdminWindow::checkTrainEditable(int x){
	return (TrainList[x]->editable());
}

void AdminWindow::searchTrain(){
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
	for (int i=0;i<cnt;i++){
		QString mc=mList[i+1].mid(1);
		QStringList md=mc.split("-");
		Train* temp=new Train(this,md[0],md[1],md[2],md[3],md[4],md[5].toInt(),md[6].toInt(),md[7].toInt(),md[8].toInt(),md[9].toInt());
		TrainList.push_back(temp);
		TrainList[i]->show(i);
	}
}

void AdminWindow::showAddWindow(){
	if (addTrainW!=NULL) delete addTrainW;
	addTrainW=new AddTrainWindow(client,this);
	addTrainW->show();
}

void AdminWindow::setupPersonalInfo(QString userinfo){
	QStringList us=userinfo.split("-");
	u=new Admin(this,client,us[0],us[1],us[2],us[3],us[4]);
	u->showPersonalInfo();
}

void AdminWindow::logout(){
	client->Write("logout-"+u->getUsername());
	this->close();
	parent->show();
	parent->ui.lPassword->clear();
}

void AdminWindow::exitProgram(){
	QMessageBox msgBox;
	msgBox.setText(QStringLiteral("您确定要退出吗？"));
	QPushButton *bYes=msgBox.addButton(QStringLiteral("是"),QMessageBox::ButtonRole::NoRole);
	QPushButton *bNo=msgBox.addButton(QStringLiteral("否"),QMessageBox::ButtonRole::NoRole);
	connect(bYes,SIGNAL(clicked()),&msgBox,SLOT(close()));
	connect(bYes,SIGNAL(clicked()),this,SLOT(close()));
	connect(bNo,SIGNAL(clicked()),&msgBox,SLOT(close()));
	msgBox.exec();
}