#include "musicplayer.h"
#include "ui_musicplayer.h"


musicPlayer::musicPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::musicPlayer){

    ui->setupUi(this);
    playlist = new QMediaPlaylist();
    player = new QMediaPlayer();

    QDir * musicDir = findMusic();
    QStringList fileNames = musicDir->entryList();
    addMusic(musicDir, fileNames);
    player->setVolume(50);


    imageDir = new QDir();
    while(!imageDir->cd("images"))
        imageDir->cdUp();

    moodIndex = 0;

    QPixmap whiteArrow;
    whiteArrow.load(imageDir->absolutePath() + "/white-arrows.png");
    whiteDoubleArrowIcon = new QIcon();
    whiteDoubleArrowIcon->addPixmap(whiteArrow);
    ui->moodBox->setItemIcon(moodIndex, *whiteDoubleArrowIcon);

    emo = new remotiv();
    userCount = 0;

    skipIcon();
    playIcon();
}

void musicPlayer::playIcon(){

    ui->playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void musicPlayer::pauseIcon(){
    ui->playPauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
}

void musicPlayer::skipIcon(){
    ui->skipButton->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
}

musicPlayer::~musicPlayer(){
    delete ui;
}

/**
 * @brief musicPlayer::on_playPauseButton_clicked:
 *          Enables play, pause, resumeof a song
 */
void musicPlayer::on_playPauseButton_clicked(){

    //PLAY AUDIO FROM START
    //CHECK IF AUDIO STOPPED
    if (player->state() == 0){
        player->play();
        connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(updateTime(qint64)));
        pauseIcon();
        return;
    }

    //PAUSE AUDIO
    //CHECK IF AUDIO PLAYING
    else if (player->state() == 1){
        player->pause();
        playIcon();
        return;
    }

    //RESUME AUDIO
    //CHECK IF AUDIO IS PAUSED
    else if (player->state() == 2){
        player->play();
        pauseIcon();
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
 *
 *
 * TODO: Replace with working metadata collector
 */
void musicPlayer::addMusic(QDir * dir, QStringList fileNames){

    for(int i = 0; i < fileNames.size(); i++){
        QStringList file = fileNames[i].split(".", QString::KeepEmptyParts);
        if(0 == file[file.size() - 1].compare("mp3")
        || 0 == file[file.size() - 1].compare("wav")){
            playlist->addMedia(QUrl::fromLocalFile(dir->absolutePath() + '/' + fileNames[i]));
       }
    }

    player->setPlaylist(playlist);
    std::cout << "MediaCount: " << player->playlist()->mediaCount() << std::endl;

    /* Name, Duration, Artist, Album, Duration */
    for(int i = playlist->mediaCount() - 1; i > -1; i--){
        player->playlist()->setCurrentIndex(i);

        QStringList absoluteSongFileName = player->currentMedia().canonicalUrl().toString().split("/");
        QStringList songName = absoluteSongFileName[absoluteSongFileName.size() - 1].split(".");
        QString name = "";

        for(int i = 0; i < songName.size()-1; i++)
            name += songName[i] + " ";
        name.remove(name.size() - 1, 1);

        displayMetadata();
        if(0 == songName[songName.size() - 1].compare("mp3")
        || 0 == songName[songName.size() - 1].compare("wav")){
            QTreeWidgetItem * t = new QTreeWidgetItem();
            t->setText(0, name);
            t->setText(1, songDuration());
            t->setText(2, player->metaData("AlbumArtist").toString());
            t->setText(3, player->metaData("AlbumTitle").toString());
            t->setText(4, "None: " + QString::number(i));
            ui->songList->insertTopLevelItem(0, t);
        }
    }

    playlist->setCurrentIndex(playlist->mediaCount()-1);
    ui->songList->setCurrentItem(ui->songList->itemAt(0,0));
    ui->songList->setItemSelected(ui->songList->currentItem(),true);
}

QString musicPlayer::songDuration(){
    QString durSec;
    durSec.sprintf("%2.2d", int(player->duration() % 60000) / 1000);
    QString durMin;
    durMin.sprintf("%2.2d", int(player->duration() / 60000));
    QString durHour;
    durHour.sprintf("%2.2d", int(player->duration() / 60000) / 60);
    return durHour + ":" + durMin + ":" + durSec;
}

QString musicPlayer::songCurrent(){
    QString curSec;
    curSec.sprintf("%2.2d", int((player->position() % 60000) / 1000));
    QString curMin;
    curMin.sprintf("%2.2d", int(player->position() / 60000));
    QString curHour;
    curHour.sprintf("%2.2d", int(player->position() / 60000) / 60);
    return curHour + ":" + curMin + ":" + curSec;
}

void musicPlayer::displayMetadata(){

    if(!player->isAvailable()){ return; }

    QString title = player->metaData("Title").toString();
    QString artist = player->metaData("AlbumArtist").toString();
    QString album = player->metaData("AlbumTitle").toString();

    if(title.size() < 2){ title = "Title"; }
    if(artist.size() < 2){ artist = "Artist"; }
    if(album.size() < 2){ album = "Album"; }

    ui->trackDataLabel->setText(title + " / " + artist + " / " + album);
}

/**
 * @brief musicPlayer::on_loadButton_clicked
 *          Enables a user to load a song from a folder on their desktop
 */
void musicPlayer::on_loadButton_clicked(){

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

    playlist->setCurrentIndex(playlist->mediaCount()-1);

    QTreeWidgetItem * t = new QTreeWidgetItem();
    t->setText(0, player->metaData("Title").toString());
    t->setText(1, songDuration());
    t->setText(2, player->metaData("AlbumArtist").toString());
    t->setText(3, player->metaData("AlbumTitle").toString());
    t->setText(4, "None");
    ui->songList->insertTopLevelItem(0, t);
}

/**
 * @brief musicPlayer::on_skipButton_clicked
 *          Skip to the next track on the playlist
 *
 * TODO: Busted, need to fix so it aligns, currently reverse
 */
void musicPlayer::on_skipButton_clicked(){

    on_playPauseButton_clicked();
    QString albumArtist = player->metaData("AlbumArtist").toString();
    QString albumTitle  = player->metaData("AlbumTitle").toString();

    QTreeWidgetItem * current = ui->songList->currentItem();

    current->setText(1, songDuration());
    current->setText(2, albumArtist);
    if(albumArtist.size() < 1)
        current->setText(2, "Unknown");
    current->setText(3, albumTitle);
    if(albumTitle.size() < 1)
        current->setText(3, "Unknown");
    current->setText(4, "None");

    QTreeWidgetItem * next = ui->songList->itemBelow(current);

    if(playlist->previousIndex() == -1){
        playlist->setCurrentIndex(playlist->mediaCount());
    }
    playlist->setCurrentIndex(playlist->previousIndex());

    if(next == NULL){
        next = ui->songList->itemAt(0,0);
    }

    ui->songList->setCurrentItem(next);
    ui->songList->setItemSelected(next,true);

    emo->clearCurrentMentalState();

    on_playPauseButton_clicked();
}

/**
 * @brief musicPlayer::on_volumeSlider_valueChanged - change volume
 * @param value - value to set volume to (out of 100)
 */
void musicPlayer::on_volumeSlider_valueChanged(int value){
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

    emo->sampleEEG(userCount); // log emotional state
    updateMoodLabels();

    ui->timeLabel->setText(songCurrent() + "/" + songDuration());
    displayMetadata(); // TODO Change
}

/**
 *
 *    [0] frustration score
 *    [1] boredom score
 *    [2] meditation score
 *    [3] excitment score
 * @brief musicPlayer::updateMoodLabels -
 *              update the mood labels for the users
 */
void musicPlayer::updateMoodLabels(){

    std::vector<double> mentalState = emo->getCurrentMentalState();

    if(mentalState.size() < 4){ return; }

    // Negative is frustration, positive is meditation
    double mood = 100.0 * (mentalState[2] - mentalState[0]);
    if(mood == 0){
        ui->moodLabel->setText("Undefined");
    }else if(mood > 35.0){
        ui->moodLabel->setText("Super Happy");
    }else if(mood > 15.0){
        ui->moodLabel->setText("Happy");
    }else if(mood > 5.0){
        ui->moodLabel->setText("Feeling Good");
    }else if(mood <= 5.0 && mood >= -5.0){
        ui->moodLabel->setText("Neutral");
    }else if(mood > -15){
        ui->moodLabel->setText("Irritated");
    }else if(mood > -35){
        ui->moodLabel->setText("Annoyed");
    }else{
        ui->moodLabel->setText("Frustrated");
    }

    // Negative is boredom, positive is excitment
    double wakefullness = 100.0 * (mentalState[3] - mentalState[1]);
    if(wakefullness == 0){
        ui->wakefulnessLabel->setText("Undefined");
    }else if(wakefullness > 35.0){
        ui->wakefulnessLabel->setText("Energized!");
    }else if(wakefullness > 15.0){
        ui->wakefulnessLabel->setText("Wide Awake");
    }else if(wakefullness > 5.0){
        ui->wakefulnessLabel->setText("Attentive");
    }else if(wakefullness <= 5.0 && wakefullness >= -5.0){
        ui->wakefulnessLabel->setText("Observent");
    }else if(wakefullness > -15){
        ui->wakefulnessLabel->setText("Tired");
    }else if(wakefullness > -35){
        ui->wakefulnessLabel->setText("Yawnful");
    }else{
        ui->wakefulnessLabel->setText("Sleepy");
    }
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
    player->playlist()->setCurrentIndex(index.row());
    on_playPauseButton_clicked();
}

void musicPlayer::on_moodBox_activated(const QString &arg1){
    ui->moodBox->setItemIcon(moodIndex, QIcon());
    moodIndex = ui->moodBox->currentIndex();
    ui->moodBox->setItemIcon(moodIndex, *whiteDoubleArrowIcon);
}

void musicPlayer::on_newUserButton_clicked(){
    userCount++;
    ui->spinBox->setValue(userCount);
    emo->clearCurrentMentalState();
}

void musicPlayer::on_spinBox_editingFinished(){
    userCount = ui->spinBox->value();
}
