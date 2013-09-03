/* 
 * File:   printbits.h
 * Author: rukshan
 *
 * Created on August 29, 2013, 7:05 PM
 */

#ifndef PRINTBITS_H
#define	PRINTBITS_H
#include <QThread>
#include "MainWindow.h"

class printbits : public QThread {
public:
    printbits();
    printbits(const printbits& orig);
    virtual ~printbits();
    void setMainWindow(MainWindow *m);
    bool stat;
    void runs();
    
private:

protected:
    void run();
};

#endif	/* PRINTBITS_H */

