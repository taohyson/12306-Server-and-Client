#include "connectwindow.h"
#include "client.h"
#include <QtWidgets/QApplication>
#include <qstring.h>
#include <qstylefactory.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setStyle("Fusion");
	Client client;
	ConnectWindow w(&client);
	w.show();
	return a.exec();
}
