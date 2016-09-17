#include "addtext.h"

addText::addText(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}
QString addText::getText()
{
	return ui.lineEdit->text().trimmed();
}
addText::~addText()
{

}
