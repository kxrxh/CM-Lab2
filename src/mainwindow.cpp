#include "mainwindow.hpp"
#include "functions.hpp"
#include "half_div_method.hpp"
#include "method.hpp"
#include "newton_sys.hpp"
#include "secant_method.hpp"
#include "simple_iteration_method.hpp"
#include "systems.hpp"
#include <QtWebEngineWidgets>
#include <memory>
#include <qdebug.h>
#include <qlineseries.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  ui->setupUi(this);

  ui->text_output->acceptRichText();

  connect(ui->webEngineView, &QWebEngineView::loadFinished, this,
          &MainWindow::update_chart);
  connect(ui->clear_output, &QPushButton::clicked, ui->text_output,
          &QTextEdit::clear);
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
          SLOT(change_tab(int)));
  connect(ui->syst1_rb, &QRadioButton::clicked, this,
          &MainWindow::update_chart);
  connect(ui->syst2_rb, &QRadioButton::clicked, this,
          &MainWindow::update_chart);
}

void MainWindow::browse_btn_clicked() {
  QString filename = QFileDialog::getOpenFileName(
      nullptr, "Open File", QDir::currentPath(), "Script file (*)");
  if (filename.isEmpty()) {
    qDebug() << "No file was selected";
    return;
  }

  ui->textEdit->setText(filename);
}

void MainWindow::change_tab(int _index) { update_chart(); }

void MainWindow::draw_chart_ab() {
  QString latex_function;
  switch (ui->func_cbox->currentIndex()) {
  case 0:
    latex_function = "y=14.23x^{3}+8.1x^{2}-1.01x+0.64";
    break;
  case 1:
    latex_function = "y = x^3 + x^2 + 9.2";
    break;
  case 2:
    latex_function = R"(y = \\exp(0.24x) - 2)";
    break;
  case 3:
    latex_function = R"(y = 2*\\sin(x) + \\pi/2)";
    break;
  default:
    return;
  }

  QString js_expr = QString("calculator.setExpression({ id: 'graph', latex: "
                            "'%1' })")
                        .arg(latex_function);
  ui->webEngineView->page()->runJavaScript(js_expr);
  ui->webEngineView->page()->runJavaScript(
      "calculator.removeExpression({id: 'subgraph'})");
}

void MainWindow::draw_system_chart() {
  std::vector<QString> latex_functions(2);
  std::vector<QString> graph_names(2);
  if (ui->syst1_rb->isChecked()) {
    graph_names[0] = "graph";
    graph_names[1] = "subgraph";
    latex_functions[0] = R"(\\tan(2x+0.2y) = x^2)";
    latex_functions[1] = "4x^2+4y^2=1";
  } else {
    graph_names[0] = "graph";
    graph_names[1] = "subgraph";
    latex_functions[0] = R"(\\sin(x) = 3y)";
    latex_functions[1] = "xy + 2x^2 = 16";
  }

  QString js_expr = QString("calculator.setExpression({ id: '%1', latex: "
                            "'%2', color: Desmos.Colors.BLUE })")
                        .arg(graph_names[0], latex_functions[0]);
  qDebug() << js_expr;
  ui->webEngineView->page()->runJavaScript(js_expr);

  js_expr = QString("calculator.setExpression({ id: '%1', latex: '%2', color: "
                    "Desmos.Colors.RED })")
                .arg(graph_names[1], latex_functions[1]);

  qDebug() << js_expr;
  ui->webEngineView->page()->runJavaScript(js_expr);
}

void MainWindow::update_chart() {
  if (ui->tabWidget->currentIndex() == 0) {
    draw_chart_ab();
  } else {
    draw_system_chart();
  }
}

void MainWindow::solve_btn_clicked() {
  double a;
  double b;
  double tolerance;
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
  std::unique_ptr<Method> methodInstance;

  switch (func_indx) {
  case 0:
    f = first;
    break;
  case 1:
    f = second;
    break;
  case 2:
    f = third;
    break;
  case 3:
    f = fourth;
    break;
  default:
    return;
  }

  switch (method_indx) {
  case 0:
    methodInstance = std::make_unique<HalfDivMethod>(f, a, b, tolerance);
    break;
  case 1:
    methodInstance = std::make_unique<SecantMethod>(f, a, b, tolerance);
    break;
  case 2:
    methodInstance =
        std::make_unique<SimpleIterationMethod>(f, a, b, tolerance);
    break;
  default:
    return;
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

  double x0;
  double y0;
  double eps;
  x0 = ui->left_border_spinbox_sys->value();
  y0 = ui->right_border_spinbox_sys->value();
  eps = ui->inacc_spinbox_sys->value();

  auto [X, Y] = newton_solve(eqs, x0, y0, eps);

  ui->text_output->append("<b>Time:</b> " +
                          QDateTime::currentDateTime().toString());
  ui->text_output->append("<b>System:</b> " + (ui->syst1_rb->isChecked()
                                                   ? ui->text_eq1->toHtml()
                                                   : ui->text_eq2->toHtml()));
  ui->text_output->append("<b>Method:</b> Newton method for systems");
  ui->text_output->append("<b>Left border:</b> " + QString::number(x0));
  ui->text_output->append("<b>Right border:</b> " + QString::number(y0));
  ui->text_output->append("<b>Tolerance:</b> " + QString::number(eps));
  ui->text_output->append("<b>(X, Y):</b> " + QString::number(X) + " " +
                          QString::number(Y));
  ui->text_output->append(""); // Add a line break
}