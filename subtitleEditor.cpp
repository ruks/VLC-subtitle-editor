/* 
 * File:   subtitleEditor.cpp
 * Author: rukshan
 * 
 * Created on August 31, 2013, 9:25 AM
 */

#include "subtitleEditor.h"
#include "MainWindow.h"
#include "smem.h"
#include "player.h"
#include "printbits.h"
#include <iostream>
#include <qt4/QtGui/qevent.h>

using namespace std;

MainWindow *window;
player *mplayer;
printbits *waveGen;
subtitleSave *subSave;
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

    window->Attach(this);
    window->getTgs()->Attach(this);
    window->getTimeCursorTgs()->Attach(this);
    window->show();
}

subtitleEditor::subtitleEditor(const subtitleEditor& orig) {
}

subtitleEditor::~subtitleEditor() {
}

void subtitleEditor::Update(dataObject object) {
    if (object.object == "play_btn") {
        mplayer->load(window->getGraphicView().graphicsView);
        mplayer->play(window->getGraphicView().play);
    } else if (object.object == "stop_btn") {
        mplayer->stop();
    } else if (object.object == "on_volumeSlider_sliderMoved") {
        mplayer->changeVolume(object.val);
    } else if (object.object == "on_graphicViewSlider_sliderMoved") {
        mplayer->changePosition(object.val);
    } else if (object.object == "timeSlotBar" && object.msg == "time_slot_move") {

        int wx = window->x();
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
        int wx = window->x();
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
    }
    //    cout << object.object << endl;
}