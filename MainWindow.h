/* 
 * File:   MainWindow.h
 * Author: rukshan
 *
 * Created on August 29, 2013, 1:08 PM
 */

#ifndef _MAINWINDOW_H
#define	_MAINWINDOW_H

#include "ui_MainWindow.h"
#include "subtitleSave.h"
#include "Observable.h"
#include "player.h"
#include "header/tgs.h"

class MainWindow : public QMainWindow,public Observable {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
private:
    Ui::MainWindow widget;
    void paintEvent(QPaintEvent*);      
      
private slots:
    void updateInterface();
    void on_horizontalScrollBar_sliderMoved(int position);
    void on_srt_clicked();
    void on_play_clicked(); 
    void on_mute_clicked(); 
    void on_stop_clicked(); 
    void on_volumeSlider_sliderMoved(int position);
    void on_graphicViewSlider_sliderMoved(int position);
    void on_timeCurser_sliderPressed();
    
public:
    void addToQueue(int a,int b);
    void update();
    void setSubtitleSave(subtitleSave *s);
    Ui::MainWindow getGraphicView();
    void setPlayer(player *p);
    TGS* getTgs();
    TGS* getTimeCursorTgs();
};

#endif	/* _MAINWINDOW_H */
