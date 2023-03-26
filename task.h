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
signals:
    void stop();
public slots:
    void printMessage();
    void drawRectangle(int w, int h);

};

#endif // TASK_H
