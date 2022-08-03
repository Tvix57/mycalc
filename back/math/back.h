#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <list>
#include <vector>
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
//  std::list<double> nums;
  std::list<double, QString> polish_stack;
  std::list<double> nums_out;
  std::list<double *> address_x;
  void parsing(QString);
  int getPriority(QString);
  int getArgs(QString );
  void addAddress(double *);
  void addFunctions(QString);
  double actionOne(double, QString);
  double actionTwo(double, double, QString);
  void polishConvertation();
};

#endif //  SRC_BACK_BACK_H_
