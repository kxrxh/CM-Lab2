#include "utils.hpp"

double Math::derivative(double (*f)(double), double x, double h) {
  return (f(x + h) - f(x)) / h;
}

double Math::second_derivative(double (*f)(double), double x, double h) {
  return (f(x - h) - 2 * f(x) + f(x + h)) / (h * h);
}