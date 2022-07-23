#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <list>
#include <QtCore/QString>
#include <QtCore/QTextStream>
#include <QtCore/QRegularExpression>

#include "stack_func.h"
class back
{
public:
  back() {}
  ~back() {}
  back(QString input);
  void replaceAllX(const double &x);
  double calculate();

private:
  std::list<double> nums;
  stack_func stack;
  std::list<double *> address_x;
  void parsing(QString input);
  void addAddress(double *x);
  void addFunctions(QString);
  void addOneArgFunc(QString);
  void addTwoArgFunc(QChar);
};

#endif //  SRC_BACK_BACK_H_
