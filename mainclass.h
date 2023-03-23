#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QThreadPool>
#include <QCoreApplication>

#include "task.h"

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);
    Task* tsk;
    QThreadPool* pool;
    int countSync=0;
    void runTest();
signals:

};

#endif // MAINCLASS_H
