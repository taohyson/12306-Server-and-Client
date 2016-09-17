#include "admin.h"
#include "qmessagebox.h"

Admin::Admin(AdminWindow *parent, Client *client, QString username,QString password, QString name, QString phone, QString position)
	:AbstractUser(username,password,name,phone,true),position(position),client(client),parent(parent)
{}

void Admin::showPersonalInfo(){
	parent->ui.lUsername->setText(username);
	parent->ui.lPassword->setText(password);
	parent->ui.lName->setText(name);
	parent->ui.lPhone->setText(phone);
	parent->ui.lPosition->setText(position);
}

void Admin::editPersonalInfoEnabled(){
	parent->ui.lPassword->setEnabled(true);
	parent->ui.lName->setEnabled(true);
	parent->ui.lPhone->setEnabled(true);
}

void Admin::editPersonalInfoDisabled(){
	parent->ui.lPassword->setEnabled(false);
	parent->ui.lName->setEnabled(false);
	parent->ui.lPhone->setEnabled(false);
}

void Admin::updatePersonalInfo(){
	if (checkInfo()){
		QString password=parent->ui.lPassword->text();
		QString name=parent->ui.lName->text();
		QString phone=parent->ui.lPhone->text();
		client->Write("updateadmininfo");
		client->sleep(20);
		QString temp=username+"-"+password+"-"+name+"-"+phone+"-"+position;
		client->Write(temp);
		client->waitForReadyRead(-1);
		QString s=client->getCurrentMessage();
		if (s=="success"){
			QMessageBox msg;
			msg.setText(QStringLiteral("修改成功！"));
			msg.setWindowTitle(QStringLiteral("Success"));
			msg.exec();
			editPersonalInfoDisabled();
			updateLocalPersonalInfo();
			parent->ui.bEdit->show();
			parent->ui.bEditComplete->hide();
			parent->ui.bEditCancel->hide();
			showPersonalInfo();
		}
	}
}

void Admin::updateLocalPersonalInfo(){
	password=parent->ui.lPassword->text();
	name=parent->ui.lName->text();
	phone=parent->ui.lPhone->text();
}

bool Admin::checkInfo(){
	QString password=parent->ui.lPassword->text();
	QString name=parent->ui.lName->text();
	QString phone=parent->ui.lPhone->text();
	bool flag=true;
	if (password.contains("-") || password.contains("/") || password.contains(";")){
		QMessageBox msg;
		msg.setText(QStringLiteral("密码含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (password.length()<6||password.length()>15){
		QMessageBox msg;
		msg.setText(QStringLiteral("密码长度应在6至15位之间！"));
		msg.exec();
		flag=false;
	} else if (name.contains("-") || name.contains("/") || name.contains(";")){
		QMessageBox msg;
		msg.setText(QStringLiteral("姓名含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (!checkPhone()){
		QMessageBox msg;
		msg.setText(QStringLiteral("无效的手机号！"));
		msg.exec();
		flag=false;
	}
	return flag;
}

bool Admin::checkPhone(){
	QString phone=parent->ui.lPhone->text();
	if (phone.length()!=11) return false;
	for (int i=0;i<11;i++){
		if (!phone[i].isNumber()) return false;
	}
	return true;
}