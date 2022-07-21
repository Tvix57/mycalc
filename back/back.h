#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <stack>
#include <list>
#include <QtCore/QString>
#include <cmath>
#include <QtCore/QTextStream>

using namespace std;
class back
{
public:
  back() {}
  back(QString input);
  ~back();
  void replaceAllX(const double &x);
  double calculate();

private:
  list<double> nums;
  list<void(*)()> func;
  // list<QString> func;
  list<double *> address_x;
  void parsing(QString input);
  // void getLastPriority();
  void addAddress(double *x);
  void addFunction(QString);
  double my_summ(double arg1, double arg2);
};

// #include "back.tpp"


back::~back() {
}

void back::parsing(QString input) {
  QString tmp;
  bool flag_insert = false;


  QTextStream stream(&input);
  QList<double> array;
  while (!stream.atEnd()) {
    double number;
    stream >> number;
    array.append(number);
  }


  // for (int i = 0; input.at(i) == input.end();i++) {
  //   if (input.at(i).isDigit() || input.at(i).isPunct()) {
  //     tmp += input.at(i);
  //   } else {




  //   }
   
  
    if (tmp.toDouble()) {
    double num_tmp = input.toDouble();
    nums.push_front(num_tmp);
  } else {
    addFunction(tmp);
  }
  // }
}

double back::my_summ (double arg1, double arg2) {
 return arg1+arg2;
}

void back::addFunction(QString input) {
  // int a = ..., b = ...;
  // func.push_front([=]{sin(a)});
  // func.push_front([]{my_summ(10, 10);});
}


double back::calculate() {
  double result;
  auto iter_nums = nums.begin();
  auto iter_fnc = func.begin();
  for (; iter_nums != nums.end(); iter_nums++, iter_fnc++) {
    result = 0;
  }
  return result;
}
void back::addAddress(double *x) {
  address_x.push_back(x);
}

void back::replaceAllX(const double &x) {
  auto iter = address_x.begin();
  for (; iter != address_x.end(); iter++) {
    **iter = x;
  } 
}

#endif //  SRC_BACK_BACKEND_H_
