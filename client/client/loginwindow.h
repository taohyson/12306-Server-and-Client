#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <qwidget.h>
#include "ui_loginwindow.h"
#include "ui_connect.h"
#include "registerwindow.h"
#include "client.h"

class RegisterWindow;
class MainWindow;
class AdminWindow;
class LoginWindow : public QWidget
{
	Q_OBJECT
	friend class MainWindow;
	friend class AdminWindow;
public:
	LoginWindow(Client *client);
	~LoginWindow();
public slots:
	void login();
private:
	Ui::Login ui;
	RegisterWindow *r;
	Client *client;
	MainWindow *w1;
	AdminWindow *w2;
};

#endif 
