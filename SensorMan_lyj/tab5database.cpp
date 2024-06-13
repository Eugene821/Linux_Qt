#include "tab5database.h"
#include "ui_tab5database.h"

Tab5Database::Tab5Database(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab5Database)
{
    ui->setupUi(this);
    qSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    qSqlDatabase.setDatabaseName("aiot.db");
    if(qSqlDatabase.open())
        qDebug() << "succcess DB connection\n";
    else
        qDebug() << "fail DB connection\n";

    QString strQuery = "CREATE TABLE IF NOT EXISTS sensor_tb ("
                        "name VARCHAR(10),"
                        "date DATETIME primary key,"
                        "illu VARCHAR(10),"
                        "temp VARCHAR(10),"
                        "humid VARCHAR(10)"
                        ")";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery))
        ;
    else
        qDebug() << "create table\n";

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
//   chart->legend()->hide();
    chart->addSeries(illuLine);
    chart->addSeries(tempLine);
    chart->addSeries(humidLine);

//    chart->setTitle("illumination chart");
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 100);
//    chart->axes(Qt::Horizontal).first()->setRange(0, 24);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->pChartViewLayout->layout()->addWidget(chartView);

    axisX = new QDateTimeAxis;
//    axisX->setFormat("MM-dd hh:mm");
    axisX->setFormat("hh:mm");

    updateLastDateTimeSql(0);

    chartView->chart()->setAxisX(axisX,illuLine);
    chartView->chart()->setAxisX(axisX,tempLine);
    chartView->chart()->setAxisX(axisX,humidLine);

    connect(ui->pPBsearchDb,SIGNAL(clicked()), this, SLOT(searchDbSlot()));
    connect(ui->pPBdeleteDb,SIGNAL(clicked()), this, SLOT(deleteDbSlot()));
}
void Tab5Database::updateLastDateTime(int)
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
void Tab5Database::updateLastDateTimeSql(int)
{
    int row_count = 0;
    QDateTime from_dateTime = ui->pDateTimeEditFrom->dateTime();
    QString from_strDateTime = from_dateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime to_dateTime = ui->pDateTimeEditTo->dateTime();
    QString to_strDateTime = to_dateTime.toString("yyyy/MM/dd hh:mm:ss");

    QString strQuery = "select * from sensor_tb where date > '" + from_strDateTime + "' AND date < '" + to_strDateTime + "'";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery)){

    } else {
//        qDebug() << "select query ok";
        sqlQuery.first();
        firstDate = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
        sqlQuery.last();
        lastDate = QDateTime::fromString(sqlQuery.value("date").toString(), "yyyy/MM/dd hh:mm:ss");
    }
    if(!firstDate.isValid())
        firstDate = QDateTime::fromString(from_strDateTime, "yyyy/MM/dd hh:mm:ss");
    if(!lastDate.isValid())
        lastDate = QDateTime::fromString(to_strDateTime, "yyyy/MM/dd hh:mm:ss");
//    qDebug() << firstDate;
//    qDebug() << lastDate;
    axisX->setRange(firstDate,lastDate);
}
void Tab5Database::tab5RecvDataSlot(QString recvData)
{
//    qDebug() << "Tab5 " << recvData;
    QDateTime dateTime = QDateTime::currentDateTime();
    QStringList qlist = recvData.split("@");
    QString name = qlist[1];        //조도
    QString illu = qlist[3];        //조도
    QString temp = qlist[4];        //조도
    QString humid = qlist[5];        //조도

    QString strQuery = "INSERT INTO sensor_tb(name, date, illu, temp, humid) VALUES('" + name + "', '" + dateTime.toString("yyyy/MM/dd hh:mm:ss") + "', '" + illu + "', '" + temp + "', '" + humid + "')";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery)){
        ;
    } else {
        qDebug() << "insert query ok";
    }
}
void Tab5Database::searchDbSlot()
{
    int row_count = 0;
    QDateTime from_dateTime = ui->pDateTimeEditFrom->dateTime();
    QString from_strDateTime = from_dateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime to_dateTime = ui->pDateTimeEditTo->dateTime();
    QString to_strDateTime = to_dateTime.toString("yyyy/MM/dd hh:mm:ss");

    ui->pTBSensor->clearContents();
    illuLine->clear();
    tempLine->clear();
    humidLine->clear();

    updateLastDateTimeSql(0);

    QString strQuery = "select * from sensor_tb where date > '" + from_strDateTime + "' AND date < '" + to_strDateTime + "'";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery)){
        ;
    } else {
//        qDebug() << "select query ok";

        while(sqlQuery.next()) {
            row_count++;
            ui->pTBSensor->setRowCount(row_count);
            QTableWidgetItem * pQTableWidgetItemId = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemDate = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemIllu = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemTemp = new QTableWidgetItem();
            QTableWidgetItem * pQTableWidgetItemHumid = new QTableWidgetItem();

            pQTableWidgetItemId->setText(sqlQuery.value("name").toString());
            pQTableWidgetItemDate->setText(sqlQuery.value("date").toString());
            pQTableWidgetItemIllu->setText(sqlQuery.value("illu").toString());
            pQTableWidgetItemTemp->setText(sqlQuery.value("temp").toString());
            pQTableWidgetItemHumid->setText(sqlQuery.value("humid").toString());

            ui->pTBSensor->setItem(row_count-1,0, pQTableWidgetItemId);
            ui->pTBSensor->setItem(row_count-1,1, pQTableWidgetItemDate);
            ui->pTBSensor->setItem(row_count-1,2, pQTableWidgetItemIllu);
            ui->pTBSensor->setItem(row_count-1,3, pQTableWidgetItemTemp);
            ui->pTBSensor->setItem(row_count-1,4, pQTableWidgetItemHumid);

            QDateTime xValue = QDateTime::fromString(pQTableWidgetItemDate->text(), "yyyy/MM/dd hh:mm:ss");
            illuLine->append(xValue.toMSecsSinceEpoch(),pQTableWidgetItemIllu->text().toInt());
            tempLine->append(xValue.toMSecsSinceEpoch(),pQTableWidgetItemTemp->text().toDouble());
            humidLine->append(xValue.toMSecsSinceEpoch(),pQTableWidgetItemHumid->text().toDouble());
//            qDebug() << "illu " << pQTableWidgetItemIllu->text().toInt();
        }
        ui->pTBSensor->resizeColumnToContents(0);
        ui->pTBSensor->resizeColumnToContents(1);
    }
}
void Tab5Database::deleteDbSlot()
{
    QDateTime from_dateTime = ui->pDateTimeEditFrom->dateTime();
    QString from_strDateTime = from_dateTime.toString("yyyy/MM/dd hh:mm:ss");
    QDateTime to_dateTime = ui->pDateTimeEditTo->dateTime();
    QString to_strDateTime = to_dateTime.toString("yyyy/MM/dd hh:mm:ss");

    QString strQuery = "delete from sensor_tb where date > '" + from_strDateTime + "' AND date < '" + to_strDateTime + "'";
    QSqlQuery sqlQuery;
    if(!sqlQuery.exec(strQuery)){
        ;
    } else {
        qDebug() << "delete query ok";
    }
    ui->pTBSensor->clearContents();
    illuLine->clear();
    tempLine->clear();
    humidLine->clear();

}
Tab5Database::~Tab5Database()
{
    delete ui;
}
