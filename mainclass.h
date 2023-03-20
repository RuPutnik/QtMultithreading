#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QCoreApplication>

#include "task.h"

class QThread;

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);
    QThread* taskThread;
    Task* tsk;

    void runTest();
signals:
    void sendMessage(QString);
    void sendSingleMessage(QString);
    void closeThread();
};

#endif // MAINCLASS_H
