#include "mainwindow.hpp"
#include <QApplication>
#include <qresource.h>


int main(int argc, char *argv[]) {
  QResource::registerResource("./resources.rcc");
  QApplication a(argc, argv);

  MainWindow w;
  w.show();

  return a.exec();
}

// 1) 14.23*x^3+8.1*x^2-1.01*x+0.64 = 0
// 2) x^3 + x^2 + 9.2 = 0
// 3) exp(2.74 * x) - 54 = 0
// 4) sin(x) * 2 + pi / 2 = 0
