#include "worker.h"

Worker::Worker(QString * s) 
{
   songTitle = s;
   emotion = NULL;
}

Worker::~Worker() {
    if(emotion != NULL) {}
        delete(emotion);
    }
}

/**
* Worker thread does work
*/
void Worker::doWork() 
{
    QVector<double> v, emo_vector;
    double sum = 0;
    QString * title = getSongTitle(); // gets the song title

    while(songTitle.compare(title)  == 0) {
        double currentEmotion = getMood(); // gets to current mood value
        v.push_back(currentEmotion);
        if(v.size() ==  10) {
            for(int i = 0; i < v.size(); i++) {
                sum += v.at(i);
            }
            emo_vector.push_back(sum/v.size());
        }
        sleep(1);
        songDuration --;
    }

    sum = 0;
    // song finishes, compute the average
    for(int i = 0; i < emo_vector.size(); i++) {
        sum += emo_vector.at(i);
    }
    emotion = new double(sum/emo_vector.size();

    // need to return the calculated value
    return emotion;
    }

/**
* Api call wrapper function.
*/
double getMood() {
    return 0; // api call to the emotiv headset
}

/**
* Get the current song playing  
*/
QString getSongTitle() {
    return "title"; // some call to somewhere...
}
