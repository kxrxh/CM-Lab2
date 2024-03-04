#include "secant_method.hpp"
#include "utils.hpp"

SecantMethod::SecantMethod(double (*f)(double), double a, double b, double tol)
    : Method(f, a, b, tol) {
  if (f(a) * Math::second_derivative(f, a) > 0) {
    x0 = a;
  } else {
    x0 = b;
  }

  x1 = x0 + 0.5;
}

double SecantMethod::solve() {
  double x2, fx0, fx1, fx2, error;

  fx0 = function(x0);
  fx1 = function(x1);
  
  if (fx0 * fx1 >= 0) {
    return std::numeric_limits<double>::quiet_NaN();
  }

  for (int i = 0; i < max_it; ++i) {
    fx0 = function(x0);
    fx1 = function(x1);

    if (std::abs(fx1 - fx0) < tolerance) {
      return x1;
    }

    x2 = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);

    error = std::abs((x2 - x1) / x2);
    if (error < tolerance) {
      return x2;
    }

    x0 = x1;
    x1 = x2;
  }

  return std::numeric_limits<double>::quiet_NaN();
}