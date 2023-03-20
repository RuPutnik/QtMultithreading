#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <QDebug>
#include <QVector>

#include "task.h"

class MainClass : public QObject
{
    Q_OBJECT
public:
    explicit MainClass(QObject *parent = nullptr);
    Task* tsk;

    void runTest();
};

#endif // MAINCLASS_H
