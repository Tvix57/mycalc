#ifndef ADD_DATE_H
#define ADD_DATE_H

#include <QWidget>

namespace Ui {
class add_date;
}

class add_date : public QWidget
{
    Q_OBJECT

public:
    explicit add_date(QWidget *parent = nullptr);
    ~add_date();

public slots:
    void on_pushButton_clicked();
signals:
    void Close_add_window();

private:
    Ui::add_date *ui;
};

#endif // ADD_DATE_H
