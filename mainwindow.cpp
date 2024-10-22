#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAvailableSlots = new Availableslots(this);
    ptrBooking = new Booking(this);
    ptrCancellation = new Cancellation(this);
    ptrRecords = new Records(this);

}

MainWindow::~MainWindow()
{
    delete ptrAvailableSlots; ptrAvailableSlots = nullptr;
    delete ptrBooking;        ptrBooking = nullptr;
    delete ptrCancellation;   ptrCancellation = nullptr;
    delete ptrRecords;        ptrRecords = nullptr;
    delete ui;
}

void MainWindow::on_btnBooking_clicked()
{
    ptrBooking->populateData();
    ptrBooking->show();
}

void MainWindow::on_btnCancellation_clicked()
{
    ptrCancellation->populateData();
    ptrCancellation->show();
}

void MainWindow::on_btnAvailableSlots_clicked()
{
    ptrAvailableSlots->populateData();
    ptrAvailableSlots->show();
}

void MainWindow::on_btnRecords_clicked()
{
    ptrRecords->populateData();
    ptrRecords->show();
}
