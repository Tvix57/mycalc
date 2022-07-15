#include "calcul.h"
#include "ui_calcul.h"
#include <QMessageBox>


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
        if (input.contains("X")) {
            if (range_window->range_row_x_begin == range_window->range_row_x_end) {
                input.replace("X", QString::number(range_window->range_row_x_begin));
                ui->Out_lable->setText(history+"\n"+ QString::number(default_calc(input), 'g', 15));
                ui->input_line->clear();
            } else {
                new_graph = new graph_window();
                opti_graph(new_graph, &input);
                ui->Out_lable->setText(history+"\n"+ input);
                ui->input_line->clear();
            }
        } else {
          ui->input_line->clear();
          std::string tmp = input.toStdString();
          char *arr_tmp = (char*)tmp.c_str();
          double result = main_calc(arr_tmp);
          ui->Out_lable->setText(history+"\n"+ QString::number(result, 'g', 15));
        }
    } //else {
        ////show error mesage
//    }
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


void Calcul::calc_graph(graph_window *new_graph, QString *input, double start, double end, double step) {
    for(double tmp_d = start; tmp_d <= end; tmp_d+=step) {
        QString tmp_str = *input;
        tmp_str.replace("X", QString::number(tmp_d));
        double y_tmp = default_calc(tmp_str);
        bool new_grap_flag = false;
        if (y_tmp != y_tmp || y_tmp == INFINITY || y_tmp == -INFINITY) {
            new_grap_flag= true;
        }
        if (tmp_d != start) {
            if (new_graph->get_last_y() * y_tmp < 0) {
                double potencial_break_point_x = fabs((tmp_d-new_graph->get_last_x())/2);
                if (tmp_d > 0) {
                   potencial_break_point_x = tmp_d - potencial_break_point_x;
                } else {
                  potencial_break_point_x = tmp_d + potencial_break_point_x;
                }
                QString tmp_str2 = *input;
                tmp_str2.replace("X", QString::number(potencial_break_point_x));
                double potencial_break_point_y = default_calc(tmp_str2);
                if (potencial_break_point_y != potencial_break_point_y || potencial_break_point_y != 0 ||
                    potencial_break_point_y == INFINITY || potencial_break_point_y == -INFINITY) {
                new_grap_flag = true;
                }
            } else {
                new_grap_flag = false;
            }
        }
        new_graph->add_data(tmp_d, y_tmp, new_grap_flag);
    }
}

void Calcul::opti_graph(graph_window *new_graph, QString *input)
{
    double range_row_x_begin = range_window->range_row_x_begin;
    double range_row_x_end = range_window->range_row_x_end;
    double step = range_window->step;
//    if ( range_row_x_end - range_row_x_begin > 2 ) {
//        double range = range_row_x_end - range_row_x_begin;
//        double half_range = range /2;
//        double center = range_row_x_end - half_range;
//        calc_graph(new_graph, input, center, center+1, );
//        calc_graph(new_graph, input, center-1, center);
//        new_graph->update_graph();
//        new_graph->show();
//        QThread *r_tread = new MyThread();
//        r_tread->start(1);
//    } else {
        calc_graph(new_graph, input, range_row_x_begin, range_row_x_end, step);
        new_graph->update_graph();
        new_graph->show();
//    }
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

double Calcul::default_calc(QString input)
{
    std::string tmp = input.toStdString();
    char *arr_tmp = (char*)tmp.c_str();
    return main_calc(arr_tmp);
}
//void MyThread::run()
//{
//    calc_graph(new_graph, input, center, center+1);
//    center +=1;
//    new_graph->update_graph();
//}
