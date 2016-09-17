#ifndef ADMIN_H
#define ADMIN_H

#include "abstractuser.h"
#include "adminwindow.h"
#include "client.h"
#include <qstring.h>

class AdminWindow;
class Admin: public AbstractUser{
	Q_OBJECT
private:
	QString position;
	AdminWindow *parent;
	Client *client;
	bool checkInfo();
	bool checkPhone();
	void updateLocalPersonalInfo();
public:
	QString getUsername(){return username;}
	Admin(){}
	Admin(AdminWindow *parent, Client *client, QString username, QString password, QString name, QString phone, QString position);
public slots:
	void editPersonalInfoEnabled();
	void editPersonalInfoDisabled();
	void showPersonalInfo();
	void updatePersonalInfo();
};


#endif