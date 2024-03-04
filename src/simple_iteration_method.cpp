#include "simple_iteration_method.hpp"

double SimpleIterationMethod::solve() {
  double x0 = a;
  double x1, error;

  for (it = 0; it < max_it; ++it) {
    x1 = function(x0);            // f(x) = x
    error = fabs((x1 - x0) / x1); // Relative error

    if (error < tolerance) {
      return x1;
    }

    x0 = x1;
  }

  return std::numeric_limits<double>::quiet_NaN();
}