#include "ticket.h"
#include "qtablewidget.h"
#include "mainwindow.h"

Ticket::Ticket(MainWindow *parent, QString newTrainName, QString newSStation, QString newEStation, QString newSTime, QString newDTime,
		trainType newTrType, int newSeat, int newPrice, ticketType newTType):
trainName(newTrainName),sStation(newSStation),eStation(newEStation),sTime(newSTime),dTime(newDTime),trType(newTrType),
	seat(newSeat),price(newPrice),tType(newTType),parent(parent){
	QString temp=newTrainName;
	if (temp[0]=='G') trType2=G;
	else if (temp[0]=='T') trType2=T;
	else if (temp[0]=='K') trType2=K;
	else if (temp[0]=='D') trType2=D;
	else trType2=N;
}

QString Ticket::tt1toString(trainType t){
	switch(t){
	case Stand:return QString(QStringLiteral("坐铺"));
	case Sleep:return QString(QStringLiteral("卧铺"));
	default:return QString();
	}
}

QString Ticket::tt2toString(trainType2 t){
	switch(t){
	case T:return QString(QStringLiteral("特快"));
	case N:return QString(QStringLiteral("普通"));
	case K:return QString(QStringLiteral("快速"));
	case G:return QString(QStringLiteral("高铁"));
	case D:return QString(QStringLiteral("动车"));
	default:return QString();
	}
}

QString Ticket::seattoString(int x){
	if (trType==Stand) return QString::number(x);
	QString temp=QString::number(x/3+1);
	switch(x%3){
	case 0:temp+=QStringLiteral("上铺");break;
	case 1:temp+=QStringLiteral("中铺");break;
	case 2:temp+=QStringLiteral("下铺");break;
	}
	return temp;
}

QString Ticket::tttoString(ticketType t){
	if (t==Student) return QString(QStringLiteral("学生"));
	return QString(QStringLiteral("成人"));
}

void Ticket::show(int x){
	QTableWidget *t=parent->ui.ticketTable;
	t->setRowCount(x+1);
	t->setItem(x,0,new QTableWidgetItem(trainName));
	t->setItem(x,1,new QTableWidgetItem(sStation));
	t->setItem(x,2,new QTableWidgetItem(sTime));
	t->setItem(x,3,new QTableWidgetItem(eStation));
	t->setItem(x,4,new QTableWidgetItem(dTime));
	t->setItem(x,5,new QTableWidgetItem(tt1toString(trType)));
	t->setItem(x,6,new QTableWidgetItem(tt2toString(trType2)));
	t->setItem(x,7,new QTableWidgetItem(seattoString(seat)));
	t->setItem(x,8,new QTableWidgetItem(QString::number(price)));
	t->setItem(x,9,new QTableWidgetItem(tttoString(tType)));
}