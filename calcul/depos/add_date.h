#ifndef SRC_CALCUL_DEPOS_ADD_DATE_H_
#define SRC_CALCUL_DEPOS_ADD_DATE_H_

#include <QWidget>
#include <QDate>

namespace Ui {
class add_date;
}

class add_date : public QWidget {
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

#endif  // SRC_CALCUL_DEPOS_ADD_DATE_H_
