/* 
 * File:   player.cpp
 * Author: rukshan
 * 
 * Created on August 31, 2013, 9:01 AM
 */

#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>

libvlc_instance_t *inst;
libvlc_media_player_t *mp;
libvlc_media_t *m;

player::player() {
    inst = libvlc_new(0, NULL);
}

player::player(const player& orig) {
}

player::~player() {
}

void player::play(QPushButton *bu) {
    if (!mp)
        return;

    if (libvlc_media_player_is_playing(mp)) {
        /* Pause */
        libvlc_media_player_pause(mp);
        bu->setText("Play");
    } else {
        /* Play again */
        libvlc_media_player_play(mp);
        bu->setText("Pause");
    }
}

void player::stop() {
    if (mp) {
        // stop playing
        libvlc_media_player_stop(mp);

        // free the media_player
        libvlc_media_player_release(mp);

        libvlc_release(inst);
        mp = NULL;
    }
}

void player::load(QWidget *dis) {
    // create a new item
    //    m = libvlc_media_new_path(inst, "/home/rukshan/song.mp3");
    //        m = libvlc_media_new_path(inst, "/home/rukshan/video.mp4");
    m = libvlc_media_new_path(inst, "/home/rukshan/movie.mp4");
    if (!m)
        exit(EXIT_FAILURE);
    // create a media play playing environment
    mp = libvlc_media_player_new_from_media(m);

    // no need to keep the media now
    libvlc_media_release(m);
    // play the media_player

#if defined(Q_OS_MAC)
    libvlc_media_player_set_nsobject(mp, (void *) dis->winId());
#elif defined(Q_OS_UNIX)
    libvlc_media_player_set_xwindow(mp, dis->winId());
#elif defined(Q_OS_WIN)
    libvlc_media_player_set_hwnd(mp, dis->winId());
#endif
}

int player::getTime() {
    return libvlc_media_player_get_time(mp);
}

int player::getLength() {
    return libvlc_media_player_get_length(mp);
}

int player::getPer() {

}

bool player::isPLay() {
    if (mp == NULL) {
        return false;
    } else {
        return libvlc_media_player_is_playing(mp);
    }
}

void player::pause() {
    //    libvlc_media_player_set_pause(mp,pause());
    //  pause();
    if (libvlc_media_player_can_pause(mp)) {
        libvlc_media_player_pause(mp);
    } else {
        exit(EXIT_FAILURE);
    }
}

int player::getPosition() {
    if(mp){
    float pos = libvlc_media_player_get_position(mp);
    return (int) (pos * 1000.0);
    }else{
        return 0;
    }
}

void player::changePosition(int pos) { /* Called on position slider change */

    if (mp)
        libvlc_media_player_set_position(mp, (float) pos / 1000.0);
}

void player::changeVolume(int val) {
    if (mp)
        libvlc_audio_set_volume(mp, val);
}

void player::mute(QSlider *sli) {
    if (mp) {
        if (sli->value() == 0) { //if already muted...

            this->changeVolume(80);
            sli->setValue(80);

        } else { //else mute volume

            this->changeVolume(0);
            sli->setValue(0);

        }
    }
}

int player::setStartTime(QLabel *startTimeLabel) {
    if (!mp)
        return libvlc_media_player_get_time(mp);
    else
        return 0;
}

libvlc_media_player_t* player::getMP() {
    return mp;
}

