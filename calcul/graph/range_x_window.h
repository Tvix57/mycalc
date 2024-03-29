#ifndef SRC_CALCUL_GRAPH_RANGE_X_WINDOW_H_
#define SRC_CALCUL_GRAPH_RANGE_X_WINDOW_H_

#include <QDialog>

namespace Ui {
class range_x_window;
}

class range_x_window : public QDialog {
    Q_OBJECT

 public:
    explicit range_x_window(QWidget *parent = nullptr);
    ~range_x_window();
    double range_row_x_begin, range_row_x_end, step;

 private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_end_doubleSpinBox_valueChanged(double arg1);
    void on_start_doubleSpinBox_valueChanged(double arg1);

 private:
    Ui::range_x_window *ui;
};

#endif  // SRC_CALCUL_GRAPH_RANGE_X_WINDOW_H_
