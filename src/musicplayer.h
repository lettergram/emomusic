#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>

namespace Ui {
class musicPlayer;
}

class musicPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit musicPlayer(QWidget *parent = 0);
    ~musicPlayer();

private:
    Ui::musicPlayer *ui;
};

#endif // MUSICPLAYER_H
