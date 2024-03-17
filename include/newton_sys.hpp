#ifndef F4EC16AF_5384_46A0_83F0_A44CCB910919
#define F4EC16AF_5384_46A0_83F0_A44CCB910919
#include "systems.hpp"
#include <QPair>
std::pair<double, double> newton_solve(EquationSystem const &system, double x0,
                                       double y0, double epsilon,
                                       int max_iterations = 5000);

#endif /* F4EC16AF_5384_46A0_83F0_A44CCB910919 */