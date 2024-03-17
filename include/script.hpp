#ifndef A14AF02E_8A4D_41FA_9810_5C764DAB91DD
#define A14AF02E_8A4D_41FA_9810_5C764DAB91DD

#include <QString>

/**
 * @brief The Script class represents a script.
 */
class Script {
private:
  double left_border;     /**< The left border value. */
  double right_border;    /**< The right border value. */
  double tol;             /**< The tolerance value. */
  int function_indx = -1; /**< The function index. */
  int method_indx = -1;   /**< The method index. */

public:
  /**
   * @brief Constructs a Script object.
   * @param filename The name of the script file.
   */
  explicit Script(const QString &filename);

  /**
   * @brief Get the left border value.
   * @return The left border value.
   */
  double get_left_border() const;

  /**
   * @brief Get the right border value.
   * @return The right border value.
   */
  double get_right_border() const;

  /**
   * @brief Get the tolerance value.
   * @return The tolerance value.
   */
  double get_tol() const;

  /**
   * @brief Get the function index.
   * @return The function index.
   */
  int get_function_indx() const;

  /**
   * @brief Get the method index.
   * @return The method index.
   */
  int get_method_indx() const;

  ~Script() = default; /**< Destructor. */
};

#endif /* A14AF02E_8A4D_41FA_9810_5C764DAB91DD */