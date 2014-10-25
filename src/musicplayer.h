#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>

#include <QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QtMultimedia>
#include <QMovie>

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

private:
    Ui::musicPlayer *ui;
    QMediaPlaylist* playlist;
    QMediaPlayer* player;
    QMovie * gif;
    QDir * findMusic();

    void addMusic(QDir *, QStringList);
    void displayMetadata();
    void addGif();
};

#endif // MUSICPLAYER_H
