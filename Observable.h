/* 
 * File:   Observable.h
 * Author: rukshan
 *
 * Created on August 31, 2013, 9:31 AM
 */

#ifndef OBSERVABLE_H
#define	OBSERVABLE_H

#pragma once
#include <vector>
#include <list>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#include "subtitleEditor.h"
#include "FileIO.h"
using namespace std;

class Observable {
    vector<subtitleEditor*> list;
    
public:
    Observable();
    Observable(const Observable& orig);
    virtual ~Observable();
    void Attach(subtitleEditor *product);
    void Detach(subtitleEditor *product);
    void Notify(dataObject object);
private:

};

#endif	/* OBSERVABLE_H */

