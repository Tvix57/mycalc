#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_
#include <QtCore/QString>
#include <QtCore/QTextStream>
#include <QtCore/QRegularExpression>
#include <QtCore/QList>
#include <QtCore/QObject>

class back: public QObject
{
    Q_OBJECT
public:
  back(QString input);
  back(const back& other);
  ~back();
//  Оператор присваивания копированием
//  Конструктор перемещения
//  Оператор присваивания перемещением

  void replaceAllX(double x);
  double calculate();
  void setRange(double, double, double);

private:
  typedef struct data {
      double num;
      QString fun;
  } data_t;
  QList<data_t> polish_stack;
  QList<int> position_x;
  double start, end, step;

  void parsing(QString);
  int getPriority(QString);
  void addAddress(int);
  void addFunctions(QString);
  double actionOne(double, QString);
  double actionTwo(double, double, QString);
  int insertHighPriorityStack(QList<data_t>&, int);
  void polishConvertation();
  bool leftAssotiation(QString);
  void addAllIndex();
  void subAllIndex();

public slots:
  void calculateGraph();

signals:
  void new_coord(double x, double y);
};

#endif //  SRC_BACK_BACK_H_
