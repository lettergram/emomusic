/********************************************************************************
** Form generated from reading UI file 'musicplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICPLAYER_H
#define UI_MUSICPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicPlayer
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *waveView;
    QComboBox *moodBox;
    QListWidget *songList;
    QListWidget *playList;
    QSlider *timeSlider;
    QLabel *timeLabel;
    QLabel *label;
    QSlider *volumeSlider;
    QPushButton *playPauseButton;
    QPushButton *loadButton;
    QPushButton *skipButton;
    QLabel *trackDataLabel;

    void setupUi(QMainWindow *musicPlayer)
    {
        if (musicPlayer->objectName().isEmpty())
            musicPlayer->setObjectName(QStringLiteral("musicPlayer"));
        musicPlayer->resize(800, 530);
        centralWidget = new QWidget(musicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        waveView = new QGraphicsView(centralWidget);
        waveView->setObjectName(QStringLiteral("waveView"));
        waveView->setMaximumSize(QSize(16777215, 125));

        gridLayout->addWidget(waveView, 7, 1, 1, 3);

        moodBox = new QComboBox(centralWidget);
        moodBox->setObjectName(QStringLiteral("moodBox"));

        gridLayout->addWidget(moodBox, 3, 4, 1, 1);

        songList = new QListWidget(centralWidget);
        songList->setObjectName(QStringLiteral("songList"));

        gridLayout->addWidget(songList, 0, 2, 7, 2);

        playList = new QListWidget(centralWidget);
        playList->setObjectName(QStringLiteral("playList"));
        playList->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(playList, 0, 1, 7, 1);

        timeSlider = new QSlider(centralWidget);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        timeSlider->setOrientation(Qt::Horizontal);
        timeSlider->setTickPosition(QSlider::TicksBothSides);
        timeSlider->setTickInterval(60000);

        gridLayout->addWidget(timeSlider, 9, 1, 1, 3);

        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));

        gridLayout->addWidget(timeLabel, 9, 4, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 20));
        label->setMaximumSize(QSize(100, 20));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 4, 4, 1, 1);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(100, 16777215));
        volumeSlider->setMaximum(100);
        volumeSlider->setSliderPosition(50);
        volumeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeSlider, 5, 4, 1, 1);

        playPauseButton = new QPushButton(centralWidget);
        playPauseButton->setObjectName(QStringLiteral("playPauseButton"));

        gridLayout->addWidget(playPauseButton, 0, 4, 1, 1);

        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        gridLayout->addWidget(loadButton, 2, 4, 1, 1);

        skipButton = new QPushButton(centralWidget);
        skipButton->setObjectName(QStringLiteral("skipButton"));

        gridLayout->addWidget(skipButton, 1, 4, 1, 1);

        trackDataLabel = new QLabel(centralWidget);
        trackDataLabel->setObjectName(QStringLiteral("trackDataLabel"));

        gridLayout->addWidget(trackDataLabel, 8, 1, 1, 3);

        musicPlayer->setCentralWidget(centralWidget);

        retranslateUi(musicPlayer);

        QMetaObject::connectSlotsByName(musicPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *musicPlayer)
    {
        musicPlayer->setWindowTitle(QApplication::translate("musicPlayer", "musicPlayer", 0));
        moodBox->clear();
        moodBox->insertItems(0, QStringList()
         << QApplication::translate("musicPlayer", "Happy", 0)
         << QApplication::translate("musicPlayer", "Sad", 0)
         << QApplication::translate("musicPlayer", "Focus", 0)
         << QApplication::translate("musicPlayer", "Sleep", 0)
         << QApplication::translate("musicPlayer", "Wake-Up", 0)
        );
        timeLabel->setText(QApplication::translate("musicPlayer", "time / duration", 0));
        label->setText(QApplication::translate("musicPlayer", "Volume Control", 0));
        playPauseButton->setText(QApplication::translate("musicPlayer", "Play", 0));
        loadButton->setText(QApplication::translate("musicPlayer", "Load Track", 0));
        skipButton->setText(QApplication::translate("musicPlayer", "Skip Track", 0));
        trackDataLabel->setText(QApplication::translate("musicPlayer", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class musicPlayer: public Ui_musicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
