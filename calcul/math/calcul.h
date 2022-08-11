#ifndef CALCUL_H
#define CALCUL_H

#include <QRegularExpression>
#include <QMainWindow>
#include <QThread>
#include "credit/credit_window.h"
//#include "credit_window.h"
#include "depos/depos_window_2.h"
//#include "depos_window_2.h"
#include <QButtonGroup>
#include "graph/graph_window.h"
//#include "range_x_window.h"
#include "graph/range_x_window.h"
//#include "graph_window.h"
#include "./../back/math/back.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calcul; }
QT_END_NAMESPACE

class Calcul : public QMainWindow
{
    Q_OBJECT

public:
    Calcul(QWidget *parent = nullptr);
    ~Calcul();
private slots:

    void digits_end_fnc_but(QAbstractButton *pres_button);
    void control_input(QAbstractButton *pres_button);
    void on_C_button_clicked();
    void on_Credit_calc_button_triggered();
    void on_depos_calc_button_triggered();
    void on_graph_button_clicked();
    void on_one_more_x_clicked();
    void on_dot_button_clicked();
    void on_equal_button_clicked();
    void on_backs_button_clicked();
    void on_sign_button_clicked();
    void on_lbranch_button_clicked();
    void on_rbranch_button_clicked();
    void get_new_data(double x, double y);
    void set_default_input();

private:
    Ui::Calcul *ui;
    Credit_window *credit_window;
    depos_window_2 *deposW;
    range_x_window *range_window;
    graph_window *new_graph;

    void opti_graph(graph_window *new_graph, back &stack);

};

class Worker : public QThread, public back

{
    Q_OBJECT
public:
    Worker(QWidget *parent = nullptr);
    Worker(back &);
    void getSettings(double start_in, double end_in, double step_in);
signals:
    void new_coord(double x, double y);

protected:
    void run();
    double start, end, step;
};


#endif // CALCUL_H
