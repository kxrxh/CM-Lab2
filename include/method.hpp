#ifndef METHOD_HPP
#define METHOD_HPP
#include <cmath>
#include <functional>
#include <QString>
struct CalculationResult {
  bool success = false;
  QString message;
  double value = NAN;
};
/**
 * @brief Base class for numerical methods to find roots of a function within an
 * interval.
 */
class Method {
protected:
  std::function<double(double)>
      function; ///< Pointer to the function for which the root is to be found.
  double a;     ///< Left endpoint of the interval.
  double b;     ///< Right endpoint of the interval.
  double tolerance;    ///< Tolerance for convergence.
  unsigned int max_it; ///< Maximum number of iterations allowed.
  unsigned int it = 0; ///< Current iteration count.

public:
  /**
   * @brief Constructor to initialize the Method object.
   *
   * @param f Pointer to the function for which the root is to be found.
   * @param a Left endpoint of the interval.
   * @param b Right endpoint of the interval.
   * @param tolerance Tolerance for convergence.
   * @param max_it Maximum number of iterations allowed. Default value is 1000.
   */
  explicit Method(std::function<double(double)> const &f, double a, double b,
                  double tolerance, unsigned int max_it = 10000)
      : function(f), a(a), b(b), tolerance(tolerance), max_it(max_it) {}

  /**
   * @brief Virtual destructor for the Method class.
   */
  virtual ~Method() = default;

  /**
   * @brief Pure virtual function to be implemented by derived classes to solve
   * for the root.
   *
   * @return Approximate value of the root found by the numerical method.
   */
  virtual CalculationResult solve() = 0;

  unsigned int get_it() const { return it; }
};

#endif /* METHOD_HPP */
