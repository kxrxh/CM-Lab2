#include "newton_sys.hpp"

double derivative_x(double (*f)(double, double), double x, double y,
                    double dx = 1e-6) {
  return (f(x + dx, y) - f(x, y)) / dx;
}

double derivative_y(double (*f)(double, double), double x, double y,
                    double dy = 1e-6) {
  return (f(x, y + dy) - f(x, y)) / dy;
}

std::pair<double, double> newton_solve(EquationSystem &system, double x0,
                                       double y0, double epsilon,
                                       int max_iterations) {
  double x = x0;
  double y = y0;

  for (int i = 0; i < max_iterations; ++i) {
    double f1 = system.first(x, y);
    double f2 = system.second(x, y);

    if (fabs(f1) < epsilon && fabs(f2) < epsilon) {
      break;
    }

    double J11 = derivative_x(system.first, x, y);
    double J12 = derivative_y(system.first, x, y);
    double J21 = derivative_x(system.second, x, y);
    double J22 = derivative_y(system.second, x, y);

    double detJ = J11 * J22 - J12 * J21;
    if (fabs(detJ) < epsilon) {
      break;
    }

    double dx = (f1 * J22 - f2 * J12) / detJ;
    double dy = (J11 * f2 - J21 * f1) / detJ;

    x -= dx;
    y -= dy;
  }

  return std::make_pair(x, y);
}