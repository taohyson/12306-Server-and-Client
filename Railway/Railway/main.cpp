#include "railway.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Railway w;
	QApplication::setStyle("Fusion");

	w.show();

	return a.exec();
}
