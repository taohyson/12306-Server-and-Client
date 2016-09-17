/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *lUsername;
    QLineEdit *lPassword;
    QLabel *label;
    QLabel *label_2;
    QPushButton *bLogin;
    QPushButton *bRegister;
    QLabel *background;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(500, 350);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setMinimumSize(QSize(500, 350));
        Login->setMaximumSize(QSize(500, 350));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        Login->setFont(font);
        Login->setStyleSheet(QStringLiteral(""));
        lUsername = new QLineEdit(Login);
        lUsername->setObjectName(QStringLiteral("lUsername"));
        lUsername->setGeometry(QRect(80, 220, 161, 21));
        lUsername->setFont(font);
        lUsername->setStyleSheet(QLatin1String("QLineEdit{\n"
"	background: rgba(255,255,255,60);\n"
"	border: 0px;\n"
"	color: white;\n"
"	border-radius:5px;\n"
"	selection-background-color: rgba(255,255,255,150);\n"
"}"));
        lUsername->setInputMethodHints(Qt::ImhNone);
        lPassword = new QLineEdit(Login);
        lPassword->setObjectName(QStringLiteral("lPassword"));
        lPassword->setGeometry(QRect(80, 250, 161, 21));
        lPassword->setFont(font);
        lPassword->setStyleSheet(QLatin1String("QLineEdit{\n"
"	background: rgba(255,255,255,60);\n"
"	border: 0px;\n"
"	color: white;\n"
"	border-radius:5px;\n"
"	selection-background-color: rgba(87,96,105,150);\n"
"}"));
        lPassword->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhLatinOnly|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        lPassword->setEchoMode(QLineEdit::Password);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-30, 220, 100, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        label->setFont(font1);
        label->setStyleSheet(QLatin1String("QLabel{\n"
"	color: white;\n"
"}"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-30, 250, 100, 21));
        label_2->setFont(font1);
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"	color: white;\n"
"}"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bLogin = new QPushButton(Login);
        bLogin->setObjectName(QStringLiteral("bLogin"));
        bLogin->setGeometry(QRect(20, 290, 100, 40));
        bLogin->setFont(font1);
        bLogin->setStyleSheet(QLatin1String("QPushButton{\n"
"	background:rgba(255,255,255,60);\n"
"	border: 0px;\n"
"	border-radius:5px;\n"
"	color: rgb(255,255, 255);\n"
"	selection-background-color: rgba(255,255,255,50);\n"
"}"));
        bRegister = new QPushButton(Login);
        bRegister->setObjectName(QStringLiteral("bRegister"));
        bRegister->setGeometry(QRect(140, 290, 100, 40));
        bRegister->setFont(font1);
        bRegister->setStyleSheet(QLatin1String("QPushButton{\n"
"	background:rgba(255,255,255,60);\n"
"	border: 0px;\n"
"	border-radius:5px;\n"
"	color: rgb(255,255, 255);\n"
"	selection-background-color: rgba(255,255,255,50);\n"
"}"));
        background = new QLabel(Login);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(-110, -150, 900, 550));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        background->setFont(font2);
        background->setPixmap(QPixmap(QString::fromUtf8(":/Resources/train3.gif")));
        background->setScaledContents(true);
        background->raise();
        lUsername->raise();
        lPassword->raise();
        label->raise();
        label_2->raise();
        bLogin->raise();
        bRegister->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("Login", "\347\224\250\346\210\267\345\220\215", 0));
        label_2->setText(QApplication::translate("Login", "\345\257\206\347\240\201", 0));
        bLogin->setText(QApplication::translate("Login", "\347\231\273\345\275\225", 0));
        bRegister->setText(QApplication::translate("Login", "\346\263\250\345\206\214", 0));
        background->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
