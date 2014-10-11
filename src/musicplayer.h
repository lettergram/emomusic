#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>
#include <QMainWindow>
#include <QtMultimedia>

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

private:
    Ui::musicPlayer *ui;
    QMediaPlaylist* playlist;
    QMediaPlayer* player;

};

#endif // MUSICPLAYER_H
