#include "userinfo.h"

UserInfo::UserInfo(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}
UserInfo::UserInfo(QStringList list)
{
	ui.setupUi(this);
	QString UserId,Password,name,sex,cre,contact,nation,identity,addition;
	UserId=list[0];
	Password=list[1];
	name=list[2];
	sex=list[3];
	cre=list[4];
	contact=list[5];
	nation=list[6];
	identity=list[7];
	addition=list[8];
	ui.UserIdLabel->setText(UserId);
	ui.PassWordLabel->setText(Password);
	ui.NameLabel->setText(name);
	ui.SexLabel->setText(sex);
	ui.CreLabel->setText(cre);
	ui.ContactLabel->setText(contact);
	ui.IdentityLabel->setText(identity);
	ui.regionLabel->setText(nation);
	ui.AdditionLabel->setText(addition);
	ui.LogInLabel->setText(list[9]);
	ui.LogOutLabel->setText(list[10]);
}

UserInfo::~UserInfo()
{

}
