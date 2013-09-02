/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Thu Aug 29 09:15:51 2013
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
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(mainWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        retranslateUi(mainWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), mainWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), mainWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QDialog *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "mainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
