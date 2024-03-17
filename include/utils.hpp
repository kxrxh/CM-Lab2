#ifndef MATH_HPP
#define MATH_HPP

#include <functional>

namespace Math {
/**
 * @brief Computes the derivative of a function at a given point using finite
 * differences.
 *
 * @param f The function for which the derivative is to be calculated.
 * @param x The point at which the derivative is to be evaluated.
 * @param h Step size used in the finite difference approximation. Default value
 * is 1e-5.
 * @return The approximate derivative of the function at the given point.
 */
static double derivative(std::function<double(double)> const &f, double x,
                         double h = 1e-5) {
  return (f(x + h) - f(x)) / h;
}

/**
 * @brief Computes the second derivative of a function at a given point using
 * finite differences.
 *
 * @param f The function for which the second derivative is to be calculated.
 * @param x The point at which the second derivative is to be evaluated.
 * @param h Step size used in the finite difference approximation. Default value
 * is 1e-5.
 * @return The approximate second derivative of the function at the given point.
 */
static double second_derivative(std::function<double(double)> const &f,
                                double x, double h = 1e-5) {
  return (f(x - h) - 2 * f(x) + f(x + h)) / (h * h);
}

bool is_monotonic(double (*f)(double), double left, double right);
} // namespace Math

#endif /* MATH_HPP */