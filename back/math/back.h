#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <QtCore/QString>
#include <QtCore/QTextStream>
#include <QtCore/QRegularExpression>
#include <QtCore/QList>

class back
{
public:
  back(QString input);
  void replaceAllX(double x);
  double calculate();

private:
  typedef struct data {
      double num;
      QString fun;
  } data_t;
  QList<data_t> polish_stack;
  QList<int> position_x;
  void parsing(QString);
  int getPriority(QString);
  int getArgs(QString );
  void addAddress(int);
  void addFunctions(QString);
  double actionOne(double, QString);
  double actionTwo(double, double, QString);
  int insertHighPriorityStack(QList<data_t>&, int);
  void polishConvertation();
  bool leftAssotiation(QString);
};

#endif //  SRC_BACK_BACK_H_
