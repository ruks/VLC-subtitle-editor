/* 
 * File:   tgs.h
 * Author: rukshan
 *
 * Created on August 31, 2013, 8:00 PM
 */

#ifndef TGS_H
#define	TGS_H

#include <QGraphicsScene>
#include <QString>
#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsView>
#include <iostream>
#include "Observable.h"
#include <QEvent>
#include <string>

using namespace std;

class TGS : public QGraphicsScene, public Observable {
public:
    TGS(string sender);
    TGS(const TGS& orig);
    virtual ~TGS();

    public
slots:
    //    void drawBackground(QPainter *painter, const QRectF &rect);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    bool events(QEvent *e);
    
    QString str;
    QGraphicsTextItem cursor;
    string sender;    
    
};

#endif	/* TGS_H */

