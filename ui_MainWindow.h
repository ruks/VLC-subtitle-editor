/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created: Mon Sep 2 13:46:19 2013
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
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
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
    QGraphicsView *graphicsView_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGraphicsView *timeCurser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1029, 652);
        MainWindow->setBaseSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        view0 = new QGraphicsView(centralwidget);
        view0->setObjectName(QString::fromUtf8("view0"));
        view0->setGeometry(QRect(20, 60, 631, 121));
        view0->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        view0->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view1 = new QGraphicsView(centralwidget);
        view1->setObjectName(QString::fromUtf8("view1"));
        view1->setGeometry(QRect(20, 180, 631, 121));
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
        if (tableWidget->rowCount() < 5)
            tableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
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
        play->setGeometry(QRect(790, 320, 51, 31));
        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setGeometry(QRect(850, 320, 51, 31));
        mute = new QPushButton(centralwidget);
        mute->setObjectName(QString::fromUtf8("mute"));
        mute->setGeometry(QRect(910, 320, 51, 31));
        graphicViewSlider = new QScrollBar(centralwidget);
        graphicViewSlider->setObjectName(QString::fromUtf8("graphicViewSlider"));
        graphicViewSlider->setGeometry(QRect(660, 300, 301, 16));
        graphicViewSlider->setOrientation(Qt::Horizontal);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(980, 19, 29, 231));
        volumeSlider->setOrientation(Qt::Vertical);
        timeSlotBar = new QGraphicsView(centralwidget);
        timeSlotBar->setObjectName(QString::fromUtf8("timeSlotBar"));
        timeSlotBar->setGeometry(QRect(300, 61, 71, 241));
        timeSlotBar->setMouseTracking(false);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 320, 631, 41));
        graphicsView_2 = new QGraphicsView(centralwidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(20, 10, 631, 41));
        graphicsView_2->setStyleSheet(QString::fromUtf8("background-color: rgba(85, 0, 0,80);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 10, 31, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(700, 10, 31, 31));
        timeCurser = new QGraphicsView(centralwidget);
        timeCurser->setObjectName(QString::fromUtf8("timeCurser"));
        timeCurser->setGeometry(QRect(465, 10, 4, 291));
        timeCurser->viewport()->setProperty("cursor", QVariant(QCursor(Qt::SizeHorCursor)));
        timeCurser->setMouseTracking(false);
        timeCurser->setFocusPolicy(Qt::ClickFocus);
        timeCurser->setContextMenuPolicy(Qt::ActionsContextMenu);
        timeCurser->setAcceptDrops(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1029, 25));
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
        QWidget::setTabOrder(textEdit, graphicsView_2);
        QWidget::setTabOrder(graphicsView_2, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Start time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "End time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Duration", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Text", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        srt->setText(QApplication::translate("MainWindow", "srt", 0, QApplication::UnicodeUTF8));
        play->setText(QApplication::translate("MainWindow", "play", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("MainWindow", "stop", 0, QApplication::UnicodeUTF8));
        mute->setText(QApplication::translate("MainWindow", "mute", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
