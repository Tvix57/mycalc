/********************************************************************************
** Form generated from reading UI file 'depos_window_2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOS_WINDOW_2_H
#define UI_DEPOS_WINDOW_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_depos_window_2
{
public:
    QAction *main_calc_buttom;
    QAction *Credit_calc_button;
    QAction *depos_calc_button;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox_summ;
    QLabel *label_summ;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox_day;
    QLabel *label_day;
    QComboBox *comboBox_period;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *proc_doubleSpinBox;
    QLabel *label_9;
    QLabel *label_proc;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *nalog_doubleSpinBox_2;
    QLabel *label_8;
    QLabel *label_nalog;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *capit_checkBox;
    QLabel *label_11;
    QComboBox *comboBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *calc_pushButton_2;
    QDateEdit *start_dateEdit;
    QLabel *label_12;
    QLabel *start_date_lable;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *calc_pushButton;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *label_summ_all_out;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_nalog_out;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_summ_out;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *depos_window_2)
    {
        if (depos_window_2->objectName().isEmpty())
            depos_window_2->setObjectName(QString::fromUtf8("depos_window_2"));
        depos_window_2->resize(521, 638);
        main_calc_buttom = new QAction(depos_window_2);
        main_calc_buttom->setObjectName(QString::fromUtf8("main_calc_buttom"));
        Credit_calc_button = new QAction(depos_window_2);
        Credit_calc_button->setObjectName(QString::fromUtf8("Credit_calc_button"));
        depos_calc_button = new QAction(depos_window_2);
        depos_calc_button->setObjectName(QString::fromUtf8("depos_calc_button"));
        centralwidget = new QWidget(depos_window_2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        doubleSpinBox_summ = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_summ->setObjectName(QString::fromUtf8("doubleSpinBox_summ"));
        doubleSpinBox_summ->setProperty("showGroupSeparator", QVariant(true));
        doubleSpinBox_summ->setMaximum(100000000000000007629769841091887003294964970946560.000000000000000);
        doubleSpinBox_summ->setSingleStep(0.010000000000000);
        doubleSpinBox_summ->setValue(1000.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox_summ);

        label_summ = new QLabel(centralwidget);
        label_summ->setObjectName(QString::fromUtf8("label_summ"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_summ->sizePolicy().hasHeightForWidth());
        label_summ->setSizePolicy(sizePolicy);
        label_summ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_summ);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBox_day = new QSpinBox(centralwidget);
        spinBox_day->setObjectName(QString::fromUtf8("spinBox_day"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox_day->sizePolicy().hasHeightForWidth());
        spinBox_day->setSizePolicy(sizePolicy1);
        spinBox_day->setMinimumSize(QSize(200, 0));
        spinBox_day->setMaximumSize(QSize(200, 16777215));
        spinBox_day->setMaximum(999999999);
        spinBox_day->setValue(120);

        horizontalLayout_2->addWidget(spinBox_day);

        label_day = new QLabel(centralwidget);
        label_day->setObjectName(QString::fromUtf8("label_day"));
        label_day->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_day);

        comboBox_period = new QComboBox(centralwidget);
        comboBox_period->addItem(QString());
        comboBox_period->addItem(QString());
        comboBox_period->addItem(QString());
        comboBox_period->setObjectName(QString::fromUtf8("comboBox_period"));

        horizontalLayout_2->addWidget(comboBox_period);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        proc_doubleSpinBox = new QDoubleSpinBox(centralwidget);
        proc_doubleSpinBox->setObjectName(QString::fromUtf8("proc_doubleSpinBox"));
        sizePolicy1.setHeightForWidth(proc_doubleSpinBox->sizePolicy().hasHeightForWidth());
        proc_doubleSpinBox->setSizePolicy(sizePolicy1);
        proc_doubleSpinBox->setMinimumSize(QSize(200, 0));
        proc_doubleSpinBox->setMaximumSize(QSize(200, 16777215));
        proc_doubleSpinBox->setDecimals(4);
        proc_doubleSpinBox->setSingleStep(0.000100000000000);

        horizontalLayout_3->addWidget(proc_doubleSpinBox);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(label_9);

        label_proc = new QLabel(centralwidget);
        label_proc->setObjectName(QString::fromUtf8("label_proc"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_proc->sizePolicy().hasHeightForWidth());
        label_proc->setSizePolicy(sizePolicy3);
        label_proc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_proc);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        nalog_doubleSpinBox_2 = new QDoubleSpinBox(centralwidget);
        nalog_doubleSpinBox_2->setObjectName(QString::fromUtf8("nalog_doubleSpinBox_2"));
        sizePolicy1.setHeightForWidth(nalog_doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        nalog_doubleSpinBox_2->setSizePolicy(sizePolicy1);
        nalog_doubleSpinBox_2->setMinimumSize(QSize(200, 0));
        nalog_doubleSpinBox_2->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(nalog_doubleSpinBox_2);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(label_8);

        label_nalog = new QLabel(centralwidget);
        label_nalog->setObjectName(QString::fromUtf8("label_nalog"));
        sizePolicy3.setHeightForWidth(label_nalog->sizePolicy().hasHeightForWidth());
        label_nalog->setSizePolicy(sizePolicy3);
        label_nalog->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_nalog);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        capit_checkBox = new QCheckBox(centralwidget);
        capit_checkBox->setObjectName(QString::fromUtf8("capit_checkBox"));

        horizontalLayout_6->addWidget(capit_checkBox);

        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_11);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_6->addWidget(comboBox);


        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout_5->addLayout(verticalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 3, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 3, 1, 1);

        calc_pushButton_2 = new QPushButton(centralwidget);
        calc_pushButton_2->setObjectName(QString::fromUtf8("calc_pushButton_2"));

        gridLayout->addWidget(calc_pushButton_2, 0, 3, 1, 1);

        start_dateEdit = new QDateEdit(centralwidget);
        start_dateEdit->setObjectName(QString::fromUtf8("start_dateEdit"));
        start_dateEdit->setCalendarPopup(true);

        gridLayout->addWidget(start_dateEdit, 1, 3, 1, 1);

        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 0, 1, 3);

        start_date_lable = new QLabel(centralwidget);
        start_date_lable->setObjectName(QString::fromUtf8("start_date_lable"));

        gridLayout->addWidget(start_date_lable, 1, 0, 1, 3);


        verticalLayout_5->addLayout(gridLayout);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 501, 215));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy5);
        scrollAreaWidgetContents->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        calc_pushButton = new QPushButton(centralwidget);
        calc_pushButton->setObjectName(QString::fromUtf8("calc_pushButton"));

        verticalLayout_5->addWidget(calc_pushButton);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_3->addWidget(label_3);

        label_summ_all_out = new QLabel(centralwidget);
        label_summ_all_out->setObjectName(QString::fromUtf8("label_summ_all_out"));
        label_summ_all_out->setScaledContents(false);
        label_summ_all_out->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout_3->addWidget(label_summ_all_out);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, 40, -1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_nalog_out = new QLabel(centralwidget);
        label_nalog_out->setObjectName(QString::fromUtf8("label_nalog_out"));
        label_nalog_out->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(label_nalog_out);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_summ_out = new QLabel(centralwidget);
        label_summ_out->setObjectName(QString::fromUtf8("label_summ_out"));
        label_summ_out->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(label_summ_out);


        verticalLayout_6->addLayout(verticalLayout);


        verticalLayout_5->addLayout(verticalLayout_6);

        depos_window_2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(depos_window_2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 521, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        depos_window_2->setMenuBar(menubar);

        menubar->addAction(menu->menuAction());
        menu->addAction(main_calc_buttom);
        menu->addAction(Credit_calc_button);
        menu->addAction(depos_calc_button);

        retranslateUi(depos_window_2);

        QMetaObject::connectSlotsByName(depos_window_2);
    } // setupUi

    void retranslateUi(QMainWindow *depos_window_2)
    {
        depos_window_2->setWindowTitle(QCoreApplication::translate("depos_window_2", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        main_calc_buttom->setText(QCoreApplication::translate("depos_window_2", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));
        Credit_calc_button->setText(QCoreApplication::translate("depos_window_2", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271", nullptr));
        depos_calc_button->setText(QCoreApplication::translate("depos_window_2", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271", nullptr));
        label_summ->setText(QCoreApplication::translate("depos_window_2", "\320\241\321\203\320\274\320\274\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        label_day->setText(QCoreApplication::translate("depos_window_2", "\320\241\321\200\320\276\320\272 \321\200\320\260\320\267\320\274\320\265\321\211\320\265\320\275\320\270\321\217", nullptr));
        comboBox_period->setItemText(0, QCoreApplication::translate("depos_window_2", "\320\222 \320\264\320\275\321\217\321\205", nullptr));
        comboBox_period->setItemText(1, QCoreApplication::translate("depos_window_2", "\320\222 \320\274\320\265\321\201\321\217\321\206\320\260\321\205", nullptr));
        comboBox_period->setItemText(2, QCoreApplication::translate("depos_window_2", "\320\222 \320\263\320\276\320\264\320\260\321\205", nullptr));

        label_9->setText(QCoreApplication::translate("depos_window_2", "%", nullptr));
        label_proc->setText(QCoreApplication::translate("depos_window_2", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\320\275\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260 \320\264\320\265\320\277\320\276\320\267\320\270\321\202\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("depos_window_2", "%", nullptr));
        label_nalog->setText(QCoreApplication::translate("depos_window_2", "\320\235\320\260\320\273\320\276\320\263\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\262\320\272\320\260", nullptr));
        capit_checkBox->setText(QCoreApplication::translate("depos_window_2", "\320\232\320\260\320\277\320\270\321\202\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_11->setText(QCoreApplication::translate("depos_window_2", "\320\237\320\265\321\200\320\265\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\262\321\213\320\277\320\273\320\260\321\202", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("depos_window_2", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\264\320\265\320\275\321\214", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("depos_window_2", "\320\232\320\260\320\266\320\264\321\203\321\216 \320\275\320\265\320\264\320\265\320\273\321\216", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("depos_window_2", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\274\320\265\321\201\321\217\321\206", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("depos_window_2", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\272\320\262\320\260\321\200\321\202\320\260\320\273", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("depos_window_2", "\320\232\320\260\320\266\320\264\321\213\320\271 \320\263\320\276\320\264", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("depos_window_2", "\320\222 \320\272\320\276\320\275\321\206\320\265 \320\277\320\265\321\200\320\270\320\276\320\264\320\260", nullptr));

        label_6->setText(QCoreApplication::translate("depos_window_2", "\320\242\320\270\320\277\n"
"\320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("depos_window_2", "\320\224\320\260\321\202\320\260\n"
"\320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("depos_window_2", "\320\241\321\203\320\274\320\274\320\260\n"
"\320\276\320\277\320\265\321\200\320\260\321\206\320\270\320\270", nullptr));
        label_7->setText(QCoreApplication::translate("depos_window_2", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214\n"
"\320\276\320\277\320\265\321\200\320\260\321\206\320\270\321\216", nullptr));
        calc_pushButton_2->setText(QCoreApplication::translate("depos_window_2", "+", nullptr));
        start_dateEdit->setDisplayFormat(QCoreApplication::translate("depos_window_2", "dd/MM/yyyy", nullptr));
        label_12->setText(QCoreApplication::translate("depos_window_2", "\320\224\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\265 \320\262\320\273\320\276\320\266\320\265\320\275\320\270\321\217 \320\270\320\273\320\270 \321\201\320\275\321\217\321\202\320\270\321\217", nullptr));
        start_date_lable->setText(QCoreApplication::translate("depos_window_2", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260 \320\262\320\272\320\273\320\260\320\264\320\260", nullptr));
        calc_pushButton->setText(QCoreApplication::translate("depos_window_2", "\320\240\320\260\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("depos_window_2", "\320\241\321\203\320\274\320\274\320\260 \321\201\321\207\320\265\321\202\320\260 \320\275\320\260 \320\272\320\276\320\275\320\265\321\206 \320\277\320\265\321\200\320\270\320\276\320\264\320\260", nullptr));
        label_summ_all_out->setText(QString());
        label->setText(QCoreApplication::translate("depos_window_2", "\320\235\320\260\320\273\320\276\320\263", nullptr));
        label_nalog_out->setText(QString());
        label_2->setText(QCoreApplication::translate("depos_window_2", "\320\241\321\203\320\274\320\274\320\260 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_summ_out->setText(QString());
        menu->setTitle(QCoreApplication::translate("depos_window_2", "\320\242\320\270\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class depos_window_2: public Ui_depos_window_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOS_WINDOW_2_H
