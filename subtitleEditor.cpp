/* 
 * File:   subtitleEditor.cpp
 * Author: rukshan
 * 
 * Created on August 31, 2013, 9:25 AM
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "subtitleEditor.h"
#include "MainWindow.h"
#include "player.h"
#include "printbits.h"
#include <iostream>
#include <qt4/QtGui/qevent.h>
#include "QFileDialog"
#include "FileSelector.h"
#include <QString>
#include <iostream>
#include <string>
#include "srtFormat.h"
#include "header/PlaySubtitle.h"

using namespace std;

MainWindow *window;
player *mplayer;
printbits *waveGen;
subtitleSave *subSave;
FileSelector *fileBrowser;

SubtitleRead *subRead;

Ui::MainWindow widjet;
int pre = 0;
bool isDrag = false;
bool isMarginX = false;
bool isMarginY = false;

subtitleEditor::subtitleEditor() {
    mplayer = new player(); // create new player object

    window = new MainWindow(); //create main window
    window->setPlayer(mplayer); // set player at the player

    waveGen = new printbits(); // set the wavegen class
    waveGen->setMainWindow(window); //set the main window on the print bits class
    waveGen->Attach(this);
    waveGen->start(); // start to read pcm data

    subSave = new subtitleSave(); // create class to save subtitle
    //    subSave->readSubtitle();
    fileBrowser = new FileSelector(); // create object to browse file
    fileBrowser->Attach(this); // set this class as a observer at filebbrowser class

    window->Attach(this); // set this class as a observer at filebbrowser class
    window->getTgs()->Attach(this); // set this class as a observer at filebbrowser class
    window->getTimeCursorTgs()->Attach(this); // set this class as a observer at filebbrowser class
    window->show(); // show the main window
    mplayer->Attach(this); // set this class as a observer at filebbrowser class
    window->getMyItem()->Attach(this);
    window->getPLaySubtitle()->Attach(this);
    //    subRead = new SubtitleRead();
    //    window->setSubReader(subRead);
    //    playSub = new PlaySubtitle(subRead,mplayer);
}

subtitleEditor::subtitleEditor(const subtitleEditor& orig) {
    //    orig=orig;    
}

subtitleEditor::~subtitleEditor() {
}

void subtitleEditor::Update(dataObject object) {
    if (object.object == "play_btn") {// catch the play btn click event
        mplayer->play();
    } else if (object.object == "pause_btn") {
        mplayer->pause();
    } else if (object.object == "srt_btn") {// catch the srt btn click event       
        fileBrowser->saveFile();
    } else if (object.object == "mute_btn") {// catch the mute btn click event
        mplayer->mute(window->getVolumeLevel());
    } else if (object.object == "stop_btn") {// catch the stop btn click event
        mplayer->stop();
    } else if (object.object == "on_volumeSlider_sliderMoved") {// catch the volumeSlider moved event
        mplayer->changeVolume(object.val);
    } else if (object.object == "on_graphicViewSlider_sliderMoved") {// catch the graphicViewSlider moved event
        mplayer->changePosition(object.val);
    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_move") {// catch the timeSlotBar moved event
        QGraphicsView *tg;
        tg = window->getGraphicView().timeSlotBar;
        int newX = tg->x() + object.x;
        QGraphicsView *gv;
        gv = window->getGraphicView().view1;
        QRect r = tg->geometry();

        if (isMarginX || isMarginY) {
            if (isMarginX && r.x() + object.x > gv->x() && r.width() - object.x > 4) {
                tg->setGeometry(r.x() + object.x, r.y(), r.width() - object.x, r.height());
                isDrag = true;
            } else if (r.x() + r.width() + object.x < gv->x() + gv->width() && r.width() + object.x > 4) {
                tg->setGeometry(r.x(), r.y(), r.width() + object.x, r.height());
                isDrag = true;
            }
        } else {
            if (newX > gv->x() && newX < gv->x() + gv->width() - tg->width()) {
                tg->setGeometry(newX, r.y(), r.width(), r.height());
                QApplication::setOverrideCursor(Qt::DragMoveCursor);
                isDrag = true;
            }
        }
        qDebug("move");
        window->increaseSubTime(object.x);

    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_mouse_release") {//time slot mouse release event
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
        isDrag = false;
    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_mouse_press") {//time slot mouse press event
    } else if (object.object == "timeCuser" && object.msg == "time_slot_mouse_press") {//time cursor mouse press event
        cout << "press" << endl;
    } else if (object.object == "timeCuser" && object.msg == "time_slot_mouse_release") {//time cursor mouse release event
        QApplication::setOverrideCursor(Qt::ArrowCursor);
    } else if (object.object == "timeCuser" && object.msg == "time_slot_move") {//time cursor mouse move event
        QGraphicsView *tg;
        tg = window->getGraphicView().timeCurser;
        QGraphicsView *gv;
        gv = window->getGraphicView().view1;
        int newX = tg->x() + object.x;
        QRect r = tg->geometry();
        if (newX > gv->x() && newX < gv->x() + gv->width()) {
            tg->setGeometry(newX, r.y(), r.width(), r.height());
        }
        QApplication::setOverrideCursor(Qt::SizeHorCursor);
    } else if (object.object == "time_slot_enter") {// mouse enter to time slot event
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
        isDrag = false;
    } else if (object.object == "time_slot_leave") {// mouse leave time slot event
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        isDrag = false;
    } else if (object.object == "time_slot_margin") {// mouse inside time slot event
        if (object.x < 0) {
            QApplication::setOverrideCursor(Qt::SizeHorCursor);
            isMarginX = true;
        } else {
            QApplication::setOverrideCursor(Qt::SizeHorCursor);
            isMarginY = true;
        }
    } else if (object.object == "time_slot_margin_leave") {// mouse leave time slot margin event
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        isMarginX = false;
        isMarginY = false;
    } else if (object.object == "time_slot_in_range") {// mouse inside the time slot margin event
        if (!isDrag) {
            QApplication::setOverrideCursor(Qt::OpenHandCursor);
        }
        isMarginX = false;
        isMarginY = false;
    } else if (object.object == "time_cursor") { //if msg from time_cursor
        if (object.msg == "inside") {// if inside
            QApplication::setOverrideCursor(Qt::SizeHorCursor);
        } else if (object.msg == "outside") {// if outside
            QApplication::setOverrideCursor(Qt::ArrowCursor);
        }
    } else if (object.object == "player") {//if msg from player
        if (object.msg == "media_explorer_media") {// if msg to open file
            fileBrowser->openFile();
        } else if (object.msg == "media_explorer_sub") {// if msg to open file
            fileBrowser->openSubFile();
        } else if (object.msg == "play") {// if play msg
            window->setPlayBtnText("play");
        } else if (object.msg == "pause") {// if pause msg
            window->setPlayBtnText("pause");
        } else if (object.msg == "mute") {// if mute msg
            window->setVolumeLevel(object.val);
        }
    } else if (object.object == "file_selector_open") {//if msg from file_selecter
        if (object.val == 0) {
            libvlc_media_player_t * m;
            m = mplayer->open(object.msg); // open new media file
            QWidget* qw;
            qw = window->getGraphicView().graphicsView; // set display on player
#if defined(Q_OS_MAC)
            libvlc_media_player_set_nsobject(m, (void *) qw->winId());
#elif defined(Q_OS_UNIX)
            libvlc_media_player_set_xwindow(mplayer->getMP(), qw->winId());
#elif defined(Q_OS_WIN)
            libvlc_media_player_set_hwnd(m, qw->winId());
#endif
        } else if (object.val == 1) {
//            subRead=new SubtitleRead();
            subRead->open(object.msg);
            window->setSubtitle(subRead->getSubList());
        }

    } else if (object.object == "file_selector_save") {
        vector<srtFormat> f = window->getCurrentSubData();
        QString filename=QString::fromStdString(object.msg);
            if(filename.endsWith(".srt",Qt::CaseInsensitive)){
                subSave->saveFile(f, object.msg);
            }else if(filename.endsWith(".ass",Qt::CaseInsensitive)){
                subSave->saveAsASS(f, object.msg);
            }                   
                
        
    } else if (object.object == "timeChange") {
        //if(object.v)
        cout << object.val << endl;
        window->changeTime(object.val);
    } else if (object.object == "printBits" && object.msg == "setGraph") {
        window->ffmpegGraphPlot(waveGen->getLeftlist(), waveGen->getRightlist());
    } else if (object.object == "sub_Play") {
        window->selectRow(object.val);
    }
    //    cout << object.object << endl;
}

void subtitleEditor::run(){
//     window->setSubtitle(subRead->getSubList());
}