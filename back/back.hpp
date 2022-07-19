#ifndef SRC_BACK_BACK_H_
#define SRC_BACK_BACK_H_

#include <stack>
#include <string>
#include <list>
#include <queue>
using namespace std;
class back
{

public:
  back() {}
  back(string input);
  // back(back &other);
  ~back();
  void replaceAllX(const double &x);
  double calculate();

private:
  queue<double> nums;
  stack<string> func;
  list<double *> address_x;
  void parsing(string input);
  // void getLastPriority();
  void addAddress(double *x);
  // void 

};

back::back(string input) {
  parsing(input);
}

// back::back(back &other) {
  
// }

back::~back() {
}

void back::parsing(string input) {
  // if (input. is_num) {
  //   nums.push(input);
  // } else if (is_fnc) {
  //   func.push(input);
  // }
}

double back::calculate() {
  double result = nums.back();
  auto iter_nums = nums.end();
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
