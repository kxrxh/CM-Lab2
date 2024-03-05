#include "mainwindow.hpp"
#include "functions.hpp"
#include "half_div_method.hpp"
#include "method.hpp"
#include "newton_sys.hpp"
#include "secant_method.hpp"
#include "simple_iteration_method.hpp"
#include "systems.hpp"
#include <qlineseries.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Create a chart view
  ui->chartview->setRenderHint(QPainter::Antialiasing);
  ui->chartview->setRubberBand(QChartView::HorizontalRubberBand);
  ui->chartview->setToolTip("Right click to zoom in, left click to zoom out");

  ui->text_output->acceptRichText();

  redraw_chart(0);

  connect(ui->clear_output, &QPushButton::clicked, this,
          &MainWindow::clear_btn_clicked);
  connect(ui->search_button, &QPushButton::clicked, this,
          &MainWindow::browse_btn_clicked);
  connect(ui->func_cbox, &QComboBox::currentTextChanged, this,
          &MainWindow::update_chart);
  connect(ui->solve_button, &QPushButton::clicked, this,
          &MainWindow::solve_btn_clicked);
  connect(ui->save_btn, &QPushButton::clicked, this,
          &MainWindow::save_result_btn_clicked);
  connect(ui->file_solve_button, &QPushButton::clicked, this,
          &MainWindow::solve_script_btn_clicked);
  connect(ui->file_solve_button_sys, &QPushButton::clicked, this,
          &MainWindow::solve_script_btn_clicked);
  connect(ui->solve_button_3, &QPushButton::clicked, this,
          &MainWindow::solve_sys_btn_clicked);
  connect(ui->tabWidget, SIGNAL(currentChanged(int)), this,
          SLOT(redraw_chart(int)));
}

MainWindow::~MainWindow() {}

void MainWindow::clear_btn_clicked() { ui->text_output->clear(); }

void MainWindow::browse_btn_clicked() {
  QString filename = QFileDialog::getOpenFileName(
      nullptr, "Open File", QDir::currentPath(), "Script file (*)");
  if (filename.isEmpty()) {
    qDebug() << "No file was selected";
    return;
  }

  ui->textEdit->setText(filename);
}

// void MainWindow::zoom_slot() {
// QValueAxis *xAxis = qobject_cast<QValueAxis *>(
//     ui->chartview->chart()->axes(Qt::Horizontal).first());

// // Check if the X-axis is successfully obtained
// if (xAxis) {
//   // Get the current range of the X-axis
//   qreal minX = xAxis->min();
//   qreal maxX = xAxis->max();

//   // redraw_chart_ab(minX, maxX);
// } else {
//   qDebug() << "Failed to get X-axis";
// }
//}

void MainWindow::draw_chart_ab(double a, double b) {
  const double step = 0.1;
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
    for (double x = -40; x <= 60; x += step) {
      double fx = third(x);
      if (fx == INFINITY)
        continue;
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
  chart->createDefaultAxes();
  chart->legend()->hide();
  chart->setTitle(ui->func_cbox->currentText());
  ui->chartview->setChart(chart);
  // connect(qobject_cast<QValueAxis *>(chart->axes(Qt::Horizontal).first()),
  //         &QValueAxis::rangeChanged, this, &MainWindow::zoom_slot);
}

void MainWindow::draw_system_chart(double a, double b) {
  const double step = 0.1;
  QLineSeries *series1 = new QLineSeries();
  QLineSeries *series2 = new QLineSeries();
  series2->setColor(Qt::red);

  EquationSystem system =
      (ui->syst1_rb->isChecked() ? first_system() : second_system());

  // Добавление точек на график для первого уравнения
  for (float x = -10.0; x <= 10.0; x += 0.1) {
    float y = system.first(
        x, x); // Используйте одинаковые x и y для первого уравнения
    series1->append(x, y);
  }

  // Добавление точек на график для второго уравнения
  for (float x = -10.0; x <= 10.0; x += 0.1) {
    float y = system.second(
        x, x); // Используйте одинаковые x и y для второго уравнения
    series2->append(x, y);
  }

  QChart *chart = new QChart();
  chart->addSeries(series1);
  chart->addSeries(series2);
  chart->setTitle("Graph of Equation System");
  chart->createDefaultAxes();
  chart->legend()->hide();

  ui->chartview->setChart(chart);
}

void MainWindow::update_chart() { draw_chart_ab(-500, 500); }

void MainWindow::redraw_chart(int index) {
  if (index == 0) {
    draw_chart_ab(-500, 500);
  } else {
    draw_system_chart(-200, 200);
  }
}
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

  int func_indx = ui->func_cbox->currentIndex();
  int method_indx = ui->method_cbox->currentIndex();

  double (*f)(double);
  Method *methodInstance = nullptr;

  switch (func_indx) {
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

  switch (method_indx) {
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
    auto it = methodInstance->get_it();
    ui->text_output->append("<b>Time:</b> " +
                            QDateTime::currentDateTime().toString());
    ui->text_output->append("<b>Function:</b> " + ui->func_cbox->currentText());
    ui->text_output->append("<b>Method:</b> " + ui->method_cbox->currentText());
    ui->text_output->append("<b>Left border:</b> " + QString::number(a));
    ui->text_output->append("<b>Right border:</b> " + QString::number(b));
    ui->text_output->append("<b>Tolerance:</b> " + QString::number(tolerance));
    ui->text_output->append("<b>Iterations:</b> " + QString::number(it));
    ui->text_output->append("<b>Root:</b> " + QString::number(x));
    ui->text_output->append("<b>F(x):</b> " + QString::number(f(x)));
    ui->text_output->append(""); // Add a line break
    delete methodInstance;
  }
}

void MainWindow::save_result_btn_clicked() {
  QString filename =
      QFileDialog::getSaveFileName(this, tr("Save File"), "", "*.txt");
  if (filename.isEmpty()) {
    return;
  }
  QFile file(filename);

  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::information(this, tr("Unable to open file"),
                             file.errorString());
    return;
  }

  QTextStream out(&file);

  out << ui->text_output->toPlainText();
}

bool MainWindow::validate_script(const Script &script) const {
  if (ui->tabWidget->currentIndex() == 0) {
    if (script.get_function_indx() < 0 ||
        script.get_function_indx() > ui->func_cbox->count() - 1) {
      return false;
    }
  } else {
    if (script.get_function_indx() < 0 || script.get_function_indx() >= 2) {
      return false;
    }
  }

  if (script.get_method_indx() < 0 ||
      script.get_method_indx() > ui->method_cbox->count() - 1) {
    return false;
  }

  if (script.get_tol() < 0) {
    return false;
  }

  return true;
}

void MainWindow::solve_script_btn_clicked() {
  QString filename;
  if (ui->tabWidget->currentIndex() == 0) {
    filename = ui->textEdit->toPlainText();
  } else {
    filename = ui->textEdit_sys->toPlainText();
  }
  Script script(ui->textEdit->toPlainText());
  if (!this->validate_script(script)) {
    QMessageBox::warning(
        this, "Invalid script",
        "Please, provide valid script file.\nDouble check your "
        "indexes and try again.");
    return;
  }

  if (ui->tabWidget->currentIndex() == 0) {
    ui->func_cbox->setCurrentIndex(script.get_function_indx());
    ui->method_cbox->setCurrentIndex(script.get_method_indx());
    ui->left_border_spinbox->setValue(script.get_left_border());
    ui->right_border_spinbox->setValue(script.get_right_border());
    ui->inacc_spinbox->setValue(script.get_tol());
  } else {
    if (script.get_function_indx() == 0) {
      ui->syst1_rb->setChecked(true);
    } else {
      ui->syst2_rb->setChecked(true);
    }

    ui->left_border_spinbox_sys->setValue(script.get_left_border());
    ui->right_border_spinbox_sys->setValue(script.get_right_border());
    ui->inacc_spinbox_sys->setValue(script.get_tol());
  }
  if (ui->tabWidget->currentIndex() == 0) {
    this->solve_btn_clicked();
    return;
  }

  this->solve_sys_btn_clicked();
}

void MainWindow::solve_sys_btn_clicked() {
  EquationSystem eqs;
  if (ui->syst1_rb->isChecked()) {
    eqs = first_system();
  } else {
    eqs = second_system();
  }

  double x0, y0, eps;
  x0 = ui->left_border_spinbox_sys->value();
  y0 = ui->right_border_spinbox_sys->value();
  eps = ui->inacc_spinbox_sys->value();

  auto result = newton_solve(eqs, x0, y0, eps);

  ui->text_output->append("<b>Time:</b> " +
                          QDateTime::currentDateTime().toString());
  ui->text_output->append("<b>System:</b> " + (ui->syst1_rb->isChecked()
                                                   ? ui->text_eq1->toHtml()
                                                   : ui->text_eq2->toHtml()));
  ui->text_output->append("<b>Method:</b> Newton method for systems");
  ui->text_output->append("<b>Left border:</b> " + QString::number(x0));
  ui->text_output->append("<b>Right border:</b> " + QString::number(y0));
  ui->text_output->append("<b>Tolerance:</b> " + QString::number(eps));
  ui->text_output->append("<b>(X, Y):</b> " + QString::number(result.first) +
                          " " + QString::number(result.second));
  ui->text_output->append(""); // Add a line break
}