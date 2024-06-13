/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *pTabWidget;
    QWidget *pTab2;
    QWidget *pTab4;
    QWidget *pTab5;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(591, 348);
        verticalLayout = new QVBoxLayout(MainWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pTabWidget = new QTabWidget(MainWidget);
        pTabWidget->setObjectName(QString::fromUtf8("pTabWidget"));
        pTab2 = new QWidget();
        pTab2->setObjectName(QString::fromUtf8("pTab2"));
        pTab2->setLayoutDirection(Qt::LeftToRight);
        pTabWidget->addTab(pTab2, QString());
        pTab4 = new QWidget();
        pTab4->setObjectName(QString::fromUtf8("pTab4"));
        pTabWidget->addTab(pTab4, QString());
        pTab5 = new QWidget();
        pTab5->setObjectName(QString::fromUtf8("pTab5"));
        pTabWidget->addTab(pTab5, QString());

        verticalLayout->addWidget(pTabWidget);


        retranslateUi(MainWidget);

        pTabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        pTabWidget->setTabText(pTabWidget->indexOf(pTab2), QApplication::translate("MainWidget", "Socket", nullptr));
        pTabWidget->setTabText(pTabWidget->indexOf(pTab4), QApplication::translate("MainWidget", "Sensor", nullptr));
        pTabWidget->setTabText(pTabWidget->indexOf(pTab5), QApplication::translate("MainWidget", "Sqlite", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
