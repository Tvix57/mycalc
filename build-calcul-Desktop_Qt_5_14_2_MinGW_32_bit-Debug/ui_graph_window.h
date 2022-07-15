/********************************************************************************
** Form generated from reading UI file 'graph_window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_WINDOW_H
#define UI_GRAPH_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_graph_window
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *widget;

    void setupUi(QDialog *graph_window)
    {
        if (graph_window->objectName().isEmpty())
            graph_window->setObjectName(QString::fromUtf8("graph_window"));
        graph_window->resize(753, 596);
        verticalLayout = new QVBoxLayout(graph_window);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QCustomPlot(graph_window);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widget);


        retranslateUi(graph_window);

        QMetaObject::connectSlotsByName(graph_window);
    } // setupUi

    void retranslateUi(QDialog *graph_window)
    {
        graph_window->setWindowTitle(QCoreApplication::translate("graph_window", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph_window: public Ui_graph_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_WINDOW_H
