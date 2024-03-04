#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  void updateTable(int mode);
  Ui::MainWindow *ui;

private slots:
  void clear_btn_clicked();

  // void solve_btn_clicked();

  void browse_btn_clicked();

  void method_changed();

  // void show_chart_btn_clicked();

  // void save_result_btn_clicked();
};
#endif // MAINWINDOW_H
