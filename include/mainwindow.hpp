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

class MainWindow final : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow() override = default;

private:
  std::unique_ptr<Ui::MainWindow> ui = std::make_unique<Ui::MainWindow>();

  bool validate_script(const Script &script) const;

  void draw_chart_ab();
  void draw_system_chart();

private slots:
  void solve_btn_clicked();

  void solve_sys_btn_clicked();

  void browse_btn_clicked();

  void change_tab(int index);

  void update_chart();

  void save_result_btn_clicked();

  void solve_script_btn_clicked();
};
#endif // MAINWINDOW_H
