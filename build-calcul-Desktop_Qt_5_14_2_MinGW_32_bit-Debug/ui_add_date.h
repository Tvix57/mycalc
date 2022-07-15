/********************************************************************************
** Form generated from reading UI file 'add_date.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_DATE_H
#define UI_ADD_DATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_date
{
public:
    QHBoxLayout *horizontalLayout;
    QDateEdit *date_addition_form;
    QDoubleSpinBox *summ_addition_form;
    QComboBox *type_addition_form;
    QPushButton *pushButton;

    void setupUi(QWidget *add_date)
    {
        if (add_date->objectName().isEmpty())
            add_date->setObjectName(QString::fromUtf8("add_date"));
        add_date->resize(419, 63);
        horizontalLayout = new QHBoxLayout(add_date);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, -1, 0, 6);
        date_addition_form = new QDateEdit(add_date);
        date_addition_form->setObjectName(QString::fromUtf8("date_addition_form"));
        date_addition_form->setMaximumSize(QSize(200, 50));
        date_addition_form->setCalendarPopup(true);

        horizontalLayout->addWidget(date_addition_form);

        summ_addition_form = new QDoubleSpinBox(add_date);
        summ_addition_form->setObjectName(QString::fromUtf8("summ_addition_form"));
        summ_addition_form->setMaximumSize(QSize(16777215, 50));
        summ_addition_form->setProperty("showGroupSeparator", QVariant(true));
        summ_addition_form->setMaximum(1000000000000000019884624838656.000000000000000);
        summ_addition_form->setSingleStep(0.010000000000000);

        horizontalLayout->addWidget(summ_addition_form);

        type_addition_form = new QComboBox(add_date);
        type_addition_form->addItem(QString());
        type_addition_form->addItem(QString());
        type_addition_form->setObjectName(QString::fromUtf8("type_addition_form"));
        type_addition_form->setMaximumSize(QSize(350, 50));

        horizontalLayout->addWidget(type_addition_form);

        pushButton = new QPushButton(add_date);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(30, 50));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(add_date);

        QMetaObject::connectSlotsByName(add_date);
    } // setupUi

    void retranslateUi(QWidget *add_date)
    {
        add_date->setWindowTitle(QCoreApplication::translate("add_date", "Form", nullptr));
        date_addition_form->setDisplayFormat(QCoreApplication::translate("add_date", "dd/MM/yyyy", nullptr));
        type_addition_form->setItemText(0, QCoreApplication::translate("add_date", "\320\237\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265", nullptr));
        type_addition_form->setItemText(1, QCoreApplication::translate("add_date", "\320\241\320\275\321\217\321\202\320\270\320\265", nullptr));

        pushButton->setText(QCoreApplication::translate("add_date", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_date: public Ui_add_date {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_DATE_H
