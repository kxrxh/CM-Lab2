#include "dark_theme.hpp"
#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DarkThemeHelper::applyDarkTheme();


    MainWindow w;
    w.show();

    return a.exec();
}
