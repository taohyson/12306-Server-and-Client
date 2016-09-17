#ifndef USERINFO_H
#define USERINFO_H

#include <QDialog>
#include "ui_userinfo.h"

class UserInfo : public QDialog
{
	Q_OBJECT

public:
	UserInfo(QWidget *parent = 0);
	UserInfo(QStringList list);
	~UserInfo();

private:
	Ui::UserInfo ui;
};

#endif // USERINFO_H
