/* 
 * File:   MyGraphicScene.h
 * Author: rukshan
 *
 * Created on September 3, 2013, 8:29 PM
 */

#ifndef MYGRAPHICSCENE_H
#define	MYGRAPHICSCENE_H
#include <QPainter>
#include <QRectF>
//#in

class MyGraphicScene : public QGraphicsScene {
public:
    MyGraphicScene();
    MyGraphicScene(const MyGraphicScene& orig);
    virtual ~MyGraphicScene();
private:

protected:
    void drawForeground(QPainter *painter, const QRectF &rect);

};

#endif	/* MYGRAPHICSCENE_H */

