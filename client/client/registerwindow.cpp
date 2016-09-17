#include "registerwindow.h"
#include "qmessagebox.h"
#include "qdebug.h"
RegisterWindow::RegisterWindow(LoginWindow *l, Client *c){
	ui.setupUi(this);
	parent=l;
	client=c;
	connect(ui.bCancel,SIGNAL(clicked()),parent,SLOT(show()));
	connect(ui.bCancel,SIGNAL(clicked()),this,SLOT(close()));
	connect(ui.bRegister,SIGNAL(clicked()),this,SLOT(sendInfo()));
	connect(ui.cTType,SIGNAL(currentIndexChanged(int)),this,SLOT(extraInfoEditEnabled(int)));
}

void RegisterWindow::extraInfoEditEnabled(int x){
	if (x==1) {
		ui.lSchoolName->setEnabled(true);
		ui.lSchoolID->setEnabled(true);
	} else {
		ui.lSchoolName->setEnabled(false);
		ui.lSchoolName->clear();
		ui.lSchoolID->setEnabled(false);
		ui.lSchoolID->clear();
	}
}

RegisterWindow::~RegisterWindow(){
	
}

void RegisterWindow::sendInfo(){
	/*GetInfo*/
	username=ui.lUsername->text();
	password=ui.lPassword->text();
	password2=ui.lPassword2->text();
	name=ui.lName->text();
	gender=(ui.cGender->currentIndex()==0);
	birthday=ui.dBirthday->date();
	country=ui.cCountry->currentText();
	ID=ui.lID->text();
	phone=ui.lPhone->text();
	tType=(ui.cTType->currentIndex()==0);
	schoolName=ui.lSchoolName->text();
	schoolID=ui.lSchoolID->text();

	if (check()){
		client->Write("register");
		client->sleep(20);
		QString temp=username+"-"+password+"-"+name+"-"+(gender?"Male":"Female");
		temp+="-"+country+"-"+ID+"-"+phone+"-"+(tType?"Adult":"Student")+"-"+schoolName+","+schoolID;
		client->Write(temp);
	    client->waitForReadyRead(-1);
		QString s=client->getCurrentMessage();
		if (s=="success"){
			QMessageBox msg;
			msg.setText(QStringLiteral("注册成功！"));
			msg.setWindowTitle(QStringLiteral("Success"));
			msg.exec();
			this->close();
			parent->show();
		} else if (s=="xusername"){
			QMessageBox msg;
			msg.setText(QStringLiteral("用户名已被注册！"));
			msg.setWindowTitle(QStringLiteral("Error"));
			msg.exec();
		} else if (s=="xID"){
			QMessageBox msg;
			msg.setText(QStringLiteral("身份证号已被注册！"));
			msg.setWindowTitle(QStringLiteral("Error"));
			msg.exec();
		} else{
			QMessageBox msg;
			msg.setText(QStringLiteral("服务器错误！"));
			msg.setWindowTitle(QStringLiteral("Error"));
			msg.exec();
		}
	}
}

bool RegisterWindow::checkID(){
	if (ID.length()!=18) return false;
	for (int i=0;i<17;i++){
		if (!ID[i].isNumber()) return false; 
	}
	if (ID[17].isNumber() || ID[17]=='x' || ID[17]=='X') return true; else return false;
}

bool RegisterWindow::checkPhone(){
	if (phone.length()!=11) return false;
	for (int i=0;i<11;i++){
		if (!ID[i].isNumber()) return false;
	}
	return true;
}

bool RegisterWindow::check(){
	bool flag=true;
	if (username.length()<6||username.length()>20){
		QMessageBox msg;
		msg.setText(QStringLiteral("用户名长度应在6至20位之间！"));
		msg.exec();
		flag=false;
	} else if (username.contains("-") || username.contains("/") || username.contains(";")) {
		QMessageBox msg;
		msg.setText(QStringLiteral("用户名含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (name.contains("-") || name.contains("/") || name.contains(";")) {
		QMessageBox msg;
		msg.setText(QStringLiteral("姓名含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (password.length()<6||password.length()>15){
		QMessageBox msg;
		msg.setText(QStringLiteral("密码长度应在6至15位之间！"));
		msg.exec();
		flag=false;
	} else if (password.contains("-") || password.contains("/") || password.contains(";")){
		QMessageBox msg;
		msg.setText(QStringLiteral("密码含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (!(password2==password)) {
		QMessageBox msg;
		msg.setText(QStringLiteral("两次输入密码不同！"));
		msg.exec();
		flag=false;
	} else if (schoolName.contains("-") || schoolName.contains("/") || schoolName.contains(";")) {
		QMessageBox msg;
		msg.setText(QStringLiteral("学校名称含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (schoolID.contains("-") || schoolID.contains("/") || schoolID.contains(";")) {
		QMessageBox msg;
		msg.setText(QStringLiteral("学号含非法字符！"));
		msg.setInformativeText(QStringLiteral("- / ;均为非法字符"));
		msg.exec();
		flag=false;
	} else if (country!=QStringLiteral("中国")) {
		return true;
	} else if (!checkPhone()){
		QMessageBox msg;
		msg.setText(QStringLiteral("无效的手机号！"));
		msg.exec();
		flag=false;
	} else if (!checkID()){
		QMessageBox msg;
		msg.setText(QStringLiteral("无效的身份证号！"));
		msg.exec();
		flag=false;
	} else if (!(birthday.year()==(ID.mid(6,4).toInt())&&
			birthday.month()==(ID.mid(10,2).toInt())&&
			birthday.day()==(ID.mid(12,2).toInt()))){
		QMessageBox msg;
		msg.setText(QStringLiteral("生日与身份证号不符！"));
		msg.exec();
		flag=false;
	} else if (ID.mid(16,1).toInt()%2!=(gender?1:0)) {
		QMessageBox msg;
		msg.setText(QStringLiteral("性别与身份证号不符！"));
		msg.exec();
		flag=false;
	} else {
		int a[18];
		for (int i=0;i<17;i++) a[i]=ID.mid(i,1).toInt();
		if (ID.mid(17,1)=="X" || ID.mid(17,1)=="x") a[17]=10; else a[17]=ID.mid(17,1).toInt();
		int sum = a[0]*7 + a[1]*9 + a[2]*10 + a[3]*5 + a[4]*8 + a[5]*4 + a[6]*2  
        + a[7]*1 + a[8]*6 + a[9]*3 +a[10]*7 + a[11]*9 + a[12]*10 + a[13]*5  
        + a[14]*8 + a[15]*4 + a[16]*2;
		int b=sum%11;
		if (b!=(12-a[17])%11) {
			QMessageBox msg;
			msg.setText(QStringLiteral("无效的身份证号！"));
			msg.exec();
			flag=false;
		}
	}
	return flag;
}