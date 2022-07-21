#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <stack>
#include <list>
#include <QtCore/QString>

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
  list<QString> func;
  list<double *> address_x;
  void parsing(QString input);
  // void getLastPriority();
  void addAddress(double *x);
  void addFunction(QString);

};

back::back(QString input) {
  parsing(input);
}

back::~back() {
}

void back::parsing(QString input) {
  QString tmp;
  bool flag_insert = false;
  for (int i = 0; input.at(i) == input.end();i++) {
   tmp += input.at(i);
  
    if (input.toDouble()) {
    double num_tmp = input.toDouble();
    nums.push_front(num_tmp);
  } else {
    addFunction(tmp);
  }
  }
}
void back::addFunction(QString input) {

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
