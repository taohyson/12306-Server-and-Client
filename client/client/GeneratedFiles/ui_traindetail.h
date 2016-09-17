/********************************************************************************
** Form generated from reading UI file 'traindetail.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINDETAIL_H
#define UI_TRAINDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trainDetail
{
public:
    QLabel *label;
    QTableWidget *detailTable;
    QPushButton *pushButton;

    void setupUi(QWidget *trainDetail)
    {
        if (trainDetail->objectName().isEmpty())
            trainDetail->setObjectName(QStringLiteral("trainDetail"));
        trainDetail->resize(350, 491);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        trainDetail->setFont(font);
        label = new QLabel(trainDetail);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 250, 51));
        label->setAlignment(Qt::AlignCenter);
        detailTable = new QTableWidget(trainDetail);
        if (detailTable->columnCount() < 2)
            detailTable->setColumnCount(2);
        detailTable->setObjectName(QStringLiteral("detailTable"));
        detailTable->setGeometry(QRect(25, 80, 299, 331));
        detailTable->setMinimumSize(QSize(0, 0));
        detailTable->setMaximumSize(QSize(3000, 4500));
        detailTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        detailTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        detailTable->setAlternatingRowColors(true);
        detailTable->setSelectionMode(QAbstractItemView::SingleSelection);
        detailTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        detailTable->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        detailTable->setColumnCount(2);
        detailTable->horizontalHeader()->setCascadingSectionResizes(false);
        detailTable->horizontalHeader()->setStretchLastSection(true);
        pushButton = new QPushButton(trainDetail);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 430, 111, 41));

        retranslateUi(trainDetail);
        QObject::connect(pushButton, SIGNAL(clicked()), trainDetail, SLOT(close()));

        QMetaObject::connectSlotsByName(trainDetail);
    } // setupUi

    void retranslateUi(QWidget *trainDetail)
    {
        trainDetail->setWindowTitle(QApplication::translate("trainDetail", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("trainDetail", "XXX\346\254\241\345\210\227\350\275\246\350\277\220\350\241\214\346\227\266\345\210\273\350\241\250", 0));
        pushButton->setText(QApplication::translate("trainDetail", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class trainDetail: public Ui_trainDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINDETAIL_H
