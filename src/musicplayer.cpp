#include "musicplayer.h"
#include "ui_musicplayer.h"

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
