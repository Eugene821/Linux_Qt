#ifndef __CUSTOM_WIDGET__
#define __CUSTOM_WIDGET__

#include <QWidget>
#include "customwidget.h"

class CustomWidget : public QWidget {
	Q_OBJECT

public:
	CustomWidget(QWidget *parent = 0);
signals:
	void widgetClicked();
public slots:
	void processClick();

};

#endif
