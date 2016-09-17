#pragma once
#include <Qstring>
class Ticket
{
public:
	Ticket(void){}
	~Ticket(void);
	QString TrainId;
	QString UserId;
	QString StartTime;
	QString EndTime;//为了查询
	QString Origin;
	QString Destination;
	QString Buyer;
	int Seat;
	int Tickettype;
	int cartype;//为了查询

	int OriginStationId;
	double price;
	int DestinationStaionId;//查余票用
};

