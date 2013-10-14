/*
 * File:   FileSelector.cpp
 * Author: rukshan
 *
 * Created on September 7, 2013, 11:25 PM
 */

#include "FileSelector.h"
#include <iostream>
using namespace std;

FileSelector::FileSelector() {
}

FileSelector::~FileSelector() {
}

void FileSelector::openFile() {
    //    QFileDialog::getOpenFileName(this, tr("Open Document"), QDir::currentPath(), tr("Document files (*.mp4 *.flv);;All files (*.*)"), 0, QFileDialog::DontUseNativeDialog);

    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Open Document"),
            QDir::currentPath(),
            tr("Media files (*.mp4 *.flv);;Document files (*.doc *.rtf);;All files (*.*)"));
    if (!filename.isNull()) {
        //        qDebug(filename.toAscii());
        dataObject ob;
        ob.object = "file_selector_open";
        ob.val=0;
        ob.msg = filename.toStdString();
        Notify(ob);
        //        cout<<filename.toStdString()<<endl;
    }
}

void FileSelector::openSubFile(){
    QString filename = QFileDialog::getOpenFileName(
            this,
            tr("Open Document"),
            QDir::currentPath(),
            tr("Subtitle files (*.srt *.ass);;All files (*.*)"));
    
    if (!filename.isNull()) {
        dataObject ob;
        ob.object = "file_selector_open";
        ob.val=1;
        ob.msg = filename.toStdString();         
        Notify(ob);
    }
    
}
void FileSelector::openFiles() {
    QStringList filenames = QFileDialog::getOpenFileNames(
            this,
            tr("Open Document"),
            QDir::currentPath(),
            tr("Documents (*.doc);;All files (*.*)"));
    if (!filenames.isEmpty()) {
        qDebug(filenames.join(",").toAscii());
    }
}

void FileSelector::openDir() {
    QString dirname = QFileDialog::getExistingDirectory(
            this,
            tr("Select a Directory"),
            QDir::currentPath());
    if (!dirname.isNull()) {
        qDebug(dirname.toAscii());
    }
}

void FileSelector::saveFile() {
    QString filename = QFileDialog::getSaveFileName(
            this,
            tr("Save Document"),
            QDir::currentPath(),
            tr("srt (*.srt);;ssa (*.ssa)"));
//    if(filename.endsWith(".srt",Qt::CaseInsensitive)){
//    cout<<"srt"<<endl;
//    }
    if (!filename.isNull()) {
        dataObject ob;
        ob.object = "file_selector_save";
        ob.msg = filename.toStdString();
        Notify(ob);
        qDebug(filename.toAscii());
    }
}