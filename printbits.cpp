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
    Options options;
    options.define("b|bits=i:0", "number of bits to display for each sample");
    options.define("n|samples=i:-1", "number of samples to display");
    options.define("s|start=i:0", "starting samples to display");
    options.define("S|no-space=b", "don't put spaces into data");
    //options.process(argc, argv);
    if (options.getArgCount() == 0) {
        cout << "Usage: " << options.getCommand()
                << " filename"
                << endl;
        exit(1);
    }
    spaceQ = !options.getBoolean("no-space");
    int bitdisplay = options.getInteger("bits");
    int start = options.getInteger("start");
    int sampledisplay = options.getInteger("samples");
    //    SoundFileRead soundfile(options.getArg(1));
    SoundFileRead soundfile("/home/rukshan/audio.wav");

    if (bitdisplay <= 0) {
        bitdisplay = soundfile.getBitsPerSample();
    }
    if (bitdisplay > 24) {
        cout << "Error: cannot handle bit sizes greater than 24 bits." << endl;
        exit(1);
    }
    int i, channel;

    cout << "; Sample count = " << soundfile.getSamples() << "\n";
    cout << "; Channels     = " << soundfile.getChannels() << "\n";
    cout << "; Native Bits  = " << soundfile.getBitsPerSample() << "\n";
    if (start < 0) {
        start = 0;
    } else if (start >= soundfile.getSamples()) {
        start = 0;
    }
    soundfile.gotoSample(start);
    if (sampledisplay <= 0) {
        sampledisplay = soundfile.getSamples();
    }
    sampledisplay = sampledisplay - start;

    //    int v;

    for (i = start; i < start + sampledisplay; i++) {
        //cout << i << ":\t";
        //        for (channel = 0; channel < soundfile.getChannels(); channel++) {
        //            //printBinary(soundfile.getCurrentSample24Bit(channel), bitdisplay);
        //            //cout<<soundfile.getCurrentSample24Bit(channel);
        //            //cout << "\t";
        //            v = soundfile.getCurrentSample24Bit(channel);
        //
        //            if (channel == 0) {
        //                win->addToQueue(v / 1000);
        //                //cout<<v/1000;
        //            }
        //        }
        //        cout<<endl;
        //        cout << "\n";
        int v0, v1;
        v0 = soundfile.getCurrentSample24Bit(0);
        v1 = soundfile.getCurrentSample24Bit(1);
        win->addToQueue(v0 / 1200, v1 / 1200);
        soundfile.incrementSample();
    }
    cout << "finish" << endl;
    win->update();
}

void printbits::setMainWindow(MainWindow* m) {
    win = m;
}

void printbits::run() {
    SNDFILE *SoundFile;
    SF_INFO SoundFileInfo;
    short int *Samples;


    SoundFile = sf_open("/home/rukshan/audio.wav", SFM_READ, &SoundFileInfo);
    //open a file and put it's info into a struct "SoundFileInfo"

    Samples = new short int[SoundFileInfo.channels * SoundFileInfo.frames];
    //allocate an array to hold the samples

    sf_readf_short(SoundFile, Samples, SoundFileInfo.frames);
    //fill the array with sample values, a frame equals on sample per channel 
    int frames = SoundFileInfo.frames;
    //    cout << frames << endl;
    for (int i = 100000; i < frames; i++) {
//        cout << Samples[i] << endl;
//        cout << Samples[i]*10000 << " " << Samples[i + 1]*10000 << endl;
    }
    //    cout << "finish" << endl;
    //    win->update();
    //    cout<<SoundFileInfo.frames<<endl;
    win->setSampleList(Samples, SoundFileInfo.frames);
}