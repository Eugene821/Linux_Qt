#ifndef TAB2SOCKECLIENT_H
#define TAB2SOCKECLIENT_H

#include <QWidget>
#include <QTime>
#include "socketclient.h"
#include "keyboard.h"

namespace Ui {
class Tab2SockeClient;
}

class Tab2SockeClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab2SockeClient(QWidget *parent = nullptr);
    ~Tab2SockeClient();
    SocketClient *pSocketClient;
private slots:
    void on_pPBServerConnect_clicked(bool checked);

private:
    Ui::Tab2SockeClient *ui;
    //SocketClient *pSocketClient;
    Keyboard *pKeyBoard;

private slots:
    void socketRecvUpdateSlot(QString);
    void on_pPBSendButton_clicked();

signals:
    void ledWriteSig(int);
    void tab4RecvDataSig(QString);
    void tab5RecvDataSig(QString);

};

#endif // TAB2SOCKECLIENT_H
