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
#include <vector>
#include <srtFormat.h>
#include <QDragEnterEvent>
#include <QDropEvent>

class MainWindow : public QMainWindow,public Observable {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
private:
    Ui::MainWindow widget;
    void paintEvent(QPaintEvent*);      
    void drawRuler();
    void drawGraph();
    void addToGraph();
    
private slots:
    void updateInterface();
    void on_horizontalScrollBar_sliderMoved(int position);
    void on_srt_clicked();
    void on_play_clicked(); 
    void on_mute_clicked(); 
    void on_stop_clicked(); 
    void on_volumeSlider_sliderMoved(int position);
    void on_graphicViewSlider_sliderMoved(int position);
//    void on_timeCurser_sliderPressed();
    void on_scale_in_but_clicked();
    void on_scale_out_but_clicked();
    
    
public:
    void addToQueue(int a,int b);
    void update();
    void setSubtitleSave(subtitleSave *s);
    Ui::MainWindow getGraphicView();
    void setPlayer(player *p);
    TGS* getTgs();
    TGS* getTimeCursorTgs();
    void setSampleList(short int *sam,int len);
    void setSubtitle(vector<srtFormat> v);
    void setPlayBtnText(string msg);
    int getVolumeLevel();
    void setVolumeLevel(int val);
    
    protected:
        void dragEnterEvent(QDragEnterEvent *e);
        void dropEvent(QDropEvent *e);
    
};

#endif	/* _MAINWINDOW_H */
