#include "booking.h"
#include "ui_booking.h"
#include <QRandomGenerator>

Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking)
{
    ui->setupUi(this);
}

void Booking::populateData()
{

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("select Slot from joshjan_booking where Status='Y'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "read was successful "<< query.lastQuery();
    //db.close();

    ui->cmbSlot->clear();
    //changin default style of seats those are available
    while(query.next())
    {
        ui->cmbSlot->addItem(query.value(0).toString());
    }
}

Booking::~Booking()
{
    delete ui;
}

void Booking::on_btnCancel_clicked()
{
    this->close();
}
void Booking::on_btnBook_clicked()
{
    ui->lblInfo->setText("");
    //qDebug() << qrand() % ((111111 + 1) - 111111) + 999999;
    qDebug() << QRandomGenerator::global()->bounded(111111, 999999);

    QString sName = ui->txtName->text();
    QString sContactNo = ui->txtContactNo->text();
    QString sSlot = ui->cmbSlot->currentText();
    //int sTokenNo = (qrand() % ((999999 + 1) - 111111) + 111111);
    int sTokenNo = QRandomGenerator::global()->bounded(111111, 999999);
    QString sDate = QDate::currentDate().toString();

    int flag = 0;
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("update joshjan_booking set Status='N', TokenNo = '" + QString::number(sTokenNo) + "'where Slot='" +sSlot+ "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else{
        qDebug() << "read was successful "<< query.lastQuery(); flag++;
       }
    query.clear();
    query.prepare("insert into joshjan_transaction (Slot, CustomerName, CustomerContact, TokenNo, Status, DateTime) values ('" + sSlot+ "', '" + sName + "','"+ sContactNo + "','" + QString::number(sTokenNo) + "','Booked','" + sDate + "')");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else{
        qDebug() << "read was successful "<< query.lastQuery();flag++;
    }

    if(flag == 2)
    {
        ui->txtName->clear();
        ui->txtContactNo->clear();
        populateData();
        ui->lblInfo->setText("Slot has been booked!! Token No : " + QString::number(sTokenNo));

    }
    else
    {
        ui->lblInfo->setText("Error: Try again");
    }
}
