#ifndef SEATTRAIN_H
#define SEATTRAIN_H

#include "abstracttrain.h"
class SeatTrain:public AbstractTrain{
public:
	SeatTrain(){}
	SeatTrain(QString newTrainName, QString newSStation, QString newEStation, QString newSTime, QString newETime,
		int newPrice, int newTicketsLeft, int newTrainType, int is1i, int is2i)
		:AbstractTrain(newTrainName,newSStation,newEStation,newSTime,newETime,newPrice,newTicketsLeft,newTrainType,is1i,is1i){}
private:
	QString SeatToString(int x){
		return QString(x);
	}
};

#endif