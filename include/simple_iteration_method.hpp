#ifndef DAEF7103_2B01_4001_8F80_3B8D54F10C2C
#define DAEF7103_2B01_4001_8F80_3B8D54F10C2C

#include "method.hpp"
#include <cmath>

class SimpleIterationMethod : public Method {
public:
  SimpleIterationMethod(double (*f)(double), double a, double b, double tol)
      : Method(f, a, b, tol){};

  double solve() override;
};

#endif /* DAEF7103_2B01_4001_8F80_3B8D54F10C2C */
