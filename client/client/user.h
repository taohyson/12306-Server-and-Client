#ifndef USER_H
#define USER_H
#include "abstractuser.h"
#include <vector>
#include "ticket.h"
#include "enum.h"
#include "client.h"
#include "ui_buyother.h"
using namespace std;

class MainWindow;
class User:public AbstractUser{
	Q_OBJECT
private:
	genderType gender;
	QString ID;
	QString country;
	QString schoolName;
	QString schoolNum;
	int balance;
	Client *client;
	MainWindow *parent;
	int ticketToReturn;
	int trainToBuy;
	bool checkInfo();
	bool checkPhone();
	bool checkID();
	void updateLocalPersonalInfo();
	int dateCheck(QString d1);
	bool ticketCheck(QString t, QString d);
	Ui::buyOtherWindow ui;
	QWidget *buyOtherW;
public:
	User();
	User(Client* newClient, MainWindow* parent, QString newUsername, QString newPassword, QString newName, genderType newGender, QString newID, QString newPhone,
		QString newCountry, ticketType newTType, int newBalance, QString schoolName="", QString schoolNum="");
	QString getUsername(){return username;}
	void addTicket(Ticket *newTicket){
		ticketList.push_back(newTicket);
	}
	vector<Ticket*> ticketList;
	void showTicket(int x);
	void buy(int x);
	void buyStudent(int x);
	void buyOther(int x);
	int ticketTypeToBuy;
	//ticketType getTType();
	ticketType tType;
public slots:
	void returnTicket(int column, int row);
	void sendReturnInfo();
	void editPersonalInfoEnabled();
	void editPersonalInfoDisabled();
	void updatePersonalInfo();
	void showPersonalInfo();
	void pay(int x);
	void sendBuyInfo();
	void sendBuyOtherInfo();
private slots:
	void extraInfoEditEnabled(int x);
};
#endif