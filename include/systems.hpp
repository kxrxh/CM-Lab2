#ifndef D6D8A922_6765_45F5_A790_B469F576F149
#define D6D8A922_6765_45F5_A790_B469F576F149

#include <cmath>
#include <functional>
#include <utility>

/**
 * @brief Typedef for EquationSystem, which is a pair of std::function objects
 * representing a system of two nonlinear equations.
 *
 * The first std::function represents the first equation f(x, y) = 0, and the
 * second std::function represents the second equation g(x, y) = 0.
 */
using EquationSystem = std::pair<std::function<double(double, double)>,
                                 std::function<double(double, double)>>;

/**
 * @brief Defines the first system of nonlinear equations.
 *
 * @return An EquationSystem object representing the system of equations:
 *         f(x, y) = sin(2x) - 3 - y = 0
 *         g(x, y) = 4x^2 + 4y - 1 = 0
 */
static EquationSystem first_system() {
  auto f = [](double x, double y) { return std::sin(2 * x) - 3 - y; };
  auto g = [](double x, double y) { return 4 * x * x + 4 * y - 1; };
  return std::make_pair(f, g);
}

/**
 * @brief Defines the second system of nonlinear equations.
 *
 * @return An EquationSystem object representing the system of equations:
 *         f(x, y) = sin(x) - 3y = 0
 *         g(x, y) = xy + 2x^2 - 16 = 0
 */
static EquationSystem second_system() {
  auto f = [](double x, double y) { return std::sin(x) - 3 * y; };
  auto g = [](double x, double y) { return x * y + 2 * x * x - 16; };
  return std::make_pair(f, g);
}

#endif /* D6D8A922_6765_45F5_A790_B469F576F149 */