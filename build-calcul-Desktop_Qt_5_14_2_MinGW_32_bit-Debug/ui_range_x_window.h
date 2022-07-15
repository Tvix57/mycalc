/********************************************************************************
** Form generated from reading UI file 'range_x_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANGE_X_WINDOW_H
#define UI_RANGE_X_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_range_x_window
{
public:
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *start_doubleSpinBox;
    QDoubleSpinBox *end_doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *range_x_window)
    {
        if (range_x_window->objectName().isEmpty())
            range_x_window->setObjectName(QString::fromUtf8("range_x_window"));
        range_x_window->resize(605, 119);
        horizontalLayout_4 = new QHBoxLayout(range_x_window);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(range_x_window);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(range_x_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(range_x_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(range_x_window);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        start_doubleSpinBox = new QDoubleSpinBox(range_x_window);
        start_doubleSpinBox->setObjectName(QString::fromUtf8("start_doubleSpinBox"));
        start_doubleSpinBox->setDecimals(6);
        start_doubleSpinBox->setMinimum(-1000000.000000000000000);
        start_doubleSpinBox->setMaximum(1000000.000000000000000);
        start_doubleSpinBox->setSingleStep(0.000001000000000);

        horizontalLayout->addWidget(start_doubleSpinBox);

        end_doubleSpinBox = new QDoubleSpinBox(range_x_window);
        end_doubleSpinBox->setObjectName(QString::fromUtf8("end_doubleSpinBox"));
        end_doubleSpinBox->setDecimals(6);
        end_doubleSpinBox->setMinimum(-1000000.000000000000000);
        end_doubleSpinBox->setMaximum(1000000.000000000000000);
        end_doubleSpinBox->setSingleStep(0.000001000000000);

        horizontalLayout->addWidget(end_doubleSpinBox);

        doubleSpinBox = new QDoubleSpinBox(range_x_window);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(6);
        doubleSpinBox->setMinimum(0.000001000000000);
        doubleSpinBox->setMaximum(100.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(range_x_window);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        retranslateUi(range_x_window);
        QObject::connect(buttonBox, SIGNAL(accepted()), range_x_window, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), range_x_window, SLOT(reject()));

        QMetaObject::connectSlotsByName(range_x_window);
    } // setupUi

    void retranslateUi(QDialog *range_x_window)
    {
        range_x_window->setWindowTitle(QCoreApplication::translate("range_x_window", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("range_x_window", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\264\320\270\320\260\320\277\320\260\320\267\320\276\320\275 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271 \320\270 \320\262\320\265\320\273\320\270\321\207\320\270\320\275\321\203 \321\210\320\260\320\263\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("range_x_window", "X \320\274\320\270\320\275\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("range_x_window", "X \320\274\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("range_x_window", "\320\250\320\260\320\263 \320\263\321\200\320\260\321\204\320\270\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class range_x_window: public Ui_range_x_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANGE_X_WINDOW_H
