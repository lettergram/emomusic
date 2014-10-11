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
    QPushButton *loadButton;
    QSlider *volumeSlider;
    QListWidget *listWidget;
    QPushButton *skipButton;
    QPushButton *playPauseButton;
    QLabel *label;

    void setupUi(QMainWindow *musicPlayer)
    {
        if (musicPlayer->objectName().isEmpty())
            musicPlayer->setObjectName(QStringLiteral("musicPlayer"));
        musicPlayer->resize(800, 480);
        centralWidget = new QWidget(musicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        gridLayout->addWidget(loadButton, 2, 2, 1, 1);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(100, 16777215));
        volumeSlider->setMaximum(100);
        volumeSlider->setSliderPosition(50);
        volumeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeSlider, 5, 2, 1, 1);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        gridLayout->addWidget(listWidget, 0, 1, 8, 1);

        skipButton = new QPushButton(centralWidget);
        skipButton->setObjectName(QStringLiteral("skipButton"));

        gridLayout->addWidget(skipButton, 1, 2, 1, 1);

        playPauseButton = new QPushButton(centralWidget);
        playPauseButton->setObjectName(QStringLiteral("playPauseButton"));

        gridLayout->addWidget(playPauseButton, 0, 2, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 20));
        label->setMaximumSize(QSize(100, 20));
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 4, 2, 1, 1);

        musicPlayer->setCentralWidget(centralWidget);

        retranslateUi(musicPlayer);

        QMetaObject::connectSlotsByName(musicPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *musicPlayer)
    {
        musicPlayer->setWindowTitle(QApplication::translate("musicPlayer", "musicPlayer", 0));
        loadButton->setText(QApplication::translate("musicPlayer", "Load Track", 0));
        skipButton->setText(QApplication::translate("musicPlayer", "Skip Track", 0));
        playPauseButton->setText(QApplication::translate("musicPlayer", "Play", 0));
        label->setText(QApplication::translate("musicPlayer", "Volume Control", 0));
    } // retranslateUi

};

namespace Ui {
    class musicPlayer: public Ui_musicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
