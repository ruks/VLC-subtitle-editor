/* 
 * File:   FileSelector.h
 * Author: rukshan
 *
 * Created on September 7, 2013, 11:25 PM
 */

#ifndef _FILESELECTOR_H
#define	_FILESELECTOR_H
#include <QFileDialog>
#include "Observable.h"

class FileSelector : public QWidget, public Observable {
public:
    FileSelector();
    virtual ~FileSelector();
    void openFile();
    void openSubFile();
    void openFiles();
    void openDir();
    void saveFile();

private:
};

#endif	/* _FILESELECTOR_H */
