/* 
 * File:   MyItem.h
 * Author: rukshan
 *
 * Created on September 20, 2013, 1:03 PM
 */

#ifndef MYITEM_H
#define	MYITEM_H
#include <QtGui>
#include <QtCore>
#include "Observable.h"

class MyItem : public QGraphicsRectItem,public Observable {
public:
    MyItem();
    MyItem(const MyItem& orig);
    virtual ~MyItem();
private:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    bool sceneEventFilter(QGraphicsItem *watched,QEvent *event);

};

#endif	/* MYITEM_H */

