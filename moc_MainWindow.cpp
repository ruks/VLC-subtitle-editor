/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Wed Oct 9 11:26:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      39,   30,   11,   11, 0x08,
      79,   11,   11,   11, 0x08,
      96,   11,   11,   11, 0x08,
     114,   11,   11,   11, 0x08,
     136,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     172,   30,   11,   11, 0x08,
     205,   30,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     272,   11,   11,   11, 0x08,
     300,   11,   11,   11, 0x08,
     327,   11,   11,   11, 0x08,
     355,   11,   11,   11, 0x08,
     379,   11,   11,   11, 0x08,
     404,   11,   11,   11, 0x08,
     439,   11,   11,   11, 0x08,
     523,  471,   11,   11, 0x08,
     574,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0updateInterface()\0position\0"
    "on_horizontalScrollBar_sliderMoved(int)\0"
    "on_srt_clicked()\0on_play_clicked()\0"
    "on_pauseBtn_clicked()\0on_mute_clicked()\0"
    "on_stop_clicked()\0on_volumeSlider_sliderMoved(int)\0"
    "on_graphicViewSlider_sliderMoved(int)\0"
    "on_subTimeStartCmd_clicked()\0"
    "on_subTimeStopCmd_clicked()\0"
    "on_add_row_after_clicked()\0"
    "on_add_row_before_clicked()\0"
    "on_remove_row_clicked()\0"
    "on_actionSrt_triggered()\0"
    "on_actionSubtitle_file_triggered()\0"
    "on_actionMedia_file_triggered()\0"
    "currentRow,currentColumn,previousRow,previousColumn\0"
    "on_tableWidget_currentCellChanged(int,int,int,int)\0"
    "on_textEdit_textChanged()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateInterface(); break;
        case 1: _t->on_horizontalScrollBar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_srt_clicked(); break;
        case 3: _t->on_play_clicked(); break;
        case 4: _t->on_pauseBtn_clicked(); break;
        case 5: _t->on_mute_clicked(); break;
        case 6: _t->on_stop_clicked(); break;
        case 7: _t->on_volumeSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_graphicViewSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_subTimeStartCmd_clicked(); break;
        case 10: _t->on_subTimeStopCmd_clicked(); break;
        case 11: _t->on_add_row_after_clicked(); break;
        case 12: _t->on_add_row_before_clicked(); break;
        case 13: _t->on_remove_row_clicked(); break;
        case 14: _t->on_actionSrt_triggered(); break;
        case 15: _t->on_actionSubtitle_file_triggered(); break;
        case 16: _t->on_actionMedia_file_triggered(); break;
        case 17: _t->on_tableWidget_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 18: _t->on_textEdit_textChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    if (!strcmp(_clname, "Observable"))
        return static_cast< Observable*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
