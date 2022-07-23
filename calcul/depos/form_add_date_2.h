#ifndef FORM_ADD_DATE_2_H
#define FORM_ADD_DATE_2_H

#include <QWidget>

namespace Ui {
class form_add_date_2;
}

class form_add_date_2 : public QWidget
{
    Q_OBJECT

public:
    explicit form_add_date_2(QWidget *parent = nullptr);
    ~form_add_date_2();

private:
    Ui::form_add_date_2 *ui;
};

#endif // FORM_ADD_DATE_2_H
