/********************************************************************************
** Form generated from reading UI file 'railway.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAILWAY_H
#define UI_RAILWAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RailwayClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RailwayClass)
    {
        if (RailwayClass->objectName().isEmpty())
            RailwayClass->setObjectName(QStringLiteral("RailwayClass"));
        RailwayClass->resize(371, 384);
        centralWidget = new QWidget(RailwayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(15);
        spinBox->setFont(font2);
        spinBox->setMaximum(9999);
        spinBox->setSingleStep(100);
        spinBox->setValue(1234);

        horizontalLayout->addWidget(spinBox);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 2, 1, 2, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_2->addWidget(label_4);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font3.setPointSize(12);
        lineEdit->setFont(font3);

        horizontalLayout_2->addWidget(lineEdit);


        gridLayout->addWidget(groupBox_2, 3, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy4);
        label->setStyleSheet(QStringLiteral("background-image: url(:/Railway/Resources/head.jpg);"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        RailwayClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RailwayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 371, 23));
        RailwayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RailwayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RailwayClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RailwayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RailwayClass->setStatusBar(statusBar);
        QWidget::setTabOrder(spinBox, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton);

        retranslateUi(RailwayClass);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(RailwayClass);
    } // setupUi

    void retranslateUi(QMainWindow *RailwayClass)
    {
        RailwayClass->setWindowTitle(QApplication::translate("RailwayClass", "Railway", 0));
        label_2->setText(QApplication::translate("RailwayClass", "\351\223\201\350\267\25712306++\346\234\215\345\212\241\345\231\250", 0));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("RailwayClass", "\347\253\257\345\217\243\345\217\267", 0));
        pushButton->setText(QApplication::translate("RailwayClass", "\345\274\200\345\220\257\346\234\215\345\212\241\345\231\250", 0));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("RailwayClass", "\346\225\260\346\215\256\345\272\223", 0));
        lineEdit->setText(QApplication::translate("RailwayClass", ".//database.db", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RailwayClass: public Ui_RailwayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAILWAY_H
