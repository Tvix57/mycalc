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
  void replaceAllX(const double &x);
  double calculate();

private:
  typedef struct data {
      double num;
      QString fun;
  } data_t;
  QList <data_t> polish_stack;
  QList<double> nums_out;
  QList<double *> address_x;
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
