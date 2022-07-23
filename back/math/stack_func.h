#ifndef STACK_FUNC_H
#define STACK_FUNC_H


class node {
public:
  node *prev;
  double (stack_func::*fnc_ptr)(double, double) ;
};
// node& operator--() {
//     return *this->prev;
// }

class stack_func : public node
{
private:
  node *head;

public:
  stack_func();
  ~stack_func();
  void addSumm();
  void addSub();
  void addNode();
  bool empty();
  node *begin();
private:
  double add_fnc(double, double);
  double sub_fnc(double, double);
  double mul_fnc(double, double);
  double div_fnc(double, double);
  double sin_fnc(double, double);
  double cos_fnc(double, double);
  double acos_fnc(double, double);
  double asin_fnc(double, double);
  double tan_fnc(double, double);
  double atan_fnc(double, double);
  double sqrt_fnc(double, double);
  double ln_fnc(double, double);
  double log_fnc(double, double);
  double pow_fnc(double, double);
  double mod_fnc(double, double);
  double unar_min(double, double);
};

#endif // STACK_FUNC_H
