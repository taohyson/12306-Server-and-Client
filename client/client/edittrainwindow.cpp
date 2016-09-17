#include "edittrainwindow.h"
#include "adminwindow.h"
#include "qmessagebox.h"

EditTrainWindow::EditTrainWindow(AdminWindow *parent, Client *client)
	:parent(parent),client(client)
{
	ui.setupUi(this);
	ui.stationTable->setColumnCount(2);
	ui.stationTable->setHorizontalHeaderItem(0,new QTableWidgetItem(QStringLiteral("车站名")));
	ui.stationTable->setColumnWidth(0,150);
	ui.stationTable->setHorizontalHeaderItem(1,new QTableWidgetItem(QStringLiteral("到站时间")));
	//ui.stationTable->setColumnWidth(1,160);
	int x=parent->ui.trainTable->currentRow();
	QString temp="midstation-";
	temp+=parent->getTrain(x)->getTrainName()+"-";
	temp+=parent->getTrain(x)->getSTime();
	client->Write(temp);
	client->waitForReadyRead(-1);
	QString m=client->getCurrentMessage();
	QStringList ml=m.split(";");
	int cnt=ml[0].toInt();
	ui.stationTable->setRowCount(cnt+1);
	QStringList ul;
	for (int i=1;i<=cnt;i++){
		ul=ml[i].mid(1).split("-");
		ui.stationTable->setItem(i-1,0,new QTableWidgetItem(ul[1]));
		//ui.stationTable->item(i-1,0)->setText(ul[1]);
		QDateTime qdt=QDateTime::fromString(ul[3],"yyyy/MM/dd hh:mm");
		QDateTimeEdit *qdte=new QDateTimeEdit(qdt);
		qdte->setDisplayFormat("yyyy/MM/dd hh:mm");
		if (i==1) qdte->setEnabled(false);
		ui.stationTable->setCellWidget(i-1,1,qdte);
	}
	ui.stationTable->setItem(cnt,0,new QTableWidgetItem(ul[2]));
	QDateTime qdt=QDateTime::fromString(ul[4],"yyyy/MM/dd hh:mm");
	QDateTimeEdit *qdte=new QDateTimeEdit(qdt);
	qdte->setDisplayFormat("yyyy/MM/dd hh:mm");
	ui.stationTable->setCellWidget(cnt,1,qdte);
	ui.sStationCnt->setValue(cnt+1);
	ui.cSeatType->setCurrentIndex(parent->getTrain(x)->getTrainType());
	ui.lTrainName->setText(parent->getTrain(x)->getTrainName());
	connect(ui.bEditPer,SIGNAL(clicked()),this,SLOT(sendEditMsgPer()));
	connect(ui.bEditTep,SIGNAL(clicked()),this,SLOT(sendEditMsgTep()));
}

bool EditTrainWindow::check(){
	bool flag=true;
	for (int i=0;i<ui.sStationCnt->value()-1;i++){
		QDateTimeEdit *d1=(QDateTimeEdit *)ui.stationTable->cellWidget(i,1);
		QDateTimeEdit *d2=(QDateTimeEdit *)ui.stationTable->cellWidget(i+1,1);
		QDateTime dt1=d1->dateTime(); QDateTime dt2=d2->dateTime();
		if (dt1.secsTo(dt2)<=0) {
			QMessageBox msg;
			msg.setText(QStringLiteral("抵达时刻不能早于出发时刻！"));
			msg.setWindowTitle("Error");
			msg.exec();
			flag=false; break;
		}
	}
	return flag;
}

void EditTrainWindow::sendEditMsgPer(){
	if (!check()) return;
	int flag=0;
	for (int i=0;i<ui.sStationCnt->value()-1;i++){
		QString temp="updatetraininfo-";
		temp+=ui.lTrainName->text()+"-";
		QDateTimeEdit *d1=(QDateTimeEdit *)ui.stationTable->cellWidget(i,1);
		temp+=d1->text()+"-";
		QDateTimeEdit *d2=(QDateTimeEdit *)ui.stationTable->cellWidget(i+1,1);
		temp+=d2->text()+"-";
		temp+=ui.stationTable->item(i,0)->text()+"-";
		temp+=ui.stationTable->item(i+1,0)->text()+"-";
		temp+=QString::number(ui.cSeatType->currentIndex())+"-";
		temp+=QString::number(i)+"-0-";
		temp+=QString::number(ui.sDaysCnt->value());
		client->Write(temp);
		client->waitForReadyRead(-1);
		QString m=client->getCurrentMessage();
		if (!(m=="success")) flag=2;
	}
	if (flag==0){
		QMessageBox msg;
		msg.setText(QStringLiteral("修改成功！"));
		msg.exec();
		this->close();
		parent->searchTrain();
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("修改失败！"));
		msg.exec();
	}
}

void EditTrainWindow::sendEditMsgTep(){
	if (!check()) return;
	int flag=0;
	for (int i=0;i<ui.sStationCnt->value()-1;i++){
		QString temp="updatetraininfo-";
		temp+=ui.lTrainName->text()+"-";
		QDateTimeEdit *d1=(QDateTimeEdit *)ui.stationTable->cellWidget(i,1);
		temp+=d1->text()+"-";
		QDateTimeEdit *d2=(QDateTimeEdit *)ui.stationTable->cellWidget(i+1,1);
		temp+=d2->text()+"-";
		temp+=ui.stationTable->item(i,0)->text()+"-";
		temp+=ui.stationTable->item(i+1,0)->text()+"-";
		temp+=QString::number(ui.cSeatType->currentIndex())+"-";
		temp+=QString::number(i)+"-1-";
		temp+=QString::number(ui.sDaysCnt->value());
		client->Write(temp);
		client->waitForReadyRead(-1);
		QString m=client->getCurrentMessage();
		if (!(m=="success")) flag=2;
	}
	if (flag==0){
		QMessageBox msg;
		msg.setText(QStringLiteral("修改成功！"));
		msg.exec();
		this->close();
		parent->searchTrain();
	} else {
		QMessageBox msg;
		msg.setText(QStringLiteral("修改失败！"));
		msg.exec();
	}
}

