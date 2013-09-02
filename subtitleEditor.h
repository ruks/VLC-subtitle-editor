/* 
 * File:   subtitleEditor.h
 * Author: rukshan
 *
 * Created on August 31, 2013, 9:25 AM
 */

#ifndef SUBTITLEEDITOR_H
#define	SUBTITLEEDITOR_H

#include "IObserver.h"
#include "srtFormat.h"

class subtitleEditor : IObserver {
public:
    subtitleEditor();
    subtitleEditor(const subtitleEditor& orig);
    virtual ~subtitleEditor();
    void Update(dataObject object);
private:

};

#endif	/* SUBTITLEEDITOR_H */

