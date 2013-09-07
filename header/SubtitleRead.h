/* 
 * File:   SubtitleRead.h
 * Author: rukshan
 *
 * Created on September 4, 2013, 10:44 PM
 */

#ifndef SUBTITLEREAD_H
#define	SUBTITLEREAD_H
#include <vector>
#include <srtFormat.h>

class SubtitleRead {
public:
    SubtitleRead();
    SubtitleRead(const SubtitleRead& orig);
    virtual ~SubtitleRead();
    void open(string filePath);
    void decodeToSRT(char line[]);
    vector<srtFormat> getSubList();
private:

};

#endif	/* SUBTITLEREAD_H */

