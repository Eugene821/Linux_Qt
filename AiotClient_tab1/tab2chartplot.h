#ifndef TAB2CHARTPLOT_H
#define TAB2CHARTPLOT_H

#include <QWidget>
#include <QLineSeries>
#include <QChartView>
#include <QDebug>
#include <QDateTimeAxis>
#include <QDate>
#include <QTime>
QT_CHARTS_USE_NAMESPACE
namespace Ui {
class Tab2ChartPlot;
}

class Tab2ChartPlot : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2ChartPlot(QWidget *parent = nullptr);
    ~Tab2ChartPlot();

private:
    Ui::Tab2ChartPlot *ui;
    QLineSeries* illuLine;
    QChart *chart = nullptr;
    QChartView *chartView = nullptr;
    QDateTimeAxis * axisX;
    QDateTime firstDate;
    QDateTime lastDate;
private slots:
    void chartPlotClear();
    void tab2RecvDataSlot(QString);
    void updateLastDateTime(int);
};

#endif // TAB2CHARTPLOT_H

