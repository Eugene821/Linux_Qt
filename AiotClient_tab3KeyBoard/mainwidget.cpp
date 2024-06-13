#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    pTab1DevControl = new Tab1DevControl(ui->pTab1);
    ui->pTab1->setLayout(pTab1DevControl->layout());

    pTab2SockeClient = new Tab2SockeClient(ui->pTab2);
    ui->pTab2->setLayout(pTab2SockeClient->layout());

    pTab3ControlPannel = new Tab3ControlPannel(ui->pTab3);
    ui->pTab2->setLayout(pTab3ControlPannel->layout());

    ui->pTabWidget->setCurrentIndex(1);
    connect(pTab2SockeClient,SIGNAL(ledWriteSig(int)), pTab1DevControl->getpDial(),SLOT(setValue(int)));
    connect(pTab3ControlPannel, SIGNAL(socketSendDataSig(QString)),pTab2SockeClient->pSocketClient,SLOT(slotSocketSendData(QString)));
    connect(pTab2SockeClient, SIGNAL(tab3RecvDataSig(QString)),pTab3ControlPannel,SLOT(tab3RecvDataSlot(QString)));
}

MainWidget::~MainWidget()
{
    delete ui;
}

