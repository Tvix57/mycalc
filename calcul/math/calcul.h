#ifndef CALCUL_H
#define CALCUL_H

#include <QRegularExpression>
#include <QMainWindow>
#include <QThread>
#include <QButtonGroup>

#include "credit/credit_window.h"
#include "depos/depos_window_2.h"
#include "graph/graph_window.h"
#include "graph/range_x_window.h"
#include "./../back/math/back.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Calcul;}
QT_END_NAMESPACE

enum InputPreset {
    Default = 0,
    OneArgument,
    TwoArgument,
    Nums,
    RightBranch,
    LeftBranch,
    XButon,
    CButton,
    SignButton
};

class Calcul : public QMainWindow
{
    Q_OBJECT

public:
    Calcul(QWidget *parent = nullptr);
    ~Calcul();

private slots:
    void inputString(QAbstractButton *pres_button);
    void controlInput(QAbstractButton *pres_button);
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



private:
    Ui::Calcul *ui;
    Credit_window *credit_window;
    depos_window_2 *deposW;
    range_x_window *range_window;
    graph_window *new_graph;

    void opti_graph(graph_window *new_graph, Tvix57::back *stack);
    void setInputPreset(InputPreset preset = Default);
    void set_default_input();
    void setOneArgPreset();
    void setTwoArgPreset();
};

#endif // CALCUL_H
