#include "script.hpp"
#include <QDebug>
#include <QFile>
#include <QTextStream>

Script::Script(const QString &filename) {
  QFile file(filename);

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    qWarning() << "Error: Unable to open file.";
    return;
  }

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine().trimmed(); // Trimmed once for all lines
    QStringList parts = line.split(':');
    if (parts.size() != 2) // Check if there are exactly 2 parts
      continue;

    const QString &key = parts[0];
    const QString &value = parts[1];
    bool converted = false;
    if (key == "method") {
      this->method_indx = value.toInt(&converted);
    } else if (key == "function") {
      this->function_indx = value.toInt(&converted);
    } else if (key == "left_border") {
      this->left_border = value.toDouble(&converted);
    } else if (key == "right_border") {
      this->right_border = value.toDouble(&converted);
    } else if (key == "tolerance") {
      this->tol = value.toDouble(&converted);
    }

    if (!converted) {
      qWarning() << "Error converting value to integer or double:" << key
                 << value;
    }
  }

  file.close();
}

double Script::get_tol() const { return this->tol; }

double Script::get_left_border() const { return this->left_border; }

double Script::get_right_border() const { return this->right_border; }

int Script::get_method_indx() const { return this->method_indx; }

int Script::get_function_indx() const { return this->function_indx; }