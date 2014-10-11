/********************************************************************************
** Form generated from reading UI file 'musicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicPlayer
{
public:
    QWidget *centralWidget;
    QPushButton *playPauseButton;
    QPushButton *skipButton;
    QPushButton *loadButton;
    QListWidget *listWidget;

    void setupUi(QMainWindow *musicPlayer)
    {
        if (musicPlayer->objectName().isEmpty())
            musicPlayer->setObjectName(QStringLiteral("musicPlayer"));
        musicPlayer->resize(800, 480);
        centralWidget = new QWidget(musicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        playPauseButton = new QPushButton(centralWidget);
        playPauseButton->setObjectName(QStringLiteral("playPauseButton"));
        playPauseButton->setGeometry(QRect(30, 30, 114, 32));
        skipButton = new QPushButton(centralWidget);
        skipButton->setObjectName(QStringLiteral("skipButton"));
        skipButton->setGeometry(QRect(30, 70, 114, 32));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setGeometry(QRect(30, 110, 114, 32));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(230, 30, 256, 192));
        musicPlayer->setCentralWidget(centralWidget);

        retranslateUi(musicPlayer);

        QMetaObject::connectSlotsByName(musicPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *musicPlayer)
    {
        musicPlayer->setWindowTitle(QApplication::translate("musicPlayer", "musicPlayer", 0));
        playPauseButton->setText(QApplication::translate("musicPlayer", "Play", 0));
        skipButton->setText(QApplication::translate("musicPlayer", "Skip Track", 0));
        loadButton->setText(QApplication::translate("musicPlayer", "Load Track", 0));
    } // retranslateUi

};

namespace Ui {
    class musicPlayer: public Ui_musicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
