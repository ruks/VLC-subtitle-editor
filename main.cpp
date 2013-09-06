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

using namespace std;

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    QApplication app(argc, argv);

    subtitleEditor *edit = new subtitleEditor();
//    SubtitleRead *r=new SubtitleRead();
//    r->open();
//    cout<<r->getSubList().at(1).text<<endl;
    
//    string s1="rrr";
//    string s2="100";
    
//    cout<<atoi(s2.c_str())<<endl;
    return app.exec();
}
