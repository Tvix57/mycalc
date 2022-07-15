#ifndef RANGE_X_WINDOW_H
#define RANGE_X_WINDOW_H

#include <QDialog>

namespace Ui {
class range_x_window;
}

class range_x_window : public QDialog
{
    Q_OBJECT

public:
    explicit range_x_window(QWidget *parent = nullptr);
    ~range_x_window();
    double range_row_x_begin, range_row_x_end, step;

private slots:

    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::range_x_window *ui;

};

#endif // RANGE_X_WINDOW_H
