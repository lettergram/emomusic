#ifndef WORKER_H
#define WORKER_H

#include <QThread>
#include <QVector>
#include <QMutex>

class Worker: public QObject
{  
    Q_Object

    public:
        explicit Worker();

    private:
        Qvector emo_vector; // main vector, each element is an average of 10 second intervals
        double getMood();
        int getDuration();

    signals:
        void finished();
    
    public slots:
        void doWork();
};
#endif // WORKER_H
