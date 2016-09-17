/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *main;
    QWidget *tab;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lStart;
    QLineEdit *lDes;
    QLabel *label_23;
    QDateEdit *dDate;
    QPushButton *bSearch;
    QTableWidget *trainTable;
    QPushButton *bBuy;
    QTimeEdit *time1;
    QTimeEdit *time2;
    QLabel *label_24;
    QPushButton *bBuyStudent;
    QLabel *label_25;
    QLabel *label_26;
    QComboBox *cType;
    QPushButton *bBuyOther;
    QLabel *lEmpty;
    QWidget *tab_2;
    QTableWidget *ticketTable;
    QPushButton *bReturn;
    QPushButton *bRefresh;
    QWidget *tab_3;
    QPushButton *bEdit;
    QPushButton *bLogout;
    QPushButton *bExit;
    QLineEdit *lID;
    QLabel *label_6;
    QLineEdit *lSchoolName;
    QComboBox *cGender;
    QComboBox *cTType;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lName;
    QLabel *label_9;
    QLineEdit *lUsername;
    QDateEdit *dBirthday;
    QLineEdit *lSchoolID;
    QLineEdit *lPassword;
    QLabel *label_13;
    QLabel *label_11;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lPhone;
    QLabel *label_16;
    QComboBox *cCountry;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *bEditComplete;
    QLabel *label_10;
    QLabel *label_20;
    QLineEdit *lPay;
    QPushButton *bPay;
    QPushButton *bEditCancel;
    QWidget *tab_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        MainWindow->setMaximumSize(QSize(1000, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        main = new QTabWidget(centralwidget);
        main->setObjectName(QStringLiteral("main"));
        main->setGeometry(QRect(0, 0, 1001, 700));
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
"  width: 210px;\n"
" }\n"
"\n"
" QTabBar::tab:selected {\n"
"  background: rgb(173,195,192);\n"
" }"));
        main->setTabPosition(QTabWidget::North);
        main->setTabShape(QTabWidget::Triangular);
        main->setIconSize(QSize(20, 20));
        main->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label_21 = new QLabel(tab);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 40, 81, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        label_21->setFont(font1);
        label_22 = new QLabel(tab);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(170, 40, 81, 21));
        label_22->setFont(font1);
        lStart = new QLineEdit(tab);
        lStart->setObjectName(QStringLiteral("lStart"));
        lStart->setGeometry(QRect(80, 30, 81, 41));
        lStart->setFont(font1);
        lStart->setAlignment(Qt::AlignCenter);
        lDes = new QLineEdit(tab);
        lDes->setObjectName(QStringLiteral("lDes"));
        lDes->setGeometry(QRect(220, 30, 81, 41));
        lDes->setFont(font1);
        lDes->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(tab);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(310, 40, 81, 21));
        label_23->setFont(font1);
        dDate = new QDateEdit(tab);
        dDate->setObjectName(QStringLiteral("dDate"));
        dDate->setGeometry(QRect(380, 30, 121, 41));
        dDate->setFont(font1);
        dDate->setCurrentSection(QDateTimeEdit::YearSection);
        dDate->setCalendarPopup(true);
        dDate->setDate(QDate(2016, 9, 12));
        bSearch = new QPushButton(tab);
        bSearch->setObjectName(QStringLiteral("bSearch"));
        bSearch->setGeometry(QRect(860, 30, 111, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        bSearch->setFont(font2);
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
        bBuy = new QPushButton(tab);
        bBuy->setObjectName(QStringLiteral("bBuy"));
        bBuy->setGeometry(QRect(850, 460, 121, 41));
        bBuy->setFont(font2);
        time1 = new QTimeEdit(tab);
        time1->setObjectName(QStringLiteral("time1"));
        time1->setGeometry(QRect(580, 30, 61, 41));
        time1->setFont(font1);
        time1->setTime(QTime(8, 0, 0));
        time2 = new QTimeEdit(tab);
        time2->setObjectName(QStringLiteral("time2"));
        time2->setGeometry(QRect(650, 30, 61, 41));
        time2->setFont(font1);
        time2->setTime(QTime(20, 0, 0));
        label_24 = new QLabel(tab);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(510, 40, 81, 21));
        label_24->setFont(font1);
        bBuyStudent = new QPushButton(tab);
        bBuyStudent->setObjectName(QStringLiteral("bBuyStudent"));
        bBuyStudent->setGeometry(QRect(720, 460, 121, 41));
        bBuyStudent->setFont(font2);
        label_25 = new QLabel(tab);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(50, 470, 471, 21));
        label_25->setFont(font);
        label_26 = new QLabel(tab);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(720, 40, 81, 21));
        label_26->setFont(font1);
        cType = new QComboBox(tab);
        cType->setObjectName(QStringLiteral("cType"));
        cType->setGeometry(QRect(790, 30, 61, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        cType->setFont(font3);
        bBuyOther = new QPushButton(tab);
        bBuyOther->setObjectName(QStringLiteral("bBuyOther"));
        bBuyOther->setGeometry(QRect(590, 460, 121, 41));
        bBuyOther->setFont(font2);
        lEmpty = new QLabel(tab);
        lEmpty->setObjectName(QStringLiteral("lEmpty"));
        lEmpty->setGeometry(QRect(350, 100, 300, 91));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(15);
        font4.setItalic(false);
        lEmpty->setFont(font4);
        lEmpty->setStyleSheet(QLatin1String("QLabel {\n"
"	color: rgb(207, 207, 207)\n"
"}"));
        lEmpty->setAlignment(Qt::AlignCenter);
        main->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        ticketTable = new QTableWidget(tab_2);
        ticketTable->setObjectName(QStringLiteral("ticketTable"));
        ticketTable->setGeometry(QRect(10, 10, 981, 451));
        ticketTable->setFont(font);
        ticketTable->setStyleSheet(QStringLiteral("QTableWidget{ gridline-color : rgba(255, 255, 255, 0)}"));
        ticketTable->setFrameShape(QFrame::StyledPanel);
        ticketTable->setFrameShadow(QFrame::Sunken);
        ticketTable->setLineWidth(0);
        ticketTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ticketTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ticketTable->setAutoScroll(true);
        ticketTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ticketTable->setAlternatingRowColors(true);
        ticketTable->setSelectionMode(QAbstractItemView::SingleSelection);
        ticketTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        ticketTable->setShowGrid(false);
        ticketTable->setGridStyle(Qt::NoPen);
        ticketTable->setSortingEnabled(false);
        ticketTable->horizontalHeader()->setVisible(false);
        ticketTable->horizontalHeader()->setStretchLastSection(true);
        ticketTable->verticalHeader()->setVisible(false);
        bReturn = new QPushButton(tab_2);
        bReturn->setObjectName(QStringLiteral("bReturn"));
        bReturn->setGeometry(QRect(760, 470, 101, 41));
        bReturn->setFont(font2);
        bRefresh = new QPushButton(tab_2);
        bRefresh->setObjectName(QStringLiteral("bRefresh"));
        bRefresh->setGeometry(QRect(870, 470, 101, 41));
        bRefresh->setFont(font2);
        main->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tab_3->setFont(font3);
        bEdit = new QPushButton(tab_3);
        bEdit->setObjectName(QStringLiteral("bEdit"));
        bEdit->setGeometry(QRect(520, 370, 151, 30));
        bEdit->setFont(font3);
        bLogout = new QPushButton(tab_3);
        bLogout->setObjectName(QStringLiteral("bLogout"));
        bLogout->setGeometry(QRect(680, 370, 100, 30));
        bLogout->setFont(font3);
        bExit = new QPushButton(tab_3);
        bExit->setObjectName(QStringLiteral("bExit"));
        bExit->setGeometry(QRect(790, 370, 100, 30));
        bExit->setFont(font3);
        lID = new QLineEdit(tab_3);
        lID->setObjectName(QStringLiteral("lID"));
        lID->setEnabled(false);
        lID->setGeometry(QRect(190, 340, 191, 21));
        lID->setFont(font3);
        lID->setReadOnly(false);
        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(90, 220, 72, 15));
        label_6->setFont(font3);
        lSchoolName = new QLineEdit(tab_3);
        lSchoolName->setObjectName(QStringLiteral("lSchoolName"));
        lSchoolName->setEnabled(false);
        lSchoolName->setGeometry(QRect(640, 190, 191, 21));
        lSchoolName->setFont(font3);
        lSchoolName->setReadOnly(false);
        cGender = new QComboBox(tab_3);
        cGender->setObjectName(QStringLiteral("cGender"));
        cGender->setEnabled(false);
        cGender->setGeometry(QRect(190, 250, 71, 22));
        cGender->setFont(font3);
        cGender->setEditable(false);
        cGender->setFrame(true);
        cTType = new QComboBox(tab_3);
        cTType->setObjectName(QStringLiteral("cTType"));
        cTType->setEnabled(false);
        cTType->setGeometry(QRect(640, 160, 121, 22));
        cTType->setFont(font3);
        label_12 = new QLabel(tab_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(540, 160, 72, 15));
        label_12->setFont(font3);
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(90, 190, 72, 15));
        label_7->setFont(font3);
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 310, 72, 15));
        label_8->setFont(font3);
        lName = new QLineEdit(tab_3);
        lName->setObjectName(QStringLiteral("lName"));
        lName->setEnabled(false);
        lName->setGeometry(QRect(190, 220, 191, 21));
        lName->setFont(font3);
        lName->setReadOnly(false);
        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 160, 72, 15));
        label_9->setFont(font3);
        lUsername = new QLineEdit(tab_3);
        lUsername->setObjectName(QStringLiteral("lUsername"));
        lUsername->setEnabled(false);
        lUsername->setGeometry(QRect(190, 160, 191, 21));
        lUsername->setFont(font3);
        lUsername->setReadOnly(true);
        dBirthday = new QDateEdit(tab_3);
        dBirthday->setObjectName(QStringLiteral("dBirthday"));
        dBirthday->setEnabled(false);
        dBirthday->setGeometry(QRect(190, 280, 110, 22));
        dBirthday->setFont(font3);
        dBirthday->setReadOnly(false);
        dBirthday->setCalendarPopup(false);
        lSchoolID = new QLineEdit(tab_3);
        lSchoolID->setObjectName(QStringLiteral("lSchoolID"));
        lSchoolID->setEnabled(false);
        lSchoolID->setGeometry(QRect(640, 220, 191, 21));
        lSchoolID->setFont(font3);
        lSchoolID->setReadOnly(false);
        lPassword = new QLineEdit(tab_3);
        lPassword->setObjectName(QStringLiteral("lPassword"));
        lPassword->setEnabled(false);
        lPassword->setGeometry(QRect(190, 190, 191, 21));
        lPassword->setFont(font3);
        lPassword->setEchoMode(QLineEdit::Password);
        lPassword->setReadOnly(false);
        label_13 = new QLabel(tab_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(540, 190, 72, 15));
        label_13->setFont(font3);
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(90, 340, 72, 15));
        label_11->setFont(font3);
        label_14 = new QLabel(tab_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 250, 72, 15));
        label_14->setFont(font3);
        label_15 = new QLabel(tab_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(90, 370, 72, 15));
        label_15->setFont(font3);
        lPhone = new QLineEdit(tab_3);
        lPhone->setObjectName(QStringLiteral("lPhone"));
        lPhone->setEnabled(false);
        lPhone->setGeometry(QRect(190, 370, 191, 21));
        lPhone->setFont(font3);
        lPhone->setReadOnly(false);
        label_16 = new QLabel(tab_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(540, 220, 72, 15));
        label_16->setFont(font3);
        cCountry = new QComboBox(tab_3);
        cCountry->setObjectName(QStringLiteral("cCountry"));
        cCountry->setEnabled(false);
        cCountry->setGeometry(QRect(190, 310, 151, 22));
        cCountry->setFont(font3);
        label_17 = new QLabel(tab_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(540, 120, 91, 21));
        label_17->setFont(font2);
        label_18 = new QLabel(tab_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(90, 280, 72, 15));
        label_18->setFont(font3);
        label_19 = new QLabel(tab_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(90, 120, 91, 21));
        label_19->setFont(font2);
        bEditComplete = new QPushButton(tab_3);
        bEditComplete->setObjectName(QStringLiteral("bEditComplete"));
        bEditComplete->setGeometry(QRect(520, 370, 71, 30));
        bEditComplete->setFont(font3);
        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(540, 260, 81, 21));
        label_10->setFont(font2);
        label_20 = new QLabel(tab_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(540, 300, 72, 15));
        label_20->setFont(font3);
        lPay = new QLineEdit(tab_3);
        lPay->setObjectName(QStringLiteral("lPay"));
        lPay->setEnabled(false);
        lPay->setGeometry(QRect(640, 300, 101, 21));
        lPay->setFont(font3);
        bPay = new QPushButton(tab_3);
        bPay->setObjectName(QStringLiteral("bPay"));
        bPay->setGeometry(QRect(770, 300, 93, 28));
        bPay->setFont(font3);
        bEditCancel = new QPushButton(tab_3);
        bEditCancel->setObjectName(QStringLiteral("bEditCancel"));
        bEditCancel->setGeometry(QRect(600, 370, 71, 30));
        bEditCancel->setFont(font3);
        main->addTab(tab_3, QString());
        bEditCancel->raise();
        bEditComplete->raise();
        bEdit->raise();
        bLogout->raise();
        bExit->raise();
        lID->raise();
        label_6->raise();
        lSchoolName->raise();
        cGender->raise();
        cTType->raise();
        label_12->raise();
        label_7->raise();
        label_8->raise();
        lName->raise();
        label_9->raise();
        lUsername->raise();
        dBirthday->raise();
        lSchoolID->raise();
        lPassword->raise();
        label_13->raise();
        label_11->raise();
        label_14->raise();
        label_15->raise();
        lPhone->raise();
        label_16->raise();
        cCountry->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        label_10->raise();
        label_20->raise();
        lPay->raise();
        bPay->raise();
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 120, 300, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(13);
        label->setFont(font5);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 190, 200, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font6.setPointSize(10);
        label_2->setFont(font6);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(390, 270, 200, 41));
        label_3->setFont(font6);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(340, 320, 300, 41));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(340, 350, 300, 41));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        main->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(main, lStart);
        QWidget::setTabOrder(lStart, lDes);
        QWidget::setTabOrder(lDes, dDate);
        QWidget::setTabOrder(dDate, time1);
        QWidget::setTabOrder(time1, time2);
        QWidget::setTabOrder(time2, cType);
        QWidget::setTabOrder(cType, bSearch);
        QWidget::setTabOrder(bSearch, trainTable);
        QWidget::setTabOrder(trainTable, bBuyOther);
        QWidget::setTabOrder(bBuyOther, bBuyStudent);
        QWidget::setTabOrder(bBuyStudent, bBuy);
        QWidget::setTabOrder(bBuy, ticketTable);
        QWidget::setTabOrder(ticketTable, bReturn);
        QWidget::setTabOrder(bReturn, bRefresh);
        QWidget::setTabOrder(bRefresh, bEdit);
        QWidget::setTabOrder(bEdit, bLogout);
        QWidget::setTabOrder(bLogout, bExit);
        QWidget::setTabOrder(bExit, lID);
        QWidget::setTabOrder(lID, lSchoolName);
        QWidget::setTabOrder(lSchoolName, cGender);
        QWidget::setTabOrder(cGender, cTType);
        QWidget::setTabOrder(cTType, lName);
        QWidget::setTabOrder(lName, lUsername);
        QWidget::setTabOrder(lUsername, dBirthday);
        QWidget::setTabOrder(dBirthday, lSchoolID);
        QWidget::setTabOrder(lSchoolID, lPassword);
        QWidget::setTabOrder(lPassword, lPhone);
        QWidget::setTabOrder(lPhone, cCountry);
        QWidget::setTabOrder(cCountry, bEditComplete);
        QWidget::setTabOrder(bEditComplete, lPay);
        QWidget::setTabOrder(lPay, bPay);
        QWidget::setTabOrder(bPay, bEditCancel);

        retranslateUi(MainWindow);
        QObject::connect(bEdit, SIGNAL(clicked()), bEdit, SLOT(hide()));
        QObject::connect(bEdit, SIGNAL(clicked()), bEditComplete, SLOT(show()));
        QObject::connect(bEdit, SIGNAL(clicked()), bEditCancel, SLOT(show()));
        QObject::connect(bEditCancel, SIGNAL(clicked()), bEditCancel, SLOT(hide()));
        QObject::connect(bEditCancel, SIGNAL(clicked()), bEditComplete, SLOT(hide()));
        QObject::connect(bEditCancel, SIGNAL(clicked()), bEdit, SLOT(show()));

        main->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label_21->setText(QApplication::translate("MainWindow", "\345\207\272\345\217\221\347\253\231", 0));
        label_22->setText(QApplication::translate("MainWindow", "\345\210\260\350\276\276\347\253\231", 0));
        label_23->setText(QApplication::translate("MainWindow", "\345\207\272\350\241\214\346\227\245\346\234\237", 0));
        dDate->setDisplayFormat(QApplication::translate("MainWindow", "yyyy/MM/dd", 0));
        bSearch->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", 0));
        bBuy->setText(QApplication::translate("MainWindow", "\350\264\255\344\271\260", 0));
        time1->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm", 0));
        time2->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm", 0));
        label_24->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\345\214\272\351\227\264", 0));
        bBuyStudent->setText(QApplication::translate("MainWindow", "\350\264\255\344\271\260\345\255\246\347\224\237\347\245\250", 0));
        label_25->setText(QApplication::translate("MainWindow", "\346\270\251\351\246\250\346\217\220\347\244\272\357\274\232\345\217\214\345\207\273\350\241\250\344\270\255\347\232\204\345\210\227\350\275\246\345\217\257\346\237\245\347\234\213\351\200\224\347\273\217\350\275\246\347\253\231\344\270\216\345\201\234\347\253\231\346\227\266\351\227\264", 0));
        label_26->setText(QApplication::translate("MainWindow", "\345\210\227\350\275\246\347\261\273\345\236\213", 0));
        cType->clear();
        cType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\205\250\351\203\250", 0)
         << QApplication::translate("MainWindow", "G", 0)
         << QApplication::translate("MainWindow", "D", 0)
         << QApplication::translate("MainWindow", "T", 0)
         << QApplication::translate("MainWindow", "K", 0)
        );
        bBuyOther->setText(QApplication::translate("MainWindow", "\344\270\272\344\273\226\344\272\272\344\271\260\347\245\250", 0));
        lEmpty->setText(QApplication::translate("MainWindow", "\350\277\231\351\207\214\347\251\272\347\251\272\345\246\202\344\271\237\342\200\246T^T", 0));
        main->setTabText(main->indexOf(tab), QApplication::translate("MainWindow", "\351\242\204\350\256\242\350\275\246\347\245\250", 0));
        bReturn->setText(QApplication::translate("MainWindow", "\351\200\200\347\245\250", 0));
        bRefresh->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260", 0));
        main->setTabText(main->indexOf(tab_2), QApplication::translate("MainWindow", "\345\267\262\350\264\255\350\275\246\347\245\250", 0));
        bEdit->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", 0));
        bLogout->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        bExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
        label_6->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215", 0));
        cGender->clear();
        cGender->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\224\267", 0)
         << QApplication::translate("MainWindow", "\345\245\263", 0)
        );
        cTType->clear();
        cTType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\210\220\344\272\272", 0)
         << QApplication::translate("MainWindow", "\345\255\246\347\224\237", 0)
        );
        label_12->setText(QApplication::translate("MainWindow", "\346\227\205\345\256\242\347\261\273\345\236\213", 0));
        label_7->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201", 0));
        label_8->setText(QApplication::translate("MainWindow", "\345\233\275\345\256\266/\345\234\260\345\214\272", 0));
        label_9->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", 0));
        label_13->setText(QApplication::translate("MainWindow", "\345\255\246\346\240\241\345\220\215\347\247\260", 0));
        label_11->setText(QApplication::translate("MainWindow", "\350\272\253\344\273\275\350\257\201\345\217\267", 0));
        label_14->setText(QApplication::translate("MainWindow", "\346\200\247\345\210\253", 0));
        label_15->setText(QApplication::translate("MainWindow", "\346\211\213\346\234\272\345\217\267\347\240\201", 0));
        label_16->setText(QApplication::translate("MainWindow", "\345\255\246\345\217\267", 0));
        cCountry->clear();
        cCountry->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\344\270\255\345\233\275", 0)
         << QApplication::translate("MainWindow", "\345\205\266\344\273\226\345\233\275\345\256\266", 0)
        );
        label_17->setText(QApplication::translate("MainWindow", "\351\231\204\345\212\240\344\277\241\346\201\257", 0));
        label_18->setText(QApplication::translate("MainWindow", "\345\207\272\347\224\237\346\227\245\346\234\237", 0));
        label_19->setText(QApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257", 0));
        bEditComplete->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220", 0));
        label_10->setText(QApplication::translate("MainWindow", "\350\264\246\346\210\267\344\277\241\346\201\257", 0));
        label_20->setText(QApplication::translate("MainWindow", "\344\275\231\351\242\235", 0));
        bPay->setText(QApplication::translate("MainWindow", "\345\205\205\345\200\274", 0));
        bEditCancel->setText(QApplication::translate("MainWindow", "\345\217\226\346\266\210", 0));
        main->setTabText(main->indexOf(tab_3), QApplication::translate("MainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("MainWindow", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        label_2->setText(QApplication::translate("MainWindow", "C++\347\250\213\345\272\217\350\256\276\350\256\241\344\270\216\350\256\255\347\273\203", 0));
        label_3->setText(QApplication::translate("MainWindow", "\350\256\276\350\256\241\350\200\205", 0));
        label_4->setText(QApplication::translate("MainWindow", "\345\260\271\347\247\213\351\230\263   yinqy15@mails.tsinghua.edu.cn", 0));
        label_5->setText(QApplication::translate("MainWindow", "\345\217\266\346\262\201\345\252\233   yeqy15@mails.tsinghua.edu.cn", 0));
        main->setTabText(main->indexOf(tab_4), QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\210\221\344\273\254", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
