/* 
 * File:   MyItem.cpp
 * Author: rukshan
 * 
 * Created on September 20, 2013, 1:03 PM
 */

#include "header/MyItem.h"
#include "srtFormat.h"

MyItem::MyItem() {
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable, true);
//    installSceneEventFilter(this);
}

MyItem::MyItem(const MyItem& orig) {
}

MyItem::~MyItem() {
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QApplication::setOverrideCursor(Qt::ClosedHandCursor);
}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    QApplication::restoreOverrideCursor();
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    int k = event->screenPos().x() - event->lastScreenPos().x();
    int i = event->pos().x();
    int j = rect().x();
    QString s = QString::number(i, 10);
    
    if (i >= j && i <= j + 10) {
        this->setRect(rect().x() + k, rect().y(), rect().width() - k, rect().height());
        qDebug("here");
    } else if (i >= j + rect().width() - 5 && i <= j + rect().width()) {
        this->setRect(rect().x(), rect().y(), rect().width() + k, rect().height());
    } else {
        this->setX(this->x() + k);
    }
    dataObject ob;
    ob.object = "timeChange";
    ob.val = i;
    //    Notify(ob);
}

void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    QApplication::setOverrideCursor(Qt::OpenHandCursor);
}

void MyItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    //    QApplication::restoreOverrideCursor();
    QApplication::setOverrideCursor(Qt::ArrowCursor);
    qDebug("leave");
}

void MyItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    int i = event->pos().x();
    int j = rect().x();
    QString s = QString::number(i, 10);
    QString sj = QString::number(j, 10);

//    qDebug(s.toStdString().c_str());
//    qDebug(sj.toStdString().c_str());
    if (i >= j && i <= j + 5) {
        QApplication::setOverrideCursor(Qt::SizeHorCursor);
    } else if (i >= j + rect().width() - 5 && i <= j + rect().width()) {
        QApplication::setOverrideCursor(Qt::SizeHorCursor);
    } else {
        QApplication::setOverrideCursor(Qt::OpenHandCursor);
    }
}

bool MyItem::sceneEventFilters(QGraphicsItem* watched, QEvent* event) {
    if (watched == this) {

        if (event->type() == QEvent::MouseButtonPress) {
            cout << "item pressed!" << endl;
            return TRUE;
        } else {
            return FALSE;
        }

    }
    qDebug("no");
}