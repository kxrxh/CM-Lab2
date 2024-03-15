#ifndef BAC19AD4_3356_40A1_9E35_A744F1C0E0E0
#define BAC19AD4_3356_40A1_9E35_A744F1C0E0E0

#include "method.hpp"
#include <cmath>

class HalfDivMethod : public Method {
public:
  HalfDivMethod(std::function<double(double)> const &f, double a, double b,
                double tol)
      : Method(f, a, b, tol) {}
  double solve() override;
};

#endif /* BAC19AD4_3356_40A1_9E35_A744F1C0E0E0 */
