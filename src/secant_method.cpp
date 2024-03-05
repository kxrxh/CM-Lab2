#include "secant_method.hpp"

SecantMethod::SecantMethod(double (*f)(double), double a, double b, double tol)
    : Method(f, a, b, tol) {
  // if (f(a) * Math::second_derivative(f, a) > 0) {
  //   x0 = a;
  // } else {
  //   x0 = b;
  // }

  // x1 = x0 + 0.5;

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