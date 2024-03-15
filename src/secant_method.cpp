#include "secant_method.hpp"

SecantMethod::SecantMethod(std::function<double(double)> const &f, double a,
                           double b, double tol)
    : Method(f, a, b, tol) {
  x0 = a;
  x1 = b;
}

double SecantMethod::solve() {
  double x_next;

  if (function(x0) * function(x1) >= 0) {
    return NAN;
  }

  do {
    x_next = x1 - function(x1) * ((x1 - x0) / (function(x1) - function(x0)));
    x0 = x1;
    x1 = x_next;
    it++;
  } while (fabs(function(x_next)) > tolerance && fabs(x1 - x0) > tolerance &&
           it < max_it);

  return x_next;
}