#ifndef DAEF7103_2B01_4001_8F80_3B8D54F10C2C
#define DAEF7103_2B01_4001_8F80_3B8D54F10C2C

#include "method.hpp"

#include <cmath>

/**
 * @brief The SimpleIterationMethod class implements the simple iteration method
 * for finding the root of a function.
 */
class SimpleIterationMethod final : public Method {
public:
  /**
   * @brief Constructs a SimpleIterationMethod object.
   *
   * @param f The function for which the root needs to be found.
   * @param a The initial guess for the root.
   * @param b The second initial guess for the root (not used in this method).
   * @param tol The desired tolerance for the root approximation.
   */
  SimpleIterationMethod(std::function<double(double)> const &f, double a,
                        double b, double tol)
      : Method(f, a, b, tol) {}

  /**
   * @brief Solves for the root of the function using the simple iteration
   * method.
   *
   * @return A CalculationResult struct containing the success status and the
   * approximate root (if found).
   */
  CalculationResult solve() override;
};

#endif /* DAEF7103_2B01_4001_8F80_3B8D54F10C2C */