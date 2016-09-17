/********************************************************************************
** Form generated from reading UI file 'connect.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECT_H
#define UI_CONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_connect
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lIP;
    QLabel *label_3;
    QPushButton *bSubmit;
    QPushButton *bExit;
    QSpinBox *sPort;
    QLabel *background;

    void setupUi(QWidget *connect)
    {
        if (connect->objectName().isEmpty())
            connect->setObjectName(QStringLiteral("connect"));
        connect->resize(400, 225);
        connect->setMinimumSize(QSize(400, 225));
        connect->setMaximumSize(QSize(400, 225));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        connect->setFont(font);
        label = new QLabel(connect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 40, 241, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("QLabel{\n"
"	color : rgba(80,80,80,150);\n"
"}"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(connect);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 100, 80, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(10);
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"	color : rgba(60,60,60,150);\n"
"}"));
        label_2->setAlignment(Qt::AlignCenter);
        lIP = new QLineEdit(connect);
        lIP->setObjectName(QStringLiteral("lIP"));
        lIP->setGeometry(QRect(110, 100, 111, 21));
        lIP->setFont(font2);
        lIP->setStyleSheet(QLatin1String("QLineEdit{\n"
"	background: rgba(60,60,60,60);\n"
"	border: 0px;\n"
"	color: white;\n"
"	border-radius:5px;\n"
"	selection-background-color: rgba(40,40,40,60);\n"
"}"));
        label_3 = new QLabel(connect);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 130, 80, 21));
        label_3->setFont(font2);
        label_3->setStyleSheet(QLatin1String("QLabel{\n"
"	color : rgba(60,60,60,150);\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        bSubmit = new QPushButton(connect);
        bSubmit->setObjectName(QStringLiteral("bSubmit"));
        bSubmit->setGeometry(QRect(30, 170, 81, 28));
        bSubmit->setFont(font2);
        bSubmit->setStyleSheet(QLatin1String("QPushButton{\n"
"	background: rgba(60,60,60,60);\n"
"	border: 0px;\n"
"	color: white;\n"
"	border-radius:5px;\n"
"}"));
        bExit = new QPushButton(connect);
        bExit->setObjectName(QStringLiteral("bExit"));
        bExit->setGeometry(QRect(130, 170, 81, 28));
        bExit->setFont(font2);
        bExit->setStyleSheet(QLatin1String("QPushButton{\n"
"	background: rgba(60,60,60,60);\n"
"	border: 0px;\n"
"	color: white;\n"
"	border-radius:5px;\n"
"}"));
        sPort = new QSpinBox(connect);
        sPort->setObjectName(QStringLiteral("sPort"));
        sPort->setGeometry(QRect(110, 130, 111, 22));
        sPort->setFont(font2);
        sPort->setStyleSheet(QLatin1String("QSpinBox{\n"
"	background: rgba(60,60,60,60);\n"
"	border: 0px;\n"
"	color: white;\n"
"	border-radius:5px;\n"
"	selection-background-color: rgba(40,40,40,60);\n"
"}"));
        sPort->setMaximum(9999);
        sPort->setValue(1234);
        background = new QLabel(connect);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, -15, 530, 270));
        background->setPixmap(QPixmap(QString::fromUtf8(":/Resources/train2.gif")));
        background->setScaledContents(true);
        background->raise();
        label->raise();
        label_2->raise();
        lIP->raise();
        label_3->raise();
        bSubmit->raise();
        bExit->raise();
        sPort->raise();

        retranslateUi(connect);
        QObject::connect(bExit, SIGNAL(clicked()), connect, SLOT(close()));

        QMetaObject::connectSlotsByName(connect);
    } // setupUi

    void retranslateUi(QWidget *connect)
    {
        connect->setWindowTitle(QApplication::translate("connect", "Form", 0));
        label->setText(QApplication::translate("connect", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("connect", "\346\234\215\345\212\241\345\231\250IP", 0));
        lIP->setText(QApplication::translate("connect", "127.0.0.1", 0));
        label_3->setText(QApplication::translate("connect", "\347\253\257\345\217\243", 0));
        bSubmit->setText(QApplication::translate("connect", "\350\277\236\346\216\245", 0));
        bExit->setText(QApplication::translate("connect", "\351\200\200\345\207\272", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class connect: public Ui_connect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECT_H
