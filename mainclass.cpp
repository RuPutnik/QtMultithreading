#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    tsk=new Task(parent);
    pool=new QThreadPool(parent);

    connect(tsk,&Task::finished,this,[this]{
        countSync++; //синхронизируем потоки
        qDebug()<<"sync: "<<countSync;

        if(pool->activeThreadCount()==0){
            qDebug()<<"success sync";
            QThread::currentThread()->quit();
        }
    });
}

void MainClass::runTest()
{
    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    qDebug()<<"Ideal count threads: "<<QThread::idealThreadCount(); //Выводим оптимальное количество потоков, оно же количество
    //потоков в пуле.
    auto func=QRunnable::create(std::bind(&Task::printMessage,tsk,"haha"));
    tsk->setAutoDelete(false);

    pool->start(tsk);
    pool->start(tsk);
    pool->start(tsk);
    pool->start(tsk);

    pool->start(tsk);
    pool->start(tsk);
    pool->start(tsk);
    pool->start(tsk);

    pool->start(func);
}
