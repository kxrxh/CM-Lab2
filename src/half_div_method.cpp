#include "half_div_method.hpp"

CalculationResult HalfDivMethod::solve() {
  if (function(a) * function(b) > 0) {
    return {
        .success = false,
        .message = "Function has same sign at both endpoints.",
        .value = NAN,
    };
  }

  for (int i = 0; i < max_it; ++i) {
    this->it++;
    double x = (a + b) / 2;
    double fx = function(x);

    if (function(a) * fx > 0) {
      a = x;
    } else {
      b = x;
    }

    if (fabs(a - b) <= tolerance || fabs(fx) < tolerance) {
      x = (a + b) / 2;
      return {.success = true, .value = x};
    }
  }

  return {.success = false, .message = "Failed to converge.", .value = NAN};
}