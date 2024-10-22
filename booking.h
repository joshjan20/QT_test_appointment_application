#ifndef BOOKING_H
#define BOOKING_H

#include <QDialog>
#include "mydb.h"
#include <QTime>

namespace Ui {
class Booking;
}

class Booking : public QDialog
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);
    ~Booking();
    void populateData();
private slots:
    void on_btnBook_clicked();
    void on_btnCancel_clicked();

private:
    Ui::Booking *ui;
};

#endif // BOOKING_H
