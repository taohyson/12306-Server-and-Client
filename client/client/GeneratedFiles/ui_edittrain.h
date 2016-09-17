/********************************************************************************
** Form generated from reading UI file 'edittrain.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTRAIN_H
#define UI_EDITTRAIN_H

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

class Ui_editTrainWindow
{
public:
    QPushButton *bCancel;
    QLabel *label_2;
    QPushButton *bEditPer;
    QLabel *label;
    QLabel *label_4;
    QSpinBox *sStationCnt;
    QTableWidget *stationTable;
    QLabel *label_7;
    QLineEdit *lTrainName;
    QComboBox *cSeatType;
    QDateEdit *dStartDate;
    QLabel *label_3;
    QPushButton *bEditTep;
    QLabel *label_8;
    QSpinBox *sDaysCnt;

    void setupUi(QWidget *editTrainWindow)
    {
        if (editTrainWindow->objectName().isEmpty())
            editTrainWindow->setObjectName(QStringLiteral("editTrainWindow"));
        editTrainWindow->resize(400, 611);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        editTrainWindow->setFont(font);
        editTrainWindow->setContextMenuPolicy(Qt::DefaultContextMenu);
        bCancel = new QPushButton(editTrainWindow);
        bCancel->setObjectName(QStringLiteral("bCancel"));
        bCancel->setGeometry(QRect(270, 550, 100, 31));
        label_2 = new QLabel(editTrainWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 40, 200, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        bEditPer = new QPushButton(editTrainWindow);
        bEditPer->setObjectName(QStringLiteral("bEditPer"));
        bEditPer->setGeometry(QRect(30, 550, 100, 31));
        label = new QLabel(editTrainWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 90, 72, 15));
        label_4 = new QLabel(editTrainWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 210, 72, 15));
        sStationCnt = new QSpinBox(editTrainWindow);
        sStationCnt->setObjectName(QStringLiteral("sStationCnt"));
        sStationCnt->setEnabled(false);
        sStationCnt->setGeometry(QRect(140, 210, 111, 21));
        sStationCnt->setMinimum(2);
        sStationCnt->setMaximum(20);
        stationTable = new QTableWidget(editTrainWindow);
        stationTable->setObjectName(QStringLiteral("stationTable"));
        stationTable->setGeometry(QRect(20, 240, 361, 281));
        stationTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        stationTable->setSelectionMode(QAbstractItemView::NoSelection);
        stationTable->horizontalHeader()->setStretchLastSection(true);
        label_7 = new QLabel(editTrainWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 180, 72, 15));
        lTrainName = new QLineEdit(editTrainWindow);
        lTrainName->setObjectName(QStringLiteral("lTrainName"));
        lTrainName->setEnabled(false);
        lTrainName->setGeometry(QRect(140, 90, 171, 21));
        cSeatType = new QComboBox(editTrainWindow);
        cSeatType->setObjectName(QStringLiteral("cSeatType"));
        cSeatType->setGeometry(QRect(140, 180, 111, 22));
        dStartDate = new QDateEdit(editTrainWindow);
        dStartDate->setObjectName(QStringLiteral("dStartDate"));
        dStartDate->setEnabled(false);
        dStartDate->setGeometry(QRect(140, 120, 110, 22));
        dStartDate->setDateTime(QDateTime(QDate(2016, 9, 12), QTime(0, 0, 0)));
        label_3 = new QLabel(editTrainWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 120, 72, 15));
        bEditTep = new QPushButton(editTrainWindow);
        bEditTep->setObjectName(QStringLiteral("bEditTep"));
        bEditTep->setGeometry(QRect(150, 550, 100, 31));
        label_8 = new QLabel(editTrainWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 150, 91, 16));
        sDaysCnt = new QSpinBox(editTrainWindow);
        sDaysCnt->setObjectName(QStringLiteral("sDaysCnt"));
        sDaysCnt->setEnabled(true);
        sDaysCnt->setGeometry(QRect(160, 150, 91, 21));
        sDaysCnt->setMinimum(1);
        sDaysCnt->setMaximum(10);
        sDaysCnt->setValue(1);

        retranslateUi(editTrainWindow);
        QObject::connect(bCancel, SIGNAL(clicked()), editTrainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(editTrainWindow);
    } // setupUi

    void retranslateUi(QWidget *editTrainWindow)
    {
        editTrainWindow->setWindowTitle(QApplication::translate("editTrainWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        bCancel->setText(QApplication::translate("editTrainWindow", "\345\217\226\346\266\210", 0));
        label_2->setText(QApplication::translate("editTrainWindow", "\344\277\256\346\224\271\345\210\227\350\275\246\344\277\241\346\201\257", 0));
        bEditPer->setText(QApplication::translate("editTrainWindow", "\346\260\270\344\271\205\344\277\256\346\224\271", 0));
        label->setText(QApplication::translate("editTrainWindow", "\345\210\227\350\275\246\345\220\215\347\247\260", 0));
        label_4->setText(QApplication::translate("editTrainWindow", "\347\253\231\347\202\271\344\270\252\346\225\260", 0));
        label_7->setText(QApplication::translate("editTrainWindow", "\345\270\255\344\275\215\347\261\273\345\236\213", 0));
        cSeatType->clear();
        cSeatType->insertItems(0, QStringList()
         << QApplication::translate("editTrainWindow", "\345\235\220\351\223\272", 0)
         << QApplication::translate("editTrainWindow", "\345\215\247\351\223\272", 0)
        );
        label_3->setText(QApplication::translate("editTrainWindow", "\344\277\256\346\224\271\346\227\245\346\234\237", 0));
        bEditTep->setText(QApplication::translate("editTrainWindow", "\344\270\264\346\227\266\344\277\256\346\224\271", 0));
        label_8->setText(QApplication::translate("editTrainWindow", "\344\270\264\346\227\266\344\277\256\346\224\271\345\244\251\346\225\260", 0));
    } // retranslateUi

};

namespace Ui {
    class editTrainWindow: public Ui_editTrainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTRAIN_H
