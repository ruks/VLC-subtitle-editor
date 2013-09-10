/*
 * File:   main.cpp
 * Author: rukshan
 *
 * Created on August 29, 2013, 9:14 AM
 */

#include <QtGui/QApplication>
#include "smem.h"
#include <QTimer>
#include "MainWindow.h"
#include "printbits.h"
#include "subtitleSave.h"
#include "player.h"
#include "subtitleEditor.h"
#include "header/SubtitleRead.h"
#include "iostream"
#include "FileSelector.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    subtitleEditor *edit = new subtitleEditor();
//    FileSelector s;
//    s.openFile();
    //    SubtitleRead *r=new SubtitleRead();
    //    r->open("/home/rukshan/movie.srt");
//    string s="ruk";
//    string c="RUK";
//    cout<<strcasecmp(s.c_str(),c.c_str())<<endl;
    return app.exec();
}
