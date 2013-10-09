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
#include <QThread>
#include "qcustomplot.h"
#include "header/MyItem.h"
#include "header/SubtitleRead.h"
#include "header/PlaySubtitle.h"
#include <QQueue>

class MainWindow : public QMainWindow, public Observable {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();
private:
    Ui::MainWindow widget;
    void paintEvent(QPaintEvent*);
    void drawRuler();
    void drawGraph();
    //    void addToGraph();

private slots:
    void updateInterface();
    void on_horizontalScrollBar_sliderMoved(int position);
    void on_srt_clicked();
    void on_play_clicked();
    void on_pauseBtn_clicked();
    void on_mute_clicked();
    void on_stop_clicked();
    void on_volumeSlider_sliderMoved(int position);
    void on_graphicViewSlider_sliderMoved(int position);
    void on_subTimeStartCmd_clicked();
    void on_subTimeStopCmd_clicked();
    void on_add_row_after_clicked();
    void on_add_row_before_clicked();
    void on_remove_row_clicked();
    
    void on_actionSrt_triggered();
    void on_actionSubtitle_file_triggered();
    void on_actionMedia_file_triggered();   
    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);
    
    void on_textEdit_textChanged();
public:
    void addToQueue(int a, int b);
    void update();
    void setSubtitleSave(subtitleSave *s);
    Ui::MainWindow getGraphicView();
    void setPlayer(player *p);
    TGS* getTgs();
    TGS* getTimeCursorTgs();
    void setSampleList(short int *s, int frame, int rate/*QQueue<int> L, QQueue<int> R*/);
    void setSubtitle(vector<srtFormat> v);
    void setPlayBtnText(string msg);
    int getVolumeLevel();
    void setVolumeLevel(int val);
    void addToGraph();
    void plotGraph();
    vector<srtFormat> getCurrentSubData();
    MyItem* getMyItem();
    void changeTime(int n);
    void addRow(bool isUp);
    void removeRow();
    void ffmpegGraphPlot(QQueue<int> LL, QQueue<int> RR);
    void increaseSubTime(int i);
    void decreaseSubTime(int i);
    void setSubReader(SubtitleRead *read);
    void selectRow(int i);
    PlaySubtitle* getPLaySubtitle();
    
protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
    void run();

};

#endif	/* _MAINWINDOW_H */
