#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <list>
#include <QtCore/QString>
#include <QtCore/QTextStream>
#include <QtCore/QRegularExpression>

class back
{
public:
  back(QString input);
  void replaceAllX(const double &x);
  double calculate();

private:
  std::list<double> nums;
  std::list<QString> func;
  std::list<double *> address_x;
  void parsing(QString input);
  void addAddress(double *x);
  void addFunctions(QString);
  double actionOne(double, QString);
  double actionTwo(double, double, QString);
};

#endif //  SRC_BACK_BACK_H_
