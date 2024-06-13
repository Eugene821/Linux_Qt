#include "tab3controlpannel.h"
#include "ui_tab3controlpannel.h"

Tab3ControlPannel::Tab3ControlPannel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab3ControlPannel)
{
    ui->setupUi(this);
    paletteColorOn.setColor(ui->pPBLamp->backgroundRole(),QColor(255,0,0));
    paletteColorOff.setColor(ui->pPBLamp->backgroundRole(),QColor(0,0,255));
    ui->pPBLamp->setPalette(paletteColorOff);
    ui->pPBPlug->setPalette(paletteColorOff);
    connect(ui->pPBLamp, SIGNAL(clicked(bool)),this, SLOT(lampOnOffSlot(bool)));
    connect(ui->pPBPlug, SIGNAL(clicked(bool)),this, SLOT(plugOnOffSlot(bool)));
}

void Tab3ControlPannel::lampOnOffSlot(bool bCheck)
{

    if(bCheck)
    {
        emit socketSendDataSig("[HM_CON]LAMPON");
        //ui->pPBLamp->setIcon(QIcon(":/Images/Image/light_on.png"));
        //ui->pPBLamp->setPalette(paletteColorOn);
    }
    else
    {
        emit socketSendDataSig("[HM_CON]LAMPOFF");
        ui->pPBLamp->setIcon(QIcon(":/images/Image/light_off.png"));
        ui->pPBLamp->setPalette(paletteColorOff);
    }

}

void Tab3ControlPannel::plugOnOffSlot(bool bCheck)
{
    if(bCheck)
    {
        emit socketSendDataSig("[HM_CON]GASON");
        //ui->pPBPlug->setIcon(QIcon(":/images/Image/plug_on.png"));
        //ui->pPBPlug->setPalette(paletteColorOn);
    }
    else
    {
        emit socketSendDataSig("[HM_CON]GASOFF");
        ui->pPBPlug->setIcon(QIcon(":/images/Image/plug_off.png"));
        ui->pPBPlug->setPalette(paletteColorOff);
    }
}

void Tab3ControlPannel::tab3RecvDataSlot(QString recvData)
{
    QStringList qList = recvData.split("@");
    //qList[0] => Null, qList[1] => HM_CON, qList[2] =>LAMPON
    if(qList[2] == "LAMPON")
    {
        ui->pPBLamp->setIcon(QIcon(":/images/Image/light_on.png"));
        ui->pPBLamp->setPalette(paletteColorOn);
    }
    else if(qList[2] == "LAMPOFF")
    {
        ui->pPBLamp->setIcon(QIcon(":/images/Image/light_off.png"));
        ui->pPBLamp->setPalette(paletteColorOff);
    }
    else if(qList[2] == "GASON")
    {
        ui->pPBPlug->setIcon(QIcon(":/images/Image/plug_on.png"));
        ui->pPBPlug->setPalette(paletteColorOn);
    }
    else if(qList[2] == "GASOFF")
    {
        ui->pPBPlug->setIcon(QIcon(":/images/Image/plug_off.png"));
        ui->pPBPlug->setPalette(paletteColorOff);
    }
}

Tab3ControlPannel::~Tab3ControlPannel()
{
    delete ui;
}

