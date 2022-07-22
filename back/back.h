#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <list>
#include <QtCore/QString>
#include <cmath>
#include <QtCore/QTextStream>
#include <QtCore/QRegularExpression>
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
  // std::list<void(*)()> func;
  std::list<std::function<void()>> func;
  std::list<double *> address_x;
  void parsing(QString input);
  // void getLastPriority();
  void addAddress(double *x);
  void addFunction(QString);
  void oneArgFunc(QString);
  void twoArgFunc(QChar);
  double my_summ(double, double);
};

#endif //  SRC_BACK_BACK_H_
