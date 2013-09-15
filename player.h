/* 
 * File:   player.h
 * Author: rukshan
 *
 * Created on August 31, 2013, 9:01 AM
 */

#ifndef PLAYER_H
#define	PLAYER_H

//#include <QObject>
#include <vlc/vlc.h>
#include <iostream>
#include "Observable.h"

using namespace std;

class player : public Observable {
public:
    player();
    player(const player& orig);
    virtual ~player();
    //private:

public:
    void play();
    void pause();
    void stop();
    int getTime();
    int getLength();
    int getPer();
    bool isPLay();
    int getPosition();
    void changePosition(int pos);
    void changeVolume(int val);
    void mute(int val);
    int setStartTime();
    libvlc_media_player_t *getMP();
    libvlc_media_player_t *open(string path);
};

#endif	/* PLAYER_H */

