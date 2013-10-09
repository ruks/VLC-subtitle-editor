
/* 
 * File:   subtitleSave.cpp
 * Author: rukshan
 * 
 * Created on August 30, 2013, 7:59 PM
 */

#include "subtitleSave.h"
#include "subtitleEditor.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>  //include this to use string streams
#include <string>


using namespace std;

subtitleSave::subtitleSave() {
    cout << endl;
}

subtitleSave::subtitleSave(const subtitleSave& orig) {
}

subtitleSave::~subtitleSave() {
}

void subtitleSave::saveFile(vector<srtFormat> s, string path) {// save to file
    ofstream myfile;
    myfile.open(path.c_str(), ios::trunc); // create new file
    string start, stop;
    for (int i = 0; i < s.size(); i++) {
        srtFormat f = s.at(i);

        start = f.startH + ":" + f.startM + ":" + f.startS + "," + f.startMs;
        stop = f.stopH + ":" + f.stopM + ":" + f.stopS + "," + f.stopMs;

        myfile << s.at(i).id << endl; // add id 
        myfile << start + " --> " + stop << endl; // add start and stop time information
        myfile << s.at(i).text << endl; //add text 
        myfile << endl;
    }
    myfile.close(); // close the opened file
}

void subtitleSave::saveAsSRT(node nodes[]) {

}

void subtitleSave::saveAsASS(vector<srtFormat> s, string path) {
    //Dialogue: 0,0:00:32.69,0:00:36.33,sincity,,0000,0000,0000,,
    //{\i1}She shivers in the wind\Nlike the last leaf on a dying tree.{\i0}
    //
    ofstream myfile;
    myfile.open(path.c_str(), ios::trunc); // create new file
    string start, stop;
    for (int i = 0; i < s.size(); i++) {
        srtFormat f = s.at(i);

        start = f.startH + ":" + f.startM + ":" + f.startS + "." + f.startMs;
        stop = f.stopH + ":" + f.stopM + ":" + f.stopS + "." + f.stopMs;

        myfile << "Dialogue: 0,";
        myfile << start << ",";
        myfile << stop << ",";
        myfile << "sincity,,0000,0000,0000,,";
        myfile << s.at(i).text << endl;

    }
    myfile.close(); // close the opened file
}



