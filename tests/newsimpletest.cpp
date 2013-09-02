/* 
 * File:   newsimpletest.cpp
 * Author: rukshan
 *
 * Created on Sep 2, 2013, 1:48:03 PM
 */

#include <stdlib.h>
#include <iostream>
#include "subtitleSave.h"

/*
 * Simple C++ Test Suite
 */

void testSaveFile() {
    string s;
    subtitleSave _subtitleSave;
    subtitleSave.saveFile(s);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testSaveFile (newsimpletest) message=error message sample" << std::endl;
    }
}

int mains(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testSaveFile (newsimpletest)" << std::endl;
    testSaveFile();
    std::cout << "%TEST_FINISHED% time=0 testSaveFile (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

