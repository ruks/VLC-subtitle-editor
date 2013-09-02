/*
 * File:   main.cpp
 * Author: rukshan
 *
 * Created on August 29, 2013, 9:14 AM
 */

#include <QtGui/QApplication>
//#include "m
#include "smem.h"
#include <QTimer>
#include "MainWindow.h"
#include "printbits.h"
#include "subtitleSave.h"
#include "player.h"
#include "subtitleEditor.h"

int mains(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    QApplication app(argc, argv);
//    MainWindow *m = new MainWindow();
//    subtitleSave *s = new subtitleSave();
//    m->setSubtitleSave(s);
//    m->show();


    subtitleEditor *edit = new subtitleEditor();
//    m->Attach(edit);

    return app.exec();

    //    s.saveFile("rukshan");
    //    s.saveFile("rukshan");
    //    string a="rukshan";

    //    s->saveFile(a);
    //    node no[10];
    //    no[0].id = 0;
    //    no[0].startTime = "10:10:10,100";
    //    no[0].endTime = "20:20:20,200";
    //    no[0].duration = "2000";
    //    no[0].text = "this this my first subtitle file";
    //    s->saveAsSRT(no);
    //    return 0;




    //smem *c = new smem();
    //c->setMainWindow(m);
    //c->start();

    //    printbits *p = new printbits();
    //    p->setMainWindow(m);
    //    p->start();
    //
    //    // create and show your widgets here
    //
    //    return app.exec();
}
