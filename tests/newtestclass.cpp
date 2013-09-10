/*
 * File:   newtestclass.cpp
 * Author: rukshan
 *
 * Created on Sep 9, 2013, 6:52:14 PM
 */

#include "newtestclass.h"
#include "player.h"
#include "player.cpp"
#include "QtGui"

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testChangePosition() {
    int pos;
    player _player;
    _player.changePosition(pos);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testChangeVolume() {
    int val;
    player _player;
    _player.changeVolume(val);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetLength() {
    player _player;
    int result = _player.getLength();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetMP() {
    player _player;
    libvlc_media_player_t* result = _player.getMP();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetPer() {
    player _player;
    int result = _player.getPer();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetPosition() {
    player _player;
    int result = _player.getPosition();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testGetTime() {
    player _player;
    int result = _player.getTime();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testIsPLay() {
    player _player;
    bool result = _player.isPLay();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testLoad() {
    player _player;
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testMute() {
    player _player;
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testOpen() {
    string path;
    player _player;
    _player.open(path);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testPause() {
    player _player;
    _player.pause();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testPlay() {
    player _player;
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testPlayer() {
    player _player();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testPlayer2() {
//    const player& orig;
//    player _player(orig);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testSetStartTime() {
    player _player;
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

void newtestclass::testStop() {
    player _player;
    _player.stop();
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

