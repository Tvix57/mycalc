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
    ~graph_window();
    void add_data(double x_out, double y_out, bool new_grap_flag);
    void update_graph();
    double get_last_y();
    double get_last_x();

private slots:


private:
    Ui::graph_window *ui;
    QVector<double> x,y;
    QMouseEvent *mouse;
    int conut_graph;
    double break_point;
};

#endif // GRAPH_WINDOW_H
