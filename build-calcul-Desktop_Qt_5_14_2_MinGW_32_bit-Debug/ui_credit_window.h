/********************************************************************************
** Form generated from reading UI file 'credit_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDIT_WINDOW_H
#define UI_CREDIT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Credit_window
{
public:
    QAction *main_calc_button;
    QAction *Credit_calc_button;
    QAction *depos_calc_button;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *sum_doubleSpinBox;
    QLabel *label_summ;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *term_spinBox;
    QLabel *label_day;
    QComboBox *period_comboBox;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *proc_doubleSpinBox;
    QLabel *label;
    QLabel *label_proc;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *calc_Button;
    QVBoxLayout *verticalLayout;
    QRadioButton *radio_dif_type;
    QRadioButton *radio_anue_type;
    QGridLayout *gridLayout;
    QLabel *label_month_pay;
    QLabel *label_overpay;
    QLabel *label_all_payed;
    QLabel *label_res_month_pay;
    QLabel *label_res_overpay;
    QLabel *label_res_all_payed;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *Credit_window)
    {
        if (Credit_window->objectName().isEmpty())
            Credit_window->setObjectName(QString::fromUtf8("Credit_window"));
        Credit_window->resize(430, 332);
        main_calc_button = new QAction(Credit_window);
        main_calc_button->setObjectName(QString::fromUtf8("main_calc_button"));
        Credit_calc_button = new QAction(Credit_window);
        Credit_calc_button->setObjectName(QString::fromUtf8("Credit_calc_button"));
        depos_calc_button = new QAction(Credit_window);
        depos_calc_button->setObjectName(QString::fromUtf8("depos_calc_button"));
        centralwidget = new QWidget(Credit_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        sum_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        sum_doubleSpinBox->setObjectName(QString::fromUtf8("sum_doubleSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sum_doubleSpinBox->sizePolicy().hasHeightForWidth());
        sum_doubleSpinBox->setSizePolicy(sizePolicy);
        sum_doubleSpinBox->setMaximum(10000000000000000905969664.000000000000000);
        sum_doubleSpinBox->setSingleStep(0.010000000000000);

        horizontalLayout_3->addWidget(sum_doubleSpinBox);

        label_summ = new QLabel(centralwidget);
        label_summ->setObjectName(QString::fromUtf8("label_summ"));

        horizontalLayout_3->addWidget(label_summ);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        term_spinBox = new QSpinBox(centralwidget);
        term_spinBox->setObjectName(QString::fromUtf8("term_spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(term_spinBox->sizePolicy().hasHeightForWidth());
        term_spinBox->setSizePolicy(sizePolicy1);
        term_spinBox->setMinimumSize(QSize(200, 0));
        term_spinBox->setMaximumSize(QSize(200, 16777215));
        term_spinBox->setMaximum(999999999);

        horizontalLayout_2->addWidget(term_spinBox);

        label_day = new QLabel(centralwidget);
        label_day->setObjectName(QString::fromUtf8("label_day"));
        label_day->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_day);

        period_comboBox = new QComboBox(centralwidget);
        period_comboBox->addItem(QString());
        period_comboBox->addItem(QString());
        period_comboBox->addItem(QString());
        period_comboBox->setObjectName(QString::fromUtf8("period_comboBox"));

        horizontalLayout_2->addWidget(period_comboBox);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        proc_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        proc_doubleSpinBox->setObjectName(QString::fromUtf8("proc_doubleSpinBox"));
        sizePolicy1.setHeightForWidth(proc_doubleSpinBox->sizePolicy().hasHeightForWidth());
        proc_doubleSpinBox->setSizePolicy(sizePolicy1);
        proc_doubleSpinBox->setMinimumSize(QSize(200, 0));
        proc_doubleSpinBox->setMaximumSize(QSize(200, 16777215));
        proc_doubleSpinBox->setDecimals(4);
        proc_doubleSpinBox->setSingleStep(0.000100000000000);

        horizontalLayout->addWidget(proc_doubleSpinBox);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(label);

        label_proc = new QLabel(centralwidget);
        label_proc->setObjectName(QString::fromUtf8("label_proc"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_proc->sizePolicy().hasHeightForWidth());
        label_proc->setSizePolicy(sizePolicy3);
        label_proc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_proc);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        calc_Button = new QPushButton(centralwidget);
        calc_Button->setObjectName(QString::fromUtf8("calc_Button"));

        horizontalLayout_4->addWidget(calc_Button);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radio_dif_type = new QRadioButton(centralwidget);
        radio_dif_type->setObjectName(QString::fromUtf8("radio_dif_type"));

        verticalLayout->addWidget(radio_dif_type);

        radio_anue_type = new QRadioButton(centralwidget);
        radio_anue_type->setObjectName(QString::fromUtf8("radio_anue_type"));

        verticalLayout->addWidget(radio_anue_type);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_month_pay = new QLabel(centralwidget);
        label_month_pay->setObjectName(QString::fromUtf8("label_month_pay"));

        gridLayout->addWidget(label_month_pay, 0, 0, 1, 1);

        label_overpay = new QLabel(centralwidget);
        label_overpay->setObjectName(QString::fromUtf8("label_overpay"));

        gridLayout->addWidget(label_overpay, 0, 1, 1, 1);

        label_all_payed = new QLabel(centralwidget);
        label_all_payed->setObjectName(QString::fromUtf8("label_all_payed"));

        gridLayout->addWidget(label_all_payed, 0, 2, 1, 1);

        label_res_month_pay = new QLabel(centralwidget);
        label_res_month_pay->setObjectName(QString::fromUtf8("label_res_month_pay"));

        gridLayout->addWidget(label_res_month_pay, 1, 0, 1, 1);

        label_res_overpay = new QLabel(centralwidget);
        label_res_overpay->setObjectName(QString::fromUtf8("label_res_overpay"));

        gridLayout->addWidget(label_res_overpay, 1, 1, 1, 1);

        label_res_all_payed = new QLabel(centralwidget);
        label_res_all_payed->setObjectName(QString::fromUtf8("label_res_all_payed"));

        gridLayout->addWidget(label_res_all_payed, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        Credit_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Credit_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 430, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Credit_window->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(main_calc_button);
        menu->addAction(Credit_calc_button);
        menu->addAction(depos_calc_button);

        retranslateUi(Credit_window);

        QMetaObject::connectSlotsByName(Credit_window);
    } // setupUi

    void retranslateUi(QMainWindow *Credit_window)
    {
        Credit_window->setWindowTitle(QCoreApplication::translate("Credit_window", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        main_calc_button->setText(QCoreApplication::translate("Credit_window", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));
        Credit_calc_button->setText(QCoreApplication::translate("Credit_window", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271", nullptr));
        depos_calc_button->setText(QCoreApplication::translate("Credit_window", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271", nullptr));
        label_summ->setText(QCoreApplication::translate("Credit_window", "\320\241\321\203\320\274\320\274\320\260 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        label_day->setText(QCoreApplication::translate("Credit_window", "\320\241\321\200\320\276\320\272 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        period_comboBox->setItemText(0, QCoreApplication::translate("Credit_window", "\320\222 \320\264\320\275\321\217\321\205", nullptr));
        period_comboBox->setItemText(1, QCoreApplication::translate("Credit_window", "\320\222 \320\274\320\265\321\201\321\217\321\206\320\260\321\205", nullptr));
        period_comboBox->setItemText(2, QCoreApplication::translate("Credit_window", "\320\222 \320\263\320\276\320\264\320\260\321\205", nullptr));

        label->setText(QCoreApplication::translate("Credit_window", "%", nullptr));
        label_proc->setText(QCoreApplication::translate("Credit_window", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        calc_Button->setText(QCoreApplication::translate("Credit_window", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        radio_dif_type->setText(QCoreApplication::translate("Credit_window", "\320\224\320\270\321\204\321\204\320\265\321\200\320\265\320\275\321\206\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271", nullptr));
        radio_anue_type->setText(QCoreApplication::translate("Credit_window", "\320\220\320\275\320\275\321\203\320\270\321\202\320\265\321\202\320\275\321\213\320\271", nullptr));
        label_month_pay->setText(QCoreApplication::translate("Credit_window", "\320\225\320\266\320\265\320\274\320\265\321\201\321\217\321\207\320\275\321\213\320\271 \320\277\320\273\320\260\321\202\320\265\320\266", nullptr));
        label_overpay->setText(QCoreApplication::translate("Credit_window", "\320\237\320\265\321\200\320\265\320\277\320\273\320\260\321\202\320\260 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
        label_all_payed->setText(QCoreApplication::translate("Credit_window", "\320\236\320\261\321\211\320\260\321\217 \320\262\321\213\320\277\320\273\320\260\321\202\320\260", nullptr));
        label_res_month_pay->setText(QString());
        label_res_overpay->setText(QString());
        label_res_all_payed->setText(QString());
        menu->setTitle(QCoreApplication::translate("Credit_window", "\320\242\320\270\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Credit_window: public Ui_Credit_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDIT_WINDOW_H
