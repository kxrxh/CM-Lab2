#include "newton_sys.hpp"
#include <functional>

/**
 * @brief Calculates the partial derivative of a function f(x, y) with respect
 * to x using finite differences.
 *
 * @param f The function f(x, y) for which the partial derivative is to be
 * calculated.
 * @param x The x-coordinate at which the derivative is to be evaluated.
 * @param y The y-coordinate at which the derivative is to be evaluated.
 * @param dx The step size for the finite difference approximation (default:
 * 1e-6).
 * @return The approximate partial derivative of f(x, y) with respect to x.
 */
static double derivative_x(std::function<double(double, double)> const &f,
                           double x, double y, double dx = 1e-6) {
  // Use the central difference formula to approximate the partial derivative
  return (f(x + dx, y) - f(x - dx, y)) / (2 * dx);
}

/**
 * @brief Calculates the partial derivative of a function f(x, y) with respect
 * to y using finite differences.
 *
 * @param f The function f(x, y) for which the partial derivative is to be
 * calculated.
 * @param x The x-coordinate at which the derivative is to be evaluated.
 * @param y The y-coordinate at which the derivative is to be evaluated.
 * @param dy The step size for the finite difference approximation (default:
 * 1e-6).
 * @return The approximate partial derivative of f(x, y) with respect to y.
 */
static double derivative_y(std::function<double(double, double)> const &f,
                           double x, double y, double dy = 1e-6) {
  // Use the central difference formula to approximate the partial derivative
  return (f(x, y + dy) - f(x, y - dy)) / (2 * dy);
}

/**
 * @brief Solves a system of two nonlinear equations using Newton's method.
 *
 * @param system The EquationSystem object representing the system of nonlinear
 * equations.
 * @param x0 The initial guess for the x-coordinate of the solution.
 * @param y0 The initial guess for the y-coordinate of the solution.
 * @param epsilon The desired tolerance for the solution.
 * @param max_iterations The maximum number of iterations allowed.
 * @return A pair containing the approximate solution (x, y) for the system of
 * equations.
 */
std::pair<double, double> newton_solve(EquationSystem const &system, double x0,
                                       double y0, double epsilon,
                                       int max_iterations) {
  double x = x0;
  double y = y0;

  for (int i = 0; i < max_iterations; ++i) {
    // Calculate the function values at the current approximation
    double f1 = system.first(x, y);
    double f2 = system.second(x, y);

    // Check if the solution has been found within the desired tolerance
    if (fabs(f1) < epsilon && fabs(f2) < epsilon) {
      return std::make_pair(x, y);
    }

    // Calculate the Jacobian matrix using finite differences
    double J11 = derivative_x(system.first, x, y);
    double J12 = derivative_y(system.first, x, y);
    double J21 = derivative_x(system.second, x, y);
    double J22 = derivative_y(system.second, x, y);

    // Calculate the determinant of the Jacobian matrix
    double detJ = J11 * J22 - J12 * J21;

    // If the determinant is close to zero, the Jacobian is singular, and the
    // solution is returned
    if (fabs(detJ) < epsilon) {
      return std::make_pair(x, y);
    }

    // Calculate the next approximation using Newton's method
    double dx = (f1 * J22 - f2 * J12) / detJ;
    double dy = (J11 * f2 - J21 * f1) / detJ;

    // Update the approximations
    x -= dx;
    y -= dy;
  }

  // If the maximum number of iterations is reached without convergence, return
  // the last approximation
  return std::make_pair(x, y);
}