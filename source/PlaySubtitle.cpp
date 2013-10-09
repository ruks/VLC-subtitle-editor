/* 
 * File:   PlaySubtitle.cpp
 * Author: rukshan
 * 
 * Created on October 2, 2013, 7:19 PM
 */

#include <math.h>

#include "header/PlaySubtitle.h"
#include <exception>
using namespace std;

PlaySubtitle::PlaySubtitle(SubtitleRead* subtitleRead, player* player) {
    read = subtitleRead;
    this->play = player;
    id = 0;
    ob.object = "sub_Play";
    //    read->open("/home/rukshan/Oblivion.srt");
    //    this->v = read->getSubList();

}

PlaySubtitle::PlaySubtitle(const PlaySubtitle& orig) {
}

PlaySubtitle::~PlaySubtitle() {
}

void PlaySubtitle::start(int time) {

    //        id=0;

    if (play->isPLay()) {
        findID(time, id);
        //        cout << id << endl;
        if (isSub) {
            ob.val = id;
            Notify(ob);
        } else {
            ob.val = -1;
            Notify(ob);
        }
    }

}

void PlaySubtitle::findID(int time, int n) {
    //    cout<<"came"<<endl;
    if (n >= table->rowCount() || n < 0) {
//        id = 0;
        isSub = false;
        return;
    }

    int subSTime;
    int subStopTime;
    srtFormat srt;

    try {
        //        srt = this->v.at(n);

        QTimeEdit *st = qobject_cast<QTimeEdit*>(table->cellWidget(n, 0));
        QTimeEdit *ft = qobject_cast<QTimeEdit*>(table->cellWidget(n, 1));
        subSTime = (st->time().hour()*3600 + st->time().minute()*60 + st->time().second())*1000 + st->time().msec();
        subStopTime = (ft->time().hour()*3600 + ft->time().minute()*60 + ft->time().second())*1000 + ft->time().msec();



    } catch (exception x) {
        //        cout << x.name << endl;
    }

    int presubStopTime;
    if (n > 0) {
        QTimeEdit *preft = qobject_cast<QTimeEdit*>(table->cellWidget(n - 1, 1));
        presubStopTime = (preft->time().hour()*3600 + preft->time().minute()*60 + preft->time().second())*1000 + preft->time().msec();
    }

    if (time < subSTime) {
        //        
        if (time < presubStopTime) {
            findID(time, n - 1);
        } else {
            isSub = false;
            return;
        }
    } else if (time > subStopTime) {
        findID(time, n + 1);
    } else {
        id = n;
        isSub = true;
        return;
    }
    //            cout << time << " " << subSTime << " " << subStopTime << endl;
}

void PlaySubtitle::setSublist(vector<srtFormat> list) {
    v = list;
}

void PlaySubtitle::setTable(QTableWidget* tab) {
    table = tab;
}