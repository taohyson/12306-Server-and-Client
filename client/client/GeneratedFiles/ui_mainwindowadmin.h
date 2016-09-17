/********************************************************************************
** Form generated from reading UI file 'mainwindowadmin.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWADMIN_H
#define UI_MAINWINDOWADMIN_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *main;
    QWidget *tab;
    QTableWidget *trainTable;
    QPushButton *bEditTrain;
    QPushButton *bDeleteTrain;
    QPushButton *bNewTrain;
    QLabel *label_25;
    QTimeEdit *time2;
    QDateEdit *dDate;
    QLineEdit *lDes;
    QPushButton *bSearch;
    QLabel *label_24;
    QLabel *label_26;
    QTimeEdit *time1;
    QLineEdit *lStart;
    QLabel *label_21;
    QLabel *label_22;
    QComboBox *cType;
    QLabel *label_23;
    QWidget *tab_3;
    QPushButton *bEdit;
    QPushButton *bLogout;
    QPushButton *bExit;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lName;
    QLabel *label_9;
    QLineEdit *lUsername;
    QLineEdit *lPosition;
    QLineEdit *lPassword;
    QLabel *label_15;
    QLineEdit *lPhone;
    QLabel *label_16;
    QLabel *label_19;
    QPushButton *bEditComplete;
    QPushButton *bEditCancel;
    QWidget *tab_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QMainWindow *adminWindow)
    {
        if (adminWindow->objectName().isEmpty())
            adminWindow->setObjectName(QStringLiteral("adminWindow"));
        adminWindow->resize(1000, 589);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        adminWindow->setFont(font);
        adminWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(adminWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        main = new QTabWidget(centralwidget);
        main->setObjectName(QStringLiteral("main"));
        main->setGeometry(QRect(0, 0, 1000, 700));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main->sizePolicy().hasHeightForWidth());
        main->setSizePolicy(sizePolicy);
        main->setFont(font);
        main->setStyleSheet(QLatin1String(" QTabBar::tab {\n"
"  background: rgb(87,96,105);\n"
"  color: white;\n"
"  padding: 20px;\n"
"  width: 300px;\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"  background: rgb(173,195,192);\n"
" }"));
        main->setTabPosition(QTabWidget::North);
        main->setTabShape(QTabWidget::Triangular);
        main->setIconSize(QSize(20, 20));
        main->setElideMode(Qt::ElideNone);
        main->setUsesScrollButtons(false);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        trainTable = new QTableWidget(tab);
        trainTable->setObjectName(QStringLiteral("trainTable"));
        trainTable->setGeometry(QRect(10, 90, 981, 351));
        trainTable->setFont(font);
        trainTable->setFrameShape(QFrame::StyledPanel);
        trainTable->setLineWidth(0);
        trainTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        trainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        trainTable->setAlternatingRowColors(true);
        trainTable->setSelectionMode(QAbstractItemView::SingleSelection);
        trainTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        trainTable->setShowGrid(false);
        trainTable->horizontalHeader()->setStretchLastSection(true);
        bEditTrain = new QPushButton(tab);
        bEditTrain->setObjectName(QStringLiteral("bEditTrain"));
        bEditTrain->setGeometry(QRect(840, 460, 121, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        bEditTrain->setFont(font1);
        bDeleteTrain = new QPushButton(tab);
        bDeleteTrain->setObjectName(QStringLiteral("bDeleteTrain"));
        bDeleteTrain->setGeometry(QRect(710, 460, 121, 41));
        bDeleteTrain->setFont(font1);
        bNewTrain = new QPushButton(tab);
        bNewTrain->setObjectName(QStringLiteral("bNewTrain"));
        bNewTrain->setGeometry(QRect(580, 460, 121, 41));
        bNewTrain->setFont(font1);
        label_25 = new QLabel(tab);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(50, 470, 471, 21));
        label_25->setFont(font);
        time2 = new QTimeEdit(tab);
        time2->setObjectName(QStringLiteral("time2"));
        time2->setGeometry(QRect(650, 30, 61, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(9);
        time2->setFont(font2);
        time2->setTime(QTime(20, 0, 0));
        dDate = new QDateEdit(tab);
        dDate->setObjectName(QStringLiteral("dDate"));
        dDate->setGeometry(QRect(380, 30, 121, 41));
        dDate->setFont(font2);
        dDate->setCurrentSection(QDateTimeEdit::YearSection);
        dDate->setCalendarPopup(true);
        dDate->setDate(QDate(2016, 9, 12));
        lDes = new QLineEdit(tab);
        lDes->setObjectName(QStringLiteral("lDes"));
        lDes->setGeometry(QRect(220, 30, 81, 41));
        lDes->setFont(font2);
        lDes->setAlignment(Qt::AlignCenter);
        bSearch = new QPushButton(tab);
        bSearch->setObjectName(QStringLiteral("bSearch"));
        bSearch->setGeometry(QRect(860, 30, 111, 41));
        bSearch->setFont(font1);
        label_24 = new QLabel(tab);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(510, 40, 81, 21));
        label_24->setFont(font2);
        label_26 = new QLabel(tab);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(720, 40, 81, 21));
        label_26->setFont(font2);
        time1 = new QTimeEdit(tab);
        time1->setObjectName(QStringLiteral("time1"));
        time1->setGeometry(QRect(580, 30, 61, 41));
        time1->setFont(font2);
        time1->setTime(QTime(8, 0, 0));
        lStart = new QLineEdit(tab);
        lStart->setObjectName(QStringLiteral("lStart"));
        lStart->setGeometry(QRect(80, 30, 81, 41));
        lStart->setFont(font2);
        lStart->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(tab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 40, 81, 21));
        label_21->setFont(font2);
        label_22 = new QLabel(tab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(170, 40, 81, 21));
        label_22->setFont(font2);
        cType = new QComboBox(tab);
        cType->setObjectName(QStringLiteral("cType"));
        cType->setGeometry(QRect(790, 30, 61, 41));
        cType->setFont(font2);
        label_23 = new QLabel(tab);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(310, 40, 81, 21));
        label_23->setFont(font2);
        main->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        tab_3->setFont(font3);
        bEdit = new QPushButton(tab_3);
        bEdit->setObjectName(QStringLiteral("bEdit"));
        bEdit->setGeometry(QRect(400, 350, 221, 30));
        bEdit->setFont(font3);
        bLogout = new QPushButton(tab_3);
        bLogout->setObjectName(QStringLiteral("bLogout"));
        bLogout->setGeometry(QRect(400, 400, 100, 30));
        bLogout->setFont(font3);
        bExit = new QPushButton(tab_3);
        bExit->setObjectName(QStringLiteral("bExit"));
        bExit->setGeometry(QRect(520, 400, 100, 30));
        bExit->setFont(font3);
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(360, 190, 72, 15));
        label_6->setFont(font3);
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(360, 160, 72, 15));
        label_7->setFont(font3);
        lName = new QLineEdit(tab_3);
        lName->setObjectName(QStringLiteral("lName"));
        lName->setEnabled(false);
        lName->setGeometry(QRect(460, 190, 191, 21));
        lName->setFont(font3);
        lName->setReadOnly(false);
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(360, 130, 72, 15));
        label_9->setFont(font3);
        lUsername = new QLineEdit(tab_3);
        lUsername->setObjectName(QStringLiteral("lUsername"));
        lUsername->setEnabled(false);
        lUsername->setGeometry(QRect(460, 130, 191, 21));
        lUsername->setFont(font3);
        lUsername->setReadOnly(true);
        lPosition = new QLineEdit(tab_3);
        lPosition->setObjectName(QStringLiteral("lPosition"));
        lPosition->setEnabled(false);
        lPosition->setGeometry(QRect(460, 250, 191, 21));
        lPosition->setFont(font3);
        lPosition->setReadOnly(false);
        lPassword = new QLineEdit(tab_3);
        lPassword->setObjectName(QStringLiteral("lPassword"));
        lPassword->setEnabled(false);
        lPassword->setGeometry(QRect(460, 160, 191, 21));
        lPassword->setFont(font3);
        lPassword->setEchoMode(QLineEdit::Password);
        lPassword->setReadOnly(false);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 220, 72, 15));
        label_15->setFont(font3);
        lPhone = new QLineEdit(tab_3);
        lPhone->setObjectName(QStringLiteral("lPhone"));
        lPhone->setEnabled(false);
        lPhone->setGeometry(QRect(460, 220, 191, 21));
        lPhone->setFont(font3);
        lPhone->setReadOnly(false);
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(360, 250, 72, 15));
        label_16->setFont(font3);
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(360, 90, 91, 21));
        label_19->setFont(font1);
        bEditComplete = new QPushButton(tab_3);
        bEditComplete->setObjectName(QStringLiteral("bEditComplete"));
        bEditComplete->setGeometry(QRect(400, 350, 101, 30));
        bEditComplete->setFont(font3);
        bEditCancel = new QPushButton(tab_3);
        bEditCancel->setObjectName(QStringLiteral("bEditCancel"));
        bEditCancel->setGeometry(QRect(520, 350, 101, 30));
        bEditCancel->setFont(font3);
        main->addTab(tab_3, QString());
        bEditCancel->raise();
        bEditComplete->raise();
        bEdit->raise();
        bLogout->raise();
        bExit->raise();
        label_6->raise();
        label_7->raise();
        lName->raise();
        label_9->raise();
        lUsername->raise();
        lPosition->raise();
        lPassword->raise();
        label_15->raise();
        lPhone->raise();
        label_16->raise();
        label_19->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 120, 300, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(13);
        label->setFont(font4);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(420, 190, 200, 41));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(10);
        label_2->setFont(font5);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 270, 200, 41));
        label_3->setFont(font5);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 320, 300, 41));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 350, 300, 41));
        label_5->setFont(font2);
        label_5->setAlignment(Qt::AlignCenter);
        main->addTab(tab_4, QString());
        adminWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(main, lStart);
        QWidget::setTabOrder(lStart, lDes);
        QWidget::setTabOrder(lDes, dDate);
        QWidget::setTabOrder(dDate, time1);
        QWidget::setTabOrder(time1, time2);
        QWidget::setTabOrder(time2, cType);
        QWidget::setTabOrder(cType, bSearch);
        QWidget::setTabOrder(bSearch, trainTable);
        QWidget::setTabOrder(trainTable, bNewTrain);
        QWidget::setTabOrder(bNewTrain, bDeleteTrain);
        QWidget::setTabOrder(bDeleteTrain, bEditTrain);
        QWidget::setTabOrder(bEditTrain, bEdit);
        QWidget::setTabOrder(bEdit, bLogout);
        QWidget::setTabOrder(bLogout, bExit);
        QWidget::setTabOrder(bExit, lName);
        QWidget::setTabOrder(lName, lUsername);
        QWidget::setTabOrder(lUsername, lPosition);
        QWidget::setTabOrder(lPosition, lPassword);
        QWidget::setTabOrder(lPassword, lPhone);
        QWidget::setTabOrder(lPhone, bEditComplete);
        QWidget::setTabOrder(bEditComplete, bEditCancel);

        retranslateUi(adminWindow);
        QObject::connect(bEdit, SIGNAL(clicked()), bEdit, SLOT(hide()));
        QObject::connect(bEditCancel, SIGNAL(clicked()), bEditComplete, SLOT(hide()));
        QObject::connect(bEdit, SIGNAL(clicked()), bEditComplete, SLOT(show()));
        QObject::connect(bEdit, SIGNAL(clicked()), bEditCancel, SLOT(show()));
        QObject::connect(bEditCancel, SIGNAL(clicked()), bEdit, SLOT(show()));
        QObject::connect(bEditCancel, SIGNAL(clicked()), bEditCancel, SLOT(hide()));

        main->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(adminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *adminWindow)
    {
        adminWindow->setWindowTitle(QApplication::translate("adminWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        bEditTrain->setText(QApplication::translate("adminWindow", "\344\277\256\346\224\271", 0));
        bDeleteTrain->setText(QApplication::translate("adminWindow", "\345\210\240\351\231\244", 0));
        bNewTrain->setText(QApplication::translate("adminWindow", "\346\226\260\345\242\236", 0));
        label_25->setText(QApplication::translate("adminWindow", "\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\350\241\250\344\270\255\347\232\204\345\210\227\350\275\246\345\217\257\346\237\245\347\234\213\351\200\224\347\273\217\350\275\246\347\253\231\344\270\216\345\201\234\347\253\231\346\227\266\351\227\264", 0));
        time2->setDisplayFormat(QApplication::translate("adminWindow", "HH:mm", 0));
        dDate->setDisplayFormat(QApplication::translate("adminWindow", "yyyy/MM/dd", 0));
        bSearch->setText(QApplication::translate("adminWindow", "\346\237\245\350\257\242", 0));
        label_24->setText(QApplication::translate("adminWindow", "\346\227\266\351\227\264\345\214\272\351\227\264", 0));
        label_26->setText(QApplication::translate("adminWindow", "\345\210\227\350\275\246\347\261\273\345\236\213", 0));
        time1->setDisplayFormat(QApplication::translate("adminWindow", "HH:mm", 0));
        label_21->setText(QApplication::translate("adminWindow", "\345\207\272\345\217\221\347\253\231", 0));
        label_22->setText(QApplication::translate("adminWindow", "\345\210\260\350\276\276\347\253\231", 0));
        cType->clear();
        cType->insertItems(0, QStringList()
         << QApplication::translate("adminWindow", "\345\205\250\351\203\250", 0)
         << QApplication::translate("adminWindow", "G", 0)
         << QApplication::translate("adminWindow", "D", 0)
         << QApplication::translate("adminWindow", "T", 0)
         << QApplication::translate("adminWindow", "K", 0)
        );
        label_23->setText(QApplication::translate("adminWindow", "\345\207\272\350\241\214\346\227\245\346\234\237", 0));
        main->setTabText(main->indexOf(tab), QApplication::translate("adminWindow", "\347\273\264\346\212\244\350\275\246\346\254\241", 0));
        bEdit->setText(QApplication::translate("adminWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", 0));
        bLogout->setText(QApplication::translate("adminWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        bExit->setText(QApplication::translate("adminWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
        label_6->setText(QApplication::translate("adminWindow", "\345\247\223\345\220\215", 0));
        label_7->setText(QApplication::translate("adminWindow", "\345\257\206\347\240\201", 0));
        label_9->setText(QApplication::translate("adminWindow", "\347\224\250\346\210\267\345\220\215", 0));
        label_15->setText(QApplication::translate("adminWindow", "\346\211\213\346\234\272\345\217\267\347\240\201", 0));
        label_16->setText(QApplication::translate("adminWindow", "\350\201\214\344\275\215", 0));
        label_19->setText(QApplication::translate("adminWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", 0));
        bEditComplete->setText(QApplication::translate("adminWindow", "\345\256\214\346\210\220", 0));
        bEditCancel->setText(QApplication::translate("adminWindow", "\345\217\226\346\266\210", 0));
        main->setTabText(main->indexOf(tab_3), QApplication::translate("adminWindow", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("adminWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("adminWindow", "C++\347\250\213\345\272\217\350\256\276\350\256\241\344\270\216\350\256\255\347\273\203", 0));
        label_3->setText(QApplication::translate("adminWindow", "\350\256\276\350\256\241\350\200\205", 0));
        label_4->setText(QApplication::translate("adminWindow", "\345\260\271\347\247\213\351\230\263   yinqy15@mails.tsinghua.edu.cn", 0));
        label_5->setText(QApplication::translate("adminWindow", "\345\217\266\346\262\201\345\252\233   yeqy15@mails.tsinghua.edu.cn", 0));
        main->setTabText(main->indexOf(tab_4), QApplication::translate("adminWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
    } // retranslateUi

};

namespace Ui {
    class adminWindow: public Ui_adminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWADMIN_H
