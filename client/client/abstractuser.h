#ifndef ABSTRACTUSER_H
#define ABSTRACTUSER_H
#include <qstring.h>
#include <qapplication.h>

class AbstractUser:public QObject{
	Q_OBJECT
public:
	AbstractUser(QString newUsername,QString newPassword, QString newName, QString newPhone, bool newIsAdmin);
	AbstractUser(){}
protected:
	QString username;
	QString password;
	QString name;
	QString phone;
	bool isAdmin;
public:
	virtual void showPersonalInfo()=0;
	//virtual void updateInfo()=0;
};

#endif