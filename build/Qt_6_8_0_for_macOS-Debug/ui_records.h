/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Records
{
public:
    QTableView *tableView;

    void setupUi(QDialog *Records)
    {
        if (Records->objectName().isEmpty())
            Records->setObjectName("Records");
        Records->setWindowModality(Qt::WindowModal);
        Records->resize(320, 240);
        tableView = new QTableView(Records);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 321, 231));

        retranslateUi(Records);

        QMetaObject::connectSlotsByName(Records);
    } // setupUi

    void retranslateUi(QDialog *Records)
    {
        Records->setWindowTitle(QCoreApplication::translate("Records", "Records", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Records: public Ui_Records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
