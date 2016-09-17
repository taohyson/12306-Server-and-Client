/********************************************************************************
** Form generated from reading UI file 'buyother.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYOTHER_H
#define UI_BUYOTHER_H

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

class Ui_buyOtherWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lUsername;
    QPushButton *bSubmit;
    QPushButton *bCancel;
    QLabel *label_4;

    void setupUi(QWidget *buyOtherWindow)
    {
        if (buyOtherWindow->objectName().isEmpty())
            buyOtherWindow->setObjectName(QStringLiteral("buyOtherWindow"));
        buyOtherWindow->resize(400, 346);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        buyOtherWindow->setFont(font);
        label = new QLabel(buyOtherWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 40, 100, 21));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(buyOtherWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 100, 300, 61));
        label_2->setWordWrap(true);
        label_3 = new QLabel(buyOtherWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 240, 81, 21));
        lUsername = new QLineEdit(buyOtherWindow);
        lUsername->setObjectName(QStringLiteral("lUsername"));
        lUsername->setGeometry(QRect(180, 240, 130, 21));
        bSubmit = new QPushButton(buyOtherWindow);
        bSubmit->setObjectName(QStringLiteral("bSubmit"));
        bSubmit->setGeometry(QRect(90, 280, 100, 28));
        bCancel = new QPushButton(buyOtherWindow);
        bCancel->setObjectName(QStringLiteral("bCancel"));
        bCancel->setGeometry(QRect(210, 280, 100, 28));
        label_4 = new QLabel(buyOtherWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 170, 300, 61));
        label_4->setWordWrap(true);

        retranslateUi(buyOtherWindow);
        QObject::connect(bCancel, SIGNAL(clicked()), buyOtherWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(buyOtherWindow);
    } // setupUi

    void retranslateUi(QWidget *buyOtherWindow)
    {
        buyOtherWindow->setWindowTitle(QApplication::translate("buyOtherWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("buyOtherWindow", "\344\270\272\344\273\226\344\272\272\344\271\260\347\245\250", 0));
        label_2->setText(QApplication::translate("buyOtherWindow", "TextLabel", 0));
        label_3->setText(QApplication::translate("buyOtherWindow", "\344\271\230\345\256\242\347\224\250\346\210\267\345\220\215", 0));
        bSubmit->setText(QApplication::translate("buyOtherWindow", "\347\241\256\345\256\232", 0));
        bCancel->setText(QApplication::translate("buyOtherWindow", "\345\217\226\346\266\210", 0));
        label_4->setText(QApplication::translate("buyOtherWindow", "\346\263\250\346\204\217\357\274\232\346\202\250\345\217\252\350\203\275\344\270\272\345\267\262\345\234\250\346\234\254\347\263\273\347\273\237\345\206\205\346\263\250\345\206\214\347\232\204\347\224\250\346\210\267\350\264\255\344\271\260\350\275\246\347\245\250\357\274\214\345\271\266\344\270\224\345\217\252\350\203\275\347\224\261\344\271\230\345\256\242\346\234\254\344\272\272\350\277\233\350\241\214\351\200\200\347\245\250\346\223\215\344\275\234\357\274\201", 0));
    } // retranslateUi

};

namespace Ui {
    class buyOtherWindow: public Ui_buyOtherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYOTHER_H
