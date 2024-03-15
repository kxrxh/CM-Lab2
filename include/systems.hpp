#ifndef D6D8A922_6765_45F5_A790_B469F576F149
#define D6D8A922_6765_45F5_A790_B469F576F149

#include <QPair>
#include <cmath> // Use cmath for math functions

using EquationSystem =
    QPair<double (*)(double, double), double (*)(double, double)>;

using GraphSystem = QPair<double (*)(double), double (*)(double)>;
static EquationSystem first_system() {
  return {[](double x, double y) -> double { return std::sin(2 * x) * 3 - y; },
          [](double x, double y) -> double { return 4 * x * x + 4 * y - 1; }};
}

static EquationSystem second_system() {
  return {[](double x, double y) -> double { return sin(x) - 3 * y; },
          [](double x, double y) -> double { return x * y + 2 * x * x - 16; }};
}

static GraphSystem graph_system_first() {
  return {[](double x) -> double { return std::sin(2 * x) * 3; },
          [](double x) -> double { return (1 - 4 * x * x) / 2; }};
}

static GraphSystem graph_system_second() {
  return {[](double x) -> double { return std::sin(x) / 3; },
          [](double x) -> double { return (-2 * x * x + 16) / x; }};
}

#endif /* D6D8A922_6765_45F5_A790_B469F576F149 */
