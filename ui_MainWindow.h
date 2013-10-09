/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Wed Oct 9 11:25:59 2013
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
#include <QtGui/QHBoxLayout>
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
    QAction *actionSubtitle_file;
    QAction *actionMedia_file;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *srt;
    QScrollBar *horizontalScrollBar;
    QGraphicsView *graphicsView;
    QScrollBar *graphicViewSlider;
    QSlider *volumeSlider;
    QGraphicsView *timeSlotBar;
    QTextEdit *textEdit;
    QGraphicsView *timeCurser;
    QLabel *cTimeLbl;
    QLabel *tTimeLbl;
    QCustomPlot *PlotView1;
    QCustomPlot *PlotView0;
    QGraphicsView *view1;
    QPushButton *mute;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *add_row_after;
    QPushButton *add_row_before;
    QPushButton *remove_row;
    QPushButton *subTimeStartCmd;
    QPushButton *subTimeStopCmd;
    QPushButton *pauseBtn;
    QPushButton *play;
    QPushButton *stop;
    QMenuBar *menubar;
    QMenu *menuSrt;
    QMenu *menuSave_As;
    QMenu *menuOpen;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1138, 652);
        MainWindow->setBaseSize(QSize(0, 0));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSrt = new QAction(MainWindow);
        actionSrt->setObjectName(QString::fromUtf8("actionSrt"));
        actionSubtitle_file = new QAction(MainWindow);
        actionSubtitle_file->setObjectName(QString::fromUtf8("actionSubtitle_file"));
        actionMedia_file = new QAction(MainWindow);
        actionMedia_file->setObjectName(QString::fromUtf8("actionMedia_file"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
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
        tableWidget->setGeometry(QRect(10, 370, 1041, 231));
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
        srt->setGeometry(QRect(900, -30, 51, 31));
        horizontalScrollBar = new QScrollBar(centralwidget);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(10, 290, 631, 16));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(650, 10, 401, 271));
        graphicViewSlider = new QScrollBar(centralwidget);
        graphicViewSlider->setObjectName(QString::fromUtf8("graphicViewSlider"));
        graphicViewSlider->setGeometry(QRect(650, 290, 401, 16));
        graphicViewSlider->setOrientation(Qt::Horizontal);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(1070, 10, 29, 251));
        volumeSlider->setOrientation(Qt::Vertical);
        timeSlotBar = new QGraphicsView(centralwidget);
        timeSlotBar->setObjectName(QString::fromUtf8("timeSlotBar"));
        timeSlotBar->setGeometry(QRect(40, 10, 71, 271));
        timeSlotBar->setMouseTracking(false);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 310, 631, 51));
        timeCurser = new QGraphicsView(centralwidget);
        timeCurser->setObjectName(QString::fromUtf8("timeCurser"));
        timeCurser->setGeometry(QRect(440, 12, 16, 271));
        timeCurser->setMouseTracking(false);
        timeCurser->setFocusPolicy(Qt::ClickFocus);
        timeCurser->setContextMenuPolicy(Qt::ActionsContextMenu);
        timeCurser->setAcceptDrops(false);
        cTimeLbl = new QLabel(centralwidget);
        cTimeLbl->setObjectName(QString::fromUtf8("cTimeLbl"));
        cTimeLbl->setGeometry(QRect(650, 310, 66, 17));
        tTimeLbl = new QLabel(centralwidget);
        tTimeLbl->setObjectName(QString::fromUtf8("tTimeLbl"));
        tTimeLbl->setGeometry(QRect(980, 310, 66, 17));
        PlotView1 = new QCustomPlot(centralwidget);
        PlotView1->setObjectName(QString::fromUtf8("PlotView1"));
        PlotView1->setGeometry(QRect(10, 150, 631, 131));
        PlotView0 = new QCustomPlot(centralwidget);
        PlotView0->setObjectName(QString::fromUtf8("PlotView0"));
        PlotView0->setGeometry(QRect(10, 10, 631, 131));
        view1 = new QGraphicsView(centralwidget);
        view1->setObjectName(QString::fromUtf8("view1"));
        view1->setGeometry(QRect(10, 10, 631, 271));
        view1->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        view1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mute = new QPushButton(centralwidget);
        mute->setObjectName(QString::fromUtf8("mute"));
        mute->setGeometry(QRect(1070, 270, 30, 27));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(650, 330, 448, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        add_row_after = new QPushButton(layoutWidget);
        add_row_after->setObjectName(QString::fromUtf8("add_row_after"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("image/table_row_add_after.png"), QSize(), QIcon::Normal, QIcon::On);
        add_row_after->setIcon(icon);

        horizontalLayout->addWidget(add_row_after);

        add_row_before = new QPushButton(layoutWidget);
        add_row_before->setObjectName(QString::fromUtf8("add_row_before"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("image/table_row_add_before.png"), QSize(), QIcon::Normal, QIcon::On);
        add_row_before->setIcon(icon1);

        horizontalLayout->addWidget(add_row_before);

        remove_row = new QPushButton(layoutWidget);
        remove_row->setObjectName(QString::fromUtf8("remove_row"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("image/minus-512.png"), QSize(), QIcon::Normal, QIcon::On);
        remove_row->setIcon(icon2);
        remove_row->setIconSize(QSize(22, 18));

        horizontalLayout->addWidget(remove_row);

        subTimeStartCmd = new QPushButton(layoutWidget);
        subTimeStartCmd->setObjectName(QString::fromUtf8("subTimeStartCmd"));

        horizontalLayout->addWidget(subTimeStartCmd);

        subTimeStopCmd = new QPushButton(layoutWidget);
        subTimeStopCmd->setObjectName(QString::fromUtf8("subTimeStopCmd"));

        horizontalLayout->addWidget(subTimeStopCmd);

        pauseBtn = new QPushButton(layoutWidget);
        pauseBtn->setObjectName(QString::fromUtf8("pauseBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("image/basic2-129_media_pause-128.png"), QSize(), QIcon::Normal, QIcon::On);
        pauseBtn->setIcon(icon3);

        horizontalLayout->addWidget(pauseBtn);

        play = new QPushButton(layoutWidget);
        play->setObjectName(QString::fromUtf8("play"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("image/Play-128.png"), QSize(), QIcon::Normal, QIcon::On);
        play->setIcon(icon4);

        horizontalLayout->addWidget(play);

        stop = new QPushButton(layoutWidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("image/basic2-128_media_stop-128.png"), QSize(), QIcon::Normal, QIcon::On);
        stop->setIcon(icon5);

        horizontalLayout->addWidget(stop);

        MainWindow->setCentralWidget(centralwidget);
        tableWidget->raise();
        textEdit->raise();
        layoutWidget->raise();
        PlotView0->raise();
        PlotView1->raise();
        srt->raise();
        horizontalScrollBar->raise();
        graphicViewSlider->raise();
        volumeSlider->raise();
        graphicsView->raise();
        cTimeLbl->raise();
        tTimeLbl->raise();
        view1->raise();
        timeSlotBar->raise();
        timeCurser->raise();
        mute->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1138, 25));
        menuSrt = new QMenu(menubar);
        menuSrt->setObjectName(QString::fromUtf8("menuSrt"));
        menuSave_As = new QMenu(menuSrt);
        menuSave_As->setObjectName(QString::fromUtf8("menuSave_As"));
        menuOpen = new QMenu(menuSrt);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
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
        QWidget::setTabOrder(view1, volumeSlider);
        QWidget::setTabOrder(volumeSlider, textEdit);

        menubar->addAction(menuSrt->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuSrt->addAction(actionSave);
        menuSrt->addAction(menuSave_As->menuAction());
        menuSrt->addAction(actionExit);
        menuSrt->addAction(menuOpen->menuAction());
        menuSave_As->addAction(actionSrt);
        menuOpen->addAction(actionSubtitle_file);
        menuOpen->addAction(actionMedia_file);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionSrt->setText(QApplication::translate("MainWindow", "srt", 0, QApplication::UnicodeUTF8));
        actionSubtitle_file->setText(QApplication::translate("MainWindow", "Subtitle file", 0, QApplication::UnicodeUTF8));
        actionMedia_file->setText(QApplication::translate("MainWindow", "Media file", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Start time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "End time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Duration", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        srt->setText(QApplication::translate("MainWindow", "srt", 0, QApplication::UnicodeUTF8));
        cTimeLbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        tTimeLbl->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mute->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>mute</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        mute->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        add_row_after->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Add row after</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        add_row_after->setText(QString());
#ifndef QT_NO_TOOLTIP
        add_row_before->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>add row before</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        add_row_before->setText(QString());
#ifndef QT_NO_TOOLTIP
        remove_row->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>remove row</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        remove_row->setText(QString());
#ifndef QT_NO_TOOLTIP
        subTimeStartCmd->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>set Sub start time</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        subTimeStartCmd->setText(QApplication::translate("MainWindow", "[", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        subTimeStopCmd->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>set stop sub time</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        subTimeStopCmd->setText(QApplication::translate("MainWindow", "]", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pauseBtn->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>pause</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pauseBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        play->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>play</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        play->setText(QString());
#ifndef QT_NO_TOOLTIP
        stop->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>stop</p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        stop->setText(QString());
        menuSrt->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuSave_As->setTitle(QApplication::translate("MainWindow", "Save As", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "open", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
