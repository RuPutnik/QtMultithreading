#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <algorithm>
#include <numeric>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);

public slots:
    void printMessage(QString);
    int getSumm(QVector<int> qvec);
public:
    template<class T>
    int getMultiples(QVector<T> qvec)
    {
        return std::accumulate(std::begin(qvec),std::end(qvec),1,[](T t1, T t2){
            return t1*t2;
        });
    }
};

#endif // TASK_H
