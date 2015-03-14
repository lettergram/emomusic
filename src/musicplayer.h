#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>

#include <QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtMultimedia>
#include <QMovie>
#include <QPixmap>
#include <QGraphicsScene>

#include "user.h"
#include "worker.h"

#include "../lib/remotiv.h"

namespace Ui {
    class musicPlayer;
}

class musicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit musicPlayer(QWidget *parent = 0);
    ~musicPlayer();

private slots:

    void on_playPauseButton_clicked();
    void on_loadButton_clicked();
    void on_skipButton_clicked();
    void on_volumeSlider_valueChanged(int);
    void on_timeSlider_sliderMoved(int position);
    void updateTime(qint64);
    void on_songList_doubleClicked(const QModelIndex &index);
    void on_moodBox_activated(const QString &arg1);

    void on_newUserButton_clicked();

    void on_spinBox_editingFinished();

private:

    Ui::musicPlayer* ui;
    QMediaPlaylist* playlist;
    QMediaPlayer* player;
    int moodIndex;
    QDir * imageDir;
    QIcon * whiteDoubleArrowIcon;

    int userCount;

    remotiv * emo;

    QDir* findMusic();
    void addMusic(QDir *, QStringList);
    void displayMetadata();
    QString songDuration();
    QString songCurrent();

    void playIcon();
    void pauseIcon();
    void skipIcon();

    void updateMoodLabels();
};

#endif // MUSICPLAYER_H
