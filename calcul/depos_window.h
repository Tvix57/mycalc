#ifndef DEPOS_WINDOW_H
#define DEPOS_WINDOW_H

#include <QWidget>



namespace Ui {
class depos_window;
}

class depos_window : public QWidget
{
    Q_OBJECT

public:
    explicit depos_window(QWidget *parent = nullptr);
    ~depos_window();


private:
    Ui::depos_window *ui;
};

#endif // DEPOS_WINDOW_H
