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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicPlayer
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *volumeLabel;
    QSlider *volumeSlider;
    QLabel *trackDataLabel;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *playPauseButton;
    QPushButton *loadButton;
    QComboBox *moodBox;
    QPushButton *skipButton;
    QSlider *timeSlider;
    QSpacerItem *verticalSpacer;
    QLabel *songLabel;
    QSpacerItem *horizontalSpacer_4;
    QTreeWidget *songList;
    QLabel *playlistLabel;
    QListWidget *playList;
    QLabel *timeLabel;

    void setupUi(QMainWindow *musicPlayer)
    {
        if (musicPlayer->objectName().isEmpty())
            musicPlayer->setObjectName(QStringLiteral("musicPlayer"));
        musicPlayer->setWindowModality(Qt::NonModal);
        musicPlayer->resize(850, 600);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        font.setStyleStrategy(QFont::NoAntialias);
        musicPlayer->setFont(font);
        musicPlayer->setFocusPolicy(Qt::StrongFocus);
        musicPlayer->setContextMenuPolicy(Qt::NoContextMenu);
        musicPlayer->setAcceptDrops(false);
        musicPlayer->setStyleSheet(QLatin1String("#centralWidget{\n"
"	background:qlineargradient(spread:pad, x1:0, y1:0.0340909, x2:1, y2:1, stop:0 rgba(224, 0, 124, 255), stop:1 rgba(81, 32, 37, 255))\n"
"}\n"
"\n"
"#playList {\n"
"	color:rgba(255, 255, 255, 255); \n"
"	border-style: outset;\n"
"    border-width: 5px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"	background: rgba(255, 255, 255, 0);\n"
"    padding: 0px;\n"
"}\n"
"\n"
"#songList {\n"
"    border-style: outset;\n"
"    border-width: 5px;\n"
"    border-radius: 10px;\n"
"    border-color: white;\n"
"	background: rgba(255, 255, 255, 200);\n"
"    padding: 0px;\n"
"}\n"
"\n"
"#songList:targeted {\n"
"	color: white;\n"
"}\n"
"\n"
"#waveView {\n"
"	border-style: outset;\n"
"    border-width: 5px;\n"
"    border-radius: 10px;\n"
"    border-color: rgba(255, 255, 255, 0);\n"
"	background: rgba(255, 255, 255, 0);\n"
"    padding: 0px;\n"
"}\n"
"\n"
"#loadButton {\n"
"	 background-color: rgb(213, 23, 133);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radi"
                        "us: 10px;\n"
"     border-color: beige;\n"
"     font: bold 14px;\n"
"     min-width: 4em;\n"
"     padding: 1px;\n"
"	 color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#loadButton:pressed {\n"
"    background-color: rgb(255,255,255);\n"
"	color: rgb(239, 129, 245);\n"
"    border-style: inset;\n"
" }\n"
"\n"
"#playPauseButton {\n"
"	 background-color: rgb(213, 23, 133);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: beige;\n"
"     font: bold 14px;\n"
"     min-width: 4em;\n"
"     padding: 1px;\n"
"	 color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#playPauseButton:pressed {\n"
"    background-color: rgb(255,255,255);\n"
"	color: rgb(239, 129, 245);\n"
"    border-style: inset;\n"
" }\n"
"\n"
"#skipButton {\n"
"	 background-color: rgb(213, 23, 133);\n"
"     border-style: outset;\n"
"     border-width: 2px;\n"
"     border-radius: 10px;\n"
"     border-color: rgba(255, 255, 255, 255);\n"
"     font: bold 14px;\n"
"     min-width: 4em;\n"
"     padding: 1px;\n"
""
                        "	 color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"#skipButton:pressed {\n"
"    background-color: rgb(255,255,255);\n"
"	color: rgb(239, 129, 245);\n"
"    border-style: inset;\n"
" }\n"
"\n"
"#trackDataLabel {\n"
"	color: rgba(0, 0, 0, 150);\n"
"}\n"
"\n"
"#volumeLabel {\n"
"	color:rgba(0, 0, 0, 180);\n"
"}\n"
"\n"
"#songLabel {\n"
"	color:rgba(0, 0, 0, 180);\n"
"}\n"
"\n"
"#playlistLabel {\n"
"	color:rgba(0, 0, 0, 180);\n"
"}\n"
"\n"
"QComboBox{\n"
"    border-style: outset;\n"
"    border-width: 2px;\n"
"    border-radius: 10px;\n"
"    border-color: beige;\n"
"    font: bold 14px;\n"
"    min-width: 1em;\n"
"\n"
"	background-color: rgb(213, 23, 133);\n"
"   	color: rgb(255, 255, 255);\n"
"    selection-background-color:rgb(206, 152, 246);\n"
"}\n"
"QComboBox QAbstractItemView{\n"
"	border-width: 0px;\n"
"    background-color: rgb(213, 23, 133);\n"
"   	color: rgb(39, 223, 253);\n"
"    selection-background-color:rgb(206, 152, 246);\n"
"}\n"
"QComboBox::drop-down {\n"
"	border-width: 0px;\n"
"} \n"
"QComboBox::do"
                        "wn-arrow {\n"
"	image: url(noimg); \n"
"	border-width: 0px;\n"
"}\n"
"\n"
"QLabel {\n"
"	color:white;\n"
"}\n"
"\n"
"#trackDataLabel {\n"
"	color:white;\n"
"}\n"
"\n"
"#volumeLabel {\n"
"	color:white;\n"
"}\n"
"\n"
"#songLabel {\n"
"	color:white;\n"
"}\n"
"\n"
"#playlistLabel {\n"
"	color:white;\n"
"}\n"
"\n"
"#timeLabel {\n"
"	color:white;\n"
"}"));
        musicPlayer->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        musicPlayer->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(musicPlayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        volumeLabel = new QLabel(centralWidget);
        volumeLabel->setObjectName(QStringLiteral("volumeLabel"));
        volumeLabel->setMinimumSize(QSize(100, 20));
        volumeLabel->setMaximumSize(QSize(140, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        volumeLabel->setFont(font1);
        volumeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(volumeLabel, 15, 7, 1, 1);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(140, 16777215));
        volumeSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 13px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0.369, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(223, 19, 124, 255));\n"
"border: 1px solid rgb(142, 18, 74);\n"
"height: 4px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: rgb(230, 230, 230);\n"
"border: 1px solid rgb(117, 24, 58);\n"
"height: 12px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:0.990148, y2:0.71, stop:0 rgba(181, 181, 181, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border: 1px solid #777;\n"
"width: 8px;\n"
"height: 12px;\n"
"margin-top: -3px;\n"
"margin-bottom: -3px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
""
                        "border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        volumeSlider->setMaximum(100);
        volumeSlider->setSliderPosition(50);
        volumeSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(volumeSlider, 16, 7, 1, 1);

        trackDataLabel = new QLabel(centralWidget);
        trackDataLabel->setObjectName(QStringLiteral("trackDataLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(trackDataLabel->sizePolicy().hasHeightForWidth());
        trackDataLabel->setSizePolicy(sizePolicy);
        trackDataLabel->setMaximumSize(QSize(550, 20));
        QFont font2;
        font2.setPointSize(12);
        trackDataLabel->setFont(font2);
        trackDataLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(trackDataLabel, 15, 4, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 16, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 16, 3, 1, 1);

        playPauseButton = new QPushButton(centralWidget);
        playPauseButton->setObjectName(QStringLiteral("playPauseButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(playPauseButton->sizePolicy().hasHeightForWidth());
        playPauseButton->setSizePolicy(sizePolicy1);
        playPauseButton->setMinimumSize(QSize(74, 30));
        playPauseButton->setMaximumSize(QSize(50, 40));
        playPauseButton->setBaseSize(QSize(0, 40));
        playPauseButton->setCursor(QCursor(Qt::PointingHandCursor));
        playPauseButton->setIconSize(QSize(24, 24));

        gridLayout->addWidget(playPauseButton, 16, 0, 1, 1);

        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));
        loadButton->setMinimumSize(QSize(74, 30));

        gridLayout->addWidget(loadButton, 1, 7, 1, 1);

        moodBox = new QComboBox(centralWidget);
        moodBox->setObjectName(QStringLiteral("moodBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(moodBox->sizePolicy().hasHeightForWidth());
        moodBox->setSizePolicy(sizePolicy2);
        moodBox->setMinimumSize(QSize(21, 30));
        moodBox->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(moodBox, 3, 7, 1, 1);

        skipButton = new QPushButton(centralWidget);
        skipButton->setObjectName(QStringLiteral("skipButton"));
        sizePolicy1.setHeightForWidth(skipButton->sizePolicy().hasHeightForWidth());
        skipButton->setSizePolicy(sizePolicy1);
        skipButton->setMinimumSize(QSize(74, 30));
        skipButton->setMaximumSize(QSize(50, 40));
        skipButton->setBaseSize(QSize(40, 0));
        skipButton->setIconSize(QSize(32, 32));

        gridLayout->addWidget(skipButton, 16, 2, 1, 1);

        timeSlider = new QSlider(centralWidget);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        sizePolicy.setHeightForWidth(timeSlider->sizePolicy().hasHeightForWidth());
        timeSlider->setSizePolicy(sizePolicy);
        timeSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 13px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(245, 191, 218);\n"
"border: 1px solid rgb(142, 18, 74);\n"
"height: 4px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: rgb(245, 191, 218);\n"
"border: 1px solid rgb(117, 24, 58);\n"
"height: 12px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:qlineargradient(spread:pad, x1:0, y1:0, x2:0.990148, y2:0.71, stop:0 rgba(181, 181, 181, 255), stop:1 rgba(255, 255, 255, 255));\n"
"border: 1px solid #777;\n"
"width: 5px;\n"
"height: 12px;\n"
"margin-top: -4px;\n"
"margin-bottom: -4px;\n"
"border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(spread:pad, x1:1, y1:1, x2:0, y2:0.603, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(223, 19, 124, 255))\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::"
                        "sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        timeSlider->setOrientation(Qt::Horizontal);
        timeSlider->setTickPosition(QSlider::TicksBothSides);
        timeSlider->setTickInterval(60000);

        gridLayout->addWidget(timeSlider, 16, 4, 1, 2);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 2, 7, 1, 1);

        songLabel = new QLabel(centralWidget);
        songLabel->setObjectName(QStringLiteral("songLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(songLabel->sizePolicy().hasHeightForWidth());
        songLabel->setSizePolicy(sizePolicy3);
        songLabel->setBaseSize(QSize(500, 600));
        QFont font3;
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        songLabel->setFont(font3);
        songLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(songLabel, 0, 4, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 15, 6, 1, 1);

        songList = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(4, font1);
        __qtreewidgetitem->setFont(3, font1);
        __qtreewidgetitem->setFont(2, font1);
        __qtreewidgetitem->setFont(1, font1);
        __qtreewidgetitem->setFont(0, font1);
        songList->setHeaderItem(__qtreewidgetitem);
        songList->setObjectName(QStringLiteral("songList"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(songList->sizePolicy().hasHeightForWidth());
        songList->setSizePolicy(sizePolicy4);
        songList->setMaximumSize(QSize(9999, 9999));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(false);
        font4.setWeight(50);
        songList->setFont(font4);
        songList->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        songList->setContextMenuPolicy(Qt::DefaultContextMenu);
        songList->setAutoFillBackground(false);
        songList->setAutoScroll(false);
        songList->setProperty("showDropIndicator", QVariant(false));
        songList->setAlternatingRowColors(false);
        songList->setSelectionMode(QAbstractItemView::SingleSelection);
        songList->setIndentation(20);
        songList->setRootIsDecorated(false);
        songList->setUniformRowHeights(false);
        songList->setItemsExpandable(false);
        songList->setSortingEnabled(true);
        songList->setAllColumnsShowFocus(false);
        songList->setExpandsOnDoubleClick(false);
        songList->header()->setVisible(true);
        songList->header()->setCascadingSectionResizes(false);
        songList->header()->setDefaultSectionSize(150);
        songList->header()->setHighlightSections(false);

        gridLayout->addWidget(songList, 1, 4, 14, 2);

        playlistLabel = new QLabel(centralWidget);
        playlistLabel->setObjectName(QStringLiteral("playlistLabel"));
        playlistLabel->setMaximumSize(QSize(16777215, 20));
        playlistLabel->setFont(font3);
        playlistLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(playlistLabel, 0, 0, 1, 4);

        playList = new QListWidget(centralWidget);
        new QListWidgetItem(playList);
        new QListWidgetItem(playList);
        new QListWidgetItem(playList);
        new QListWidgetItem(playList);
        playList->setObjectName(QStringLiteral("playList"));
        sizePolicy4.setHeightForWidth(playList->sizePolicy().hasHeightForWidth());
        playList->setSizePolicy(sizePolicy4);
        playList->setMinimumSize(QSize(120, 0));
        playList->setMaximumSize(QSize(160, 9999));

        gridLayout->addWidget(playList, 1, 0, 14, 4);

        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setWeight(75);
        timeLabel->setFont(font5);
        timeLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(timeLabel, 15, 0, 1, 3);

        musicPlayer->setCentralWidget(centralWidget);

        retranslateUi(musicPlayer);

        QMetaObject::connectSlotsByName(musicPlayer);
    } // setupUi

    void retranslateUi(QMainWindow *musicPlayer)
    {
        musicPlayer->setWindowTitle(QApplication::translate("musicPlayer", "BrainBeats - Music Player", 0));
        volumeLabel->setText(QApplication::translate("musicPlayer", "Volume Control", 0));
        trackDataLabel->setText(QApplication::translate("musicPlayer", "Title/Data/Label", 0));
        playPauseButton->setText(QString());
        loadButton->setText(QApplication::translate("musicPlayer", "Load Track", 0));
        moodBox->clear();
        moodBox->insertItems(0, QStringList()
         << QApplication::translate("musicPlayer", "Select Mood", 0)
         << QApplication::translate("musicPlayer", "Happy", 0)
         << QApplication::translate("musicPlayer", "Relaxation", 0)
         << QApplication::translate("musicPlayer", "Sad", 0)
         << QApplication::translate("musicPlayer", "Upset/Angry", 0)
         << QApplication::translate("musicPlayer", "Upbeat", 0)
         << QApplication::translate("musicPlayer", "Depressing", 0)
        );
        skipButton->setText(QString());
        songLabel->setText(QApplication::translate("musicPlayer", "Songs", 0));
        QTreeWidgetItem *___qtreewidgetitem = songList->headerItem();
        ___qtreewidgetitem->setText(4, QApplication::translate("musicPlayer", "Playlist", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("musicPlayer", "Album", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("musicPlayer", "Artist", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("musicPlayer", "Duration", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("musicPlayer", "Name", 0));
        playlistLabel->setText(QApplication::translate("musicPlayer", "Playlists", 0));

        const bool __sortingEnabled = playList->isSortingEnabled();
        playList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = playList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("musicPlayer", "Workout Beats", 0));
        QListWidgetItem *___qlistwidgetitem1 = playList->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("musicPlayer", "Study Jam", 0));
        QListWidgetItem *___qlistwidgetitem2 = playList->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("musicPlayer", "Gaming", 0));
        playList->setSortingEnabled(__sortingEnabled);

        timeLabel->setText(QApplication::translate("musicPlayer", "00:00:00/00:00:00", 0));
    } // retranslateUi

};

namespace Ui {
    class musicPlayer: public Ui_musicPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICPLAYER_H
