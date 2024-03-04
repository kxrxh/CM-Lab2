#include "half_div_method.hpp"

double HalfDivMehod::solve() {
  if (function(a) * function(b) > 0) {
    return std::numeric_limits<double>::quiet_NaN();
  }

  double c, fc;
  for (int i = 0; i < max_it; ++i) {
    c = (a + b) / 2;
    fc = function(c);

    if (std::abs(fc) < tolerance) {
      it = i;
      return c;
    }

    if (function(a) * fc < 0) {
      b = c;
    } else {
      a = c;
    }
  }

  return std::numeric_limits<double>::quiet_NaN();
}