#ifndef MATH_HPP
#define MATH_HPP

namespace Math {
/**
 * @brief Computes the derivative of a function at a given point using finite
 * differences.
 *
 * @param f Pointer to the function for which the derivative is to be
 * calculated.
 * @param x The point at which the derivative is to be evaluated.
 * @param h Step size used in the finite difference approximation. Default value
 * is 1e-5.
 * @return The approximate derivative of the function at the given point.
 */
double derivative(double (*f)(double), double x, double h = 1e-5);

/**
 * @brief Computes the second derivative of a function at a given point using
 * finite differences.
 *
 * @param f Pointer to the function for which the second derivative is to be
 * calculated.
 * @param x The point at which the second derivative is to be evaluated.
 * @param h Step size used in the finite difference approximation. Default value
 * is 1e-5.
 * @return The approximate second derivative of the function at the given point.
 */
double second_derivative(double (*f)(double), double x, double h = 1e-5);

/**
 * @brief Computes the partial derivative of a function with respect to a
 * variable at a given point using finite differences.
 *
 * @param f Pointer to the multivariate function for which the partial
 * derivative is to be calculated.
 * @param x The point at which the partial derivative is to be evaluated.
 * @param h Step size used in the finite difference approximation. Default value
 * is 1e-5.
 * @param wrt_x Boolean flag indicating whether to compute the partial
 * derivative with respect to x (true) or y (false). Default value is true.
 * @return The approximate partial derivative of the function at the given point
 * with respect to the specified variable.
 */
double partial_derivative(double (*f)(double), double x, double h = 1e-5,
                          bool wrt_x = true);
} // namespace Math

#endif /* MATH_HPP */
