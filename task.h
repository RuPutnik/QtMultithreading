#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>
#include <QThread>

class Task : public QThread
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    virtual void run() override;
public slots:
    void printMessage(QString);

};

#endif // TASK_H
