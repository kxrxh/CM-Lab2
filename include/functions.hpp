#ifndef A96FF0BB_EC1D_4A92_8E85_AD22029DEE25
#define A96FF0BB_EC1D_4A92_8E85_AD22029DEE25

#include <cmath>

const double pi = 3.141592653589793;

static double first(double x) {
  return 14.23 * std::pow(x, 3) + 8.1 * std::pow(x, 2) - 1.01 * x + 0.64;
}

static double second(double x) { return std::pow(x, 3) + std::pow(x, 2) + 9.2; }

static double third(double x) { return std::exp(0.24 * x) - 2; }

static double fourth(double x) { return 2 * std::sin(x) + pi / 2; }

#endif /* A96FF0BB_EC1D_4A92_8E85_AD22029DEE25 */
