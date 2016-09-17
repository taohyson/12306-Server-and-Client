/********************************************************************************
** Form generated from reading UI file 'addtrain.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRAIN_H
#define UI_ADDTRAIN_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addTrain
{
public:
    QLabel *label;
    QLineEdit *lTrainName;
    QLabel *label_2;
    QDateEdit *dStartDate;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *sStationCnt;
    QTableWidget *stationTable;
    QPushButton *bSubmit;
    QPushButton *bCancel;
    QLabel *label_5;
    QComboBox *cTrType;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *cSeatType;
    QSpinBox *sDaysCnt;
    QLabel *label_8;

    void setupUi(QWidget *addTrain)
    {
        if (addTrain->objectName().isEmpty())
            addTrain->setObjectName(QStringLiteral("addTrain"));
        addTrain->resize(400, 600);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        addTrain->setFont(font);
        label = new QLabel(addTrain);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 90, 72, 15));
        lTrainName = new QLineEdit(addTrain);
        lTrainName->setObjectName(QStringLiteral("lTrainName"));
        lTrainName->setGeometry(QRect(140, 90, 171, 21));
        label_2 = new QLabel(addTrain);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 40, 200, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        dStartDate = new QDateEdit(addTrain);
        dStartDate->setObjectName(QStringLiteral("dStartDate"));
        dStartDate->setGeometry(QRect(140, 120, 110, 22));
        dStartDate->setDateTime(QDateTime(QDate(2016, 9, 12), QTime(0, 0, 0)));
        label_3 = new QLabel(addTrain);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 120, 72, 15));
        label_4 = new QLabel(addTrain);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 240, 72, 15));
        sStationCnt = new QSpinBox(addTrain);
        sStationCnt->setObjectName(QStringLiteral("sStationCnt"));
        sStationCnt->setGeometry(QRect(140, 240, 111, 21));
        sStationCnt->setMinimum(2);
        sStationCnt->setMaximum(20);
        stationTable = new QTableWidget(addTrain);
        stationTable->setObjectName(QStringLiteral("stationTable"));
        stationTable->setGeometry(QRect(20, 280, 361, 231));
        stationTable->setEditTriggers(QAbstractItemView::AllEditTriggers);
        stationTable->horizontalHeader()->setStretchLastSection(true);
        bSubmit = new QPushButton(addTrain);
        bSubmit->setObjectName(QStringLiteral("bSubmit"));
        bSubmit->setGeometry(QRect(90, 550, 101, 31));
        bCancel = new QPushButton(addTrain);
        bCancel->setObjectName(QStringLiteral("bCancel"));
        bCancel->setGeometry(QRect(210, 550, 101, 31));
        label_5 = new QLabel(addTrain);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 150, 72, 15));
        cTrType = new QComboBox(addTrain);
        cTrType->setObjectName(QStringLiteral("cTrType"));
        cTrType->setGeometry(QRect(140, 150, 111, 22));
        label_6 = new QLabel(addTrain);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 520, 300, 21));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(addTrain);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 210, 72, 15));
        cSeatType = new QComboBox(addTrain);
        cSeatType->setObjectName(QStringLiteral("cSeatType"));
        cSeatType->setGeometry(QRect(140, 210, 111, 22));
        sDaysCnt = new QSpinBox(addTrain);
        sDaysCnt->setObjectName(QStringLiteral("sDaysCnt"));
        sDaysCnt->setEnabled(false);
        sDaysCnt->setGeometry(QRect(140, 180, 111, 21));
        sDaysCnt->setMinimum(1);
        sDaysCnt->setMaximum(10);
        sDaysCnt->setValue(1);
        label_8 = new QLabel(addTrain);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 180, 72, 15));

        retranslateUi(addTrain);

        QMetaObject::connectSlotsByName(addTrain);
    } // setupUi

    void retranslateUi(QWidget *addTrain)
    {
        addTrain->setWindowTitle(QApplication::translate("addTrain", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("addTrain", "\345\210\227\350\275\246\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("addTrain", "\346\267\273\345\212\240\346\226\260\345\210\227\350\275\246", 0));
        label_3->setText(QApplication::translate("addTrain", "\345\247\213\345\217\221\346\227\245\346\234\237", 0));
        label_4->setText(QApplication::translate("addTrain", "\347\253\231\347\202\271\344\270\252\346\225\260", 0));
        bSubmit->setText(QApplication::translate("addTrain", "\347\241\256\350\256\244", 0));
        bCancel->setText(QApplication::translate("addTrain", "\345\217\226\346\266\210", 0));
        label_5->setText(QApplication::translate("addTrain", "\345\210\227\350\275\246\347\261\273\345\236\213", 0));
        cTrType->clear();
        cTrType->insertItems(0, QStringList()
         << QApplication::translate("addTrain", "\345\270\270\350\247\204\345\210\227\350\275\246", 0)
         << QApplication::translate("addTrain", "\344\270\264\346\227\266\345\210\227\350\275\246", 0)
        );
        label_6->setText(QApplication::translate("addTrain", "\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\345\270\270\350\247\204\345\210\227\350\275\246\346\214\211\351\246\226\347\217\255\350\275\246\350\256\276\347\275\256\345\210\260\347\253\231\346\227\266\351\227\264", 0));
        label_7->setText(QApplication::translate("addTrain", "\345\270\255\344\275\215\347\261\273\345\236\213", 0));
        cSeatType->clear();
        cSeatType->insertItems(0, QStringList()
         << QApplication::translate("addTrain", "\345\235\220\351\223\272", 0)
         << QApplication::translate("addTrain", "\345\215\247\351\223\272", 0)
        );
        label_8->setText(QApplication::translate("addTrain", "\345\274\200\350\256\276\345\244\251\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class addTrain: public Ui_addTrain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRAIN_H
