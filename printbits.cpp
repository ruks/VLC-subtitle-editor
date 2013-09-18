/* 
 * File:   printbits.cpp
 * Author: rukshan
 * 
 * Created on August 29, 2013, 7:05 PM
 */

#include "printbits.h"
#include "soundfile.h"
#include <stdlib.h>
#include <QThread>
#include "MainWindow.h"
#include "srtFormat.h"
#include <algorithm>
#include "sndfile.h"

#ifndef OLDCPP
#include <iostream>
using namespace std;
#else
#include <iostream.h>
#endif

int spaceQ = 1;
MainWindow* win;
typedef struct header_file* header_p;

printbits::printbits() {
    stat = true;
}

printbits::printbits(const printbits& orig) {
}

printbits::~printbits() {
}

void printbits::runs() {
}

void printbits::setMainWindow(MainWindow* m) {
    win = m;
}

void printbits::run() {
    SNDFILE *SoundFile;
    SF_INFO SoundFileInfo;
    short int *Samples;
    //    SoundFile = sf_open("chimes.wav", SFM_READ, &SoundFileInfo);
    SoundFile = sf_open("audio.wav", SFM_READ, &SoundFileInfo);
    Samples = new short int[SoundFileInfo.channels * SoundFileInfo.frames];
    sf_readf_short(SoundFile, Samples, SoundFileInfo.frames);
    int frames = SoundFileInfo.frames;
    win->setSampleList(Samples, SoundFileInfo.frames);
}