/********************************************************************************
** Form generated from reading UI file 'tab2chartplot.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAB2CHARTPLOT_H
#define UI_TAB2CHARTPLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tab2ChartPlot
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pPBClearButton;
    QVBoxLayout *pChartViewLayout;

    void setupUi(QWidget *Tab2ChartPlot)
    {
        if (Tab2ChartPlot->objectName().isEmpty())
            Tab2ChartPlot->setObjectName(QString::fromUtf8("Tab2ChartPlot"));
        Tab2ChartPlot->resize(400, 300);
        verticalLayout = new QVBoxLayout(Tab2ChartPlot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pPBClearButton = new QPushButton(Tab2ChartPlot);
        pPBClearButton->setObjectName(QString::fromUtf8("pPBClearButton"));

        horizontalLayout->addWidget(pPBClearButton);


        verticalLayout->addLayout(horizontalLayout);

        pChartViewLayout = new QVBoxLayout();
        pChartViewLayout->setObjectName(QString::fromUtf8("pChartViewLayout"));

        verticalLayout->addLayout(pChartViewLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        retranslateUi(Tab2ChartPlot);

        QMetaObject::connectSlotsByName(Tab2ChartPlot);
    } // setupUi

    void retranslateUi(QWidget *Tab2ChartPlot)
    {
        Tab2ChartPlot->setWindowTitle(QApplication::translate("Tab2ChartPlot", "Form", nullptr));
        pPBClearButton->setText(QApplication::translate("Tab2ChartPlot", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tab2ChartPlot: public Ui_Tab2ChartPlot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAB2CHARTPLOT_H
