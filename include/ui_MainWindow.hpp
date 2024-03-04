/********************************************************************************
** Form generated from reading UI file 'MainWindowheeHMM.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWHEEHMM_H
#define MAINWINDOWHEEHMM_H

#include <QtCharts/QChartView>
#include <QtCharts/chartsnamespace.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow {
public:
  QWidget *centralwidget;
  QTabWidget *tabWidget;
  QWidget *nonlin;
  QComboBox *func_cbox;
  QLabel *Functionlabel;
  QComboBox *method_cbox;
  QLabel *Functionlabel_2;
  QLabel *Functionlabel_3;
  QDoubleSpinBox *right_border_spinbox;
  QLabel *Functionlabel_4;
  QDoubleSpinBox *left_border_spinbox;
  QLabel *Functionlabel_5;
  QDoubleSpinBox *inacc_spinbox;
  QPushButton *solve_button;
  QLabel *Functionlabel_7;
  QPushButton *search_button;
  QPushButton *file_solve_button;
  QFrame *line;
  QTextEdit *textEdit;
  QWidget *syst;
  QTextBrowser *text_output;
  QPushButton *clear_output;
  QLabel *Functionlabel_9;
  QtCharts::QChartView *chartview;
  QMenuBar *menubar;
  QStatusBar *statusbar;

  void setupUi(QMainWindow *MainWindow) {
    if (MainWindow->objectName().isEmpty())
      MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1115, 1016);
    MainWindow->setMouseTracking(false);
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/assets/pig.png"), QSize(), QIcon::Normal,
                 QIcon::Off);
    MainWindow->setWindowIcon(icon);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMinimumSize(QSize(1115, 963));
    centralwidget->setMaximumSize(QSize(1115, 963));
    tabWidget = new QTabWidget(centralwidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setEnabled(true);
    tabWidget->setGeometry(QRect(6, 6, 1101, 321));
    tabWidget->setMinimumSize(QSize(1101, 321));
    QFont font;
    font.setPointSize(11);
    tabWidget->setFont(font);
    nonlin = new QWidget();
    nonlin->setObjectName(QString::fromUtf8("nonlin"));
    nonlin->setMinimumSize(QSize(1351, 980));
    nonlin->setMaximumSize(QSize(1351, 980));
    func_cbox = new QComboBox(nonlin);
    func_cbox->addItem(QString());
    func_cbox->addItem(QString());
    func_cbox->addItem(QString());
    func_cbox->addItem(QString());
    func_cbox->setObjectName(QString::fromUtf8("func_cbox"));
    func_cbox->setGeometry(QRect(20, 70, 281, 41));
    QFont font1;
    font1.setPointSize(12);
    func_cbox->setFont(font1);
    func_cbox->setEditable(false);
    func_cbox->setMaxVisibleItems(4);
    func_cbox->setMaxCount(4);
    Functionlabel = new QLabel(nonlin);
    Functionlabel->setObjectName(QString::fromUtf8("Functionlabel"));
    Functionlabel->setGeometry(QRect(20, 40, 311, 21));
    QFont font2;
    font2.setPointSize(20);
    font2.setBold(true);
    font2.setWeight(75);
    Functionlabel->setFont(font2);
    Functionlabel->setAlignment(Qt::AlignCenter);
    method_cbox = new QComboBox(nonlin);
    method_cbox->addItem(QString());
    method_cbox->addItem(QString());
    method_cbox->addItem(QString());
    method_cbox->setObjectName(QString::fromUtf8("method_cbox"));
    method_cbox->setGeometry(QRect(310, 70, 251, 41));
    method_cbox->setFont(font1);
    method_cbox->setEditable(false);
    method_cbox->setMaxVisibleItems(4);
    method_cbox->setMaxCount(4);
    Functionlabel_2 = new QLabel(nonlin);
    Functionlabel_2->setObjectName(QString::fromUtf8("Functionlabel_2"));
    Functionlabel_2->setGeometry(QRect(280, 40, 311, 21));
    Functionlabel_2->setFont(font2);
    Functionlabel_2->setAlignment(Qt::AlignCenter);
    Functionlabel_3 = new QLabel(nonlin);
    Functionlabel_3->setObjectName(QString::fromUtf8("Functionlabel_3"));
    Functionlabel_3->setGeometry(QRect(20, 130, 131, 31));
    QFont font3;
    font3.setPointSize(16);
    font3.setBold(true);
    font3.setWeight(75);
    Functionlabel_3->setFont(font3);
    Functionlabel_3->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                  Qt::AlignVCenter);
    right_border_spinbox = new QDoubleSpinBox(nonlin);
    right_border_spinbox->setObjectName(
        QString::fromUtf8("right_border_spinbox"));
    right_border_spinbox->setGeometry(QRect(190, 170, 131, 31));
    right_border_spinbox->setDecimals(4);
    right_border_spinbox->setMinimum(-100000000000000.000000000000000);
    right_border_spinbox->setMaximum(100000000000000.000000000000000);
    right_border_spinbox->setSingleStep(0.100000000000000);
    Functionlabel_4 = new QLabel(nonlin);
    Functionlabel_4->setObjectName(QString::fromUtf8("Functionlabel_4"));
    Functionlabel_4->setGeometry(QRect(190, 130, 141, 31));
    Functionlabel_4->setFont(font3);
    Functionlabel_4->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                  Qt::AlignVCenter);
    left_border_spinbox = new QDoubleSpinBox(nonlin);
    left_border_spinbox->setObjectName(
        QString::fromUtf8("left_border_spinbox"));
    left_border_spinbox->setGeometry(QRect(20, 170, 131, 31));
    left_border_spinbox->setDecimals(4);
    left_border_spinbox->setMinimum(-100000000000000.000000000000000);
    left_border_spinbox->setMaximum(1000000000000000.000000000000000);
    left_border_spinbox->setSingleStep(0.100000000000000);
    Functionlabel_5 = new QLabel(nonlin);
    Functionlabel_5->setObjectName(QString::fromUtf8("Functionlabel_5"));
    Functionlabel_5->setGeometry(QRect(360, 130, 141, 29));
    Functionlabel_5->setFont(font3);
    Functionlabel_5->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                  Qt::AlignVCenter);
    inacc_spinbox = new QDoubleSpinBox(nonlin);
    inacc_spinbox->setObjectName(QString::fromUtf8("inacc_spinbox"));
    inacc_spinbox->setGeometry(QRect(360, 170, 131, 29));
    inacc_spinbox->setAccelerated(false);
    inacc_spinbox->setDecimals(7);
    inacc_spinbox->setMinimum(0.000000000000000);
    inacc_spinbox->setMaximum(1.000000000000000);
    inacc_spinbox->setSingleStep(0.000001000000000);
    inacc_spinbox->setValue(0.000001000000000);
    solve_button = new QPushButton(nonlin);
    solve_button->setObjectName(QString::fromUtf8("solve_button"));
    solve_button->setGeometry(QRect(160, 210, 221, 41));
    QFont font4;
    font4.setPointSize(11);
    font4.setBold(true);
    font4.setWeight(75);
    solve_button->setFont(font4);
    Functionlabel_7 = new QLabel(nonlin);
    Functionlabel_7->setObjectName(QString::fromUtf8("Functionlabel_7"));
    Functionlabel_7->setGeometry(QRect(730, 30, 311, 41));
    Functionlabel_7->setFont(font2);
    Functionlabel_7->setAlignment(Qt::AlignCenter);
    search_button = new QPushButton(nonlin);
    search_button->setObjectName(QString::fromUtf8("search_button"));
    search_button->setGeometry(QRect(990, 80, 41, 41));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/assets/search.png"), QSize(),
                  QIcon::Normal, QIcon::Off);
    search_button->setIcon(icon1);
    search_button->setIconSize(QSize(24, 24));
    search_button->setFlat(true);
    file_solve_button = new QPushButton(nonlin);
    file_solve_button->setObjectName(QString::fromUtf8("file_solve_button"));
    file_solve_button->setGeometry(QRect(740, 130, 291, 61));
    file_solve_button->setFont(font4);
    line = new QFrame(nonlin);
    line->setObjectName(QString::fromUtf8("line"));
    line->setGeometry(QRect(670, 0, 20, 291));
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    textEdit = new QTextEdit(nonlin);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));
    textEdit->setGeometry(QRect(770, 80, 221, 41));
    QFont font5;
    font5.setPointSize(9);
    textEdit->setFont(font5);
    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/assets/afanas.jpg"), QSize(),
                  QIcon::Normal, QIcon::Off);
    tabWidget->addTab(nonlin, icon2, QString());
    syst = new QWidget();
    syst->setObjectName(QString::fromUtf8("syst"));
    QIcon icon3;
    icon3.addFile(QString::fromUtf8(":/assets/klim.jpg"), QSize(),
                  QIcon::Normal, QIcon::Off);
    tabWidget->addTab(syst, icon3, QString());
    text_output = new QTextBrowser(centralwidget);
    text_output->setObjectName(QString::fromUtf8("text_output"));
    text_output->setGeometry(QRect(10, 720, 1091, 241));
    clear_output = new QPushButton(centralwidget);
    clear_output->setObjectName(QString::fromUtf8("clear_output"));
    clear_output->setGeometry(QRect(1040, 720, 61, 38));
    clear_output->setFont(font4);
    clear_output->setFlat(true);
    Functionlabel_9 = new QLabel(centralwidget);
    Functionlabel_9->setObjectName(QString::fromUtf8("Functionlabel_9"));
    Functionlabel_9->setGeometry(QRect(10, 680, 98, 36));
    Functionlabel_9->setFont(font2);
    Functionlabel_9->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                  Qt::AlignVCenter);
    chartview = new QtCharts::QChartView(centralwidget);
    chartview->setObjectName(QString::fromUtf8("chartview"));
    chartview->setGeometry(QRect(60, 330, 1001, 351));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1115, 30));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
    Functionlabel->setBuddy(func_cbox);
    Functionlabel_2->setBuddy(method_cbox);
    Functionlabel_3->setBuddy(left_border_spinbox);
    Functionlabel_4->setBuddy(right_border_spinbox);
    Functionlabel_5->setBuddy(inacc_spinbox);
    Functionlabel_7->setBuddy(textEdit);
#endif // QT_CONFIG(shortcut)

    retranslateUi(MainWindow);

    tabWidget->setCurrentIndex(0);
    func_cbox->setCurrentIndex(0);
    method_cbox->setCurrentIndex(0);
    clear_output->setDefault(false);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow) {
    MainWindow->setWindowTitle(QCoreApplication::translate(
        "MainWindow", "Laboratory work #2", nullptr));
    func_cbox->setItemText(0, QCoreApplication::translate(
                                  "MainWindow",
                                  "y = 14.23x^3 + 8.1x^2\342\210\2221.01x+0.64",
                                  nullptr));
    func_cbox->setItemText(1, QCoreApplication::translate("MainWindow",
                                                          "y = x^3 + x^2 + 9.2",
                                                          nullptr));
    func_cbox->setItemText(2, QCoreApplication::translate("MainWindow",
                                                          "y = exp(2.74x) - 54",
                                                          nullptr));
    func_cbox->setItemText(3, QCoreApplication::translate("MainWindow",
                                                          "y = 2*sin(x) + pi/2",
                                                          nullptr));

    func_cbox->setCurrentText(QCoreApplication::translate(
        "MainWindow", "y = 14.23x^3 + 8.1x^2\342\210\2221.01x+0.64", nullptr));
    Functionlabel->setText(
        QCoreApplication::translate("MainWindow", "Function", nullptr));
    method_cbox->setItemText(
        0, QCoreApplication::translate("MainWindow",
                                       "The method of half division", nullptr));
    method_cbox->setItemText(1, QCoreApplication::translate("MainWindow",
                                                            "The secant method",
                                                            nullptr));
    method_cbox->setItemText(
        2, QCoreApplication::translate("MainWindow",
                                       "The simple iteration method", nullptr));

    method_cbox->setCurrentText(QCoreApplication::translate(
        "MainWindow", "The method of half division", nullptr));
    Functionlabel_2->setText(
        QCoreApplication::translate("MainWindow", "Method", nullptr));
    Functionlabel_3->setText(
        QCoreApplication::translate("MainWindow", "Left border", nullptr));
    Functionlabel_4->setText(
        QCoreApplication::translate("MainWindow", "Right border", nullptr));
    Functionlabel_5->setText(
        QCoreApplication::translate("MainWindow", "Inaccuracy", nullptr));
    solve_button->setText(
        QCoreApplication::translate("MainWindow", "Solve", nullptr));
    Functionlabel_7->setText(QCoreApplication::translate(
        "MainWindow", "Load preset from file", nullptr));
    search_button->setText(QString());
    file_solve_button->setText(QCoreApplication::translate(
        "MainWindow", "Solve using file data", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(nonlin),
                          QCoreApplication::translate(
                              "MainWindow", "The nonlinear equation", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(syst),
        QCoreApplication::translate(
            "MainWindow", "The system of nonlinear equations", nullptr));
    clear_output->setText(
        QCoreApplication::translate("MainWindow", "Clear", nullptr));
    Functionlabel_9->setText(
        QCoreApplication::translate("MainWindow", "Output", nullptr));
  } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWHEEHMM_H
