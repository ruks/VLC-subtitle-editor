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
#include "smem.h"
#include "player.h"
#include "printbits.h"
#include <iostream>
#include <qt4/QtGui/qevent.h>
#include "QFileDialog"
#include "FileSelector.h"
#include <QString>
#include <iostream>
#include <string>

using namespace std;

MainWindow *window;
player *mplayer;
printbits *waveGen;
subtitleSave *subSave;
FileSelector *fileBrowser;

Ui::MainWindow widjet;
int pre = 0;
bool isDrag = false;
bool isMarginX = false;
bool isMarginY = false;

subtitleEditor::subtitleEditor() {
    mplayer = new player();

    window = new MainWindow();
    window->setPlayer(mplayer);

    waveGen = new printbits();
    waveGen->setMainWindow(window);
    waveGen->start();

    subSave = new subtitleSave();
    //    subSave->readSubtitle();
    fileBrowser = new FileSelector();
    fileBrowser->Attach(this);

    window->Attach(this);
    window->getTgs()->Attach(this);
    window->getTimeCursorTgs()->Attach(this);
    window->show();
    mplayer->Attach(this);
}

subtitleEditor::subtitleEditor(const subtitleEditor& orig) {
    //    orig=orig;
}

subtitleEditor::~subtitleEditor() {
}

void subtitleEditor::Update(dataObject object) {
    if (object.object == "play_btn") {
        mplayer->play();
    } else if (object.object == "mute_btn") {
        mplayer->mute(window->getVolumeLevel());
    } else if (object.object == "stop_btn") {
        mplayer->stop();
    } else if (object.object == "on_volumeSlider_sliderMoved") {
        mplayer->changeVolume(object.val);
    } else if (object.object == "on_graphicViewSlider_sliderMoved") {
        mplayer->changePosition(object.val);
    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_move") {
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
    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_mouse_release") {
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
        isDrag = false;
    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_mouse_press") {
        //                cout<<"press"<<endl;
    } else if (object.object == "timeCuser" && object.msg == "time_slot_mouse_press") {
        cout << "press" << endl;
    } else if (object.object == "timeCuser" && object.msg == "time_slot_mouse_release") {
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        //        isDrag = false;
    } else if (object.object == "timeCuser" && object.msg == "time_slot_move") {
        //        cout << object.object << endl;
        //        int wx = window->x();
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
    } else if (object.object == "time_slot_enter") {
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
        isDrag = false;
    } else if (object.object == "time_slot_leave") {
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        isDrag = false;
    } else if (object.object == "time_slot_margin") {
        if (object.x < 0) {
            QApplication::setOverrideCursor(Qt::SizeHorCursor);
            isMarginX = true;
        } else {
            QApplication::setOverrideCursor(Qt::SizeHorCursor);
            isMarginY = true;
        }
    } else if (object.object == "time_slot_margin_leave") {
        QApplication::setOverrideCursor(Qt::ArrowCursor);
        isMarginX = false;
        isMarginY = false;
    } else if (object.object == "time_slot_in_range") {
        if (!isDrag) {
            QApplication::setOverrideCursor(Qt::OpenHandCursor);
        }
        isMarginX = false;
        isMarginY = false;
        //                QApplication::restoreOverrideCursor();
    } else if (object.object == "time_cursor") {
        if (object.msg == "inside") {
            QApplication::setOverrideCursor(Qt::SizeHorCursor);
        } else if (object.msg == "outside") {
            QApplication::setOverrideCursor(Qt::ArrowCursor);
        }
    } else if (object.object == "player") {
        if (object.msg == "media_explorer") {
            cout << object.msg << endl;
            fileBrowser->openFile();
        } else if (object.msg == "play") {
            window->setPlayBtnText("play");
        } else if (object.msg == "pause") {
            window->setPlayBtnText("pause");
        } else if (object.msg == "mute") {
            window->setVolumeLevel(object.val);
        }
    } else if (object.object == "file_selecter") {
        libvlc_media_player_t * m;
        m=mplayer->open(object.msg);
        QWidget* qw;
        qw=window->getGraphicView().graphicsView;
#if defined(Q_OS_MAC)
        libvlc_media_player_set_nsobject(m, (void *) qw->winId());
#elif defined(Q_OS_UNIX)
        libvlc_media_player_set_xwindow(m,qw->winId());
#elif defined(Q_OS_WIN)
        libvlc_media_player_set_hwnd(m, qw->winId());
#endif

    }
    //    cout << object.object << endl;
}