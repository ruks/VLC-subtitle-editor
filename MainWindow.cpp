/*
 * File:   MainWindow.cpp
 * Author: rukshan
 *
 * Created on August 29, 2013, 1:08 PM
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include <QPainter>
#include <QQueue>
#include <QVector>
#include <QTimer>
#include <QTimerEvent>
#include "MainWindow.h"
#include <QMainWindow>
#include "ui_MainWindow.h"
#include "player.h"
#include "header/tgs.h"
#include <QPixmap>
#include <QGraphicsView>
#include <iostream>
#include <QScrollBar>
#include <QPen>
#include <QGraphicsItem>
#include "header/tgs.h"
#include <QEvent>
#include <sstream> 

using namespace std;

QQueue<int8_t> Q0;
QQueue<int8_t> Q1;
QPixmap *pixmap;
QGraphicsPixmapItem *pixmapItem;
QGraphicsScene *scene;
bool sta;
QScrollBar *h0, *h1;
player *mpw;
subtitleSave *sub;
TGS *t;
TGS *tt;
QGraphicsScene *timeLineScene;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    widget.setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateInterface()));
    timer->start(100);
    sta = false;

    h0 = widget.view0->horizontalScrollBar();
    h1 = widget.view1->horizontalScrollBar();

    widget.tableWidget->setColumnWidth(3, widget.tableWidget->width() - 380);
    widget.graphicViewSlider->setMaximum(1000);
    t = new TGS("timeSlotBar");
    widget.timeSlotBar->setScene(t);
    widget.timeSlotBar->setBackgroundBrush(QBrush(QColor(200, 200, 255, 100)));
    widget.timeSlotBar->setStyleSheet("background-color: transparent");

    tt = new TGS("timeCuser");
    widget.timeCurser->setScene(tt);
    widget.timeCurser->setBackgroundBrush(QBrush(QColor(95, 95, 95, 255)));
    widget.timeCurser->setStyleSheet("background-color: transparent");

    timeLineScene = new QGraphicsScene();
    drawRuler();
}

MainWindow::~MainWindow() {
}

void MainWindow::setPlayer(player* p) {
    mpw = p;
}

Ui::MainWindow MainWindow::getGraphicView() {
    return widget;
}

void MainWindow::setSubtitleSave(subtitleSave* s) {
    sub = s;
}

void MainWindow::paintEvent(QPaintEvent*) {

    //    QPainter painter(this);
    //    painter.setRenderHint(QPainter::Antialiasing, true);
    //    painter.setPen(QPen(Qt::black, 2));
    //    //    printf("%d\n",Q.size());
    //    for (int i = 0; i < Q.size(); i++) {
    //        int e = Q.at(i);
    //        painter.drawLine(QPointF(i, 255), QPointF(i, 255 + e));
    //    }
    //    painter.drawLine(QPointF(0,0), QPointF(100,100));
}

void MainWindow::addToQueue(int a0, int a1) {
    Q0.enqueue(a0);
    Q1.enqueue(a1);
}

void MainWindow::updateInterface() {
    if (sta) {

        QGraphicsScene *scene0 = new QGraphicsScene();
        QGraphicsScene *scene1 = new QGraphicsScene();
        QGraphicsScene *scene2 = new QGraphicsScene();


        widget.view0->setScene(scene0);
        widget.view1->setScene(scene1);
        widget.graphicsView->setScene(scene2);
        widget.timeLine->setScene(timeLineScene);

        widget.view0->setBackgroundBrush(QBrush(Qt::green, Qt::SolidPattern));
        widget.view1->setBackgroundBrush(QBrush(Qt::green, Qt::SolidPattern));
        widget.graphicsView->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

        //        QGraphicsRectItem *rect=new QGraphicsRectItem(0,0,100,100);
        //        rect->setBrush(QBrush(Qt::green));

        int x, y0, y1;
        for (int i = 0; i < Q0.size(); i++) {
            y0 = 255 + Q0.at(i) / 3;
            x = 255;
            scene0->addLine(QLineF(i, x, i, y0), QPen(Qt::blue));
            y1 = 255 + Q1.at(i) / 3;
            scene1->addLine(QLineF(i, x, i, y1), QPen(Qt::blue));
        }


        widget.view0->show();
        widget.view1->show();
        sta = false;
    }
    h0->setMaximum(20000);
    h1->setMaximum(20000);
    widget.horizontalScrollBar->setMaximum(h0->maximum());
    widget.graphicViewSlider->setValue(mpw->getPosition());

    int a = QCursor::pos().x();
    int b = this->x();
    int c = widget.timeSlotBar->pos().x();

    int d = a - (b + c);
    int e = a - (b + c + widget.timeSlotBar->width());

    dataObject ob;
    ob.object = "time_slot_margin";

    if (d <= 4 && d > 0) {//left
        ob.x = -1;
    } else if (e < 0 && e >= -4) {
        ob.x = 1;
    } else if (d < widget.timeSlotBar->width() && d > 0) {
        ob.object = "time_slot_in_range";
    } else {
        ob.object = "time_slot_margin_leave";
    }
    Notify(ob);

    int y = QCursor::pos().x()-(widget.timeCurser->x() + this->x());
    dataObject ob1;
    if (0 < y && y < 5) {
        ob1.object = "time_cursor";
        ob1.msg = "inside";
        Notify(ob1);
    } else if (d >= widget.timeSlotBar->width() || d <= 0) {
        ob1.object = "time_cursor";
        ob1.msg = "outside";
        Notify(ob1);
    }
}

void MainWindow::update() {
    //    updateInterface();
    sta = true;

}

void MainWindow::on_horizontalScrollBar_sliderMoved(int position) {
    h1->setValue(position);
    h0->setValue(position);
    //    Notify("wave_slider");
}

void MainWindow::on_srt_clicked() {
    //    node no[10];
    //    no[0].id = 0;
    //    no[0].startTime = "10:10:10,100";
    //    no[0].endTime = "20:20:20,200";
    //    no[0].duration = "2000";
    //    no[0].text = "this this my first subtitle file";
    //    sub->saveAsSRT(no);
    //    Notify("srt_btn");
}

void MainWindow::on_play_clicked() {
    dataObject ob;
    ob.object = "play_btn";
    Notify(ob);
}

void MainWindow::on_stop_clicked() {
    //    Notify("stop_btn");
}

void MainWindow::on_mute_clicked() {
    //    Notify("mute_btn");
}

void MainWindow::on_volumeSlider_sliderMoved(int position) {
    //    Notify("on_volumeSlider_sliderMoved");
    dataObject ob;
    ob.object = "on_volumeSlider_sliderMoved";
    ob.val = position;
    Notify(ob);
}

void MainWindow::on_graphicViewSlider_sliderMoved(int position) {
    dataObject ob;
    ob.object = "on_graphicViewSlider_sliderMoved";
    ob.val = position;
    Notify(ob);
}

TGS* MainWindow::getTgs() {
    return t;
}

TGS* MainWindow::getTimeCursorTgs() {
    return tt;
}

void MainWindow::drawRuler() {
    int x = widget.timeLine->x();
    QGraphicsTextItem * io;
    for (int i = 0; i < 500; i += 10) {
        io = new QGraphicsTextItem();
        io->setPos(x + i, 10);

        int len = i;
        std::ostringstream ostr; //output string stream
//        ostr.`
        ostr << len; //use the string stream just like cout,
        string length = ostr.str();
        io->setPlainText(QString(length.c_str()));
        timeLineScene->addItem(io);
        timeLineScene->addLine(QLineF(x + i, 0, x + i, 10), QPen(Qt::white));
    }
}

void MainWindow::on_scale_in_but_clicked() {
    widget.timeLine->scale(1.1, 1);
    widget.view0->scale(1.1, 1);
    widget.view1->scale(1.1, 1);
}

void MainWindow::on_scale_out_but_clicked() {
    widget.timeLine->scale(0.9, 1);
    widget.view0->scale(0.9, 1);
    widget.view1->scale(0.9, 1);
}