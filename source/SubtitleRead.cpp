/* 
 * File:   SubtitleRead.cpp
 * Author: rukshan
 * 
 * Created on September 4, 2013, 10:44 PM
 */

#include "header/SubtitleRead.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <srtFormat.h>
#include <math.h>

int captionNumber = 1;
int lineCounter = 0;

using namespace std;

vector<srtFormat> v;

SubtitleRead::SubtitleRead() {
}

SubtitleRead::SubtitleRead(const SubtitleRead& orig) {
}

SubtitleRead::~SubtitleRead() {
}

void SubtitleRead::open(string filePath) {
    FILE *ptr_file;
    char buf[1000];// buffer for hold read text line
    captionNumber = 0;
    lineCounter = 0;
    v.clear();

    ptr_file = fopen(filePath.c_str(), "r");// open file in read mode
    if (!ptr_file)// if error
        return;

    while (fgets(buf, 1000, ptr_file) != NULL) {
        decodeToSRT(buf);// read line by line and decode
    }
    fclose(ptr_file);
}

void SubtitleRead::decodeToSRT(char line[]) {
    char *c = "-->";
    char *n = "\n";
    int num = atoi(line);// convert to numeric
    srtFormat s;

    if (num == captionNumber) {//if read number is expected create new subtitle caption
        s.id = captionNumber;
        v.push_back(s);
        captionNumber++;
        lineCounter++;
        return;
    } else if (num == captionNumber + 1) {
        captionNumber++;
        s.id = captionNumber + 1;
        v.push_back(s);
        captionNumber++;
        lineCounter++;
        return;
    }
    

    if (strstr(line, c)) {// if read line is time slot
        string time = line;
        v.at(lineCounter - 1).startH = time.substr(0, 2);
        v.at(lineCounter - 1).startM = time.substr(3, 2);
        v.at(lineCounter - 1).startS = time.substr(6, 2);
        v.at(lineCounter - 1).startMs = time.substr(9, 3);

        v.at(lineCounter - 1).stopH = time.substr(17, 2);
        v.at(lineCounter - 1).stopM = time.substr(20, 2);
        v.at(lineCounter - 1).stopS = time.substr(23, 2);
        v.at(lineCounter - 1).stopMs = time.substr(26, 3);

        return;
    }

    if (strlen(line) > 2) {// this must subtile text
        v.at(lineCounter - 1).text += line;// put multiple text line
        return;
    }



}

vector<srtFormat> SubtitleRead::getSubList() {
    return v;// get list of sub decoded
}

void SubtitleRead::clearVector() {
    v.clear();// remove content of the vector
}

void SubtitleRead::resetCounter() {
    //initialize the counter
    int captionNumber = 0;
    int lineCounter = 0;
}