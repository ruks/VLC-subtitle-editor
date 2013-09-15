/********************************************************************************
** Form generated from reading UI file 'FileSelector.ui'
**
** Created: Wed Sep 11 22:58:15 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILESELECTOR_H
#define UI_FILESELECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_FileSelector
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FileSelector)
    {
        if (FileSelector->objectName().isEmpty())
            FileSelector->setObjectName(QString::fromUtf8("FileSelector"));
        FileSelector->resize(400, 300);
        buttonBox = new QDialogButtonBox(FileSelector);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

        retranslateUi(FileSelector);
        QObject::connect(buttonBox, SIGNAL(accepted()), FileSelector, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), FileSelector, SLOT(reject()));

        QMetaObject::connectSlotsByName(FileSelector);
    } // setupUi

    void retranslateUi(QDialog *FileSelector)
    {
        FileSelector->setWindowTitle(QApplication::translate("FileSelector", "FileSelector", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FileSelector: public Ui_FileSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILESELECTOR_H
