#ifndef A16E785F_351C_4E6E_93AC_98ED657BCA66
#define A16E785F_351C_4E6E_93AC_98ED657BCA66

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <qtabwidget.h>

class ChartView : public QtCharts::QChartView {
public:
  ChartView(QWidget *parent = nullptr) : QtCharts::QChartView(parent) {}

protected:
  void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE {
    qreal factor = event->angleDelta().y() > 0 ? 0.8 : 1.2;
    chart()->zoom(factor);
    event->accept();
    QChartView::wheelEvent(event);
  }

  void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE {
    if (event->button() == Qt::MiddleButton) {
      event->accept();
      chart()->zoomReset();
      return;
    }

    QChartView::mousePressEvent(event);
  }
};

#endif /* A16E785F_351C_4E6E_93AC_98ED657BCA66 */
