/********************************************************************************
** Form generated from reading UI file 'pay.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAY_H
#define UI_PAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pay
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Pay)
    {
        if (Pay->objectName().isEmpty())
            Pay->setObjectName(QStringLiteral("Pay"));
        Pay->resize(356, 209);
        QFont font;
        font.setFamily(QString::fromUtf8("\347\255\211\347\272\277"));
        font.setPointSize(11);
        Pay->setFont(font);
        layoutWidget = new QWidget(Pay);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 140, 281, 35));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        layoutWidget->setFont(font1);
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));
        okButton->setFont(font1);

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font1);

        hboxLayout->addWidget(cancelButton);

        label = new QLabel(Pay);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 72, 16));
        label->setFont(font1);
        lineEdit = new QLineEdit(Pay);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(130, 80, 191, 21));
        lineEdit->setFont(font1);

        retranslateUi(Pay);
        QObject::connect(cancelButton, SIGNAL(clicked()), Pay, SLOT(reject()));

        QMetaObject::connectSlotsByName(Pay);
    } // setupUi

    void retranslateUi(QDialog *Pay)
    {
        Pay->setWindowTitle(QApplication::translate("Pay", "12306++\351\223\201\350\267\257\347\245\250\345\212\241\347\263\273\347\273\237", 0));
        okButton->setText(QApplication::translate("Pay", "\347\241\256\350\256\244", 0));
        cancelButton->setText(QApplication::translate("Pay", "\345\217\226\346\266\210", 0));
        label->setText(QApplication::translate("Pay", "\345\205\205\345\200\274\351\207\221\351\242\235", 0));
    } // retranslateUi

};

namespace Ui {
    class Pay: public Ui_Pay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAY_H
