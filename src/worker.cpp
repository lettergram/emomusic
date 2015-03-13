#include "worker.h"

Worker::Worker(QString * s) 
{
   songTitle = s;
   emotion = 0;
}

Worker::~Worker() {
    delete songTitle;
}

/**
* Worker thread does work
*/
double Worker::doWork()
{
    QVector<double> v, emo_vector;
    double sum = 0;
    QString title = getSongTitle(); // gets the song title

    while(songTitle->compare(title)  == 0) {
        double currentEmotion = getMood(); // gets to current mood value
        v.push_back(currentEmotion);
        if(v.size() ==  10) {
            for(int i = 0; i < v.size(); i++) {
                sum += v.at(i);
            }
            emo_vector.push_back(sum/v.size());
        }
        sleep(1);
    }

    sum = 0;
    // song finishes, compute the average
    for(int i = 0; i < emo_vector.size(); i++) {
        sum += emo_vector.at(i);
    }
    emotion = double(sum/emo_vector.size());

    // need to return the calculated value
    return emotion;
    }

/**
* Api call wrapper function.
*/
double Worker::getMood() {
    return 0; // api call to the emotiv headset
}

/**
* Get the current song playing  
*/
QString Worker::getSongTitle() {
    return "title"; // some call to somewhere...
}
