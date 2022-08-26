#ifndef GRAPH_WINDOW_H
#define GRAPH_WINDOW_H

#include <QDialog>
#include <QVector>
#include <QWheelEvent>

namespace Ui {
class graph_window;
}

class graph_window : public QDialog
{
    Q_OBJECT

public:
    explicit graph_window(QWidget *parent = nullptr);
    void setRange(double x_from, double x_to);
    ~graph_window();

public slots:
    void update_graph();
    void addData(double, double);
private:
    Ui::graph_window *ui;
    QVector<double> x,y;
    QMouseEvent *mouse;
    int conut_graph;
};

#endif // GRAPH_WINDOW_H
