#ifndef SLEEPTRAIN_H
#define SLEEPTRAIN_H

#include "abstracttrain.h"
#include "qstring.h"
class SleepTrain:public AbstractTrain{
public:
	SleepTrain(){}
	SleepTrain(QString newTrainName, QString newSStation, QString newEStation, QString newSTime, QString newETime,
		int newPrice, int newTicketsLeft, int newTrainType, int is1i, int is2i)
		:AbstractTrain(newTrainName,newSStation,newEStation,newSTime,newETime,newPrice,newTicketsLeft,newTrainType,is1i,is1i){}
private:
	QString SeatToString(int x){
		QString ans=QString((x-1)/3+1);
		switch(x%3){
		case 1:ans+=QString(QStringLiteral("ÉÏÆÌ"));break;
		case 2:ans+=QString(QStringLiteral("ÖÐÆÌ"));break;
		case 0:ans+=QString(QStringLiteral("ÏÂÆÌ"));break;
		}
	}
};

#endif