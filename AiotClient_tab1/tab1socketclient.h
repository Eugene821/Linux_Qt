#ifndef TAB1SOCKETCLIENT_H
#define TAB1SOCKETCLIENT_H

#include <QWidget>
#include <QTime>
#include "socketclient.h"

namespace Ui {
class Tab1SocketClient;
}

class Tab1SocketClient : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1SocketClient(QWidget *parent = nullptr);
    ~Tab1SocketClient();

private slots:
    void on_pPBServerConnect_clicked(bool checked);
    void socketRecvUpdateSlot(QString);
    void on_pPBSendButton_clicked();

private:
    Ui::Tab1SocketClient *ui;
    SocketClient *pSocketClient;

signals:
    void ledWriteSig(int);


};

#endif // TAB1SOCKETCLIENT_H
