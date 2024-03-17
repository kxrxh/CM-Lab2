#ifndef A629C223_8B91_41D0_9F83_417085FE9852
#define A629C223_8B91_41D0_9F83_417085FE9852

#include "method.hpp"

#include <cmath>

/**
 * @brief The SecantMethod class implements the secant method for finding the
 * root of a function.
 */
class SecantMethod : public Method {
private:
  double x0; /**< The initial guess for the root. */
  double x1; /**< The second initial guess for the root. */

public:
  /**
   * @brief Constructs a SecantMethod object.
   *
   * @param f The function for which the root needs to be found.
   * @param a The initial guess for the root.
   * @param b The second initial guess for the root.
   * @param tol The desired tolerance for the root approximation.
   */
  SecantMethod(std::function<double(double)> const &f, double a, double b,
               double tol);

  /**
   * @brief Solves for the root of the function using the secant method.
   *
   * @return A CalculationResult struct containing the success status and the
   * approximate root (if found).
   */
  CalculationResult solve() override;
};

#endif /* A629C223_8B91_41D0_9F83_417085FE9852 */