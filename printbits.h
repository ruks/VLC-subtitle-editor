/* 
 * File:   printbits.h
 * Author: rukshan
 *
 * Created on August 29, 2013, 7:05 PM
 */

#ifndef PRINTBITS_H
#define	PRINTBITS_H
#include <QThread>
#include <QQueue>
#include "MainWindow.h"
#include "Observable.h"

class printbits : public QThread, public Observable {
public:
    QQueue<int> qL;
    QQueue<int> qR;
    printbits();
    printbits(const printbits& orig);
    virtual ~printbits();
    void setMainWindow(MainWindow *m);
    bool stat;
    void runs();
    QQueue<int> getLeftlist();
    QQueue<int> getRightlist();

private:

protected:
    void run();
};

#endif	/* PRINTBITS_H */

