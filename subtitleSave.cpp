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

void subtitleSave::saveFile(vector<srtOutFormat> s) {// save to file
    ofstream myfile;
    myfile.open("example.srt", ios::trunc);// create new file
    for (int i = 0; i < s.size(); i++) {
        myfile << s.at(i).id << endl;// add id 
        myfile << s.at(i).start + " --> " + s.at(i).stop << endl;// add start and stop time information
        myfile << s.at(i).text << endl;//add text 
        myfile << endl;
    }
    myfile.close();// close the opened file
}

void subtitleSave::saveAsSRT(node nodes[]) {
    
}

void subtitleSave::saveAsSSA() {

}



