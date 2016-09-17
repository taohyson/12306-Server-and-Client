/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QGridLayout *gridLayout;
    QTableWidget *LogTableWidget;
    QTableWidget *userTableWidget;
    QPushButton *sendButton;
    QPushButton *UserInfoButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName(QStringLiteral("mainwindow"));
        mainwindow->resize(928, 527);
        mainwindow->setStyleSheet(QLatin1String("border-image: url(:/Resources/font.jpg);\n"
"\n"
""));
        gridLayout = new QGridLayout(mainwindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        LogTableWidget = new QTableWidget(mainwindow);
        if (LogTableWidget->columnCount() < 2)
            LogTableWidget->setColumnCount(2);
        if (LogTableWidget->rowCount() < 100)
            LogTableWidget->setRowCount(100);
        LogTableWidget->setObjectName(QStringLiteral("LogTableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LogTableWidget->sizePolicy().hasHeightForWidth());
        LogTableWidget->setSizePolicy(sizePolicy);
        LogTableWidget->setStyleSheet(QLatin1String("QTableWidget{ gridline-color : rgba(255, 255, 255, 0)}\n"
""));
        LogTableWidget->setLineWidth(0);
        LogTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        LogTableWidget->setAlternatingRowColors(true);
        LogTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        LogTableWidget->setShowGrid(false);
        LogTableWidget->setGridStyle(Qt::NoPen);
        LogTableWidget->setRowCount(100);
        LogTableWidget->setColumnCount(2);

        gridLayout->addWidget(LogTableWidget, 0, 0, 2, 1);

        userTableWidget = new QTableWidget(mainwindow);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        if (userTableWidget->rowCount() < 20)
            userTableWidget->setRowCount(20);
        userTableWidget->setObjectName(QStringLiteral("userTableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(userTableWidget->sizePolicy().hasHeightForWidth());
        userTableWidget->setSizePolicy(sizePolicy1);
        userTableWidget->setMinimumSize(QSize(350, 0));
        userTableWidget->setGridStyle(Qt::DashDotDotLine);
        userTableWidget->setRowCount(20);
        userTableWidget->setColumnCount(3);

        gridLayout->addWidget(userTableWidget, 0, 1, 1, 3);

        sendButton = new QPushButton(mainwindow);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        sendButton->setFont(font);
        sendButton->setStyleSheet(QLatin1String(":hover{\n"
"	background-color: rgb(0, 0, 255);\n"
"}"));

        gridLayout->addWidget(sendButton, 1, 1, 1, 1);

        UserInfoButton = new QPushButton(mainwindow);
        UserInfoButton->setObjectName(QStringLiteral("UserInfoButton"));
        UserInfoButton->setEnabled(true);
        UserInfoButton->setFont(font);

        gridLayout->addWidget(UserInfoButton, 1, 2, 1, 1);

        deleteButton = new QPushButton(mainwindow);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setFont(font);
        deleteButton->setStyleSheet(QLatin1String(":hover{\n"
"	background-color:rgb(255, 0, 0);\n"
"}"));

        gridLayout->addWidget(deleteButton, 1, 3, 1, 1);


        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QApplication::translate("mainwindow", "\351\223\201\350\267\25712306++", 0));
        sendButton->setText(QApplication::translate("mainwindow", "send message", 0));
        UserInfoButton->setText(QApplication::translate("mainwindow", "user info", 0));
        deleteButton->setText(QApplication::translate("mainwindow", "delete user", 0));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
