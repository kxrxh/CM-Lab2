/********************************************************************************
** Form generated from reading UI file 'MainWindowBNwdOx.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWBNWDOX_H
#define MAINWINDOWBNWDOX_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
  QLabel *Functionlabel_8;
  QRadioButton *syst1_rb;
  QRadioButton *syst2_rb;
  QTextBrowser *text_eq1;
  QTextBrowser *text_eq2;
  QTextEdit *textEdit_sys;
  QLabel *Functionlabel_16;
  QLabel *Functionlabel_17;
  QDoubleSpinBox *left_border_spinbox_sys;
  QLabel *Functionlabel_18;
  QPushButton *solve_button_3;
  QDoubleSpinBox *right_border_spinbox_sys;
  QPushButton *search_button_sys;
  QPushButton *file_solve_button_sys;
  QLabel *Functionlabel_19;
  QDoubleSpinBox *inacc_spinbox_sys;
  QFrame *line_3;
  QTextBrowser *text_output;
  QPushButton *clear_output;
  QLabel *Functionlabel_9;
  QPushButton *save_btn;
  QWebEngineView *webEngineView;
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
    MainWindow->setFixedSize(1115, 1016);
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
    Functionlabel_8 = new QLabel(syst);
    Functionlabel_8->setObjectName(QString::fromUtf8("Functionlabel_8"));
    Functionlabel_8->setGeometry(QRect(70, 20, 311, 41));
    Functionlabel_8->setFont(font2);
    Functionlabel_8->setAlignment(Qt::AlignCenter);
    syst1_rb = new QRadioButton(syst);
    syst1_rb->setObjectName(QString::fromUtf8("syst1_rb"));
    syst1_rb->setGeometry(QRect(40, 91, 21, 31));
    syst1_rb->setChecked(true);
    syst2_rb = new QRadioButton(syst);
    syst2_rb->setObjectName(QString::fromUtf8("syst2_rb"));
    syst2_rb->setGeometry(QRect(40, 170, 21, 31));
    text_eq1 = new QTextBrowser(syst);
    text_eq1->setObjectName(QString::fromUtf8("text_eq1"));
    text_eq1->setGeometry(QRect(70, 70, 161, 71));
    text_eq1->setFont(font1);
    text_eq1->setAutoFillBackground(true);
    text_eq1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text_eq1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text_eq2 = new QTextBrowser(syst);
    text_eq2->setObjectName(QString::fromUtf8("text_eq2"));
    text_eq2->setGeometry(QRect(70, 150, 161, 71));
    text_eq2->setFont(font1);
    text_eq2->setAutoFillBackground(true);
    text_eq2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text_eq2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    textEdit_sys = new QTextEdit(syst);
    textEdit_sys->setObjectName(QString::fromUtf8("textEdit_sys"));
    textEdit_sys->setGeometry(QRect(780, 110, 221, 41));
    textEdit_sys->setFont(font5);
    Functionlabel_16 = new QLabel(syst);
    Functionlabel_16->setObjectName(QString::fromUtf8("Functionlabel_16"));
    Functionlabel_16->setGeometry(QRect(390, 70, 141, 29));
    Functionlabel_16->setFont(font3);
    Functionlabel_16->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                   Qt::AlignVCenter);
    Functionlabel_17 = new QLabel(syst);
    Functionlabel_17->setObjectName(QString::fromUtf8("Functionlabel_17"));
    Functionlabel_17->setGeometry(QRect(240, 150, 141, 31));
    Functionlabel_17->setFont(font3);
    Functionlabel_17->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                   Qt::AlignVCenter);
    left_border_spinbox_sys = new QDoubleSpinBox(syst);
    left_border_spinbox_sys->setObjectName(
        QString::fromUtf8("left_border_spinbox_sys"));
    left_border_spinbox_sys->setGeometry(QRect(240, 110, 131, 31));
    left_border_spinbox_sys->setDecimals(4);
    left_border_spinbox_sys->setMinimum(-100000000000000.000000000000000);
    left_border_spinbox_sys->setMaximum(1000000000000000.000000000000000);
    left_border_spinbox_sys->setSingleStep(0.100000000000000);
    Functionlabel_18 = new QLabel(syst);
    Functionlabel_18->setObjectName(QString::fromUtf8("Functionlabel_18"));
    Functionlabel_18->setGeometry(QRect(740, 60, 311, 41));
    Functionlabel_18->setFont(font2);
    Functionlabel_18->setAlignment(Qt::AlignCenter);
    solve_button_3 = new QPushButton(syst);
    solve_button_3->setObjectName(QString::fromUtf8("solve_button_3"));
    solve_button_3->setGeometry(QRect(390, 160, 121, 71));
    solve_button_3->setFont(font4);
    right_border_spinbox_sys = new QDoubleSpinBox(syst);
    right_border_spinbox_sys->setObjectName(
        QString::fromUtf8("right_border_spinbox_sys"));
    right_border_spinbox_sys->setGeometry(QRect(240, 190, 131, 31));
    right_border_spinbox_sys->setDecimals(4);
    right_border_spinbox_sys->setMinimum(-100000000000000.000000000000000);
    right_border_spinbox_sys->setMaximum(100000000000000.000000000000000);
    right_border_spinbox_sys->setSingleStep(0.100000000000000);
    search_button_sys = new QPushButton(syst);
    search_button_sys->setObjectName(QString::fromUtf8("search_button_sys"));
    search_button_sys->setGeometry(QRect(1000, 110, 41, 41));
    search_button_sys->setIcon(icon1);
    search_button_sys->setIconSize(QSize(24, 24));
    search_button_sys->setFlat(true);
    file_solve_button_sys = new QPushButton(syst);
    file_solve_button_sys->setObjectName(
        QString::fromUtf8("file_solve_button_sys"));
    file_solve_button_sys->setGeometry(QRect(750, 160, 291, 61));
    file_solve_button_sys->setFont(font4);
    Functionlabel_19 = new QLabel(syst);
    Functionlabel_19->setObjectName(QString::fromUtf8("Functionlabel_19"));
    Functionlabel_19->setGeometry(QRect(240, 70, 131, 31));
    Functionlabel_19->setFont(font3);
    Functionlabel_19->setAlignment(Qt::AlignLeading | Qt::AlignLeft |
                                   Qt::AlignVCenter);
    inacc_spinbox_sys = new QDoubleSpinBox(syst);
    inacc_spinbox_sys->setObjectName(QString::fromUtf8("inacc_spinbox_sys"));
    inacc_spinbox_sys->setGeometry(QRect(390, 110, 131, 31));
    inacc_spinbox_sys->setAccelerated(false);
    inacc_spinbox_sys->setDecimals(7);
    inacc_spinbox_sys->setMinimum(0.000000000000000);
    inacc_spinbox_sys->setMaximum(1.000000000000000);
    inacc_spinbox_sys->setSingleStep(0.000001000000000);
    inacc_spinbox_sys->setValue(0.000001000000000);
    line_3 = new QFrame(syst);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setGeometry(QRect(660, 0, 20, 291));
    line_3->setFrameShape(QFrame::VLine);
    line_3->setFrameShadow(QFrame::Sunken);
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
    save_btn = new QPushButton(centralwidget);
    save_btn->setObjectName(QString::fromUtf8("save_btn"));
    save_btn->setGeometry(QRect(1000, 930, 101, 31));
    save_btn->setFont(font4);
    webEngineView = new QWebEngineView(centralwidget);
    webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
    webEngineView->setGeometry(QRect(9, 339, 1091, 331));
    QString html = R"(
<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script src="https://www.desmos.com/api/v1.8/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6"></script>
</head>
<body>
    <div id="calculator" style="height: 311px; width: 100%;"></div>
    <script>
        var elt = document.getElementById('calculator');
        var calculator = Desmos.GraphingCalculator(elt);
    </script>
</body>
</html>
)";
    webEngineView->setHtml(html);
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
    Functionlabel_8->setBuddy(func_cbox);
    Functionlabel_16->setBuddy(inacc_spinbox);
    Functionlabel_17->setBuddy(right_border_spinbox);
    Functionlabel_18->setBuddy(textEdit);
    Functionlabel_19->setBuddy(left_border_spinbox);
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
    func_cbox->setItemText(
        0, QCoreApplication::translate(
               "MainWindow", "y = 14.23x^3 + 8.1x^2 - 1.01x +0.64", nullptr));
    func_cbox->setItemText(1, QCoreApplication::translate("MainWindow",
                                                          "y = x^3 + x^2 + 9.2",
                                                          nullptr));
    func_cbox->setItemText(2, QCoreApplication::translate(
                                  "MainWindow", "y = exp(0.24x) - 2", nullptr));
    func_cbox->setItemText(3, QCoreApplication::translate("MainWindow",
                                                          "y = 2*sin(x) + pi/2",
                                                          nullptr));

    func_cbox->setCurrentText(QCoreApplication::translate(
        "MainWindow", "y = 14.23x^3 + 8.1x^2 - 1.01x +0.64", nullptr));
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
    Functionlabel_8->setText(QCoreApplication::translate(
        "MainWindow", "System of equations", nullptr));
    syst1_rb->setText(QString());
    syst2_rb->setText(QString());
    text_eq1->setHtml(QCoreApplication::translate(
        "MainWindow",
        "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" "
        "\"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
        "<html><head><meta name=\"qrichtext\" content=\"1\" /><style "
        "type=\"text/css\">\n"
        "p, li { white-space: pre-wrap; }\n"
        "</style></head><body style=\" font-family:'Noto Sans'; "
        "font-size:12pt; font-weight:400; font-style:normal;\">\n"
        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
        "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
        "style=\" font-size:14pt; font-style:italic;\">tg(2x + 0.2y) = "
        "x</span><span style=\" font-size:14pt; font-style:italic; "
        "vertical-align:super;\">2</span></p>\n"
        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
        "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
        "style=\" font-size:14pt; font-style:italic;\">4x</span><span style=\" "
        "font-size:14pt; font-style:italic; "
        "vertical-align:super;\">2</span><span style=\" font-size:14pt; "
        "font-style:italic;\"> + 4y</span><span style=\" font-size:14pt; "
        "font-style:italic; vertical-align:super;\""
        ">2</span><span style=\" font-size:14pt; "
        "font-style:italic;\">=1</span></p></body></html>",
        nullptr));
    text_eq2->setHtml(QCoreApplication::translate(
        "MainWindow",
        "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" "
        "\"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
        "<html><head><meta name=\"qrichtext\" content=\"1\" /><style "
        "type=\"text/css\">\n"
        "p, li { white-space: pre-wrap; }\n"
        "</style></head><body style=\" font-family:'Noto Sans'; "
        "font-size:12pt; font-weight:400; font-style:normal;\">\n"
        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
        "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
        "style=\" font-size:14pt; font-style:italic;\">sin(x) = 3y</span></p>\n"
        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; "
        "margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
        "style=\" font-size:14pt; font-style:italic;\">xy + 2x</span><span "
        "style=\" font-size:14pt; font-style:italic; "
        "vertical-align:super;\">2</span><span style=\" font-size:14pt; "
        "font-style:italic;\">=16</span></p></body></html>",
        nullptr));
    Functionlabel_16->setText(
        QCoreApplication::translate("MainWindow", "Inaccuracy", nullptr));
    Functionlabel_17->setText(
        QCoreApplication::translate("MainWindow", "Right border", nullptr));
    Functionlabel_18->setText(QCoreApplication::translate(
        "MainWindow", "Load preset from file", nullptr));
    solve_button_3->setText(
        QCoreApplication::translate("MainWindow", "Solve", nullptr));
    search_button_sys->setText(QString());
    file_solve_button_sys->setText(QCoreApplication::translate(
        "MainWindow", "Solve using file data", nullptr));
    Functionlabel_19->setText(
        QCoreApplication::translate("MainWindow", "Left border", nullptr));
    tabWidget->setTabText(
        tabWidget->indexOf(syst),
        QCoreApplication::translate(
            "MainWindow", "The system of nonlinear equations", nullptr));
    clear_output->setText(
        QCoreApplication::translate("MainWindow", "Clear", nullptr));
    Functionlabel_9->setText(
        QCoreApplication::translate("MainWindow", "Output", nullptr));
    save_btn->setText(
        QCoreApplication::translate("MainWindow", "Save result", nullptr));
  } // retranslateUi
};

namespace Ui {
class MainWindow : public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWBNWDOX_H
