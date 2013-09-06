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
#include <QString>

int captionNumber = 0;
int lineCounter = 0;

using namespace std;

vector<srtFormat> v;

SubtitleRead::SubtitleRead() {
}

SubtitleRead::SubtitleRead(const SubtitleRead& orig) {
}

SubtitleRead::~SubtitleRead() {
}

void SubtitleRead::open() {
    FILE *ptr_file;
    char buf[1000];

    ptr_file = fopen("input.srt", "r");
    if (!ptr_file)
        return;

    while (fgets(buf, 1000, ptr_file) != NULL) {
        //                printf("%s", buf);
        decodeToSRT(buf);
    }
    fclose(ptr_file);
}

void SubtitleRead::decodeToSRT(char line[]) {
    int allGood;
    char *c = "-->";
    char *n = "\n";
    int num = atoi(line);
    srtFormat s;

    if (num == captionNumber) {
        s.id = captionNumber;
        //        s.text="";
        v.push_back(s);
        captionNumber++;
        //        printf("%d\n", num);
        //        cout<<num<<endl;
        return;
    }

    if (strstr(line, c)) {
        //        printf("%s", line);
        string time = line;
        v.at(captionNumber - 1).startH = time.substr(0, 2);
        v.at(captionNumber - 1).startM = time.substr(3, 2);
        v.at(captionNumber - 1).startS = time.substr(6, 2);
        v.at(captionNumber - 1).startMs = time.substr(9, 3);

        v.at(captionNumber - 1).stopH = time.substr(17, 2);
        v.at(captionNumber - 1).stopM = time.substr(20, 2);
        v.at(captionNumber - 1).stopS = time.substr(23, 2);
        v.at(captionNumber - 1).stopMs = time.substr(26, 3);

        return;
    }

    if (strlen(line) > 2) {
        //        strcat(v.at(captionNumber - 1).text, line);
        v.at(captionNumber - 1).text += line;
    }

}

vector<srtFormat> SubtitleRead::getSubList() {
    return v;
}
