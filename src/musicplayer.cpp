#include "musicplayer.h"
#include "ui_musicplayer.h"


musicPlayer::musicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicPlayer)
{
    ui->setupUi(this);
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer();


    QDir * musicDir = findMusic();
    QStringList fileNames = musicDir->entryList();
    addMusic(musicDir, fileNames);
    player->setVolume(50);
    ui->songList->setCurrentRow(0);
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
        connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(updateTime(qint64)));
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

QDir * musicPlayer::findMusic(){
    QDir * dir = new QDir(QApplication::applicationDirPath());
    int i = 0;
    while(!dir->cd("music")){
        try{
            dir->cdUp();
        }catch(int e){
            std::cout << e << std::endl;
        }
        if(i++ == 5){ break; }
    }
    try{
        dir->cd("music");
    }catch(int e){
        std::cout << "Unable to find music" << std::endl;
        return NULL;
    }
    return dir;
}

void musicPlayer::addMusic(QDir * dir, QStringList fileNames){
    for(int i = 0; i < fileNames.size(); i++){
        QStringList file = fileNames[i].split(".", QString::KeepEmptyParts);

        if(0 == file[file.size() - 1].compare("mp3")
        || 0 == file[file.size() - 1].compare("wav")){
            playlist->addMedia(QUrl::fromLocalFile(dir->absolutePath() + '/' + fileNames[i]));

            QString name = "";
            for(int j = 0; j < file.size() - 1; j++){
                name += file[j];
            }
            ui->songList->addItem(name);
       }
    }
    playlist->setCurrentIndex(0);
    player->setPlaylist(playlist);
    ui->songList->setCurrentRow(0);
}

void musicPlayer::on_loadButton_clicked()
{
    QDir dir(QApplication::applicationDirPath());

    int i = 0;
    while(!dir.cd("Music")){
        try{
            dir.cdUp();
        }catch(int e){
            std::cout << e << std::endl;
        }
        if(i++ == 5){ break; }
    }

    try{
        dir.cd("Music");
    }catch(int e){
        std::cout << e << std::endl;
    }

    QString absFileName = QFileDialog::getOpenFileName(this, "Select a file to open...", dir.absolutePath());
    if(absFileName == NULL){ return; }

    playlist->addMedia(QUrl::fromLocalFile(absFileName));
    QStringList fileName = absFileName.split("/", QString::KeepEmptyParts);
    QStringList songTitle = fileName[fileName.size() - 1].split(".", QString::KeepEmptyParts);

    ui->songList->addItem(songTitle[0]);
}

void musicPlayer::on_skipButton_clicked()
{
    player->stop();
    playlist->setCurrentIndex(playlist->nextIndex());
    player->play();
    ui->songList->setCurrentRow(playlist->currentIndex());
}

void musicPlayer::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);

}

void musicPlayer::updateTime(qint64 progress){
    ui->timeSlider->setMaximum(player->duration());
    ui->timeSlider->setValue(progress);

    QString curSec;
    curSec.sprintf("%2.2d", int((progress % 60000) / 1000));
    QString curMin;
    curMin.sprintf("%3.3d", int(progress / 60000));

    QString durSec;
    durSec.sprintf("%2.2d", int(player->duration() % 60000) / 1000);
    QString durMin;
    durMin.sprintf("%3.3d", int(player->duration() / 60000));

    QString cur = curMin + "." + curSec;
    QString dur = durMin + "." + durSec;

    ui->timeLabel->setText(cur + "/" + dur);
}


void musicPlayer::on_timeSlider_sliderMoved(int position){
    player->setPosition(qint64(position));
}
