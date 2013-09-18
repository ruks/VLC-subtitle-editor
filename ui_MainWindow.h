/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Sep 18 11:21:09 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSrt;
    QWidget *centralwidget;
    QGraphicsView *view0;
    QGraphicsView *view1;
    QTableWidget *tableWidget;
    QPushButton *srt;
    QScrollBar *horizontalScrollBar;
    QGraphicsView *graphicsView;
    QPushButton *play;
    QPushButton *stop;
    QPushButton *mute;
    QScrollBar *graphicViewSlider;
    QSlider *volumeSlider;
    QGraphicsView *timeSlotBar;
    QTextEdit *textEdit;
    QGraphicsView *timeLine;
    QPushButton *scale_in_but;
    QPushButton *scale_out_but;
    QGraphicsView *timeCurser;
    QLabel *cTimeLbl;
    QLabel *tTimeLbl;
    QCustomPlot *PlotView1;
    QCustomPlot *PlotView0;
    QMenuBar *menubar;
    QMenu *menuSrt;
    QMenu *menuSave_As;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 652);
        MainWindow->setBaseSize(QSize(0, 0));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSrt = new QAction(MainWindow);
        actionSrt->setObjectName(QString::fromUtf8("actionSrt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        view0 = new QGraphicsView(centralwidget);
        view0->setObjectName(QString::fromUtf8("view0"));
        view0->setGeometry(QRect(20, 60, 631, 121));
        view0->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        view0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1 = new QGraphicsView(centralwidget);
        view1->setObjectName(QString::fromUtf8("view1"));
        view1->setGeometry(QRect(20, 160, 631, 121));
        view1->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 370, 941, 231));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(941, 231));
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        srt = new QPushButton(centralwidget);
        srt->setObjectName(QString::fromUtf8("srt"));
        srt->setGeometry(QRect(910, 20, 51, 31));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(20, 300, 631, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(660, 60, 301, 241));
        play = new QPushButton(centralwidget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(750, 320, 51, 31));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(810, 320, 51, 31));
        mute = new QPushButton(centralwidget);
        mute->setObjectName(QString::fromUtf8("mute"));
        mute->setGeometry(QRect(870, 320, 51, 31));
        graphicViewSlider = new QScrollBar(centralwidget);
        graphicViewSlider->setObjectName(QString::fromUtf8("graphicViewSlider"));
        graphicViewSlider->setGeometry(QRect(660, 300, 301, 16));
        graphicViewSlider->setOrientation(Qt::Horizontal);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(990, 60, 29, 231));
        volumeSlider->setOrientation(Qt::Vertical);
        timeSlotBar = new QGraphicsView(centralwidget);
        timeSlotBar->setObjectName(QString::fromUtf8("timeSlotBar"));
        timeSlotBar->setGeometry(QRect(300, 61, 71, 241));
        timeSlotBar->setMouseTracking(false);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 320, 631, 41));
        timeLine = new QGraphicsView(centralwidget);
        timeLine->setObjectName(QString::fromUtf8("timeLine"));
        timeLine->setGeometry(QRect(20, 10, 631, 41));
        timeLine->setStyleSheet(QString::fromUtf8("background-color: rgba(85, 0, 0,80);"));
        scale_in_but = new QPushButton(centralwidget);
        scale_in_but->setObjectName(QString::fromUtf8("scale_in_but"));
        scale_in_but->setGeometry(QRect(660, 10, 31, 31));
        scale_out_but = new QPushButton(centralwidget);
        scale_out_but->setObjectName(QString::fromUtf8("scale_out_but"));
        scale_out_but->setGeometry(QRect(700, 10, 31, 31));
        timeCurser = new QGraphicsView(centralwidget);
        timeCurser->setObjectName(QString::fromUtf8("timeCurser"));
        timeCurser->setGeometry(QRect(465, 10, 4, 291));
        timeCurser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::SizeHorCursor)));
        timeCurser->setMouseTracking(false);
        timeCurser->setFocusPolicy(Qt::ClickFocus);
        timeCurser->setContextMenuPolicy(Qt::ActionsContextMenu);
        timeCurser->setAcceptDrops(false);
        cTimeLbl = new QLabel(centralwidget);
        cTimeLbl->setObjectName(QString::fromUtf8("cTimeLbl"));
        cTimeLbl->setGeometry(QRect(660, 330, 66, 17));
        tTimeLbl = new QLabel(centralwidget);
        tTimeLbl->setObjectName(QString::fromUtf8("tTimeLbl"));
        tTimeLbl->setGeometry(QRect(940, 330, 66, 17));
        PlotView1 = new QCustomPlot(centralwidget);
        PlotView1->setObjectName(QString::fromUtf8("PlotView1"));
        PlotView1->setGeometry(QRect(20, 160, 631, 121));
        PlotView0 = new QCustomPlot(centralwidget);
        PlotView0->setObjectName(QString::fromUtf8("PlotView0"));
        PlotView0->setGeometry(QRect(20, 60, 631, 101));
        MainWindow->setCentralWidget(centralwidget);
        view0->raise();
        view1->raise();
        tableWidget->raise();
        srt->raise();
        horizontalScrollBar->raise();
        play->raise();
        stop->raise();
        mute->raise();
        graphicViewSlider->raise();
        volumeSlider->raise();
        textEdit->raise();
        timeLine->raise();
        scale_in_but->raise();
        scale_out_but->raise();
        graphicsView->raise();
        cTimeLbl->raise();
        tTimeLbl->raise();
        PlotView1->raise();
        PlotView0->raise();
        timeSlotBar->raise();
        timeCurser->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1029, 25));
        menuSrt = new QMenu(menubar);
        menuSrt->setObjectName(QString::fromUtf8("menuSrt"));
        menuSave_As = new QMenu(menuSrt);
        menuSave_As->setObjectName(QString::fromUtf8("menuSave_As"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(timeSlotBar, graphicsView);
        QWidget::setTabOrder(graphicsView, tableWidget);
        QWidget::setTabOrder(tableWidget, srt);
        QWidget::setTabOrder(srt, view1);
        QWidget::setTabOrder(view1, play);
        QWidget::setTabOrder(play, stop);
        QWidget::setTabOrder(stop, mute);
        QWidget::setTabOrder(mute, volumeSlider);
        QWidget::setTabOrder(volumeSlider, view0);
        QWidget::setTabOrder(view0, textEdit);
        QWidget::setTabOrder(textEdit, timeLine);
        QWidget::setTabOrder(timeLine, scale_in_but);
        QWidget::setTabOrder(scale_in_but, scale_out_but);

        menubar->addAction(menuSrt->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuSrt->addAction(actionSave);
        menuSrt->addAction(menuSave_As->menuAction());
        menuSrt->addAction(actionExit);
        menuSave_As->addAction(actionSrt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionSrt->setText(QApplication::translate("MainWindow", "srt", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Start time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "End time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Duration", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        srt->setText(QApplication::translate("MainWindow", "srt", 0, QApplication::UnicodeUTF8));
        play->setText(QApplication::translate("MainWindow", "play", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("MainWindow", "stop", 0, QApplication::UnicodeUTF8));
        mute->setText(QApplication::translate("MainWindow", "mute", 0, QApplication::UnicodeUTF8));
        scale_in_but->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        scale_out_but->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        cTimeLbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        tTimeLbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        menuSrt->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuSave_As->setTitle(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
