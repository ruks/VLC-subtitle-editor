/* 
 * File:   player.cpp
 * Author: rukshan
 * 
 * Created on August 31, 2013, 9:01 AM
 */

#include "player.h"
#include "srtFormat.h"
#include <stdio.h>
#include <stdlib.h>
#include <vlc/vlc.h>

libvlc_instance_t *inst;
libvlc_media_player_t *mp;
libvlc_media_t *m;

player::player() {
    inst = libvlc_new(0, NULL); //constructor
}

player::player(const player& orig) {
}

player::~player() {
}

void player::play() {
    if (!mp) { //if player is not load with media
        dataObject ob;
        ob.object = "player";
        ob.msg = "media_explorer";
        Notify(ob);
        return;
    }

    if (libvlc_media_player_is_playing(mp)) { //if current playing
        /* Pause */
        libvlc_media_player_pause(mp);
        dataObject ob;
        ob.object = "player";
        ob.msg = "play";
        Notify(ob);
    } else { //if not playing
        /* Play again */
        dataObject ob;
        ob.object = "player";
        ob.msg = "pause";
        Notify(ob);
        libvlc_media_player_play(mp);
    }
}

void player::stop() {
    if (mp) { // if player id initialize 
        // stop playing
        libvlc_media_player_stop(mp); //stop the player

        // free the media_player
        libvlc_media_player_release(mp);

        libvlc_release(inst);
        mp = NULL;
    }
}

int player::getTime() {
    if (mp) { // if player is initialise return the time
        return libvlc_media_player_get_time(mp);
    } else {
        return 0;
    }
}

int player::getLength() {
    if (mp) {// if player is initialise return the media time length
        return libvlc_media_player_get_length(mp);
    } else {
        return 0;
    }
}

int player::getPer() {

}

bool player::isPLay() {
    if (mp == NULL) { // if player is nnit initialise return false
        return false;
    } else { // if player is initialise return the whether is somethings playing
        return libvlc_media_player_is_playing(mp);
    }
}

void player::pause() {
    //    libvlc_media_player_set_pause(mp,pause());
    //  pause();
    if (libvlc_media_player_can_pause(mp)) {// if player is initialize pause player
        libvlc_media_player_pause(mp);
    } else {
        exit(EXIT_FAILURE);
    }
}

int player::getPosition() {
    if (mp) {
        float pos = libvlc_media_player_get_position(mp); // if player is initialize return position
        return (int) (pos * 1000.0);
    } else {
        return 0;
    }
}

void player::changePosition(int pos) { /* Called on position slider change */

    if (mp) // if player is initialize set position of the media
        libvlc_media_player_set_position(mp, (float) pos / 1000.0);
}

void player::changeVolume(int val) {
    if (mp) // if player is initialize change volume
        libvlc_audio_set_volume(mp, val);
}

void player::mute(int val) {
    if (mp) {
        dataObject ob;
        ob.object = "player";
        ob.msg = "mute";
        if (val == 0) { //if already muted...
            this->changeVolume(80);
            ob.val = 80;
        } else { //else mute volume
            this->changeVolume(0);
            ob.val = 0;
        }
        Notify(ob); //notify the command
    }
}

int player::setStartTime() {
    if (!mp)
        return libvlc_media_player_get_time(mp); //return the start time
    else
        return 0;
}

libvlc_media_player_t* player::getMP() {
    return mp; //return the libvlc media player
}

libvlc_media_player_t * player::open(string path) {
        stop();
    
    m = libvlc_media_new_path(inst, path.c_str());
    if (!m) {
        //        exit(EXIT_FAILURE);
        return NULL;
    }
    // create a media play playing environment
    mp = libvlc_media_player_new_from_media(m);

    // no need to keep the media now
    libvlc_media_release(m);

    return mp;
}