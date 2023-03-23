#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <QMutex>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    virtual void run() override;
    QMutex mut;

public slots:
    void printMessage(QString);
signals:
    void finished();
};

#endif // TASK_H
