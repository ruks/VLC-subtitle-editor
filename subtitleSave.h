/* 
 * File:   subtitleSave.h
 * Author: rukshan
 *
 * Created on August 30, 2013, 7:59 PM
 */

#ifndef SUBTITLESAVE_H
#define	SUBTITLESAVE_H

#include "srtFormat.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class subtitleSave {
public:
    subtitleSave();
    subtitleSave(const subtitleSave& orig);
    virtual ~subtitleSave();
private:
    
public:
    void saveAsSRT(node nodes[]);
    void saveAsSSA();
    void saveFile(string s);
};

#endif	/* SUBTITLESAVE_H */

