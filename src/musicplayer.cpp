#include "musicplayer.h"
#include "ui_musicplayer.h"
#include <QMessageBox>


musicPlayer::musicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicPlayer)
{
    ui->setupUi(this);
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer();



    //Music
    playlist->addMedia(QUrl::fromLocalFile(""));
    playlist->addMedia(QUrl::fromLocalFile(""));
    playlist->addMedia(QUrl::fromLocalFile(""));
    playlist->addMedia(QUrl::fromLocalFile(""));


    playlist->setCurrentIndex(0);
    player->setPlaylist(playlist);
    player->setVolume(100);

       //Use metadata instead here
            //Get metadata of track
            //QString title = player->metaData("Title").toString();


    ui->listWidget->addItem("Track 1");
    ui->listWidget->addItem("Track 2");
    ui->listWidget->addItem("Track 3");
    ui->listWidget->addItem("Track 4");

    ui->listWidget->setCurrentRow(0);

}

musicPlayer::~musicPlayer()
{
    delete ui;
}

void musicPlayer::on_playPauseButton_clicked()
{
    //PLAY AUDIO FROM START
    //CHECK IF AUDIO STOPPED
    if (player->state() == 0){
        player->play();
        ui->playPauseButton->setText("Pause");
        return;
    }

    //PAUSE AUDIO
    //CHECK IF AUDIO PLAYING
    else if (player->state() == 1){
        player->pause();
        ui->playPauseButton->setText("Resume");
        return;
    }

    //RESUME AUDIO
    //CHECK IF AUDIO IS PAUSED
    else if (player->state() == 2){
        player->play();
        ui->playPauseButton->setText("Pause");
        return;
    }


}

void musicPlayer::on_loadButton_clicked()
{
    QMessageBox msgBox;
     msgBox.setText("Load Track Button Clicked");
     msgBox.exec();


}

void musicPlayer::on_skipButton_clicked()
{


    player->stop();
    playlist->setCurrentIndex(playlist->nextIndex());
    player->play();
    ui->listWidget->setCurrentRow(playlist->currentIndex());



}
