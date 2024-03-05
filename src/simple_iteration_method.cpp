#include "simple_iteration_method.hpp"
#include "utils.hpp"

double SimpleIterationMethod::solve() {

  if (function(a) * function(b) >= 0) {
    return NAN;
  }

  double x0 = (a + b) / 2;
  double x1 = x0 - function(x0) / Math::derivative(function, x0);

  while (std::abs(x1 - x0) > tolerance && it < max_it) {
    x0 = x1;
    x1 = x0 - function(x0) / Math::derivative(function, x0);
    it++;
  }

  return x1;
}