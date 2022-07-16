#ifndef CREDIT_WINDOW_H
#define CREDIT_WINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include "credit_calc.h"

#ifdef __cplusplus
extern  "C"
{
    #endif
    #include "../back/backend.h"
    #ifdef __cplusplus
}
#endif

namespace Ui {
class Credit_window;
}

class Credit_window : public QMainWindow
{
    Q_OBJECT
    friend Credit_calc;
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

#endif // CREDIT_WINDOW_H
