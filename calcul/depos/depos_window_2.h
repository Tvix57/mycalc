#ifndef SRC_CALCUL_DEPOS_DEPOS_WINDOW_2_H_
#define SRC_CALCUL_DEPOS_DEPOS_WINDOW_2_H_

#include <QDoubleSpinBox>
#include <QLayout>
#include <QMainWindow>
#include "add_date.h"
#include "../back/depos/debit_calc.h"

namespace Ui {
class depos_window_2;
}

class depos_window_2 : public QMainWindow {
    Q_OBJECT
friend s21::Debit_calc;
 public:
    explicit depos_window_2(QWidget *parent = nullptr);
    ~depos_window_2();

 signals:
    void Calcul();
    void credit_window_from_depos();

 private slots:
    void on_Credit_calc_button_triggered();
    void on_main_calc_buttom_triggered();
    void on_calc_pushButton_clicked();
    void on_calc_pushButton_2_clicked();
    void delete_widg();
    void hide_capit_period(bool);

 private:
    Ui::depos_window_2 *ui;
    add_date *new_add;
    QGridLayout *addition;
    int widg_count;
};

#endif  // SRC_CALCUL_DEPOS_DEPOS_WINDOW_2_H_
