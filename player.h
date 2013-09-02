/* 
 * File:   player.h
 * Author: rukshan
 *
 * Created on August 31, 2013, 9:01 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

#include <QObject>
#include <QPushButton>
#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include <vlc/vlc.h>

class player {
public:
    player();
    player(const player& orig);
    virtual ~player();
    //private:

public:
    void play(QPushButton *bu);
    void pause();
    void stop();
    int getTime();
    int getLength();
    int getPer();
    bool isPLay();
    void load(QWidget *dis);
    int getPosition();
    void changePosition(int pos);
    void changeVolume(int val);
    void mute(QSlider *sli);
    int setStartTime(QLabel *startTimeLabel);
    libvlc_media_player_t *getMP();

};

#endif	/* PLAYER_H */

