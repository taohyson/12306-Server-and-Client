#ifndef ADDTEXT_H
#define ADDTEXT_H

#include <QDialog>
#include "ui_addtext.h"

class addText : public QDialog
{
	Q_OBJECT

public:
	addText(QWidget *parent = 0);
	~addText();
	QString getText();
private:
	Ui::addText ui;
};

#endif // ADDTEXT_H
