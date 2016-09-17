/********************************************************************************
** Form generated from reading UI file 'userinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERINFO_H
#define UI_USERINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_UserInfo
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_10;
    QLabel *LogInLabel;
    QLabel *PassWordLabel;
    QLabel *SexLabel;
    QLabel *UserIdLabel;
    QLabel *label_2;
    QLabel *NameLabel;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *ContactLabel;
    QLabel *label_6;
    QLabel *CreLabel;
    QLabel *regionLabel;
    QLabel *AdditionLabel;
    QLabel *IdentityLabel;
    QLabel *label_12;
    QLabel *LogOutLabel;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UserInfo)
    {
        if (UserInfo->objectName().isEmpty())
            UserInfo->setObjectName(QStringLiteral("UserInfo"));
        UserInfo->resize(324, 402);
        UserInfo->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 255);"));
        gridLayout_2 = new QGridLayout(UserInfo);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(UserInfo);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("color:rgb(204, 68, 0);\n"
"font: 75 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        LogInLabel = new QLabel(groupBox);
        LogInLabel->setObjectName(QStringLiteral("LogInLabel"));
        LogInLabel->setFont(font);

        gridLayout->addWidget(LogInLabel, 9, 1, 1, 1);

        PassWordLabel = new QLabel(groupBox);
        PassWordLabel->setObjectName(QStringLiteral("PassWordLabel"));
        PassWordLabel->setFont(font);

        gridLayout->addWidget(PassWordLabel, 1, 1, 1, 1);

        SexLabel = new QLabel(groupBox);
        SexLabel->setObjectName(QStringLiteral("SexLabel"));
        SexLabel->setFont(font);

        gridLayout->addWidget(SexLabel, 3, 1, 1, 1);

        UserIdLabel = new QLabel(groupBox);
        UserIdLabel->setObjectName(QStringLiteral("UserIdLabel"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UserIdLabel->sizePolicy().hasHeightForWidth());
        UserIdLabel->setSizePolicy(sizePolicy);
        UserIdLabel->setFont(font);

        gridLayout->addWidget(UserIdLabel, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        NameLabel = new QLabel(groupBox);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));
        NameLabel->setFont(font);

        gridLayout->addWidget(NameLabel, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        ContactLabel = new QLabel(groupBox);
        ContactLabel->setObjectName(QStringLiteral("ContactLabel"));
        ContactLabel->setFont(font);

        gridLayout->addWidget(ContactLabel, 5, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        CreLabel = new QLabel(groupBox);
        CreLabel->setObjectName(QStringLiteral("CreLabel"));
        CreLabel->setFont(font);

        gridLayout->addWidget(CreLabel, 4, 1, 1, 1);

        regionLabel = new QLabel(groupBox);
        regionLabel->setObjectName(QStringLiteral("regionLabel"));
        regionLabel->setFont(font);

        gridLayout->addWidget(regionLabel, 6, 1, 1, 1);

        AdditionLabel = new QLabel(groupBox);
        AdditionLabel->setObjectName(QStringLiteral("AdditionLabel"));
        AdditionLabel->setFont(font);

        gridLayout->addWidget(AdditionLabel, 8, 1, 1, 1);

        IdentityLabel = new QLabel(groupBox);
        IdentityLabel->setObjectName(QStringLiteral("IdentityLabel"));
        IdentityLabel->setFont(font);

        gridLayout->addWidget(IdentityLabel, 7, 1, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        gridLayout->addWidget(label_12, 10, 0, 1, 1);

        LogOutLabel = new QLabel(groupBox);
        LogOutLabel->setObjectName(QStringLiteral("LogOutLabel"));
        LogOutLabel->setFont(font);

        gridLayout->addWidget(LogOutLabel, 10, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(UserInfo);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStyleSheet(QLatin1String(":hover{\n"
"	background-color: rgb(170, 0, 127);\n"
"}"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(UserInfo);
        QObject::connect(buttonBox, SIGNAL(accepted()), UserInfo, SLOT(accept()));

        QMetaObject::connectSlotsByName(UserInfo);
    } // setupUi

    void retranslateUi(QDialog *UserInfo)
    {
        UserInfo->setWindowTitle(QApplication::translate("UserInfo", "UserInfo", 0));
        groupBox->setTitle(QString());
        label_10->setText(QApplication::translate("UserInfo", "\347\231\273\345\275\225\346\227\266\351\227\264\357\274\232", 0));
        LogInLabel->setText(QString());
        PassWordLabel->setText(QString());
        SexLabel->setText(QString());
        UserIdLabel->setText(QString());
        label_2->setText(QApplication::translate("UserInfo", "\345\257\206\347\240\201\357\274\232", 0));
        NameLabel->setText(QString());
        label_5->setText(QApplication::translate("UserInfo", "\350\257\201\344\273\266\345\217\267", 0));
        label->setText(QApplication::translate("UserInfo", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_3->setText(QApplication::translate("UserInfo", "\345\247\223\345\220\215\357\274\232", 0));
        label_4->setText(QApplication::translate("UserInfo", "\346\200\247\345\210\253\357\274\232", 0));
        label_8->setText(QApplication::translate("UserInfo", "\350\272\253\344\273\275\357\274\232", 0));
        label_9->setText(QApplication::translate("UserInfo", "\351\231\204\345\212\240\344\277\241\346\201\257\357\274\232", 0));
        label_7->setText(QApplication::translate("UserInfo", "\345\234\260\345\214\272\357\274\232", 0));
        ContactLabel->setText(QString());
        label_6->setText(QApplication::translate("UserInfo", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", 0));
        CreLabel->setText(QString());
        regionLabel->setText(QString());
        AdditionLabel->setText(QString());
        IdentityLabel->setText(QString());
        label_12->setText(QApplication::translate("UserInfo", "\344\270\213\347\272\277\346\227\266\351\227\264\357\274\232", 0));
        LogOutLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class UserInfo: public Ui_UserInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERINFO_H
