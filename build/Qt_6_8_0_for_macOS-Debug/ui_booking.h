/********************************************************************************
** Form generated from reading UI file 'booking.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKING_H
#define UI_BOOKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Booking
{
public:
    QLabel *label;
    QComboBox *cmbSlot;
    QLineEdit *txtName;
    QLabel *label_2;
    QPushButton *btnBook;
    QLabel *label_3;
    QLineEdit *txtContactNo;
    QLabel *lblInfo;
    QPushButton *btnCancel;

    void setupUi(QDialog *Booking)
    {
        if (Booking->objectName().isEmpty())
            Booking->setObjectName("Booking");
        Booking->setWindowModality(Qt::WindowModality::WindowModal);
        Booking->resize(311, 177);
        label = new QLabel(Booking);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 91, 16));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        cmbSlot = new QComboBox(Booking);
        cmbSlot->setObjectName("cmbSlot");
        cmbSlot->setGeometry(QRect(150, 10, 111, 22));
        cmbSlot->setFont(font);
        txtName = new QLineEdit(Booking);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(150, 40, 113, 20));
        txtName->setFont(font);
        label_2 = new QLabel(Booking);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 40, 91, 21));
        label_2->setFont(font);
        btnBook = new QPushButton(Booking);
        btnBook->setObjectName("btnBook");
        btnBook->setGeometry(QRect(150, 110, 75, 30));
        btnBook->setFont(font);
        label_3 = new QLabel(Booking);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 70, 101, 21));
        label_3->setFont(font);
        txtContactNo = new QLineEdit(Booking);
        txtContactNo->setObjectName("txtContactNo");
        txtContactNo->setGeometry(QRect(150, 70, 113, 20));
        txtContactNo->setFont(font);
        lblInfo = new QLabel(Booking);
        lblInfo->setObjectName("lblInfo");
        lblInfo->setGeometry(QRect(30, 150, 261, 20));
        btnCancel = new QPushButton(Booking);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(70, 110, 61, 30));
        btnCancel->setFont(font);

        retranslateUi(Booking);

        QMetaObject::connectSlotsByName(Booking);
    } // setupUi

    void retranslateUi(QDialog *Booking)
    {
        Booking->setWindowTitle(QCoreApplication::translate("Booking", "Booking", nullptr));
        label->setText(QCoreApplication::translate("Booking", "Select Slot", nullptr));
        label_2->setText(QCoreApplication::translate("Booking", "Name of Patient", nullptr));
        btnBook->setText(QCoreApplication::translate("Booking", "BOOK", nullptr));
        label_3->setText(QCoreApplication::translate("Booking", "Contact Number", nullptr));
        lblInfo->setText(QString());
        btnCancel->setText(QCoreApplication::translate("Booking", "CANCEL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Booking: public Ui_Booking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKING_H
