/* 
 * File:   MyQTimeEdit.h
 * Author: rukshan
 *
 * Created on October 11, 2013, 10:44 PM
 */

#ifndef MYQTIMEEDIT_H
#define	MYQTIMEEDIT_H
#include <QtCore/QtCore>
#include <QtGui/QtGui>

class MyQTimeEdit : public QTimeEdit {
    Q_OBJECT
public:
    MyQTimeEdit(QWidget * parent, int row, int col);
    MyQTimeEdit(const MyQTimeEdit& orig);
    virtual ~MyQTimeEdit();
    int row, col;

public slots:
    void timesChanged(QTime t);

signals:
void timeChanged(QTime *date);
};

#endif	/* MYQTIMEEDIT_H */

