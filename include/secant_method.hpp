#ifndef A629C223_8B91_41D0_9F83_417085FE9852
#define A629C223_8B91_41D0_9F83_417085FE9852

#include "method.hpp"
#include <cmath>

class SecantMethod : public Method {
private:
  double x0;
  double x1;

public:
  SecantMethod(std::function<double(double)> const& f, double a, double b, double tol);
  double solve() override;
};

#endif /* A629C223_8B91_41D0_9F83_417085FE9852 */
