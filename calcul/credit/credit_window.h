#ifndef SRC_CALCUL_CREDIT_CREDIT_WINDOW_H_
#define SRC_CALCUL_CREDIT_CREDIT_WINDOW_H_

#include <QMainWindow>
#include <QIntValidator>

#include "../back/credit/credit_calc.h"
namespace Ui {
class Credit_window;
}

class Credit_window : public QMainWindow {
    Q_OBJECT
    friend s21::Credit_calc;
 public:
    explicit Credit_window(QWidget *parent = nullptr);
    ~Credit_window();

 signals:
    void Calcul();
    void depow_window_from_credit();

 private slots:
    void on_calc_Button_clicked();
    void on_main_calc_button_triggered();
    void on_depos_calc_button_triggered();

 private:
    Ui::Credit_window *ui;
};

#endif  // SRC_CALCUL_CREDIT_CREDIT_WINDOW_H_
