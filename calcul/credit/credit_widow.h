#ifndef CREDIT_WIDOW_H
#define CREDIT_WIDOW_H

#include <QDialog>

namespace Ui {
class credit_widow;
}

class credit_widow : public QDialog
{
    Q_OBJECT

public:
    explicit credit_widow(QWidget *parent = nullptr);
    ~credit_widow();

private:
    Ui::credit_widow *ui;
};

#endif // CREDIT_WIDOW_H
