#include "graph_window.h"
#include "ui_graph_window.h"

#include "range_x_window.h"

graph_window::graph_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph_window)
{
    ui->setupUi(this);
    ui->widget->xAxis->setRange(-100, 100);
    ui->widget->yAxis->setRange(-100, 100);
    conut_graph = 0;
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

    ui->widget->setMouseTracking(true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
}

graph_window::~graph_window()
{
    delete ui;
}

void graph_window::add_data(double x_out, double y_out, bool new_grap_flag) {
    if (new_grap_flag) {
      update_graph();
      conut_graph++;
      x.clear();
      y.clear();
    }
        x.push_back(x_out);
        y.push_back(y_out);
}

void graph_window::addData(double x_in, double y_in) {
        x.push_back(x_in);
        y.push_back(y_in);
}


void graph_window::update_graph() {
    ui->widget->addGraph();
    ui->widget->graph(conut_graph)->addData(x,y);
    ui->widget->replot();
}

double graph_window::get_last_y() {
    return y.last();
}
double graph_window::get_last_x() {
    return x.last();
}

