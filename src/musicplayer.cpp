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
    addGif();

}

musicPlayer::~musicPlayer()
{
    delete ui;
}

/**
 * @brief musicPlayer::addGif
 *          If no EEG is connected, use gif.
 *          This loads it from images/loader.gif
 */
void musicPlayer::addGif(){
    QGraphicsScene * scene = new QGraphicsScene();
    QDir * dir = new QDir();

    while(!dir->cd("images"))
        dir->cdUp();

    QLabel *gif_anim = new QLabel();
    gif = new QMovie(dir->absolutePath() + "/loader.gif");
    gif_anim->setMovie(gif);
    gif->start();
    scene->addWidget(gif_anim);
    ui->waveView->setScene(scene);
    delete dir;
    gif->stop();
}

/**
 * @brief musicPlayer::on_playPauseButton_clicked:
 *          Enables play, pause, resumeof a song
 */
void musicPlayer::on_playPauseButton_clicked()
{
    //PLAY AUDIO FROM START
    //CHECK IF AUDIO STOPPED
    if (player->state() == 0){
        player->play();
        connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(updateTime(qint64)));
        ui->playPauseButton->setText("Pause");
        gif->start();
        return;
    }

    //PAUSE AUDIO
    //CHECK IF AUDIO PLAYING
    else if (player->state() == 1){
        player->pause();
        ui->playPauseButton->setText("Resume");
        gif->stop();
        return;
    }

    //RESUME AUDIO
    //CHECK IF AUDIO IS PAUSED
    else if (player->state() == 2){
        player->play();
        ui->playPauseButton->setText("Pause");
        gif->start();
        return;
    }


}

/**
 * @brief musicPlayer::findMusic: Finds first music folder and uses those songs
 * @return Directory of music found
 */
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

/**
 * @brief musicPlayer::addMusic: Used to add music to the playlist
 * @param dir: Directory music is located inside
 * @param fileNames: fileNames of songs to add
 */
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

/**
 * @brief musicPlayer::on_loadButton_clicked
 *          Enables a user to load a song from a folder on their desktop
 */
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

/**
 * @brief musicPlayer::on_skipButton_clicked
 *          Skip to the next track on the playlist
 */
void musicPlayer::on_skipButton_clicked()
{
    player->stop();
    playlist->setCurrentIndex(playlist->nextIndex());
    player->play();
    ui->songList->setCurrentRow(playlist->currentIndex());
}

/**
 * @brief musicPlayer::on_volumeSlider_valueChanged - change volume
 * @param value - value to set volume to (out of 100)
 */
void musicPlayer::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
}

/**
 * @brief musicPlayer::updateTime - updates the time bar
 * @param progress - Current progress of the song (in ms)
 */
void musicPlayer::updateTime(qint64 progress){
    ui->timeSlider->setMaximum(player->duration());
    ui->timeSlider->setValue(progress);

    if(player->duration() < 1)
        return;

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

/**
 * @brief musicPlayer::on_songList_doubleClicked
 *          Every time a song is clicked, it begins playing from the begining
 *
 * @param index - Index of songList, i.e. song to play
 */
void musicPlayer::on_songList_doubleClicked(const QModelIndex &index){

    std::cout << QString::number(index.row()).toStdString() << std::endl;
    player->playlist()->setCurrentIndex(index.row());
    on_playPauseButton_clicked();
    if (player->state() == 2){
            player->play();
            ui->playPauseButton->setText("Pause");
    }
}
