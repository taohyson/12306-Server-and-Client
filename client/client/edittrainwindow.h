#ifndef EDITTRAINWINDOW_H
#define EDITTRAINWINDOW_H

#include "ui_edittrain.h"
#include "client.h"

class AdminWindow;
class EditTrainWindow: public QWidget{
	Q_OBJECT
private:
	Ui::editTrainWindow ui;
	AdminWindow *parent;
	Client *client;
	bool check();
public:
	EditTrainWindow(AdminWindow* parent, Client* client);
private slots:
	void sendEditMsgPer();
	void sendEditMsgTep();
};

#endif