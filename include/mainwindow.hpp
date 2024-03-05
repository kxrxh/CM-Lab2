#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QMainWindow"
#include "script.hpp"
#include "ui_MainWindow.hpp"
#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolTip>
#include <QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

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
  Ui::MainWindow *ui;
  // void zoom_slot();

  bool validate_script(const Script &script) const;

  void draw_chart_ab(double a, double b);
  void draw_system_chart(double a, double b);

private slots:
  void clear_btn_clicked();

  void solve_btn_clicked();

  void solve_sys_btn_clicked();

  void browse_btn_clicked();

  void redraw_chart(int index);

  void update_chart();

  void save_result_btn_clicked();

  void solve_script_btn_clicked();

};
#endif // MAINWINDOW_H
