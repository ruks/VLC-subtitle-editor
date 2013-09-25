/* 
 * File:   tgs.cpp
 * Author: rukshan
 * 
 * Created on August 31, 2013, 8:00 PM
 */

#include "header/tgs.h"
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <qt4/QtGui/qapplication.h>
#include <qt4/QtGui/qevent.h>

using namespace std;

#define _alto  300
#define _ancho 700
int pre_x;
int now_x;

TGS::TGS(string sender) {
    this->sender = sender;
}

TGS::TGS(const TGS& orig) {
}

TGS::~TGS() {
}

void TGS::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) {
    QString string = QString("%1, %2") .arg(mouseEvent->scenePos().x()) .arg(mouseEvent->scenePos().y()); // Update the cursor position text
    this->str = string;
    this->update();
    dataObject ob;
    ob.object = sender;
    ob.msg = "time_slot_move";
    ob.x = mouseEvent->screenPos().x() - mouseEvent->lastScreenPos().x();
//    Notify(ob);
//    cout<<mouseEvent->type()<<endl;
}

void TGS::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->update();
    dataObject ob;
    ob.object = sender;
    ob.msg = "time_slot_mouse_press";
//    Notify(ob);
//    cout<<"press"<<endl;
}

void TGS::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    pre_x = event->scenePos().x();
    this->update();
    dataObject ob;
    ob.object = sender;
    ob.msg = "time_slot_mouse_release";
//    Notify(ob);

}

bool TGS::events(QEvent* e) {
    dataObject ob;
    ob.object = "";

    if (e->type() == 10) {
        ob.object = "time_slot_enter";
        ob.x = QCursor::pos().x();
    } else if (e->type() == 11) {
        ob.object = "time_slot_leave";
    } else if (e->type() == 155) {
        ob.x = QCursor::pos().x();
        ob.object = "time_slot_move";
    } else if (e->type() == 156) {

    } else if (e->type() == 157) {
        ob.object = "time_slot_mouse_release";
    } else {
        //        cout<<e->type()<<endl;
    }

    //    Notify(ob);
}