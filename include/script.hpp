#ifndef A14AF02E_8A4D_41FA_9810_5C764DAB91DD
#define A14AF02E_8A4D_41FA_9810_5C764DAB91DD

#include <QString>

class Script {
private:
  double left_border;
  double right_border;
  double tol;
  int function_indx = -1;
  int method_indx = -1;

public:
  explicit Script(const QString &filename);
  double get_left_border() const;
  double get_right_border() const;
  double get_tol() const;
  int get_function_indx() const;
  int get_method_indx() const;
  ~Script() = default;
};

#endif /* A14AF02E_8A4D_41FA_9810_5C764DAB91DD */
