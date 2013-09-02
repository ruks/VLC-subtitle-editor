/* 
 * File:   IObserver.h
 * Author: rukshan
 *
 * Created on August 31, 2013, 9:26 AM
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "srtFormat.h"

using namespace std;
#ifndef IOBSERVER_H
#define	IOBSERVER_H

#ifdef	__cplusplus
extern "C" {
#endif


#pragma once

class IObserver
{
public:
    virtual void Update(dataObject object) = 0;
};

#ifdef	__cplusplus
}
#endif

#endif	/* IOBSERVER_H */

