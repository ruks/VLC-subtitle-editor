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
//#include <QtCore/QtCore>
//#include <QtGui/QtGui>

class subtitleEditor : IObserver{
public:
    subtitleEditor();
    subtitleEditor(const subtitleEditor& orig);
    virtual ~subtitleEditor();
    void Update(dataObject object);
private:
protected:
    void run();

};

#endif	/* SUBTITLEEDITOR_H */

