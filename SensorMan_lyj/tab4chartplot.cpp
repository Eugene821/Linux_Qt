#include "tab4chartplot.h"
#include "ui_tab4chartplot.h"

Tab4ChartPlot::Tab4ChartPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab4ChartPlot)
{
    ui->setupUi(this);
    illuLine = new QLineSeries(this);
    illuLine->setName("조도");

    QPen pen;
    pen.setWidth(2);
    pen.setBrush(Qt::red);
    pen.setCapStyle(Qt::FlatCap);
    pen.setJoinStyle(Qt::MiterJoin);
    illuLine->setPen(pen);

    tempLine = new QLineSeries(this);
    tempLine->setName("온도");

    QPen tempPen;
    tempPen.setWidth(2);
    tempPen.setBrush(Qt::blue);
    tempPen.setCapStyle(Qt::FlatCap);
    tempPen.setJoinStyle(Qt::MiterJoin);
    tempLine->setPen(tempPen);

    humidLine = new QLineSeries(this);
    humidLine->setName("습도");

    QPen humidPen;
    humidPen.setWidth(2);
    humidPen.setBrush(Qt::green);
    humidPen.setCapStyle(Qt::FlatCap);
    humidPen.setJoinStyle(Qt::MiterJoin);
    humidLine->setPen(humidPen);

    chart = new QChart();
    chart->addSeries(illuLine);
    chart->addSeries(tempLine);
    chart->addSeries(humidLine);

    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 100);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->pChartViewLayout->layout()->addWidget(chartView);

    axisX = new QDateTimeAxis;
//    axisX->setFormat("MM-dd hh:mm");
    axisX->setFormat("hh:mm");

    updateLastDateTime(0);

    chartView->chart()->setAxisX(axisX, illuLine);
    chartView->chart()->setAxisX(axisX, tempLine);
    chartView->chart()->setAxisX(axisX, humidLine);

    connect(ui->pPBClearButton, SIGNAL(clicked()), this, SLOT(chartPlotClear()));
}
void Tab4ChartPlot::updateLastDateTime(int)
{
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();

    firstDate.setDate(date);
    firstDate.setTime(time);

    lastDate.setDate(date);
    QTime tempTime = time.addSecs(60*10);
    lastDate.setTime(tempTime);
    axisX->setRange(firstDate,lastDate);
}

void Tab4ChartPlot::chartPlotClear()
{
    illuLine->clear();   
    tempLine->clear();
    humidLine->clear();
    updateLastDateTime(0);
}

void Tab4ChartPlot::tab4RecvDataSlot(QString recvData)
{    
    QDate date = QDate::currentDate();
    QTime time = QTime::currentTime();
    QDateTime xValue;
    xValue.setDate(date);
    xValue.setTime(time);

    QStringList qlist = recvData.split("@");
    QString illu = qlist[3]; // 조도
    QString temp = qlist[4]; // 온도
    QString humid = qlist[5]; // 습도

    illuLine->append(xValue.toMSecsSinceEpoch(),illu.toInt());
    tempLine->append(xValue.toMSecsSinceEpoch(), temp.toDouble());
    humidLine->append(xValue.toMSecsSinceEpoch(), humid.toDouble());


}

Tab4ChartPlot::~Tab4ChartPlot()
{
    delete ui;
}
