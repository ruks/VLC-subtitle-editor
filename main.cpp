/*
 * File:   main.cpp
 * Author: rukshan
 *
 * Created on August 29, 2013, 9:14 AM
 */

#include <QtGui/QApplication>
#include "smem.h"
#include <QTimer>
#include <qt4/QtCore/qdebug.h>
#include "MainWindow.h"
#include "printbits.h"
#include "subtitleSave.h"
#include "player.h"
#include "subtitleEditor.h"
#include "header/SubtitleRead.h"
#include <iostream>
#include <stdlib.h>
#include "FileSelector.h"
#include <string>
#include <qt4/QtCore/qvariant.h>
#include <stdio.h>
#include <qt4/QtCore/qstring.h>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    subtitleEditor *edit = new subtitleEditor();
    
//    player *p = new player();
//    if (p->open("/home/rukshan/song.mp3")) {
//        p->play();
//        p->changeVolume(50);
//    }else{
//        cout<<"error"<<endl;
//    }
    return app.exec();
}
