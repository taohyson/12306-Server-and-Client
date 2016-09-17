/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QLineEdit *lUsername;
    QLabel *label_2;
    QLineEdit *lPassword;
    QLabel *label_3;
    QLineEdit *lPassword2;
    QLabel *label_4;
    QLineEdit *lName;
    QLabel *label_5;
    QComboBox *cGender;
    QLabel *label_6;
    QDateEdit *dBirthday;
    QLabel *label_7;
    QComboBox *cCountry;
    QLabel *label_8;
    QLineEdit *lID;
    QLabel *label_9;
    QLineEdit *lPhone;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *cTType;
    QLabel *label_13;
    QLineEdit *lSchoolName;
    QLineEdit *lSchoolID;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *bRegister;
    QPushButton *bCancel;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QStringLiteral("Register"));
        Register->resize(469, 640);
        label = new QLabel(Register);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 150, 72, 15));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        label->setFont(font);
        lUsername = new QLineEdit(Register);
        lUsername->setObjectName(QStringLiteral("lUsername"));
        lUsername->setGeometry(QRect(180, 150, 191, 21));
        lUsername->setFont(font);
        label_2 = new QLabel(Register);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 180, 72, 15));
        label_2->setFont(font);
        lPassword = new QLineEdit(Register);
        lPassword->setObjectName(QStringLiteral("lPassword"));
        lPassword->setGeometry(QRect(180, 180, 191, 21));
        lPassword->setFont(font);
        lPassword->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(Register);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 210, 72, 15));
        label_3->setFont(font);
        lPassword2 = new QLineEdit(Register);
        lPassword2->setObjectName(QStringLiteral("lPassword2"));
        lPassword2->setGeometry(QRect(180, 210, 191, 21));
        lPassword2->setFont(font);
        lPassword2->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(Register);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 240, 72, 15));
        label_4->setFont(font);
        lName = new QLineEdit(Register);
        lName->setObjectName(QStringLiteral("lName"));
        lName->setGeometry(QRect(180, 240, 191, 21));
        lName->setFont(font);
        label_5 = new QLabel(Register);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(80, 270, 72, 15));
        label_5->setFont(font);
        cGender = new QComboBox(Register);
        cGender->setObjectName(QStringLiteral("cGender"));
        cGender->setGeometry(QRect(180, 270, 71, 22));
        cGender->setFont(font);
        label_6 = new QLabel(Register);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(80, 300, 72, 15));
        label_6->setFont(font);
        dBirthday = new QDateEdit(Register);
        dBirthday->setObjectName(QStringLiteral("dBirthday"));
        dBirthday->setGeometry(QRect(180, 300, 110, 22));
        dBirthday->setFont(font);
        dBirthday->setCalendarPopup(true);
        label_7 = new QLabel(Register);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(80, 330, 72, 15));
        label_7->setFont(font);
        cCountry = new QComboBox(Register);
        cCountry->setObjectName(QStringLiteral("cCountry"));
        cCountry->setGeometry(QRect(180, 330, 151, 22));
        cCountry->setFont(font);
        label_8 = new QLabel(Register);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 360, 72, 15));
        label_8->setFont(font);
        lID = new QLineEdit(Register);
        lID->setObjectName(QStringLiteral("lID"));
        lID->setGeometry(QRect(180, 360, 191, 21));
        lID->setFont(font);
        label_9 = new QLabel(Register);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(80, 390, 72, 15));
        label_9->setFont(font);
        lPhone = new QLineEdit(Register);
        lPhone->setObjectName(QStringLiteral("lPhone"));
        lPhone->setGeometry(QRect(180, 390, 191, 21));
        lPhone->setFont(font);
        label_10 = new QLabel(Register);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(80, 110, 91, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        label_10->setFont(font1);
        label_11 = new QLabel(Register);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(80, 430, 91, 21));
        label_11->setFont(font1);
        label_12 = new QLabel(Register);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(80, 470, 72, 15));
        label_12->setFont(font);
        cTType = new QComboBox(Register);
        cTType->setObjectName(QStringLiteral("cTType"));
        cTType->setGeometry(QRect(180, 470, 121, 22));
        cTType->setFont(font);
        label_13 = new QLabel(Register);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(80, 500, 72, 15));
        label_13->setFont(font);
        lSchoolName = new QLineEdit(Register);
        lSchoolName->setObjectName(QStringLiteral("lSchoolName"));
        lSchoolName->setEnabled(false);
        lSchoolName->setGeometry(QRect(180, 500, 191, 21));
        lSchoolName->setFont(font);
        lSchoolID = new QLineEdit(Register);
        lSchoolID->setObjectName(QStringLiteral("lSchoolID"));
        lSchoolID->setEnabled(false);
        lSchoolID->setGeometry(QRect(180, 530, 191, 21));
        lSchoolID->setFont(font);
        label_14 = new QLabel(Register);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(80, 530, 72, 15));
        label_14->setFont(font);
        label_15 = new QLabel(Register);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(190, 40, 101, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(15);
        label_15->setFont(font2);
        bRegister = new QPushButton(Register);
        bRegister->setObjectName(QStringLiteral("bRegister"));
        bRegister->setGeometry(QRect(130, 580, 93, 28));
        bRegister->setFont(font);
        bCancel = new QPushButton(Register);
        bCancel->setObjectName(QStringLiteral("bCancel"));
        bCancel->setGeometry(QRect(250, 580, 93, 28));
        bCancel->setFont(font);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("Register", "\347\224\250\346\210\267\345\220\215", 0));
        label_2->setText(QApplication::translate("Register", "\345\257\206\347\240\201", 0));
        label_3->setText(QApplication::translate("Register", "\345\257\206\347\240\201\347\241\256\350\256\244", 0));
        label_4->setText(QApplication::translate("Register", "\345\247\223\345\220\215", 0));
        label_5->setText(QApplication::translate("Register", "\346\200\247\345\210\253", 0));
        cGender->clear();
        cGender->insertItems(0, QStringList()
         << QApplication::translate("Register", "\347\224\267", 0)
         << QApplication::translate("Register", "\345\245\263", 0)
        );
        label_6->setText(QApplication::translate("Register", "\345\207\272\347\224\237\346\227\245\346\234\237", 0));
        label_7->setText(QApplication::translate("Register", "\345\233\275\345\256\266/\345\234\260\345\214\272", 0));
        cCountry->clear();
        cCountry->insertItems(0, QStringList()
         << QApplication::translate("Register", "\344\270\255\345\233\275", 0)
         << QApplication::translate("Register", "\345\205\266\344\273\226\345\233\275\345\256\266", 0)
        );
        label_8->setText(QApplication::translate("Register", "\350\272\253\344\273\275\350\257\201\345\217\267", 0));
        label_9->setText(QApplication::translate("Register", "\346\211\213\346\234\272\345\217\267\347\240\201", 0));
        label_10->setText(QApplication::translate("Register", "\345\237\272\346\234\254\344\277\241\346\201\257", 0));
        label_11->setText(QApplication::translate("Register", "\351\231\204\345\212\240\344\277\241\346\201\257", 0));
        label_12->setText(QApplication::translate("Register", "\346\227\205\345\256\242\347\261\273\345\236\213", 0));
        cTType->clear();
        cTType->insertItems(0, QStringList()
         << QApplication::translate("Register", "\346\210\220\344\272\272\357\274\210\351\273\230\350\256\244\357\274\211", 0)
         << QApplication::translate("Register", "\345\255\246\347\224\237", 0)
        );
        label_13->setText(QApplication::translate("Register", "\345\255\246\346\240\241\345\220\215\347\247\260", 0));
        label_14->setText(QApplication::translate("Register", "\345\255\246\345\217\267", 0));
        label_15->setText(QApplication::translate("Register", "\347\224\250\346\210\267\346\263\250\345\206\214", 0));
        bRegister->setText(QApplication::translate("Register", "\346\263\250\345\206\214", 0));
        bCancel->setText(QApplication::translate("Register", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
