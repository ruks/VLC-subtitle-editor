/* 
 * File:   subtitleSave.cpp
 * Author: rukshan
 * 
 * Created on August 30, 2013, 7:59 PM
 */

#include "subtitleSave.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>  //include this to use string streams
#include <string>

using namespace std;

subtitleSave::subtitleSave() {
}

subtitleSave::subtitleSave(const subtitleSave& orig) {
}

subtitleSave::~subtitleSave() {
}

void subtitleSave::saveFile(string s) {
    ofstream myfile;
    myfile.open("example.txt", ios::app);
    myfile << s << endl;
    myfile.close();
}

void subtitleSave::saveAsSRT(node nodes[]) {
    string out;
    ostringstream ostr1;
    ostr1 << nodes[0].id;
    string id = ostr1.str();

    out = id + " " + nodes[0].startTime + " " + " --> " + " " + nodes[0].endTime + "\n" + nodes[0].text + "\n";
    saveFile(out);
}

void subtitleSave::saveAsSSA() {

}
