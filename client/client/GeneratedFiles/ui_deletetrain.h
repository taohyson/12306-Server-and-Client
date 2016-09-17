/********************************************************************************
** Form generated from reading UI file 'deletetrain.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETETRAIN_H
#define UI_DELETETRAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteWindow
{
public:
    QLabel *label_2;
    QLabel *msg;
    QPushButton *bDeletePer;
    QPushButton *bDeleteTem;
    QPushButton *bCancel;
    QLabel *label;
    QSpinBox *sDaysCnt;
    QLabel *label_8;

    void setupUi(QWidget *deleteWindow)
    {
        if (deleteWindow->objectName().isEmpty())
            deleteWindow->setObjectName(QStringLiteral("deleteWindow"));
        deleteWindow->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        deleteWindow->setFont(font);
        label_2 = new QLabel(deleteWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 40, 200, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        msg = new QLabel(deleteWindow);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(60, 80, 271, 61));
        QFont font2;
        font2.setPointSize(10);
        msg->setFont(font2);
        msg->setWordWrap(true);
        bDeletePer = new QPushButton(deleteWindow);
        bDeletePer->setObjectName(QStringLiteral("bDeletePer"));
        bDeletePer->setGeometry(QRect(30, 200, 100, 28));
        bDeleteTem = new QPushButton(deleteWindow);
        bDeleteTem->setObjectName(QStringLiteral("bDeleteTem"));
        bDeleteTem->setGeometry(QRect(150, 200, 100, 28));
        bCancel = new QPushButton(deleteWindow);
        bCancel->setObjectName(QStringLiteral("bCancel"));
        bCancel->setGeometry(QRect(270, 200, 100, 28));
        label = new QLabel(deleteWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 240, 361, 41));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        sDaysCnt = new QSpinBox(deleteWindow);
        sDaysCnt->setObjectName(QStringLiteral("sDaysCnt"));
        sDaysCnt->setEnabled(true);
        sDaysCnt->setGeometry(QRect(190, 160, 111, 21));
        sDaysCnt->setMinimum(1);
        sDaysCnt->setMaximum(10);
        sDaysCnt->setValue(1);
        label_8 = new QLabel(deleteWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(81, 160, 101, 20));

        retranslateUi(deleteWindow);

        QMetaObject::connectSlotsByName(deleteWindow);
    } // setupUi

    void retranslateUi(QWidget *deleteWindow)
    {
        deleteWindow->setWindowTitle(QApplication::translate("deleteWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("deleteWindow", "\345\210\240\351\231\244\345\210\227\350\275\246", 0));
        msg->setText(QApplication::translate("deleteWindow", "TextLabel", 0));
        bDeletePer->setText(QApplication::translate("deleteWindow", "\346\260\270\344\271\205\345\210\240\351\231\244", 0));
        bDeleteTem->setText(QApplication::translate("deleteWindow", "\344\270\264\346\227\266\345\210\240\351\231\244", 0));
        bCancel->setText(QApplication::translate("deleteWindow", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("deleteWindow", "\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\345\210\240\351\231\244\345\244\232\346\227\245\347\232\204\345\210\227\350\275\246\345\260\206\351\200\240\346\210\220\344\270\215\345\217\257\351\242\204\347\237\245\347\232\204\345\220\216\346\236\234\357\274\201", 0));
        label_8->setText(QApplication::translate("deleteWindow", "\344\270\264\346\227\266\345\210\240\351\231\244\345\244\251\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class deleteWindow: public Ui_deleteWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETETRAIN_H
