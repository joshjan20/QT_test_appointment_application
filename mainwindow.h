#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "availableslots.h"
#include "booking.h"
#include "cancellation.h"
#include "records.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBooking_clicked();

    void on_btnCancellation_clicked();

    void on_btnAvailableSlots_clicked();

    void on_btnRecords_clicked();

private:
    Ui::MainWindow *ui;
    Availableslots * ptrAvailableSlots;
    Booking * ptrBooking;
    Cancellation * ptrCancellation;
    Records * ptrRecords;
};

#endif // MAINWINDOW_H
