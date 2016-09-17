#ifndef REGISTERWINDOW_H_
#define REGISTERWINDOW_H_

#include <qwidget.h>
#include "ui_registerwindow.h"
#include "loginwindow.h"
#include "client.h"

class LoginWindow;
class RegisterWindow: public QWidget{
	Q_OBJECT
public:
	RegisterWindow(LoginWindow *l, Client *c);
	~RegisterWindow();
public slots:
	void sendInfo();
	void extraInfoEditEnabled(int x);
private:
	Ui::Register ui;
	LoginWindow *parent;
	Client *client;
	bool check();

	QString username;
	QString password;
	QString password2;
	QString name;
	bool gender;
	QDate birthday;
	QString country;
	QString ID;
	QString phone;
	bool tType;
	QString schoolName;
	QString schoolID;
	bool checkID();
	bool checkPhone();
};
#endif