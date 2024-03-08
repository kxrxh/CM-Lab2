#include "half_div_method.hpp"

double HalfDivMethod::solve() {
  if (function(a) * function(b) > 0) {
    return NAN;
  }

  double x;
  double fx;
  for (int i = 0; i < max_it; ++i) {
    x = (a + b) / 2;
    fx = function(x);

    if (function(a) * fx > 0) {
      a = x;
    } else {
      b = x;
    }

    it++;

    if (fabs(a - b) <= tolerance || fabs(fx) < tolerance) {
      x = (a + b) / 2;
      return x;
    }
  }

  return NAN;
}