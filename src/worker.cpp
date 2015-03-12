#include "worker.h"

Worker::Worker() 
{
   // empty constructor
}

/**
* Worker thread does work
*/
void Worker::doWork() 
{
    QVector v;
    double sum = 0;
    int songDuration = getDuration();

    while(songDuration > 0) {
        double emotionValue = getMood();
        v.push_back(emotionValue);
        if(v.size() ==  10) {
            for(int i = 0; i < v.size(); i++) {
                sum += v.at(i)
            }
            emo_vector.push_back(sum/v.size());
        }
        sleep(1);
        songDuration --;
    }

    sum = 0;
    // song finishes, compute the average
    for(int i = 0; i < emo_vector.size(); i++) {
        sum += emo_vector.at(i)
    }
    double emotion = sum/emo_vector.size();

    // returned the calculated value
    emit finished();
}

/**
* Api call wrapper function.
*/
double getMood() {
    return 0; // api call to the emotiv headset
}

/**
* Api call wrapper function.
*/
int getDuration() {
    return 0; // some call to somewhere... i need music!
}

