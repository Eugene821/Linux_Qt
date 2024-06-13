#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //pTab1DevControl = new Tab1DevControl(ui->pTab1);
    //ui->pTab1->setLayout(pTab1DevControl->layout());

    pTab1SocketClient = new Tab1SocketClient(ui->pTab1);
    ui->pTab1->setLayout(pTab1SocketClient->layout());

    ui->pTabWidget->setCurrentIndex(1);
    connect(pTab1SocketClient,SIGNAL(ledWriting(int)),pTab1SocketClient,SIGNAL(ledWriting(int)));
    connect(pTab1SocketClient,SIGNAL(tab2RecvDataSig(QString)),pTab2ChartPlot,SLOT(tab2RecvDataSlot(QString)));
    //connect(pTab2SockeClient,SIGNAL(tab5RecvDataSig(QString)),pTab5Database,SLOT(tab5RecvDataSlot(QString)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

