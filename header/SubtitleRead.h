/* 
 * File:   SubtitleRead.h
 * Author: rukshan
 *
 * Created on September 4, 2013, 10:44 PM
 */

#ifndef SUBTITLEREAD_H
#define	SUBTITLEREAD_H

class SubtitleRead {
public:
    SubtitleRead();
    SubtitleRead(const SubtitleRead& orig);
    virtual ~SubtitleRead();
    void open();
    void decodeToSRT(char line[]);
private:

};

#endif	/* SUBTITLEREAD_H */

