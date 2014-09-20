#include "musicplayer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    musicPlayer w;
    w.show();

    return a.exec();
}
