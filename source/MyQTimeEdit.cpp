/* 
 * File:   MyQTimeEdit.cpp
 * Author: rukshan
 * 
 * Created on October 11, 2013, 10:44 PM
 */

#include "header/MyQTimeEdit.h"
#include <iostream>

using namespace std;

MyQTimeEdit::MyQTimeEdit(QWidget * parent = 0, int row = -1, int col = -1) {
    this->row=row;
    this->col=col;
}

MyQTimeEdit::MyQTimeEdit(const MyQTimeEdit& orig) {
}

MyQTimeEdit::~MyQTimeEdit() {
}

void MyQTimeEdit::timesChanged(QTime t) {
//    QString sq = QString::number(t.msec());
//    qDebug(sq.toStdString().c_str());
//    cout<<row<<" "<<col<<endl;
    
}