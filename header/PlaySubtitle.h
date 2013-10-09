/* 
 * File:   PlaySubtitle.h
 * Author: rukshan
 *
 * Created on October 2, 2013, 7:19 PM
 */

#ifndef PLAYSUBTITLE_H
#define	PLAYSUBTITLE_H

#include "SubtitleRead.h"
#include "player.h"
#include "srtFormat.h"
#include "Observable.h"
#include <vector>
#include "QTableWidget"
#include <QtCore/QtCore>
#include <QtGui/QtGui>

class PlaySubtitle : public Observable{
public:
    PlaySubtitle(SubtitleRead *subtitleRead, player *player);
    PlaySubtitle(const PlaySubtitle& orig);
    virtual ~PlaySubtitle();
    void start(int time);
    void findID(int time,int n);
    void setSublist(vector<srtFormat> list);
    void setTable(QTableWidget *tab);

private:
    SubtitleRead *read;
    player *play;
    vector<srtFormat> v;
    int id;
    dataObject ob;
    QTableWidget *table;
    bool isSub;
};

#endif	/* PLAYSUBTITLE_H */

