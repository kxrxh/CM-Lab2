#include "mainwindow.hpp"
#include "functions.hpp"
#include "half_div_method.hpp"
#include "method.hpp"
#include "secant_method.hpp"
#include "simple_iteration_method.hpp"
#include "ui_MainWindow.hpp"
#include <QDebug>
#include <QFileDialog>
#include <QToolTip>
#include <QValueAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Create a chart view
  ui->chartview->setRenderHint(QPainter::Antialiasing);
  ui->chartview->setRubberBand(QChartView::RectangleRubberBand);
  ui->chartview->setToolTip("Right click to zoom in, left click to zoom out");

  redraw_chart();

  connect(ui->clear_output, &QPushButton::clicked, this,
          &MainWindow::clear_btn_clicked);
  connect(ui->search_button, &QPushButton::clicked, this,
          &MainWindow::browse_btn_clicked);
  connect(ui->func_cbox, &QComboBox::currentTextChanged, this,
          &MainWindow::redraw_chart);
  connect(ui->solve_button, &QPushButton::clicked, this,
          &MainWindow::solve_btn_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::clear_btn_clicked() { ui->text_output->clear(); }

void MainWindow::browse_btn_clicked() {
  QString file = QFileDialog::getOpenFileName(
      this, tr("Choose a file"), QDir::currentPath(), "Text files (*.txt)");
  if (!file.isEmpty()) {
    qDebug() << "No file was selected";
    return;
  }

  // TODO: Read file data
  ui->textEdit->setText(file);
}

void MainWindow::zoom_slot() {
  QValueAxis *xAxis = qobject_cast<QValueAxis *>(
      ui->chartview->chart()->axes(Qt::Horizontal).first());

  // Check if the X-axis is successfully obtained
  if (xAxis) {
    // Get the current range of the X-axis
    qreal minX = xAxis->min();
    qreal maxX = xAxis->max();

    redraw_chart_ab(minX, maxX);
  } else {
    qDebug() << "Failed to get X-axis";
  }
}

void MainWindow::redraw_chart_ab(double a, double b) {
  double step = fabs((b - a) / 100);
  QLineSeries *series = new QLineSeries();
  switch (ui->func_cbox->currentIndex()) {
  case 0: {
    for (double x = a; x <= b; x += step) {
      series->append(x, first(x));
    }
  } break;
  case 1: {
    for (double x = a; x <= b; x += step) {
      series->append(x, second(x));
    }
  } break;
  case 2: {
    for (double x = a; x <= b; x += step) {
      series->append(x, third(x));
    }
  } break;
  case 3: {
    for (double x = a; x <= b; x += step) {
      series->append(x, fourth(x));
    }
  } break;
  }
  QChart *chart = new QChart();
  chart->addSeries(series);

  chart->createDefaultAxes(); // Add default axes
  chart->legend()->hide();
  chart->setTitle(ui->func_cbox->currentText());
  ui->chartview->setChart(chart);
  connect(qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first()),
          &QValueAxis::rangeChanged, this, &MainWindow::zoom_slot);
}

void MainWindow::redraw_chart() { redraw_chart_ab(-10, 10); }

void MainWindow::solve_btn_clicked() {
  double a, b, tolerance;
  a = ui->left_border_spinbox->value();
  b = ui->right_border_spinbox->value();
  tolerance = ui->inacc_spinbox->value();

  if (a >= b) {
    QString errorMessage =
        "<font color='#ff0033'>Left border cannot be greater than/eq to "
        "right border</font>";
    QToolTip::showText(ui->left_border_spinbox->mapToGlobal(QPoint(0, 0)),
                       errorMessage);
    return;
  }

  int func = ui->func_cbox->currentIndex();
  int method = ui->method_cbox->currentIndex();

  double (*f)(double);
  Method *methodInstance = nullptr;

  switch (func) {
  case 0: {
    f = first;
  } break;
  case 1: {
    f = second;
  } break;
  case 2: {
    f = third;
  } break;
  case 3: {
    f = fourth;
  } break;
  }

  switch (method) {
  case 0:
    methodInstance = new HalfDivMehod(f, a, b, tolerance);
    break;
  case 1:
    methodInstance = new SecantMethod(f, a, b, tolerance);
    break;
  case 2:
    methodInstance = new SimpleIterationMethod(f, a, b, tolerance);
    break;
  }

  if (methodInstance != nullptr) {
    auto x = methodInstance->solve();
    qDebug() << x;
    delete methodInstance;
  }
}
