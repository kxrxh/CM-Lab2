#include "secant_method.hpp"

SecantMethod::SecantMethod(std::function<double(double)> const &f, double a,
                           double b, double tol)
    : Method(f, a, b, tol), x0(a), x1(b) {}

CalculationResult SecantMethod::solve() {
  double x_next;

  if (function(x0) * function(x1) >= 0) {
    return {.success = false,
            .message = "Function has same sign at both endpoints."};
  }

  do {
    if (fabs(function(x1)) < tolerance && fabs(x1 - x0) < tolerance) {
      return {.success = true, .value = x1};
    }

    x_next = x1 - function(x1) * ((x1 - x0) / (function(x1) - function(x0)));
    x0 = x1;
    x1 = x_next;
    it++;
  } while (it < max_it);

  return {
      .success = true,
      .message = "Maximum number of iterations reached.",
      .value = x_next,
  };
}