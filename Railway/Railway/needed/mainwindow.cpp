#include "mainwindow.h"
#include "addText.h"
#include <Qstring>
#include <Qmap>
#include "userinfo.h"
#include "user.h"
#include <QDatetime>
#include <Qmessagebox>
#include <QAbstractItemView>
#include <qspinbox>
#include <cstdlib>
#include <ctime>
QMap<QString,QString> loginMap;//记录用户登录时间
QMap<QString,QString> logoutMap;//记录用户登出时间
void sleep(unsigned int msec) 
{ 
	QTime dieTime = QTime::currentTime().addMSecs(msec); 
	while( QTime::currentTime() < dieTime ) 
	QCoreApplication::processEvents(QEventLoop::AllEvents, 100); 
}
mainwindow::mainwindow(int port,QString databaseAd,QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	/*setting tables*/
	ui.LogTableWidget->setWindowTitle("Railway Server developer log");
	QStringList header;header<<"Log information"<<"Time";
	ui.LogTableWidget->setHorizontalHeaderLabels(header);
	ui.LogTableWidget->setColumnWidth(0,430);
	ui.LogTableWidget->setColumnWidth(1,80);
	ui.LogTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.userTableWidget->setWindowTitle("Clients' information");
	QStringList header2;header2<<"UserId"<<"identity"<<"descriptor";
	ui.userTableWidget->setHorizontalHeaderLabels(header2);
	ui.userTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.userTableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);//设为多选
	ui.UserInfoButton->setEnabled(false);
	ui.deleteButton->setEnabled(false);
	ui.sendButton->setEnabled(false);
	setAutoFillBackground(true);
    QPalette palette;
	//QPixmap pixmap(":/Resources/font.jpg");
	palette.setColor(QPalette::Background, QColor(192,253,123));
    //palette.setBrush(QPalette::Window, QBrush(pixmap));
    setPalette(palette);

	/*setting signals and slots*/
	connect(&server,SIGNAL(newdebug(const QString&)),this,SLOT(Mydebug(const QString&)));
	connect(&server,SIGNAL(newUser(QString,QString)),&database,SLOT(checkNewUser(QString,QString)));
	connect(&server,SIGNAL(update()),this,SLOT(updateCurrentUser()));
	connect(&server,SIGNAL(newRegister(QString,QString,QString,QString,QString,QString,QString,QString,QString)),
		&database,SLOT(registerNewUser(QString,QString,QString,QString,QString,QString,QString,QString,QString)));
	connect(&server,SIGNAL(ticketQuery(QString)),&database,SLOT(onTicketQuery(QString)));
	connect(&server,SIGNAL(trainQuery(Train)),&database,SLOT(onTrainQuery(Train)));
	connect(&server,SIGNAL(returnTicket(Ticket)),&database,SLOT(onTicketReturn(Ticket)));
	connect(&server,SIGNAL(MidStationQuery(Train)),&database,SLOT(onMidStationQuery(Train)));
	connect(&server,SIGNAL(userAddMoney(UserClass)),&database,SLOT(onUserAddMoney(UserClass)));
	connect(&server,SIGNAL(updateUserInfo(UserClass)),&database,SLOT(onUserUpdateInfo(UserClass)));
	connect(&server,SIGNAL(buyTicket(Ticket)),&database,SLOT(onBuyTicket(Ticket)));
	connect(&server,SIGNAL(updateAdminInfo(admin)),&database,SLOT(onUpdateAdminInfo(admin)));
	connect(&server,SIGNAL(addTrainInfo(Train)),&database,SLOT(onAddTrainInfo(Train)));
	connect(&server,SIGNAL(updateTrainInfo(Train)),&database,SLOT(onUpdateTrainInfo(Train)));
	connect(&server,SIGNAL(userLogOut(QString)),this,SLOT(onUserLogOut(QString)));
	connect(&server,SIGNAL(deleteTrain(Train)),&database,SLOT(onDeleteTrain(Train)));

	connect(&database,SIGNAL(deleteTrainResult(int)),this,SLOT(onDeleteTrainResult(int)));
	connect(&database,SIGNAL(trainUpdateResult(int)),this,SLOT(onTrainUpdateResult(int)));
	connect(&database,SIGNAL(addTrainResult(int)),this,SLOT(onAddTrainResult(int)));
	connect(&database,SIGNAL(adminUpdateInfoResult(int)),this,SLOT(onAdminUpdateInfoResult(int)));
	connect(&database,SIGNAL(buyTicketResult(int)),this,SLOT(onBuyTicketResult(int)));
	connect(&database,SIGNAL(userUpdateInfoResult(int)),this,SLOT(onUserUpdateInfoResult(int)));
	connect(&database,SIGNAL(userAddMoneyResult(int)),this,SLOT(onUserAddMoneyResult(int)));
	connect(&database,SIGNAL(returndeleteResult(int)),this,SLOT(onReturnDeleteResult(int)));
	connect(&database,SIGNAL(registerUser(int)),this,SLOT(onRegisterUser(int)));
	connect(&database,SIGNAL(newUser(int,QString,int,QStringList)),this,SLOT(onNewUser(int,QString,int,QStringList)));
	connect(&database,SIGNAL(newdebug(const QString&)),this,SLOT(Mydebug(const QString&)));
	connect(&database,SIGNAL(userTicketInfo(QStringList)),this,SLOT(onTicketInfo(QStringList)));
	connect(&database,SIGNAL(trainInfo(QStringList)),this,SLOT(onTrainInfo(QStringList)));
	connect(&database,SIGNAL(midStationInfo(QStringList)),this,SLOT(onMidStationInfo(QStringList)));

	connect(this,SIGNAL(serverWrite(QString)),&server,SLOT(Write(QString)));
	connect(this,SIGNAL(serverWrite(QString,int)),&server,SLOT(Write(QString,int)));
	connect(ui.sendButton,SIGNAL(clicked()),this,SLOT(onSendClicked()));
	connect(ui.UserInfoButton,SIGNAL(clicked()),this,SLOT(onInfoClicked()));
	connect(ui.deleteButton,SIGNAL(clicked()),this,SLOT(onDeleteClicked()));

	server.listen(QHostAddress::Any,port);
	Mydebug("Server Listenning!");
	if(database.createConnection(databaseAd))
	{
		Mydebug("database link success!");
		if(database.createTables())
			Mydebug("database set up success!");
		QDateTime time = QDateTime::currentDateTime();
		database.date=time.toString("yyyy/MM/dd");
		database.deleteTrain(time.toString("yyyy/MM/dd hh:mm"));
		database.deleteTicket(time.toString("yyyy/MM/dd hh:mm"));
		database.addTrain(time.toString("yyyy-MM-dd"));
	}
	srand((unsigned)time(0));
}

//窗口输出日志信息
void mainwindow::Mydebug(const QString& str)
{
	static int i=0;//行数
	QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
	QString temp = time.toString("h:m:s"); //设置显示格式
	qDebug()<<str;
	ui.LogTableWidget->setItem(i,0,new QTableWidgetItem(str));
	ui.LogTableWidget->setItem(i,1,new QTableWidgetItem(temp));
	++i;
	if (i==ui.LogTableWidget->rowCount()-1)//如果满了，清空重新来
	{
		i=0;
		ui.LogTableWidget->clear();
	}
}

//slots
void mainwindow::onDeleteClicked()
{
	QList<int> descriptors;
	QList<QTcpSocket *> targets;
	QList<QTcpSocket *>::iterator iter;

	/*get item*/
	QList<QTableWidgetItem *>items=ui.userTableWidget->selectedItems();
	if (!items.count())
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("没有选择用户！"));
		msgBox.exec();
		Mydebug("iten not selected!");
		return ;
	}
	for (int i=0;i<items.count();i++)
	{
		int row=ui.userTableWidget->row(items.at(i));
		QTableWidgetItem *item=ui.userTableWidget->item(row,2);
		descriptors.append(item->text().toInt());
	}

	bool flag=true;//find or not
	
	if (flag)
	{
		QString message=QString("Disconnected");
		QMessageBox messageBox(QMessageBox::Warning,"DeleteTrain",QStringLiteral("你确定要踢出这些用户吗？"),QMessageBox::Yes|QMessageBox::No,NULL);
		messageBox.setButtonText(QMessageBox::Yes,QStringLiteral("当然，删了他们"));
		messageBox.setButtonText(QMessageBox::No,QStringLiteral("我再想想"));
		if (messageBox.exec()==QMessageBox::Yes)
		{
		//Mydebug(message);
			for (int i=0;i<descriptors.count();i++)
			{
				emit serverWrite(message,descriptors.at(i));
				//Mydebug(QString("%1-").arg(descriptors.at(i)));
			}
		}
	}
	else
		Mydebug("error! decriptor not found!");
}
void mainwindow::onInfoClicked()
{
	QString user;
	QList<QTcpSocket *> targets;
	QList<QTcpSocket *>::iterator iter;
	int flag=0;
	/*get item*/
	QList<QTableWidgetItem *>items=ui.userTableWidget->selectedItems();
	if (!items.count())
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("没有选择用户！"));
		msgBox.exec();
		Mydebug("iten not selected!");
		return ;
	}
	if (items.count()>1)
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("查看用户信息时请选择单个用户！"));
		msgBox.exec();
		Mydebug("too much items selected!");
		return ;
	}
	int row=ui.userTableWidget->row(items.at(0));
	if (ui.userTableWidget->item(row,1)->text().contains(QStringLiteral("管理")))
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("管理员的信息不可以查看！请去公司总部查看人员册！"));
		msgBox.exec();
		Mydebug("cannot look up ad's info!");
		return ;
	}
	QTableWidgetItem *item=ui.userTableWidget->item(row,0);
	if (!item)
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("没有选择合适用户！"));
		msgBox.exec();
		Mydebug("no proper user selected");
		return ;
	}
	if (item->backgroundColor()==QColor(252,222,156))
		flag=2;
	else
	{
		flag=1;
	}
	user=item->text();
	if (flag)
	{
		QStringList temp=database.queryInfo("USER",user);
		temp.removeLast();
		if (!loginMap.contains(user))
			Mydebug("no user log in record!");

		else
		{
			if (flag==2)//不在线
			{
				temp.append(loginMap[user]);
				temp.append(logoutMap[user]);
			}
			if (flag==1)//在线
			{
				temp.append(loginMap[user]);
				temp.append(QStringLiteral("当前在线"));
			}
		}
		UserInfo w(temp);
		w.exec();
	}
	else
		Mydebug("error! decriptor not found!");
}
void mainwindow::onSendClicked()
{
	QList<int> descriptors;
	QList<QTcpSocket *> targets;
	QList<QTcpSocket *>::iterator iter;

	/*get item*/
	QList<QTableWidgetItem *>items=ui.userTableWidget->selectedItems();
	if (!items.count())
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("没有选择用户！"));
		msgBox.exec();
		Mydebug("iten not selected!");
		return ;
	}
	for (int i=0;i<items.count();i++)
	{
		int row=ui.userTableWidget->row(items.at(i));
		QTableWidgetItem *item=ui.userTableWidget->item(row,2);
		descriptors.append(item->text().toInt());
	}

	bool flag=true;//find or not
	
	if (flag)
	{
		addText w;
		if (w.exec()==QDialog::Accepted)
		{
			QString message=w.getText();
			//Mydebug(QString("%1").arg(message.length()));
			//Mydebug(message);
			for (int i=0;i<descriptors.count();i++)
			{
				emit serverWrite(message,descriptors.at(i));
				//Mydebug(QString("%1-").arg(descriptors.at(i)));
			}
		}
	}
	else
		Mydebug("error! decriptor not found!");
}
void mainwindow::updateCurrentUser()
{
	//Mydebug("updateCurrentUser running");
	QList<int> _descriptors;
	int temp;
	_descriptors.clear();
	for (int i=0;i<server._clients.count();++i)
		_descriptors.append((int)server._clients.at(i)->socketDescriptor());
	//setting usertable
	for (int i=0;i<getRow(ui.userTableWidget);i++)
	{
		//Mydebug(QString("%1").arg(i));
		temp=ui.userTableWidget->item(i,2)->text().toInt();
		if (!_descriptors.contains(temp)
			&& ui.userTableWidget->item(i,2)->backgroundColor()!=QColor(252,222,156))
		{
			//add something;
			QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
			QString temp = time.toString("h:m:s"); //设置显示格式
			logoutMap[ui.userTableWidget->item(i,0)->text()]=temp;//设置登出时间到内存
			for(int j=0;j<ui.userTableWidget->columnCount();j++)
			{
				QTableWidgetItem *item=ui.userTableWidget->item(i,j);
				if (item)//如果非空
				{
					const QColor color = QColor(252,222,156);
					item->setBackgroundColor(color);
				}
			}
		}
	}
}
void mainwindow::onNewUser(int flag,QString name,int id,QStringList info)
{
	//Mydebug(info.join("-"));
	if (flag==2)//success
	{
		/*判断用户是否已经登录*/
		if (IsLogin(name))
		{
			emit serverWrite("user Already login in !");
			return ;
		}

		/*update mainwindow*/
		addUserInfo(server.currentSocket->socketDescriptor());
		addUserInfo(name,id,server.currentSocket->socketDescriptor());
		ui.UserInfoButton->setEnabled(true);
		ui.deleteButton->setEnabled(true);
		ui.sendButton->setEnabled(true);
		QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
	    QString temp = time.toString("h:m:s"); //设置显示格式
		loginMap[name]=temp;
		QString str=info.join("-");
		if (id==User)
			emit serverWrite("success-User;"+str);
		else if (id==Admin)
			emit serverWrite("success-Administrator;"+str);
		Mydebug("a client has login!");
	}
	else if (flag==1)//xuser
	{
		emit serverWrite("xuser");
	}
	else if (flag==0)//xpasswd
		emit serverWrite("xpasswd");
	else//程序错乱.
	{
		Mydebug("ERRRRRRRRRRRRRRROR!");
		emit serverWrite("server unexpected error!");
	}
}
void mainwindow::onRegisterUser(int flag)
{
	if (flag==2)
	{
		emit serverWrite("success");
	}
	else if (flag==1)
	{
		emit serverWrite("xusername");
	}
	else if (flag==0)
	{
		emit serverWrite("xID");
	}
	else
	{
		emit serverWrite("server unexpected error!");
	}
}
void mainwindow::onTicketInfo(QStringList info)
{
	QString temp=info.join("-");
	emit serverWrite(temp);
}
void mainwindow::onTrainInfo(QStringList info)
{
	QString temp=info.join("-");
	emit serverWrite(temp);
}
void mainwindow::onReturnDeleteResult(int flag)
{
	if (flag==1)//删除成功
	{
		emit serverWrite("success");
		return;
	}
	else if(flag==0)//没有
	{
		emit serverWrite("xticket");
		return;
	}
	else//多删orsql崩了
	{
		emit serverWrite("unexpected error!");
		return ;
	}

}
void mainwindow::onMidStationInfo(QStringList info)
{
	QString temp=info.join("-");
	emit serverWrite(temp);
}
void mainwindow::onUserAddMoneyResult(int flag)
{
	if (flag==1)//success
	{
		emit serverWrite("success");
	}
	else if(flag==-1)
	{
		emit serverWrite("server sql error!");
	}
	else
	{
		emit serverWrite("unexpected error!");
	}
	
}
void mainwindow::onUserUpdateInfoResult(int flag)
{
	if(flag==1)//success
	{
		emit serverWrite("success");
	}
	else
	{
		emit serverWrite("unexpected error!");
	}
}
void mainwindow::onBuyTicketResult(int flag)
{
	if (flag==1)
		emit serverWrite("success");
	else if (flag==0)
	{
		emit serverWrite("xuser");
	}
	else
	{
		emit serverWrite("server unexpected error!");
	}
}
void mainwindow::onAdminUpdateInfoResult(int flag)
{
	if (flag)
	{
		emit serverWrite("success");
	}
	else
	{
		emit serverWrite("unexpected error");
	}

}
void mainwindow::onAddTrainResult(int flag)
{
	if (flag==1)//成功
	{
		emit serverWrite("success");
	}
	else if(flag==0)//exists
	{
		emit serverWrite("exists");
	}
	else
	{
		emit serverWrite("server unexpected error");
	}
}
void mainwindow::onTrainUpdateResult(int flag)
{
	if (flag==1)
	{
		emit serverWrite("success");
	}
	else if (flag==0)
	{
		emit serverWrite("success but xpermanent");
	}
	else
	{
		emit serverWrite("unexpected error");
	}
}
void mainwindow::onUserLogOut(QString UserId)
{
	QString currentUserId;
	bool flag=false;
	for (int i=0;i<getRow(ui.userTableWidget);i++)
	{
		//Mydebug(QString("%1").arg(i));
		currentUserId=ui.userTableWidget->item(i,0)->text();
		if (currentUserId==UserId
			&& ui.userTableWidget->item(i,2)->backgroundColor()!=QColor(252,222,156))
		{
			flag=true;
			//add something;
			QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
			QString temp = time.toString("h:m:s"); //设置显示格式
			logoutMap[currentUserId]=temp;//设置登出时间到内存
			for(int j=0;j<ui.userTableWidget->columnCount();j++)
			{
				QTableWidgetItem *item=ui.userTableWidget->item(i,j);
				if (item)//如果非空
				{
					const QColor color = QColor(252,222,156);
					item->setBackgroundColor(color);
				}
			}
		}
	}
	//if (flag)
	//	emit serverWrite("success");
	//else
	//{
	//	emit serverWrite("xuser!");
	//}
}
void mainwindow::onDeleteTrainResult(int flag)
{
	if (flag==1)
	{
		emit serverWrite("success");
	}
	else if (flag==0)
	{
		emit serverWrite("success but xpermanent");
	}
	else
	{
		emit serverWrite("unexpected error");
	}
}

//aux_fuctions
void mainwindow::addUserInfo(QString user,int identity,int _d)//"0"不修改
{
	if (user!="0") 
		ui.userTableWidget->setItem(getRow(ui.userTableWidget,_d),0,new QTableWidgetItem(user));
	if (identity!=0)
	{
		if (identity==Admin)//管理员
		{
			int row=getRow(ui.userTableWidget,_d);
			if (row==-1) 
			{
				Mydebug("error!descriptor not found");
				return;
			}
			ui.userTableWidget->setItem(row,1,new QTableWidgetItem(QStringLiteral("管理员")));
		}
		else if (identity==User)//用户
		{
			int row=getRow(ui.userTableWidget,_d);
			if (row==-1) 
			{
				Mydebug("error!descriptor not found");
				return;
			}
			ui.userTableWidget->setItem(row,1,new QTableWidgetItem(QString::fromLocal8Bit("用户")));
		}
		else 
			Mydebug("error!Wrong Identity");
	}
}
void mainwindow::addUserInfo(int _d)
{
	int row=getRow(ui.userTableWidget);
	//Mydebug(QString("%1").arg(row));
	if(row==-1)
	{
		Mydebug("error!List full!");
		return ;
	}
	ui.userTableWidget->setItem(row,2,new QTableWidgetItem(QString("%1").arg(_d)));
}
int mainwindow::getRow(QTableWidget * rs,int _d)//找到制定descritor所在地
{
	for (int j=0;j<rs->rowCount();j++)
	{
		QTableWidgetItem *item=rs->item(j,2);//2是descriptor
		if (!item)
		{
			Mydebug("error!");
			return 0;
		}
		if (item->text().toInt()==_d && item->backgroundColor()!=QColor(252,222,156))
			return j;
	}
	return -1;
}
int mainwindow::getRow(QTableWidget *rs)//get row with no descriptor
{
	for (int j=0;j<rs->rowCount();j++)
	{
		QTableWidgetItem *item=rs->item(j,2);//2是descriptor
		if (!item)
			return j;
	}
	return -1;
}
bool mainwindow::IsLogin(const QString& UserId)
{
	for (int j=0;j<ui.userTableWidget->rowCount();j++)
	{
		QTableWidgetItem *item=ui.userTableWidget->item(j,0);//2是descriptor
		if (!item)
		{
			return false;
		}
		if (item->text()==UserId && item->backgroundColor()!=QColor(252,222,156))
			return true;
	}
	return false;
}

mainwindow::~mainwindow()
{

}

