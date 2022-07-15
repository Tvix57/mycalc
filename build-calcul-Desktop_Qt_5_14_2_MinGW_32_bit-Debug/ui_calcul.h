/********************************************************************************
** Form generated from reading UI file 'calcul.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCUL_H
#define UI_CALCUL_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calcul
{
public:
    QAction *main_calc_button;
    QAction *Credit_calc_button;
    QAction *depos_calc_button;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *Out_lable;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *graph_button;
    QPushButton *one_more_x;
    QLineEdit *input_line;
    QGridLayout *buttons;
    QPushButton *seven_button;
    QPushButton *four_button;
    QPushButton *sudstraction_button;
    QPushButton *addition_button;
    QPushButton *sin_button;
    QPushButton *lbranch_button;
    QPushButton *sqrt_button;
    QPushButton *dot_button;
    QPushButton *five_button;
    QPushButton *atan_button;
    QPushButton *three_button;
    QPushButton *asin_button_2;
    QPushButton *sign_button;
    QPushButton *tan_button;
    QPushButton *C_button;
    QPushButton *acos_button;
    QPushButton *equal_button;
    QPushButton *cos_button;
    QPushButton *rbranch_button;
    QPushButton *backs_button;
    QPushButton *multiply_button;
    QPushButton *two_button;
    QPushButton *pow_button;
    QPushButton *zero_button;
    QPushButton *nine_button;
    QPushButton *six_button;
    QPushButton *devision_button;
    QPushButton *eight_button;
    QPushButton *one_button;
    QPushButton *log_button;
    QPushButton *ln_button;
    QPushButton *mod_button;
    QMenuBar *menuBar;
    QMenu *menu;
    QButtonGroup *buttonGroup_fnc_twoarg;
    QButtonGroup *buttonGroup_num;
    QButtonGroup *buttonGroup_fnc_onearg;

    void setupUi(QMainWindow *Calcul)
    {
        if (Calcul->objectName().isEmpty())
            Calcul->setObjectName(QString::fromUtf8("Calcul"));
        Calcul->resize(358, 621);
        main_calc_button = new QAction(Calcul);
        main_calc_button->setObjectName(QString::fromUtf8("main_calc_button"));
        Credit_calc_button = new QAction(Calcul);
        Credit_calc_button->setObjectName(QString::fromUtf8("Credit_calc_button"));
        depos_calc_button = new QAction(Calcul);
        depos_calc_button->setObjectName(QString::fromUtf8("depos_calc_button"));
        centralwidget = new QWidget(Calcul);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 330, 192));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        Out_lable = new QLabel(centralwidget);
        Out_lable->setObjectName(QString::fromUtf8("Out_lable"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Out_lable->sizePolicy().hasHeightForWidth());
        Out_lable->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        Out_lable->setFont(font);
        Out_lable->setFocusPolicy(Qt::NoFocus);
        Out_lable->setTextFormat(Qt::PlainText);
        Out_lable->setScaledContents(false);
        Out_lable->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);
        Out_lable->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout_2->addWidget(Out_lable);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graph_button = new QPushButton(centralwidget);
        graph_button->setObjectName(QString::fromUtf8("graph_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(graph_button->sizePolicy().hasHeightForWidth());
        graph_button->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tahoma"));
        font1.setPointSize(18);
        font1.setItalic(false);
        graph_button->setFont(font1);
        graph_button->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img /img/icons8-sin-24.png"), QSize(), QIcon::Normal, QIcon::Off);
        graph_button->setIcon(icon);
        graph_button->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(graph_button);

        one_more_x = new QPushButton(centralwidget);
        one_more_x->setObjectName(QString::fromUtf8("one_more_x"));
        sizePolicy1.setHeightForWidth(one_more_x->sizePolicy().hasHeightForWidth());
        one_more_x->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Tahoma"));
        font2.setPointSize(16);
        font2.setItalic(false);
        one_more_x->setFont(font2);
        one_more_x->setCursor(QCursor(Qt::PointingHandCursor));
        one_more_x->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(one_more_x);

        input_line = new QLineEdit(centralwidget);
        input_line->setObjectName(QString::fromUtf8("input_line"));
        input_line->setMaxLength(255);
        input_line->setReadOnly(true);

        horizontalLayout->addWidget(input_line);


        verticalLayout->addLayout(horizontalLayout);

        buttons = new QGridLayout();
        buttons->setObjectName(QString::fromUtf8("buttons"));
        seven_button = new QPushButton(centralwidget);
        buttonGroup_num = new QButtonGroup(Calcul);
        buttonGroup_num->setObjectName(QString::fromUtf8("buttonGroup_num"));
        buttonGroup_num->addButton(seven_button);
        seven_button->setObjectName(QString::fromUtf8("seven_button"));
        sizePolicy1.setHeightForWidth(seven_button->sizePolicy().hasHeightForWidth());
        seven_button->setSizePolicy(sizePolicy1);
        seven_button->setFont(font1);
        seven_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(seven_button, 10, 0, 1, 1);

        four_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(four_button);
        four_button->setObjectName(QString::fromUtf8("four_button"));
        sizePolicy1.setHeightForWidth(four_button->sizePolicy().hasHeightForWidth());
        four_button->setSizePolicy(sizePolicy1);
        four_button->setFont(font1);
        four_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(four_button, 11, 0, 1, 1);

        sudstraction_button = new QPushButton(centralwidget);
        buttonGroup_fnc_twoarg = new QButtonGroup(Calcul);
        buttonGroup_fnc_twoarg->setObjectName(QString::fromUtf8("buttonGroup_fnc_twoarg"));
        buttonGroup_fnc_twoarg->addButton(sudstraction_button);
        sudstraction_button->setObjectName(QString::fromUtf8("sudstraction_button"));
        sizePolicy1.setHeightForWidth(sudstraction_button->sizePolicy().hasHeightForWidth());
        sudstraction_button->setSizePolicy(sizePolicy1);
        sudstraction_button->setFont(font1);
        sudstraction_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(sudstraction_button, 11, 4, 1, 1);

        addition_button = new QPushButton(centralwidget);
        buttonGroup_fnc_twoarg->addButton(addition_button);
        addition_button->setObjectName(QString::fromUtf8("addition_button"));
        sizePolicy1.setHeightForWidth(addition_button->sizePolicy().hasHeightForWidth());
        addition_button->setSizePolicy(sizePolicy1);
        addition_button->setFont(font1);
        addition_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(addition_button, 12, 4, 1, 1);

        sin_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg = new QButtonGroup(Calcul);
        buttonGroup_fnc_onearg->setObjectName(QString::fromUtf8("buttonGroup_fnc_onearg"));
        buttonGroup_fnc_onearg->addButton(sin_button);
        sin_button->setObjectName(QString::fromUtf8("sin_button"));
        sizePolicy1.setHeightForWidth(sin_button->sizePolicy().hasHeightForWidth());
        sin_button->setSizePolicy(sizePolicy1);
        sin_button->setFont(font1);
        sin_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(sin_button, 8, 0, 1, 1);

        lbranch_button = new QPushButton(centralwidget);
        lbranch_button->setObjectName(QString::fromUtf8("lbranch_button"));
        sizePolicy1.setHeightForWidth(lbranch_button->sizePolicy().hasHeightForWidth());
        lbranch_button->setSizePolicy(sizePolicy1);
        lbranch_button->setFont(font1);
        lbranch_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(lbranch_button, 7, 4, 1, 1);

        sqrt_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(sqrt_button);
        sqrt_button->setObjectName(QString::fromUtf8("sqrt_button"));
        sizePolicy1.setHeightForWidth(sqrt_button->sizePolicy().hasHeightForWidth());
        sqrt_button->setSizePolicy(sizePolicy1);
        sqrt_button->setFont(font1);
        sqrt_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(sqrt_button, 6, 2, 1, 1);

        dot_button = new QPushButton(centralwidget);
        dot_button->setObjectName(QString::fromUtf8("dot_button"));
        sizePolicy1.setHeightForWidth(dot_button->sizePolicy().hasHeightForWidth());
        dot_button->setSizePolicy(sizePolicy1);
        dot_button->setFont(font1);
        dot_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(dot_button, 13, 2, 1, 1);

        five_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(five_button);
        five_button->setObjectName(QString::fromUtf8("five_button"));
        sizePolicy1.setHeightForWidth(five_button->sizePolicy().hasHeightForWidth());
        five_button->setSizePolicy(sizePolicy1);
        five_button->setFont(font1);
        five_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(five_button, 11, 1, 1, 1);

        atan_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(atan_button);
        atan_button->setObjectName(QString::fromUtf8("atan_button"));
        sizePolicy1.setHeightForWidth(atan_button->sizePolicy().hasHeightForWidth());
        atan_button->setSizePolicy(sizePolicy1);
        atan_button->setFont(font1);
        atan_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(atan_button, 7, 2, 1, 1);

        three_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(three_button);
        three_button->setObjectName(QString::fromUtf8("three_button"));
        sizePolicy1.setHeightForWidth(three_button->sizePolicy().hasHeightForWidth());
        three_button->setSizePolicy(sizePolicy1);
        three_button->setFont(font1);
        three_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(three_button, 12, 2, 1, 1);

        asin_button_2 = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(asin_button_2);
        asin_button_2->setObjectName(QString::fromUtf8("asin_button_2"));
        sizePolicy1.setHeightForWidth(asin_button_2->sizePolicy().hasHeightForWidth());
        asin_button_2->setSizePolicy(sizePolicy1);
        asin_button_2->setFont(font1);
        asin_button_2->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(asin_button_2, 7, 0, 1, 1);

        sign_button = new QPushButton(centralwidget);
        sign_button->setObjectName(QString::fromUtf8("sign_button"));
        sizePolicy1.setHeightForWidth(sign_button->sizePolicy().hasHeightForWidth());
        sign_button->setSizePolicy(sizePolicy1);
        sign_button->setFont(font1);
        sign_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(sign_button, 13, 0, 1, 1);

        tan_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(tan_button);
        tan_button->setObjectName(QString::fromUtf8("tan_button"));
        sizePolicy1.setHeightForWidth(tan_button->sizePolicy().hasHeightForWidth());
        tan_button->setSizePolicy(sizePolicy1);
        tan_button->setFont(font1);
        tan_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(tan_button, 8, 2, 1, 1);

        C_button = new QPushButton(centralwidget);
        C_button->setObjectName(QString::fromUtf8("C_button"));
        sizePolicy1.setHeightForWidth(C_button->sizePolicy().hasHeightForWidth());
        C_button->setSizePolicy(sizePolicy1);
        C_button->setFont(font1);
        C_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(C_button, 9, 0, 1, 1);

        acos_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(acos_button);
        acos_button->setObjectName(QString::fromUtf8("acos_button"));
        sizePolicy1.setHeightForWidth(acos_button->sizePolicy().hasHeightForWidth());
        acos_button->setSizePolicy(sizePolicy1);
        acos_button->setFont(font1);
        acos_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(acos_button, 7, 1, 1, 1);

        equal_button = new QPushButton(centralwidget);
        equal_button->setObjectName(QString::fromUtf8("equal_button"));
        sizePolicy1.setHeightForWidth(equal_button->sizePolicy().hasHeightForWidth());
        equal_button->setSizePolicy(sizePolicy1);
        equal_button->setFont(font1);
        equal_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(equal_button, 13, 4, 1, 1);

        cos_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(cos_button);
        cos_button->setObjectName(QString::fromUtf8("cos_button"));
        sizePolicy1.setHeightForWidth(cos_button->sizePolicy().hasHeightForWidth());
        cos_button->setSizePolicy(sizePolicy1);
        cos_button->setFont(font1);
        cos_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(cos_button, 8, 1, 1, 1);

        rbranch_button = new QPushButton(centralwidget);
        rbranch_button->setObjectName(QString::fromUtf8("rbranch_button"));
        sizePolicy1.setHeightForWidth(rbranch_button->sizePolicy().hasHeightForWidth());
        rbranch_button->setSizePolicy(sizePolicy1);
        rbranch_button->setFont(font1);
        rbranch_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(rbranch_button, 8, 4, 1, 1);

        backs_button = new QPushButton(centralwidget);
        backs_button->setObjectName(QString::fromUtf8("backs_button"));
        sizePolicy1.setHeightForWidth(backs_button->sizePolicy().hasHeightForWidth());
        backs_button->setSizePolicy(sizePolicy1);
        backs_button->setFont(font1);
        backs_button->setCursor(QCursor(Qt::PointingHandCursor));
        backs_button->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img /img/icons8-backs.png"), QSize(), QIcon::Normal, QIcon::Off);
        backs_button->setIcon(icon1);
        backs_button->setIconSize(QSize(22, 22));
        backs_button->setAutoRepeat(true);

        buttons->addWidget(backs_button, 9, 1, 1, 1);

        multiply_button = new QPushButton(centralwidget);
        buttonGroup_fnc_twoarg->addButton(multiply_button);
        multiply_button->setObjectName(QString::fromUtf8("multiply_button"));
        sizePolicy1.setHeightForWidth(multiply_button->sizePolicy().hasHeightForWidth());
        multiply_button->setSizePolicy(sizePolicy1);
        multiply_button->setFont(font1);
        multiply_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(multiply_button, 10, 4, 1, 1);

        two_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(two_button);
        two_button->setObjectName(QString::fromUtf8("two_button"));
        sizePolicy1.setHeightForWidth(two_button->sizePolicy().hasHeightForWidth());
        two_button->setSizePolicy(sizePolicy1);
        two_button->setFont(font1);
        two_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(two_button, 12, 1, 1, 1);

        pow_button = new QPushButton(centralwidget);
        buttonGroup_fnc_twoarg->addButton(pow_button);
        pow_button->setObjectName(QString::fromUtf8("pow_button"));
        sizePolicy1.setHeightForWidth(pow_button->sizePolicy().hasHeightForWidth());
        pow_button->setSizePolicy(sizePolicy1);
        pow_button->setFont(font1);
        pow_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(pow_button, 9, 2, 1, 1);

        zero_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(zero_button);
        zero_button->setObjectName(QString::fromUtf8("zero_button"));
        sizePolicy1.setHeightForWidth(zero_button->sizePolicy().hasHeightForWidth());
        zero_button->setSizePolicy(sizePolicy1);
        zero_button->setFont(font1);
        zero_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(zero_button, 13, 1, 1, 1);

        nine_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(nine_button);
        nine_button->setObjectName(QString::fromUtf8("nine_button"));
        sizePolicy1.setHeightForWidth(nine_button->sizePolicy().hasHeightForWidth());
        nine_button->setSizePolicy(sizePolicy1);
        nine_button->setFont(font1);
        nine_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(nine_button, 10, 2, 1, 1);

        six_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(six_button);
        six_button->setObjectName(QString::fromUtf8("six_button"));
        sizePolicy1.setHeightForWidth(six_button->sizePolicy().hasHeightForWidth());
        six_button->setSizePolicy(sizePolicy1);
        six_button->setFont(font1);
        six_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(six_button, 11, 2, 1, 1);

        devision_button = new QPushButton(centralwidget);
        buttonGroup_fnc_twoarg->addButton(devision_button);
        devision_button->setObjectName(QString::fromUtf8("devision_button"));
        sizePolicy1.setHeightForWidth(devision_button->sizePolicy().hasHeightForWidth());
        devision_button->setSizePolicy(sizePolicy1);
        devision_button->setFont(font1);
        devision_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(devision_button, 9, 4, 1, 1);

        eight_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(eight_button);
        eight_button->setObjectName(QString::fromUtf8("eight_button"));
        sizePolicy1.setHeightForWidth(eight_button->sizePolicy().hasHeightForWidth());
        eight_button->setSizePolicy(sizePolicy1);
        eight_button->setFont(font1);
        eight_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(eight_button, 10, 1, 1, 1);

        one_button = new QPushButton(centralwidget);
        buttonGroup_num->addButton(one_button);
        one_button->setObjectName(QString::fromUtf8("one_button"));
        sizePolicy1.setHeightForWidth(one_button->sizePolicy().hasHeightForWidth());
        one_button->setSizePolicy(sizePolicy1);
        one_button->setFont(font1);
        one_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(one_button, 12, 0, 1, 1);

        log_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(log_button);
        log_button->setObjectName(QString::fromUtf8("log_button"));
        sizePolicy1.setHeightForWidth(log_button->sizePolicy().hasHeightForWidth());
        log_button->setSizePolicy(sizePolicy1);
        log_button->setFont(font1);
        log_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(log_button, 6, 0, 1, 1);

        ln_button = new QPushButton(centralwidget);
        buttonGroup_fnc_onearg->addButton(ln_button);
        ln_button->setObjectName(QString::fromUtf8("ln_button"));
        sizePolicy1.setHeightForWidth(ln_button->sizePolicy().hasHeightForWidth());
        ln_button->setSizePolicy(sizePolicy1);
        ln_button->setFont(font1);
        ln_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(ln_button, 6, 1, 1, 1);

        mod_button = new QPushButton(centralwidget);
        buttonGroup_fnc_twoarg->addButton(mod_button);
        mod_button->setObjectName(QString::fromUtf8("mod_button"));
        sizePolicy1.setHeightForWidth(mod_button->sizePolicy().hasHeightForWidth());
        mod_button->setSizePolicy(sizePolicy1);
        mod_button->setFont(font1);
        mod_button->setCursor(QCursor(Qt::PointingHandCursor));

        buttons->addWidget(mod_button, 6, 4, 1, 1);


        verticalLayout->addLayout(buttons);


        verticalLayout_2->addLayout(verticalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        Calcul->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(Calcul);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 358, 24));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Calcul->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(main_calc_button);
        menu->addAction(Credit_calc_button);
        menu->addAction(depos_calc_button);

        retranslateUi(Calcul);
        QObject::connect(equal_button, SIGNAL(clicked()), Calcul, SLOT(update()));

        QMetaObject::connectSlotsByName(Calcul);
    } // setupUi

    void retranslateUi(QMainWindow *Calcul)
    {
        Calcul->setWindowTitle(QCoreApplication::translate("Calcul", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\272\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        main_calc_button->setText(QCoreApplication::translate("Calcul", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271", nullptr));
#if QT_CONFIG(tooltip)
        main_calc_button->setToolTip(QCoreApplication::translate("Calcul", "\320\220\320\273\320\263\320\265\320\261\321\200\320\260\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \320\270 \321\202\321\200\320\270\320\263\320\276\320\275\320\276\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\270\320\265 \321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
#endif // QT_CONFIG(tooltip)
        Credit_calc_button->setText(QCoreApplication::translate("Calcul", "\320\232\321\200\320\265\320\264\320\270\321\202\320\275\321\213\320\271", nullptr));
#if QT_CONFIG(tooltip)
        Credit_calc_button->setToolTip(QCoreApplication::translate("Calcul", "\320\240\320\260\321\201\321\207\320\265\321\202 \321\201\321\203\320\274\320\274\321\213 \320\277\320\265\321\200\320\265\320\277\320\273\320\260\321\202\321\213 \320\277\320\276 \320\272\321\200\320\265\320\264\320\270\321\202\321\203", nullptr));
#endif // QT_CONFIG(tooltip)
        depos_calc_button->setText(QCoreApplication::translate("Calcul", "\320\224\320\265\320\277\320\276\320\267\320\270\321\202\320\275\321\213\320\271", nullptr));
#if QT_CONFIG(tooltip)
        depos_calc_button->setToolTip(QCoreApplication::translate("Calcul", "\320\240\320\260\321\201\321\207\320\265\321\202 \320\277\321\200\320\276\321\206\320\265\320\275\321\202\320\276\320\262 \320\277\320\276 \320\264\320\265\320\277\320\276\320\267\320\270\321\202\321\203", nullptr));
#endif // QT_CONFIG(tooltip)
        Out_lable->setText(QString());
        graph_button->setText(QString());
#if QT_CONFIG(whatsthis)
        one_more_x->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
#if QT_CONFIG(accessibility)
        one_more_x->setAccessibleDescription(QString());
#endif // QT_CONFIG(accessibility)
        one_more_x->setText(QCoreApplication::translate("Calcul", "X", nullptr));
        seven_button->setText(QCoreApplication::translate("Calcul", "7", nullptr));
#if QT_CONFIG(shortcut)
        seven_button->setShortcut(QCoreApplication::translate("Calcul", "7", nullptr));
#endif // QT_CONFIG(shortcut)
        four_button->setText(QCoreApplication::translate("Calcul", "4", nullptr));
#if QT_CONFIG(shortcut)
        four_button->setShortcut(QCoreApplication::translate("Calcul", "4", nullptr));
#endif // QT_CONFIG(shortcut)
        sudstraction_button->setText(QCoreApplication::translate("Calcul", "-", nullptr));
#if QT_CONFIG(shortcut)
        sudstraction_button->setShortcut(QCoreApplication::translate("Calcul", "-", nullptr));
#endif // QT_CONFIG(shortcut)
        addition_button->setText(QCoreApplication::translate("Calcul", "+", nullptr));
#if QT_CONFIG(shortcut)
        addition_button->setShortcut(QCoreApplication::translate("Calcul", "+", nullptr));
#endif // QT_CONFIG(shortcut)
        sin_button->setText(QCoreApplication::translate("Calcul", "sin", nullptr));
#if QT_CONFIG(shortcut)
        sin_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        lbranch_button->setText(QCoreApplication::translate("Calcul", "(", nullptr));
#if QT_CONFIG(shortcut)
        lbranch_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        sqrt_button->setText(QCoreApplication::translate("Calcul", "sqrt", nullptr));
#if QT_CONFIG(shortcut)
        sqrt_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        dot_button->setText(QCoreApplication::translate("Calcul", ".", nullptr));
#if QT_CONFIG(shortcut)
        dot_button->setShortcut(QCoreApplication::translate("Calcul", ".", nullptr));
#endif // QT_CONFIG(shortcut)
        five_button->setText(QCoreApplication::translate("Calcul", "5", nullptr));
#if QT_CONFIG(shortcut)
        five_button->setShortcut(QCoreApplication::translate("Calcul", "5", nullptr));
#endif // QT_CONFIG(shortcut)
        atan_button->setText(QCoreApplication::translate("Calcul", "atan", nullptr));
#if QT_CONFIG(shortcut)
        atan_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        three_button->setText(QCoreApplication::translate("Calcul", "3", nullptr));
#if QT_CONFIG(shortcut)
        three_button->setShortcut(QCoreApplication::translate("Calcul", "3", nullptr));
#endif // QT_CONFIG(shortcut)
        asin_button_2->setText(QCoreApplication::translate("Calcul", "asin", nullptr));
#if QT_CONFIG(shortcut)
        asin_button_2->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        sign_button->setText(QCoreApplication::translate("Calcul", "-/+", nullptr));
        tan_button->setText(QCoreApplication::translate("Calcul", "tan", nullptr));
#if QT_CONFIG(shortcut)
        tan_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        C_button->setText(QCoreApplication::translate("Calcul", "C", nullptr));
#if QT_CONFIG(shortcut)
        C_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        acos_button->setText(QCoreApplication::translate("Calcul", "acos", nullptr));
#if QT_CONFIG(shortcut)
        acos_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        equal_button->setText(QCoreApplication::translate("Calcul", "=", nullptr));
#if QT_CONFIG(shortcut)
        equal_button->setShortcut(QCoreApplication::translate("Calcul", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        cos_button->setText(QCoreApplication::translate("Calcul", "cos", nullptr));
#if QT_CONFIG(shortcut)
        cos_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        rbranch_button->setText(QCoreApplication::translate("Calcul", ")", nullptr));
#if QT_CONFIG(shortcut)
        rbranch_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        backs_button->setText(QString());
#if QT_CONFIG(shortcut)
        backs_button->setShortcut(QCoreApplication::translate("Calcul", "Backspace", nullptr));
#endif // QT_CONFIG(shortcut)
        multiply_button->setText(QCoreApplication::translate("Calcul", "*", nullptr));
#if QT_CONFIG(shortcut)
        multiply_button->setShortcut(QCoreApplication::translate("Calcul", "*", nullptr));
#endif // QT_CONFIG(shortcut)
        two_button->setText(QCoreApplication::translate("Calcul", "2", nullptr));
#if QT_CONFIG(shortcut)
        two_button->setShortcut(QCoreApplication::translate("Calcul", "2", nullptr));
#endif // QT_CONFIG(shortcut)
        pow_button->setText(QCoreApplication::translate("Calcul", "^", nullptr));
        zero_button->setText(QCoreApplication::translate("Calcul", "0", nullptr));
#if QT_CONFIG(shortcut)
        zero_button->setShortcut(QCoreApplication::translate("Calcul", "0", nullptr));
#endif // QT_CONFIG(shortcut)
        nine_button->setText(QCoreApplication::translate("Calcul", "9", nullptr));
#if QT_CONFIG(shortcut)
        nine_button->setShortcut(QCoreApplication::translate("Calcul", "9", nullptr));
#endif // QT_CONFIG(shortcut)
        six_button->setText(QCoreApplication::translate("Calcul", "6", nullptr));
#if QT_CONFIG(shortcut)
        six_button->setShortcut(QCoreApplication::translate("Calcul", "6", nullptr));
#endif // QT_CONFIG(shortcut)
        devision_button->setText(QCoreApplication::translate("Calcul", "/", nullptr));
#if QT_CONFIG(shortcut)
        devision_button->setShortcut(QCoreApplication::translate("Calcul", "/, \\", nullptr));
#endif // QT_CONFIG(shortcut)
        eight_button->setText(QCoreApplication::translate("Calcul", "8", nullptr));
#if QT_CONFIG(shortcut)
        eight_button->setShortcut(QCoreApplication::translate("Calcul", "8", nullptr));
#endif // QT_CONFIG(shortcut)
        one_button->setText(QCoreApplication::translate("Calcul", "1", nullptr));
#if QT_CONFIG(shortcut)
        one_button->setShortcut(QCoreApplication::translate("Calcul", "1", nullptr));
#endif // QT_CONFIG(shortcut)
        log_button->setText(QCoreApplication::translate("Calcul", "log", nullptr));
#if QT_CONFIG(shortcut)
        log_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        ln_button->setText(QCoreApplication::translate("Calcul", "ln", nullptr));
#if QT_CONFIG(shortcut)
        ln_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        mod_button->setText(QCoreApplication::translate("Calcul", "mod", nullptr));
#if QT_CONFIG(shortcut)
        mod_button->setShortcut(QCoreApplication::translate("Calcul", "Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        menu->setTitle(QCoreApplication::translate("Calcul", "\320\242\320\270\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calcul: public Ui_Calcul {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCUL_H
