#include "train.h"
#include "mainwindow.h"
#include "qstring.h"
#include "qmessagebox.h"
#include "adminwindow.h"

Train::Train(MainWindow *parent, QString newTrainName, QString newSStation, QString newEStation, QString newSTime, QString newETime,
		int newTrainType, int newPrice, int newTicketsLeft, int is1i, int is2i)
		:parent(parent),trainName(newTrainName),sStation(newSStation),eStation(newEStation),sTime(newSTime),eTime(newETime),
		price(newPrice),ticketsLeft(newTicketsLeft),is1(is1i),is2(is2i){
	trainType1=(newTrainType==0)?Stand:Sleep;
	QString temp=newTrainName;
	if (temp[0]=='G') trainType3=G;
	else if (temp[0]=='T') trainType3=T;
	else if (temp[0]=='K') trainType3=K;
	else if (temp[0]=='D') trainType3=D;
	else trainType3=N;
	windowType=0;
}

Train::Train(AdminWindow *parent, QString newTrainName, QString newSStation, QString newEStation, QString newSTime, QString newETime,
		int newTrainType, int newPrice, int newTicketsLeft, int is1i, int is2i)
		:parent2(parent),trainName(newTrainName),sStation(newSStation),eStation(newEStation),sTime(newSTime),eTime(newETime),
		price(newPrice),ticketsLeft(newTicketsLeft),is1(is1i),is2(is2i){
	trainType1=(newTrainType==0)?Stand:Sleep;
	QString temp=newTrainName;
	if (temp[0]=='G') trainType3=G;
	else if (temp[0]=='T') trainType3=T;
	else if (temp[0]=='K') trainType3=K;
	else if (temp[0]=='D') trainType3=D;
	else trainType3=N;
	windowType=1;
}

bool Train::editable(){
	if (trainType1==Stand) {
		if (ticketsLeft==120) return true; else return false;
	} else {
		if (ticketsLeft==60) return true; else return false;
	}
}


QString Train::tt1toString(trainType t){
	switch(t){
	case Stand:return QString(QStringLiteral("坐铺"));
	case Sleep:return QString(QStringLiteral("卧铺"));
	default:return QString();
	}
}

QString Train::tt2toString(trainType2 t){
	switch(t){
	case T:return QString(QStringLiteral("特快"));
	case N:return QString(QStringLiteral("普通"));
	case K:return QString(QStringLiteral("快速"));
	case G:return QString(QStringLiteral("高铁"));
	case D:return QString(QStringLiteral("动车"));
	default:return QString();
	}
}

void Train::show(int x){
	QTableWidget *t;
	//qDebug()<<typeid(parent).name();
	if (windowType==0) t=parent->ui.trainTable;
	else t=parent2->ui.trainTable;
	t->setRowCount(x+1);
	t->setItem(x,0,new QTableWidgetItem(trainName));
	t->setItem(x,1,new QTableWidgetItem(sStation));
	t->setItem(x,2,new QTableWidgetItem(sTime));
	t->setItem(x,3,new QTableWidgetItem(eStation));
	t->setItem(x,4,new QTableWidgetItem(eTime));
	t->setItem(x,5,new QTableWidgetItem(tt1toString(trainType1)));
	t->setItem(x,6,new QTableWidgetItem(tt2toString(trainType3)));
	t->setItem(x,7,new QTableWidgetItem(QString::number(price)));
	t->setItem(x,8,new QTableWidgetItem(QString::number(ticketsLeft)));
}