#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

public slots:
    void printMessage(QString);
};

#endif // TASK_H
