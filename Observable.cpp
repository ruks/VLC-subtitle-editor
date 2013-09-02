/* 
 * File:   Observable.cpp
 * Author: rukshan
 * 
 * Created on August 31, 2013, 9:31 AM
 */

#include "Observable.h"
#include <algorithm>

using namespace std;


Observable::Observable() {
}

Observable::Observable(const Observable& orig) {
}

Observable::~Observable() {
}

void Observable::Attach(subtitleEditor *shop) {
    list.push_back(shop);
}

void Observable::Detach(subtitleEditor *shop) {
    list.erase(std::remove(list.begin(), list.end(), shop), list.end());
}

void Observable::Notify(dataObject object) {
    for (vector<subtitleEditor*>::const_iterator iter = list.begin(); iter != list.end(); ++iter) {
        if (*iter != 0) {
            (*iter)->Update(object);
        }
    }
}