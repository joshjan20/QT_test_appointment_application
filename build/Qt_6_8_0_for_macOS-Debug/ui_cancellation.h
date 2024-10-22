/********************************************************************************
** Form generated from reading UI file 'cancellation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANCELLATION_H
#define UI_CANCELLATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Cancellation
{
public:
    QPushButton *btnCancel;
    QComboBox *cmbSlot;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *txtTokenNo;
    QLabel *lblInfo;

    void setupUi(QDialog *Cancellation)
    {
        if (Cancellation->objectName().isEmpty())
            Cancellation->setObjectName("Cancellation");
        Cancellation->setWindowModality(Qt::WindowModal);
        Cancellation->resize(320, 151);
        btnCancel = new QPushButton(Cancellation);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(110, 80, 75, 30));
        QFont font;
        font.setPointSize(10);
        btnCancel->setFont(font);
        cmbSlot = new QComboBox(Cancellation);
        cmbSlot->setObjectName("cmbSlot");
        cmbSlot->setGeometry(QRect(150, 10, 111, 22));
        cmbSlot->setFont(font);
        label_2 = new QLabel(Cancellation);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 91, 21));
        label_2->setFont(font);
        label = new QLabel(Cancellation);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 91, 16));
        label->setFont(font);
        txtTokenNo = new QLineEdit(Cancellation);
        txtTokenNo->setObjectName("txtTokenNo");
        txtTokenNo->setGeometry(QRect(150, 40, 113, 20));
        txtTokenNo->setFont(font);
        lblInfo = new QLabel(Cancellation);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setGeometry(QRect(70, 120, 181, 16));

        retranslateUi(Cancellation);

        QMetaObject::connectSlotsByName(Cancellation);
    } // setupUi

    void retranslateUi(QDialog *Cancellation)
    {
        Cancellation->setWindowTitle(QCoreApplication::translate("Cancellation", "Cancel Booking", nullptr));
        btnCancel->setText(QCoreApplication::translate("Cancellation", "CANCEL", nullptr));
        label_2->setText(QCoreApplication::translate("Cancellation", "Token No", nullptr));
        label->setText(QCoreApplication::translate("Cancellation", "Select Slot", nullptr));
        lblInfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Cancellation: public Ui_Cancellation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANCELLATION_H
