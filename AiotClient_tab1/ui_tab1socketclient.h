/********************************************************************************
** Form generated from reading UI file 'tab1socketclient.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB1SOCKETCLIENT_H
#define UI_TAB1SOCKETCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab1SocketClient
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *pPBRecvDataClear;
    QPushButton *pPBServerConnect;
    QVBoxLayout *verticalLayout;
    QTextEdit *pTERecvData;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *pLERevcid;
    QLineEdit *pLESendData;
    QPushButton *pPBSendButton;

    void setupUi(QWidget *Tab1SocketClient)
    {
        if (Tab1SocketClient->objectName().isEmpty())
            Tab1SocketClient->setObjectName(QString::fromUtf8("Tab1SocketClient"));
        Tab1SocketClient->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Tab1SocketClient);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Tab1SocketClient);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pPBRecvDataClear = new QPushButton(Tab1SocketClient);
        pPBRecvDataClear->setObjectName(QString::fromUtf8("pPBRecvDataClear"));

        horizontalLayout->addWidget(pPBRecvDataClear);

        pPBServerConnect = new QPushButton(Tab1SocketClient);
        pPBServerConnect->setObjectName(QString::fromUtf8("pPBServerConnect"));
        pPBServerConnect->setCheckable(true);

        horizontalLayout->addWidget(pPBServerConnect);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pTERecvData = new QTextEdit(Tab1SocketClient);
        pTERecvData->setObjectName(QString::fromUtf8("pTERecvData"));

        verticalLayout->addWidget(pTERecvData);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pLERevcid = new QLineEdit(Tab1SocketClient);
        pLERevcid->setObjectName(QString::fromUtf8("pLERevcid"));

        horizontalLayout_2->addWidget(pLERevcid);

        pLESendData = new QLineEdit(Tab1SocketClient);
        pLESendData->setObjectName(QString::fromUtf8("pLESendData"));

        horizontalLayout_2->addWidget(pLESendData);

        pPBSendButton = new QPushButton(Tab1SocketClient);
        pPBSendButton->setObjectName(QString::fromUtf8("pPBSendButton"));

        horizontalLayout_2->addWidget(pPBSendButton);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 6);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(Tab1SocketClient);

        QMetaObject::connectSlotsByName(Tab1SocketClient);
    } // setupUi

    void retranslateUi(QWidget *Tab1SocketClient)
    {
        Tab1SocketClient->setWindowTitle(QApplication::translate("Tab1SocketClient", "Form", nullptr));
        label->setText(QApplication::translate("Tab1SocketClient", "\354\210\230\354\213\240 \353\215\260\354\235\264\355\204\260", nullptr));
        pPBRecvDataClear->setText(QApplication::translate("Tab1SocketClient", "\354\210\230\354\213\240 \354\202\255\354\240\234", nullptr));
        pPBServerConnect->setText(QApplication::translate("Tab1SocketClient", "\354\204\234\353\262\204 \354\227\260\352\262\260", nullptr));
        pPBSendButton->setText(QApplication::translate("Tab1SocketClient", "\354\206\241\354\213\240", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab1SocketClient: public Ui_Tab1SocketClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB1SOCKETCLIENT_H
