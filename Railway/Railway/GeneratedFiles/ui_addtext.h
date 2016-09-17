/********************************************************************************
** Form generated from reading UI file 'addtext.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTEXT_H
#define UI_ADDTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addText
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *addText)
    {
        if (addText->objectName().isEmpty())
            addText->setObjectName(QStringLiteral("addText"));
        addText->resize(251, 259);
        gridLayout = new QGridLayout(addText);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(addText);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        gridLayout->addWidget(label_2, 0, 0, 1, 3);

        label = new QLabel(addText);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(15);
        label->setFont(font);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(addText);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMaxLength(1000000);

        gridLayout->addWidget(lineEdit, 1, 1, 1, 2);

        pushButton = new QPushButton(addText);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pushButton, 2, 0, 1, 2);

        pushButton_2 = new QPushButton(addText);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 1);


        retranslateUi(addText);
        QObject::connect(pushButton, SIGNAL(clicked()), addText, SLOT(accept()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), addText, SLOT(reject()));
        QObject::connect(lineEdit, SIGNAL(editingFinished()), pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(addText);
    } // setupUi

    void retranslateUi(QDialog *addText)
    {
        addText->setWindowTitle(QApplication::translate("addText", "addText", 0));
        label_2->setText(QString());
        label->setText(QApplication::translate("addText", "message\357\274\232", 0));
        pushButton->setText(QApplication::translate("addText", "\347\241\256\350\256\244", 0));
        pushButton_2->setText(QApplication::translate("addText", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class addText: public Ui_addText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTEXT_H
