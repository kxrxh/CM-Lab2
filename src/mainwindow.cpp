#include "mainwindow.hpp"
#include "ui_MainWindow.hpp"
#include <QDebug>
#include <QFileDialog>

void MainWindow::updateTable(int mode) {
  qDebug() << "Updating table header: (" << mode << ")";
  auto &table = ui->result_table;
  table->clear();
  QStringList headers;

  switch (mode) {
  case 0: {
    table->setColumnCount(8);
    headers << "#"
            << "a"
            << "b"
            << "x"
            << "f(a)"
            << "f(b)"
            << "f(x)"
            << "|a - b|";
  } break;
  case 1: {
    table->setColumnCount(6);
    headers << "#"
            << "x_k-1"
            << "x_k"
            << "x_k+1"
            << "f(x_k+1)"
            << "|x_k+1 - x_k|";
  } break;
  case 2: {
    table->setColumnCount(5);
    headers << "#"
            << "x_k"
            << "x_k+1"
            << "f(x_k+1)"
            << "|x_k+1 - x_k|";
  } break;
  default: {
  } break;
  }

  table->setHorizontalHeaderLabels(headers);
  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->clear_output, &QPushButton::clicked, this,
          &MainWindow::clear_btn_clicked);
  connect(ui->search_button, &QPushButton::clicked, this,
          &MainWindow::browse_btn_clicked);
  connect(ui->method_cbox, QOverload<int>::of(&QComboBox::currentIndexChanged),
          this, &MainWindow::method_changed);
  updateTable(ui->method_cbox->currentIndex());
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

  ui->textEdit->setText(file);
}

void MainWindow::method_changed() {
  updateTable(ui->method_cbox->currentIndex());
}