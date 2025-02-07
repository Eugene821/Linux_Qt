#ifndef KEYLED_H
#define KEYLED_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
#include <QSocketNotifier>

class KeyLed : public QWidget
{
    Q_OBJECT

public:
    explicit KeyLed(QWidget *parent = nullptr);
    ~KeyLed();

private:
    QFile * pFile;
    int keyledFd;
    QSocketNotifier * pKeyLedNotifier;
private slots:
    //void writeLedData(int);
    void readKeyData(int);

public slots:
    void writeLedData(int);
public slots:

signals:
    void updateKeydataSig(int);
};

#endif // KEYLED_H
