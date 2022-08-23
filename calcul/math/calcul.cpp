#include "calcul.h"
#include "ui_calcul.h"


#include <QMessageBox>
#include <QThread>
#include <QTimer>
#include <QScrollArea>

Calcul::Calcul(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calcul)
{
    ui->setupUi(this);
    credit_window = new Credit_window();
    deposW = new depos_window_2();
    range_window = new range_x_window();

    connect(credit_window, &Credit_window::Calcul, this, &Calcul::show);
    connect(deposW, &depos_window_2::Calcul, this, &Calcul::show);
    connect(credit_window, &Credit_window::depow_window_from_credit, deposW, &depos_window_2::show);
    connect(deposW, &depos_window_2::credit_window_from_depos, credit_window, &Credit_window::show);

    connect(ui->buttonGroup_num, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(digits_end_fnc_but(QAbstractButton *)));
    connect(ui->buttonGroup_fnc_onearg,SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(digits_end_fnc_but(QAbstractButton *)));
    connect(ui->buttonGroup_fnc_twoarg,SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(digits_end_fnc_but(QAbstractButton *)));
    connect(ui->buttonGroup_num, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(control_input(QAbstractButton *)));
    connect(ui->buttonGroup_fnc_onearg,SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(control_input(QAbstractButton *)));
    connect(ui->buttonGroup_fnc_twoarg,SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(control_input(QAbstractButton *)));
    set_default_input();
    ui->scrollArea->setWidget(ui->Out_lable);
}

Calcul::~Calcul()
{
    delete ui;
}

void Calcul::digits_end_fnc_but(QAbstractButton * pres_button) {
    QString input = (ui->input_line->text());
    if (pres_button == ui->mod_button) {
        input += "%";
    } else {
            input += pres_button->text();
    }
    if (pres_button->group() == ui->buttonGroup_fnc_onearg) {
        input +="(";
    }
        ui->input_line->setText(input);
}

void Calcul::control_input(QAbstractButton *pres_button) {
    if (pres_button->group() == ui->buttonGroup_fnc_onearg) {
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->rbranch_button->blockSignals(true);
        ui->sign_button->blockSignals(false);
        ui->buttonGroup_num->blockSignals(false);
        ui->one_more_x->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->lbranch_button->blockSignals(false);
    } else if (pres_button->group() == ui->buttonGroup_fnc_twoarg) {
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->rbranch_button->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->buttonGroup_num->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->one_more_x->blockSignals(false);
        ui->lbranch_button->blockSignals(false);
        ui->sign_button->blockSignals(false);
    } else if (pres_button->group() == ui->buttonGroup_num) {
        ui->buttonGroup_fnc_onearg->blockSignals(true);
        ui->one_more_x->blockSignals(true);
        ui->lbranch_button->blockSignals(true);
        ui->sign_button->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(false);
        ui->rbranch_button->blockSignals(false);
    } else if (pres_button == ui->rbranch_button) {
        ui->lbranch_button->blockSignals(true);
        ui->buttonGroup_num->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(true);
        ui->one_more_x->blockSignals(true);
        ui->sign_button->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(false);
    } else if (pres_button == ui->lbranch_button) {
        ui->rbranch_button->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->sign_button->blockSignals(false);
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->buttonGroup_num->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->one_more_x->blockSignals(false);
    } else if (pres_button == ui->one_more_x) {
        ui->rbranch_button->blockSignals(false);
        ui->lbranch_button->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(false);
        ui->one_more_x->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(true);
        ui->buttonGroup_num->blockSignals(true);
        ui->dot_button->blockSignals(true);
        ui->sign_button->blockSignals(true);
    } else if (pres_button == ui->C_button) {
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->one_more_x->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->lbranch_button->blockSignals(false);
        ui->rbranch_button->blockSignals(true);
        ui->sign_button->blockSignals(false);
    }else if (pres_button == ui->sign_button) {
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->buttonGroup_num->blockSignals(false);
        ui->one_more_x->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->lbranch_button->blockSignals(false);
        ui->rbranch_button->blockSignals(true);
    }
}

void Calcul::on_C_button_clicked()
{
    ui->input_line->clear();
    set_default_input();
}

void Calcul::on_Credit_calc_button_triggered()
{
    credit_window->show();
    this->close();
}

void Calcul::on_depos_calc_button_triggered()
{
    deposW->show();
    this->close();
}

void Calcul::on_graph_button_clicked()
{
    range_window->show();
}

void Calcul::on_one_more_x_clicked()
{
    QPushButton *pres_button = (QPushButton *) sender();
    digits_end_fnc_but(pres_button);
    control_input(pres_button);
}

void Calcul::on_dot_button_clicked()
{
    QPushButton *pres_button = (QPushButton *) sender();
    digits_end_fnc_but(pres_button);
    pres_button->blockSignals(true);
}

void Calcul::on_equal_button_clicked()
{
    QString input = (ui->input_line->text());
    QString history = (ui->Out_lable->text());
    QRegularExpression reg ("(([0-9]|[0-9]+['.']|['.'][0-9]+)|['X'])[)]*$");
    if (input.contains(reg)) {
        set_default_input();
        s21::back *calc = new s21::back(input);
        if (input.contains("X")) {
            if (range_window->range_row_x_begin == range_window->range_row_x_end) {
                calc->replaceAllX(range_window->range_row_x_begin);
                ui->Out_lable->setText(history+"\n"+ QString::number(calc->calculate(), 'g', 15));
                ui->input_line->clear();
                calc->deleteLater();
                ui->scrollArea->setVerticalScrollBar(0);
            } else {
                new_graph = new graph_window();
//                connect(new_graph, SIGNAL(), new_graph, SLOT(deleteLater()));

                opti_graph(new_graph, calc);
                ui->Out_lable->setText(history+"\n"+ input);
                ui->input_line->clear();
            }
        } else {
          ui->input_line->clear();
          ui->Out_lable->setText(history+"\n"+ QString::number(calc->calculate(), 'g', 15));
          calc->deleteLater();
        }
    }
}

void Calcul::on_backs_button_clicked()
{
    QString input = (ui->input_line->text());
    if (input.endsWith("sin(") || input.endsWith("cos(") ||
        input.endsWith("tan(") || input.endsWith("log(") ) {
      input.chop(4);
      if (input.endsWith("a")) {
          input.chop(1);
      }
    } else if (input.endsWith("ln(")) {
      input.chop(3);

    } else if (input.endsWith("sqrt(") || input.endsWith("asin(") ||
               input.endsWith("acos(") || input.endsWith("atan(")) {
      input.chop(5);

    }else if (input.endsWith("(-")) {
      input.chop(2);
    } else {
      input.chop(1);
    }
    ui->input_line->setText(input);
    QRegularExpression reg_num ("([0-9]|['.'])$");
    QRegularExpression reg_fnc_two ("([+]|[-]|[*]|[/]|[%])$");
    if (input.isEmpty()) {
        set_default_input();
    } else if(input.contains(reg_num)) {
        ui->one_more_x->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(false);
        QRegularExpression dot_reg ("[0-9]*[.][0-9]*$");
        if (input.contains(dot_reg)) {
           ui->dot_button->blockSignals(true);
        } else {
           ui->dot_button->blockSignals(false);
        }
    } else if (input.endsWith("(-")) {
        ui->one_more_x->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->buttonGroup_num->blockSignals(false);
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->rbranch_button->blockSignals(true);
        ui->lbranch_button->blockSignals(false);
    } else if (input.contains(reg_fnc_two)) {
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->buttonGroup_num->blockSignals(false);
        ui->dot_button->blockSignals(false);
        ui->one_more_x->blockSignals(false);
    } else if (input.endsWith("(")) {
        ui->buttonGroup_num->blockSignals(false);
        ui->buttonGroup_fnc_onearg->blockSignals(false);
        ui->buttonGroup_fnc_twoarg->blockSignals(true);
        ui->rbranch_button->blockSignals(true);
        ui->lbranch_button->blockSignals(false);
         ui->dot_button->blockSignals(false);
        ui->one_more_x->blockSignals(false);
    } else if (input.endsWith(")")) {
        ui->buttonGroup_fnc_onearg->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(false);
        ui->rbranch_button->blockSignals(false);
        ui->lbranch_button->blockSignals(true);
        ui->one_more_x->blockSignals(true);
         ui->dot_button->blockSignals(true);
    } else if (input.endsWith("X")) {
        ui->one_more_x->blockSignals(true);
        ui->dot_button->blockSignals(true);
        ui->buttonGroup_num->blockSignals(true);
        ui->buttonGroup_fnc_onearg->blockSignals(true);
        ui->buttonGroup_fnc_twoarg->blockSignals(false);
    }
}

void Calcul::on_sign_button_clicked()
{
    QString input = (ui->input_line->text());
        input +="(-";
    ui->input_line->setText(input);
    QPushButton *pres_button = (QPushButton *) sender();
    control_input(pres_button);
}

void Calcul::on_lbranch_button_clicked()
{
    QPushButton *pres_button = (QPushButton *) sender();
    digits_end_fnc_but(pres_button);
    control_input(pres_button);
}

void Calcul::on_rbranch_button_clicked()
{
    QPushButton *pres_button = (QPushButton *) sender();
    digits_end_fnc_but(pres_button);
    control_input(pres_button);
}

void Calcul::get_new_data(double x, double y) {
    new_graph->add_data(x,y,false);
}

void Calcul::opti_graph(graph_window *new_graph, s21::back *stack)
{
    QThread *thread1 = new QThread;
    QTimer *time = new QTimer;
    stack->setRange(range_window->range_row_x_begin,
                   range_window->range_row_x_end,
                   range_window->step);
    connect(stack, SIGNAL(new_coord(double, double)) , this, SLOT(get_new_data(double, double)));
    connect(stack, SIGNAL(done()), thread1, SIGNAL(finished()));
    connect(stack, SIGNAL(done()), new_graph, SLOT(update_graph()));
    connect(thread1, SIGNAL(started()), stack, SLOT(calculateGraph()));
    connect(time, SIGNAL(timeout()), new_graph, SLOT(update_graph()));
    connect(thread1, SIGNAL(finished()), time, SLOT(stop()));
    connect(thread1, SIGNAL(finished()), stack, SLOT(deleteLater()));
    connect(thread1, SIGNAL(finished()), time, SLOT(deleteLater()));
    connect(thread1, SIGNAL(finished()), thread1, SLOT(quit()));
    connect(thread1, SIGNAL(finished()), thread1, SLOT(deleteLater()));
    stack->moveToThread(thread1);
    thread1->start(QThread::HighPriority);
    time->start(100);
    new_graph->show();
}

void Calcul::set_default_input()
{
    ui->buttonGroup_fnc_twoarg->blockSignals(true);
    ui->buttonGroup_fnc_onearg->blockSignals(false);
    ui->one_more_x->blockSignals(false);
    ui->dot_button->blockSignals(false);
    ui->lbranch_button->blockSignals(false);
    ui->rbranch_button->blockSignals(true);
    ui->sign_button->blockSignals(false);
    ui->buttonGroup_num->blockSignals(false);
}



