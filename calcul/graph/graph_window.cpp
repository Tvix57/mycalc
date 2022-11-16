#include "graph_window.h"
#include "ui_graph_window.h"
#include <cmath>
#include "range_x_window.h"

graph_window::graph_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::graph_window) {
    ui->setupUi(this);
    ui->widget->xAxis->setRange(-100, 100);
    ui->widget->yAxis->setRange(-100, 100);
    conut_graph = 0;
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));
    ui->widget->setMouseTracking(true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    connect(this, SIGNAL(rejected()), this, SLOT(deleteLater()));
}

graph_window::~graph_window() {
    delete ui;
}

void graph_window::setRange(double x_from, double x_to) {
    ui->widget->xAxis->setRange(x_from, x_to);
    ui->widget->yAxis->setRange(x_from, x_to);
}

void graph_window::addData(double x_in, double y_in) {
    if (!y.empty() && y_in  * y.last() < 0) {
        conut_graph++;
        update_graph();
    }
        x.push_back(x_in);
        y.push_back(y_in);
}

void graph_window::update_graph() {
    ui->widget->addGraph();
    ui->widget->graph(conut_graph)->addData(x, y);
    ui->widget->replot();
    x.clear();
    y.clear();
}
