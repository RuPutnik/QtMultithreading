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
    void sendMess(QString msg);
};

#endif // MAINCLASS_H
