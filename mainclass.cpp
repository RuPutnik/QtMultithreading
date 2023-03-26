#include "mainclass.h"
#include <QThread>

MainClass::MainClass(QObject *parent)
    : QObject{parent}
{
    tsk=new Task();
    taskThread=QThread::create(&Task::printMessage,tsk,"hello bitches");

    connect(taskThread,&QThread::finished,this,&QCoreApplication::quit,Qt::QueuedConnection);
    connect(this,&MainClass::sendMess,tsk,&Task::printMessage,Qt::QueuedConnection);
}

void MainClass::runTest()
{

    qDebug()<<"Main thread id: "<<QThread::currentThreadId();
    taskThread->start();


    //слот, связанный с этим сигналом запустится в главном потоке, что подтверждает теорию, о том, что данный способ создания потока не порождает цикл событий и не может
    //работать с доп. сигналами
    emit sendMess("infoinfo");

}
