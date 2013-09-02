/* 
 * File:   srtFormat.h
 * Author: rukshan
 *
 * Created on August 30, 2013, 10:54 PM
 */
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#ifndef SRTFORMAT_H
#define	SRTFORMAT_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct node {
        int id;
        string startTime;
        string endTime;
        string duration;
        string text;
    };
    
    struct dataObject{
        string object;
        string msg;
        int val;
        int x;
        int y;
    };

#ifdef	__cplusplus
}
#endif

#endif	/* SRTFORMAT_H */

