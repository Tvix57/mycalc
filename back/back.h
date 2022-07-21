#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

//#include <stack>
#include <list>
#include <QtCore/QString>
#include <cmath>
#include <QtCore/QTextStream>

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
  std::list<void(*)()> func;
  // list<QString> func;
  std::list<double *> address_x;
  void parsing(QString input);
  // void getLastPriority();
  void addAddress(double *x);
  void addFunction(QString);
  double my_summ(double arg1, double arg2);
};

double back::my_summ (double arg1, double arg2) {
 return arg1+arg2;
}

#endif //  SRC_BACK_BACK_H_
