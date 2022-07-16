#ifndef DEPOS_WINDOW_2_H
#define DEPOS_WINDOW_2_H

#include <QDoubleSpinBox>
#include <QLayout>
#include <QMainWindow>
#include "add_date.h"
#include "debit_calc.h"

#ifdef __cplusplus
extern  "C"
{
    #endif
    #include "../back/backend.h"
    #ifdef __cplusplus
}
#endif

namespace Ui {
class depos_window_2;
}

class depos_window_2 : public QMainWindow
{
    Q_OBJECT
friend Debit_calc;
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

#endif // DEPOS_WINDOW_2_H
