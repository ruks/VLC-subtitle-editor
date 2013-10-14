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
#include <qt4/QtGui/qabstractslider.h>
#include <QPen>
#include <QGraphicsItem>
#include "header/tgs.h"
#include "header/SubtitleRead.h"
#include "qstringbuilder.h"
#include "qthread.h"
#include "header/MyItem.h"
#include "header/PlaySubtitle.h"
#include <QEvent>
#include <sstream>
#include <math.h> 
#include <QUrl>
#include <qt4/QtGui/qtablewidget.h>
#include <qt4/QtCore/qdebug.h>
#include <QDebug>
#include <qt4/QtCore/qstring.h>
#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <qt4/QtCore/qmetatype.h>
#include <qt4/QtCore/qvariant.h>
#include "header/PlaySubtitle.h"
#include "header/MyQTimeEdit.h"

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
QGraphicsScene *scene0;
QGraphicsScene *scene1;
QGraphicsScene *scene2;
short int *Samples;
double SampleLength;
int sampleRate;
SubtitleRead *reads;
int posi = 0;
MyItem *slot;
QQueue<int> qLL;
QQueue<int> qRR;
PlaySubtitle *playSub;
vector<srtFormat> subList;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    widget.setupUi(this); //init gui components
    setAcceptDrops(true); //accept drag & drop
    QTimer *timer = new QTimer(this); //create timer
    connect(timer, SIGNAL(timeout()), this, SLOT(updateInterface())); //connect method to timer object
    timer->start(10); // start timer with 100ms interval
    sta = false;

    //    h0 = widget.view0->horizontalScrollBar();
    h1 = widget.view1->horizontalScrollBar();

    widget.volumeSlider->setMaximum(200); // set volume bar as maximum 200

    widget.tableWidget->setColumnWidth(3, widget.tableWidget->width() - 380); // set table width
    widget.graphicViewSlider->setMaximum(1000);

    t = new TGS("timeSlotBar"); // draw object for change time duration
    widget.timeSlotBar->setScene(t);
    widget.timeSlotBar->setBackgroundBrush(QBrush(QColor(200, 200, 255, 100)));
    widget.timeSlotBar->setStyleSheet("background-color: transparent");
    widget.timeSlotBar->setVisible(true);

    tt = new TGS("timeCuser"); // draw object for time cursor
    widget.timeCurser->setScene(tt);
    widget.timeCurser->setBackgroundBrush(QBrush(QColor(95, 95, 95, 255)));
    widget.timeCurser->setStyleSheet("background-color: transparent");

    //    widget.view0->setStyleSheet("background-color: transparent");
    widget.view1->setStyleSheet("background-color: transparent");
    timeLineScene = new QGraphicsScene();
    drawRuler();
    drawGraph();

    reads = new SubtitleRead(); // create object for read subtitle
    widget.volumeSlider->setValue(80);

//    reads->open("/home/rukshan/Oblivion.srt");
//    setSubtitle(reads->getSubList());

    playSub = new PlaySubtitle(reads, mpw);
    playSub->setTable(widget.tableWidget);
    widget.menubar->show();
}

MainWindow::~MainWindow() {
}

void MainWindow::setPlayer(player* p) {
    mpw = p; //set player object in this object 
}

void MainWindow::setSubReader(SubtitleRead* read) {
    reads = read;
}

Ui::MainWindow MainWindow::getGraphicView() {
    return widget; // return this object 
}

void MainWindow::setSubtitleSave(subtitleSave* s) {
    sub = s;
}

void MainWindow::paintEvent(QPaintEvent*) {

}

void MainWindow::addToQueue(int a0, int a1) {
    Q0.enqueue(a0); // add channel one data of media file
    Q1.enqueue(a1); // add channel TWO data of media file
}

void MainWindow::updateInterface() {
    // update interface 

    /* update player time infomation*/
    widget.graphicViewSlider->setValue(mpw->getPosition());
    int t = mpw->getTime() / 1000;
    int h, m, s;
    QString fh, fm, fs;

    h = t / 3600;
    m = (t / 60) % 60;
    s = t % 60;

    if (h < 10) {
        fh = "0" + QString::number(h);
    } else {
        fh = QString::number(h);
    }

    if (m < 10) {
        fm = "0" + QString::number(m);
    } else {
        fm = QString::number(m);
    }

    if (s < 10) {
        fs = "0" + QString::number(s);
    } else {
        fs = QString::number(s);
    }

    widget.cTimeLbl->setText(fh + ":" + fm + ":" + fs);

    t = mpw->getLength() / 1000;
    h = t / 3600;
    m = (t / 60) % 60;
    s = t % 60;

    if (h < 10) {
        fh = "0" + QString::number(h);
    } else {
        fh = QString::number(h);
    }

    if (m < 10) {
        fm = "0" + QString::number(m);
    } else {
        fm = QString::number(m);
    }

    if (s < 10) {
        fs = "0" + QString::number(s);
    } else {
        fs = QString::number(s);
    }
    widget.tTimeLbl->setText(fh + ":" + fm + ":" + fs);


    /* update cursor position and determine its location*/
    int a = QCursor::pos().x();
    int b = this->x();
    int c = widget.timeSlotBar->pos().x();

    int d = a - (b + c);
    int e = a - (b + c + widget.timeSlotBar->width());

    dataObject ob;
    ob.object = "time_slot_margin";

    int vi = QCursor::pos().y() - this->y() - widget.timeSlotBar->y();
    QString q = QString::number(vi);
    //    qDebug(q.toStdString().c_str());



    if (d <= 4 && d > 0) {//left
        ob.x = -1;
    } else if (e < 0 && e >= -4) {
        ob.x = 1;
    } else if (d < widget.timeSlotBar->width() && d > 0) {
        ob.object = "time_slot_in_range";
    } else {
        ob.object = "time_slot_margin_leave";
    }

    if (vi < 30 && vi > 265) {
        //        ob.object = "time_slot_leave";
        qDebug("out");
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

    playSub->start(mpw->getTime());
    //posi = posi + 44 * widget.PlotView1->xAxis->scaleLogBase();
    //    widget.PlotView1->xAxis->setRange(posi, widget.PlotView1->xAxis->range().size(), Qt::AlignLeft);
    //    widget.PlotView1->replot();
}

void MainWindow::update() {
    //    updateInterface();
    sta = true;

}

void MainWindow::on_horizontalScrollBar_sliderMoved(int position) {
    QString q = QString::number(widget.PlotView0->xAxis->range().size(), 0, 0);
    //    qDebug(q.toStdString().c_str());

    int n = (qLL.size()) / 100000;

    if (qAbs(widget.PlotView0->xAxis->range().center() - position) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        widget.PlotView0->xAxis->setRange((n + 1) * position, widget.PlotView0->xAxis->range().size(), Qt::AlignLeft);
        widget.PlotView0->replot();
    }
    if (qAbs(widget.PlotView1->xAxis->range().center() - position) > 0.01) // if user is dragging plot, we don't want to replot twice
    {
        widget.PlotView1->xAxis->setRange((n + 1) * position, widget.PlotView1->xAxis->range().size(), Qt::AlignLeft);
        widget.PlotView1->replot();
    }

}

void MainWindow::on_srt_clicked() {
    dataObject ob;
    ob.object = "srt_btn";
    Notify(ob); // 
}

void MainWindow::on_play_clicked() {
    //    playSub->setSublist(getCurrentSubData());
    dataObject ob;
    ob.object = "play_btn";
    Notify(ob); // inform play button has pressed
}

void MainWindow::on_pauseBtn_clicked() {
    dataObject ob;
    ob.object = "pause_btn";
    Notify(ob); // inform play button has pressed
}

void MainWindow::on_stop_clicked() {
    dataObject ob;
    ob.object = "stop_btn";
    Notify(ob);
    // inform play button has pressed
}

void MainWindow::on_mute_clicked() {
    dataObject ob;
    ob.object = "mute_btn";
    Notify(ob);
    // inform mute button has pressed
}

void MainWindow::on_volumeSlider_sliderMoved(int position) {
    //    Notify("on_volumeSlider_sliderMoved");
    dataObject ob;
    ob.object = "on_volumeSlider_sliderMoved";
    ob.val = position;
    Notify(ob);
    // inform volume slider has moved
}

void MainWindow::on_graphicViewSlider_sliderMoved(int position) {
    dataObject ob;
    ob.object = "on_graphicViewSlider_sliderMoved";
    ob.val = position;
    Notify(ob);
    // inform graphicViewSlider slider has moved
}

TGS* MainWindow::getTgs() {
    return t;
}

TGS* MainWindow::getTimeCursorTgs() {
    return tt;
}

void MainWindow::drawRuler() {
    /* draw the timeline*/
    //    int x = widget.timeLine->x();
    //    QGraphicsTextItem * io;
    //    for (int i = 0; i < 500; i += 10) {
    //        io = new QGraphicsTextItem();
    //        io->setPos(x + i, 10);
    //
    //        int len = i;
    //        std::ostringstream ostr; //output string stream
    //        ostr << len; //use the string stream just like cout,
    //        string length = ostr.str();
    //        io->setPlainText(QString(length.c_str()));
    //        //        timeLineScene->addItem(io);
    //        timeLineScene->addLine(QLineF(x + i, 0, x + i, 10), QPen(Qt::white));
    //    }
}

void MainWindow::on_add_row_after_clicked() {
    /* scale in time line and two graphs */
    //    widget.timeLine->scale(1.1, 1);
    //    widget.view0->scale(1.1, 1);
    //    widget.view1->scale(1.1, 1);
    addRow(false);
    //    addRow(false);
}

void MainWindow::on_add_row_before_clicked() {
    /* scale out time line and two graphs */
    //    widget.timeLine->scale(0.9, 1);
    //    widget.view0->scale(0.9, 1);
    //    widget.view1->scale(0.9, 1);
    addRow(true);
}

void MainWindow::on_remove_row_clicked() {
    removeRow();
}

void MainWindow::setSampleList(short int *s, int frame, int rate/*QQueue<int> L, QQueue<int> R*/) {
    //set the pcm data
    //    qLL = L;
    //    qRR = R;
    Samples = s;
    SampleLength = frame;
    sampleRate = rate;
}

void MainWindow::drawGraph() {
    // draw the two graphs
    scene0 = new QGraphicsScene();
    scene1 = new QGraphicsScene();
    scene2 = new QGraphicsScene();


    //    widget.view0->setScene(scene0);
    widget.view1->setScene(scene1);

    slot = new MyItem();

    QBrush brush(QColor::fromRgb(255, 0, 0, 100));
    QPen pen(QColor::fromRgb(0, 0, 255, 100));
    pen.setWidth(1);

    slot->setBrush(QBrush(QColor(200, 200, 255, 100)));
    slot->setPen(pen);
    slot->setRect(50, 60, 71, 241);
    slot->setTransformOriginPoint(0, 0);

    //    scene1->addItem(slot);


    widget.graphicsView->setScene(scene2);
    //    widget.timeLine->setScene(timeLineScene);

    QBrush br(QColor::fromRgb(0, 255, 0, 100));
    //    widget.view0->setBackgroundBrush(QBrush(Qt::green, Qt::SolidPattern));
    widget.view1->setBackgroundBrush(br);
    widget.graphicsView->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

    //    widget.view0->show();
    widget.view1->show();

    //    h0->setMaximum(50000);
    h1->setMaximum(50000);
    widget.horizontalScrollBar->setMaximum(50000);
    //    widget.horizontalScrollBar->setValue(widget.view0->horizontalScrollBar()->value());
}

void MainWindow::addToGraph() {
    //    int v = widget.horizontalScrollBar->value();
    int y0, y1;
    //    x = 255;
    int xx;
    QPen pen(Qt::blue);
    pen.setWidth(2);

    int preX0 = 0;
    int preY0 = 255;
    int preX1 = 0;
    int preY1 = 255;

    //add all pcm data to graph
    int s = 300000; //=0;
    int st = 305000; //=SampleLength;

    for (int i = s; i < st; i += 2) {
        xx = i;
        y0 = 255 + Samples[i] / 20;
        //        scene0->addLine(xx, x, xx, y0, pen);
        scene0->addLine(preX0, preY0, xx, y0, pen);
        preY0 = y0;
        preX0 = xx;

        y1 = 255 + Samples[i + 1] / 20;
        //        scene1->addLine(xx, x, xx, y1, pen);
        scene1->addLine(preX1, preY1, xx, y1, pen);
        preY1 = y1;
        preX1 = xx;
        cout << y1 << endl;
    }

}

void MainWindow::plotGraph() {
    widget.PlotView0->addGraph();
    widget.PlotView0->graph()->setPen(QPen(Qt::blue));
    widget.PlotView0->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    widget.PlotView0->graph()->setPen(QPen(Qt::red));

    widget.PlotView1->addGraph();
    widget.PlotView1->graph()->setPen(QPen(Qt::blue));
    widget.PlotView1->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    widget.PlotView1->graph()->setPen(QPen(Qt::red));

    //int size = qLL.size();
    int size = SampleLength / 50;
    QVector<double> x0(size), y0(size); // initialize with entries 0..100
    QVector<double> x1(size), y1(size); // initialize with entries 0..100

    for (int i = 0; i < size; i += 2) {
        x0[i] = i; // x goes from -1 to 1
        y0[i] = Samples[100000 + i] / 20; // let's plot a quadratic function

        //        x1[i] = i; // x goes from -1 to 1
        y1[i] = Samples[100000 + i + 1] / 20; // let's plot a quadratic function
        //        cout<<y0[i]<<endl;
    }

    //    for (int i = 0; i < size; i++) {
    //        x0[i] = i; // x goes from -1 to 1
    //        y0[i] = qLL.at(i); // let's plot a quadratic function
    ////        y0[i]=100;
    //    }

    widget.PlotView0->addGraph();
    widget.PlotView0->graph(0)->setData(x0, y0);

    widget.PlotView0->xAxis->setRange(0, 1000);
    widget.PlotView0->yAxis->setRange(-255, 255);
    //    widget.PlotView0->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    widget.PlotView0->replot();

    widget.PlotView1->addGraph();
    widget.PlotView1->graph(0)->setData(x0, y1);

    widget.PlotView1->xAxis->setRange(0, 1000);
    widget.PlotView1->yAxis->setRange(-255, 255);
    //        widget.PlotView1->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    widget.PlotView1->replot();
}

void MainWindow::setSubtitle(vector<srtFormat> vv) {
    subList = vv;
    //addToGraph(); // draw data on graph as thread function
    widget.tableWidget->setRowCount(0); // clear the exsisting subtitles

    long st;
    long et;
    long dt;

    int sH, fH;
    int sM, fM;
    int sS, fS;
    int sMs, fMs;

    //add subtitle component as appropriate
    //QMessageBox *msgBox = new QMessageBox(this); 
    QString lString("HelloWorld");
    QMessageBox msgBox(QMessageBox::Information, QString("HelloWorld"), (lString), QMessageBox::NoButton, this);
    
    for (int i = 0; i < (signed int) subList.size(); i++) {
        srtFormat srt = subList.at(i);
        widget.tableWidget->insertRow(i);
        QString s = QString::fromStdString(srt.text);

        st = (atoi(srt.startH.c_str())*3600 + atoi(srt.startM.c_str())*60 + atoi(srt.startS.c_str()))*1000 + atoi(srt.startMs.c_str());
        et = (atoi(srt.stopH.c_str())*3600 + atoi(srt.stopM.c_str())*60 + atoi(srt.stopS.c_str()))*1000 + atoi(srt.stopMs.c_str());

        //        QString sTime = QString::fromStdString(srt.startH + ":" + srt.startM + ":" + srt.startS + "," + srt.startMs);
        //        QString eTime = QString::fromStdString(srt.stopH + ":" + srt.stopM + ":" + srt.stopS + "," + srt.stopMs);
        dt = et - st;

        sH = QString::fromStdString(srt.startH).toInt();
        sM = QString::fromStdString(srt.startM).toInt();
        sS = QString::fromStdString(srt.startS).toInt();
        sMs = QString::fromStdString(srt.startMs).toInt();

        fH = QString::fromStdString(srt.stopH).toInt();
        fM = QString::fromStdString(srt.stopM).toInt();
        fS = QString::fromStdString(srt.stopS).toInt();
        fMs = QString::fromStdString(srt.stopMs).toInt();

        QTimeEdit *st = new QTimeEdit(widget.tableWidget);
        st->setDisplayFormat("HH:mm:ss.zzz");
        st->setTime(QTime(sH, sM, sS, sMs));

        QTimeEdit *ft = new QTimeEdit(widget.tableWidget);
        ft->setDisplayFormat("HH:mm:ss.zzz");
        ft->setTime(QTime(fH, fM, fS, fMs));

        QTextEdit *edit = new QTextEdit(widget.tableWidget);
        edit->setText(s.trimmed().simplified());

        QSpinBox *spin = new QSpinBox(widget.tableWidget);
        spin->setRange(0, 100000);
        spin->setValue(dt);

        QObject::connect(st, SIGNAL(timeChanged(QTime)), this, SLOT(timesChanged(QTime)));
        QObject::connect(ft, SIGNAL(timeChanged(QTime)), this, SLOT(timesChanged(QTime)));

        widget.tableWidget->setCellWidget(i, 0, st);
        widget.tableWidget->setCellWidget(i, 1, ft);
        widget.tableWidget->setCellWidget(i, 2, spin);
        widget.tableWidget->setCellWidget(i, 3, edit);

        cout << (i * 100) / subList.size() << " %\r";
        cout.flush();
        
//        msgBox.setText(QString::number((i * 100) / subList.size())); 
//        widget.textEdit->setText(QString::number((i * 100) / subList.size()));
//        msgBox->setText("rukshan");
//        msgBox.show();        
    }
}

void MainWindow::timesChanged(QTime t) {
    //when time edit event occur
    QWidget *wid = QApplication::focusWidget();
    QTimeEdit *cell = qobject_cast<QTimeEdit*>(wid);

    QTimeEdit *st;
    QTimeEdit *et;
    QSpinBox *du;
    int start, end;
    if (wid) {
        QModelIndex index = widget.tableWidget->indexAt(cell->pos());
        //        cout << index.row() << " " << index.column() << endl;
        if (index.column() == 0) {
            st = cell;
            et = qobject_cast<QTimeEdit*>(widget.tableWidget->cellWidget(index.row(), 1));
        } else {
            et = cell;
            st = qobject_cast<QTimeEdit*>(widget.tableWidget->cellWidget(index.row(), 0));
        }
        QTime tt;
        tt = st->time();
        start = tt.msec() + 1000 * (tt.second() + tt.minute()*60 + tt.hour()*3600);
        tt = et->time();
        end = tt.msec() + 1000 * (tt.second() + tt.minute()*60 + tt.hour()*3600);

        if (start > end) {
            if (index.column() == 0) {
                st->setTime(et->time());
            } else {
                et->setTime(st->time());
            }
        }

        du = qobject_cast<QSpinBox*>(widget.tableWidget->cellWidget(index.row(), 2));
        du->setValue(end - start);

    }



}

void MainWindow::dragEnterEvent(QDragEnterEvent* e) {
    if (e->mimeData()->hasFormat("text/uri-list"))//set the drag enter event
        e->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent* e) {
    QList<QUrl> urls = e->mimeData()->urls();
    QString fileName = urls.first().toLocalFile(); // convert the drop file into file

    string s = strchr(fileName.toStdString().c_str(), '.');
    widget.textEdit->setText(QString::fromStdString(s));
    if (s == ".srt") {//if drop item is srt read and set
        reads->open(fileName.toStdString());
        setSubtitle(reads->getSubList());
    } else if (strcasecmp(s.c_str(), ".mp4") == 0) {//else it is mp4 open in player
        //        mpw->open(fileName.toStdString());
        dataObject ob;
        ob.val =0;
        ob.object = "file_selector_open";
//        ob.val = 1;
        ob.msg = fileName.toStdString();
        Notify(ob);
    }
    //    qDebug(fileName.toStdString().c_str());
}

void MainWindow::setPlayBtnText(string msg) {
    widget.play->setText(QString::fromStdString(msg)); // change play btn text
}

void MainWindow::setVolumeLevel(int val) {
    widget.volumeSlider->setValue(val); // set the volume level
}

int MainWindow::getVolumeLevel() {
    return widget.volumeSlider->value(); //get the volume level
}

void MainWindow::run() {

}

vector<srtFormat> MainWindow::getCurrentSubData() {
    vector<srtFormat> res; // create vector
    srtFormat f;
    for (int i = 0; i < widget.tableWidget->rowCount(); i++) { //get data from table and add into vector

        QTimeEdit *st = qobject_cast<QTimeEdit*>(widget.tableWidget->cellWidget(i, 0));
        QTimeEdit *ft = qobject_cast<QTimeEdit*>(widget.tableWidget->cellWidget(i, 1));
        QTextEdit *tex = qobject_cast<QTextEdit*>(widget.tableWidget->cellWidget(i, 3));

        f.id = i;
        //        f.start = widget.tableWidget->item(i, 0)->text().toStdString();
        //        f.start=st->time().hour()+":"+st->time().minute()+":"+st->time().second()+
        //        f.stop = widget.tableWidget->item(i, 1)->text().toStdString();
        //        f.text = widget.tableWidget->item(i, 3)->text().toStdString();

        if (st->time().hour() < 10)
            f.startH = "0" + QString::number(st->time().hour(), 10).toStdString();
        else
            f.startH = QString::number(st->time().hour(), 10).toStdString();

        if (st->time().minute() < 10)
            f.startM = "0" + QString::number(st->time().minute(), 10).toStdString();
        else
            f.startM = QString::number(st->time().minute(), 10).toStdString();

        if (st->time().second() < 10)
            f.startS = "0" + QString::number(st->time().second(), 10).toStdString();
        else
            f.startS = QString::number(st->time().second(), 10).toStdString();

        if (st->time().msec() < 10)
            f.startMs = "00" + QString::number(st->time().msec(), 10).toStdString();
        else if (st->time().msec() < 100)
            f.startMs = "0" + QString::number(st->time().msec(), 10).toStdString();
        else
            f.startMs = QString::number(st->time().msec(), 10).toStdString();


        if (ft->time().hour() < 10)
            f.stopH = "0" + QString::number(ft->time().hour(), 10).toStdString();
        else
            f.stopH = QString::number(ft->time().hour(), 10).toStdString();

        if (ft->time().minute() < 10)
            f.stopM = "0" + QString::number(ft->time().minute(), 10).toStdString();
        else
            f.stopM = QString::number(ft->time().minute(), 10).toStdString();

        if (ft->time().second() < 10)
            f.stopS = "0" + QString::number(ft->time().second(), 10).toStdString();
        else
            f.stopS = QString::number(ft->time().second(), 10).toStdString();

        if (ft->time().msec() < 10)
            f.stopMs = "00" + QString::number(ft->time().msec(), 10).toStdString();
        else if (ft->time().msec() < 100)
            f.stopMs = "0" + QString::number(ft->time().msec(), 10).toStdString();
        else
            f.stopMs = QString::number(ft->time().msec(), 10).toStdString();

        f.text = tex->toPlainText().toStdString();
        res.push_back(f);
    }
    return res;
}

MyItem* MainWindow::getMyItem() {
    return slot;
}

void MainWindow::changeTime(int n) {
    int i = widget.tableWidget->currentRow();
    string time = widget.tableWidget->item(i, 0)->text().toStdString();
    int h = atoi(time.substr(0, 2).c_str());
    int m = atoi(time.substr(3, 2).c_str());
    int s = atoi(time.substr(6, 2).c_str());
    int ms = atoi(time.substr(9, 3).c_str());
    int tt = ms + (s + m * 60 + h * 3600)*1000;
    tt += n;

    int t1 = tt / 1000;
    int MS = tt % 1000;
    int S = t1 % 60;
    int M = t1 / 60;
    int H = t1 / 3600;

    QString st = QString::number(H, 10) + ":" + QString::number(M, 10) + ":" + QString::number(S, 10) + "," + QString::number(MS, 10);

    widget.tableWidget->setItem(i, 0, new QTableWidgetItem(st));
}

void MainWindow::on_subTimeStartCmd_clicked() {
    qDebug("start");

    int n = widget.tableWidget->currentRow();
    if (n < 0) {
        return;
    }
    //    widget.textEdit->setText(QString::number(mpw->getTime()));
    int t = mpw->getTime();
    int ms = t % 1000;
    t = t / 1000;
    int h = t / 3600;
    int m = (t / 60) % 60;
    int s = t % 60;


    QTimeEdit *q = qobject_cast<QTimeEdit *>(widget.tableWidget->cellWidget(n, 0));
    q->setTime(QTime(h, m, s, ms));
}

void MainWindow::on_subTimeStopCmd_clicked() {
    qDebug("stop");
    int n = widget.tableWidget->currentRow();
    if (n < 0) {
        return;
    }
    int t = mpw->getTime();
    int ms = t % 1000;
    t = t / 1000;
    int h = t / 3600;
    int m = (t / 60) % 60;
    int s = t % 60;


    QTimeEdit *q = qobject_cast<QTimeEdit *>(widget.tableWidget->cellWidget(n, 1));
    q->setTime(QTime(h, m, s, ms));
}

void MainWindow::addRow(bool isUp) {

    int n = widget.tableWidget->currentRow();
    //    qDebug(QString::number(n).toStdString().c_str());

    if (isUp) {
        //        n;
    } else {
        n++;
    }

    if (n < 0) {
        n = 0;
    }
    widget.tableWidget->insertRow(n);

    QTimeEdit *st = new QTimeEdit(widget.tableWidget);
    st->setDisplayFormat("HH:mm:ss.zzz");

    QTimeEdit *ft = new QTimeEdit(widget.tableWidget);
    ft->setDisplayFormat("HH:mm:ss.zzz");

    QTextEdit *edit = new QTextEdit(widget.tableWidget);

    QSpinBox *spin = new QSpinBox(widget.tableWidget);
    spin->setRange(0, 100000);

    QObject::connect(st, SIGNAL(timeChanged(QTime)), this, SLOT(timesChanged(QTime)));
    QObject::connect(ft, SIGNAL(timeChanged(QTime)), this, SLOT(timesChanged(QTime)));

    //    widget.tableWidget->model()

    widget.tableWidget->setCellWidget(n, 0, st);
    widget.tableWidget->setCellWidget(n, 1, ft);
    widget.tableWidget->setCellWidget(n, 2, spin);
    widget.tableWidget->setCellWidget(n, 3, edit);

    //    widget.tableWidget->row(st);
}

void MainWindow::removeRow() {
    int n = widget.tableWidget->currentRow();
    widget.tableWidget->removeRow(n);
}

void MainWindow::increaseSubTime(int i) {
    int n = widget.tableWidget->currentRow();
    if (n < 0) {
        return;
    }

    //    QTimeEdit *q = qobject_cast<QTimeEdit *>(widget.tableWidget->cellWidget(n, 0));
    //    QTime t=q->time().addMSecs();

    //    q->setTime(t);
}

void MainWindow::decreaseSubTime(int i) {
}

void MainWindow::ffmpegGraphPlot(QQueue<int> LL, QQueue<int> RR) {
    qLL = LL;
    qRR = RR;

    widget.PlotView0->addGraph();
    widget.PlotView0->graph()->setPen(QPen(Qt::blue));
    widget.PlotView0->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    widget.PlotView0->graph()->setPen(QPen(Qt::red));

    widget.PlotView1->addGraph();
    widget.PlotView1->graph()->setPen(QPen(Qt::blue));
    widget.PlotView1->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    widget.PlotView1->graph()->setPen(QPen(Qt::red));

    //int size = qLL.size();
    int size = LL.size() / 5;
    QVector<double> x0(size), y0(size); // initialize with entries 0..100
    QVector<double> x1(size), y1(size); // initialize with entries 0..100

    for (int i = 0; i < size; i += 1) {
        x0[i] = i; // x goes from -1 to 1
        y0[i] = LL.at(i); // let's plot a quadratic function
        //        y1[i] = LL.at(i+1); // let's plot a quadratic function
        //        y0[i] = rand()*1000;
        //        cout<<LL.at(i)<<endl;
        //        y1[i] = Samples[100000 + i + 1] / 20; // let's plot a quadratic function
    }

    widget.PlotView0->addGraph();
    widget.PlotView0->graph(0)->setData(x0, y0);

    widget.PlotView0->xAxis->setRange(0, 1000);
    widget.PlotView0->yAxis->setRange(-255, 255);
    widget.PlotView0->replot();

    widget.PlotView1->addGraph();
    widget.PlotView1->graph(0)->setData(x0, y1);

    widget.PlotView1->xAxis->setRange(0, 1000);
    widget.PlotView1->yAxis->setRange(-255, 255);
    widget.PlotView1->replot();

    cout << size << endl;
}

void MainWindow::selectRow(int i) {
    //    widget.tableWidget.
    if (i >= 0) {
        widget.tableWidget->selectRow(i);
        QTextEdit *st = qobject_cast<QTextEdit*>(widget.tableWidget->cellWidget(i, 3));
        widget.textEdit->setText(st->toPlainText());
    } else {
        QTextEdit *st = qobject_cast<QTextEdit*>(widget.tableWidget->cellWidget(i, 3));
        widget.textEdit->setText("");
    }
}

PlaySubtitle* MainWindow::getPLaySubtitle() {
    return playSub;
}

void MainWindow::on_actionSave_As_2_triggered() {
    dataObject ob;
    ob.object = "srt_btn";
    Notify(ob);
}

void MainWindow::on_actionSubtitle_file_triggered() {
    dataObject ob;
    ob.object = "player";
    ob.msg = "media_explorer_sub";
    Notify(ob);
}

void MainWindow::on_actionMedia_file_triggered() {
    dataObject ob;
    ob.object = "player";
    ob.msg = "media_explorer_media";
    Notify(ob);
}

void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn) {
    if (currentRow >= 0) {
        widget.tableWidget->selectRow(currentRow);
        QTextEdit *st = qobject_cast<QTextEdit*>(widget.tableWidget->cellWidget(currentRow, 3));
        widget.textEdit->setText(st->toPlainText());
    } else {
    }
}

void MainWindow::on_textEdit_textChanged() {
    int currentRow = widget.tableWidget->currentRow();
    if (currentRow >= 0) {
        QTextEdit *st = qobject_cast<QTextEdit*>(widget.tableWidget->cellWidget(currentRow, 3));
        //        st->setText(widget.textEdit->toPlainText());
    }
}

void MainWindow::on_clearTable_clicked() {
    widget.tableWidget->setRowCount(0);
}

void MainWindow::setTable() {

}