#include "tab1socketclient.h"
#include "ui_tab1socketclient.h"

Tab1SocketClient::Tab1SocketClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1SocketClient)
{
    ui->setupUi(this);
    pSocketClient = new SocketClient(this);
    connect(pSocketClient, SIGNAL(sigSocketRecv(QString)), this, SLOT(socketRecvUpdateSlot(QString)));
    ui->pPBSendButton->setEnabled(false);
}

Tab1SocketClient::~Tab1SocketClient()
{
    delete ui;
}


void Tab1SocketClient::on_pPBServerConnect_clicked(bool checked)
{
    bool bOk;
    if(checked)
    {
        pSocketClient->slotConnectToServer(bOk);
        if(bOk)
        {
            ui->pPBServerConnect->setText("서버 해제");
            ui->pPBSendButton->setEnabled(true);
        }
    }else{
        pSocketClient->slotClosedByServer();
        ui->pPBServerConnect->setText("서버 연결");
        ui->pPBSendButton->setEnabled(false);
    }
}

void Tab1SocketClient::socketRecvUpdateSlot(QString strRecvData)
{
    QTime time = QTime::currentTime();
    QString strTime = time.toString();
    strRecvData.chop(1);    //"\n" 제거
    strTime = strTime + " " + strRecvData;

    ui->pTERecvData->append(strRecvData);
    //[LYJ_QT]LED@0xff ==> @LYJ_QT@LED@0xff
    strRecvData.replace("[","@");
    strRecvData.replace("]","@");
    QStringList qList = strRecvData.split("@");

    if(qList[2].indexOf("LED") == 0)
    {
        bool bOk;
        int ledNo = qList[3].toInt(&bOk, 16);
        if(bOk)
            emit ledWriteSig(ledNo);
    }
}

void Tab1SocketClient::on_pPBSendButton_clicked()
{
    QString strRecvId = ui->pLERevcid->text();
    QString strSendData = ui->pLESendData->text();
    if(!strSendData.isEmpty())
    {
        if(strRecvId.isEmpty())
            strSendData = "[ALLMSG]" + strSendData;
        else
            strSendData = "["+strRecvId+"]"+strSendData;

        pSocketClient->slotSocketSendData(strSendData);
        ui->pLESendData->clear();
    }
}
