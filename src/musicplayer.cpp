#include "musicplayer.h"
#include "ui_musicplayer.h"
#include <QMessageBox>


musicPlayer::musicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicPlayer)
{
    ui->setupUi(this);
}

musicPlayer::~musicPlayer()
{
    delete ui;
}

void musicPlayer::on_playPauseButton_clicked()
{
    QMessageBox msgBox;
     msgBox.setText("The Play/Pause Button Clicked");
     msgBox.exec();
     QMediaPlayer* player = new QMediaPlayer();
     player->setMedia(QUrl::fromLocalFile(""));     //Location of music file
     player->setVolume(5);
     player->play();
}

void musicPlayer::on_loadButton_clicked()
{
    QMessageBox msgBox;
     msgBox.setText("Load Track Button Clicked");
     msgBox.exec();


}
