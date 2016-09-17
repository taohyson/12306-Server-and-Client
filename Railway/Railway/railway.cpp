#include "railway.h"
#include "mainwindow.h"
#include <qdebug>
#include <QmessageBox>
Railway::Railway(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	flag=false;
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(onclicked()));
	//connect(ui.spinBox,SIGNAL(editingFinished()),this,SLOT(onclicked()));
}
void Railway::onclicked()
{
	if (flag)//貌似editingFinished这个signal有点小问题。。。会触发两次
		return ;
	flag=true;
	if (ui.spinBox->value()==0)
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("端口不能为0！"));
		msgBox.exec();
		flag=false;
		return;
	}
	if (!ui.lineEdit->text().contains("db"))
	{
		QMessageBox msgBox;
		msgBox.setText(QStringLiteral("请输入合适的数据库名！"));
		msgBox.exec();
		flag=false;
		return;
	}
	qDebug()<<QString("Your assigned port is %1").arg(ui.spinBox->value());
	mainwindow *m=new mainwindow(ui.spinBox->value(),ui.lineEdit->text());
	m->show();
	setVisible(false);
}
Railway::~Railway()
{

}
