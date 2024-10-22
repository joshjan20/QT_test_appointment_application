#include "cancellation.h"
#include "ui_cancellation.h"

Cancellation::Cancellation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cancellation)
{
    ui->setupUi(this);
}

void Cancellation::populateData()
{
    ui->cmbSlot->clear();
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("select Slot from joshjan_booking where Status='N'");

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

    if(ui->cmbSlot->count() <= 0)
    {
        ui->cmbSlot->setEnabled(false);
        ui->txtTokenNo->setEnabled(false);
        ui->btnCancel->setEnabled(false);
    }


}

Cancellation::~Cancellation()
{
    delete ui;
}

void Cancellation::on_btnBook_clicked()
{
    QString sTokenNo = ui->txtTokenNo->text();
    QString sSlot = ui->cmbSlot->currentText();

    int flag = 0;
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("update joshjan_booking set Status='Y', TokenNo = '' where Slot='" +sSlot+ "' and TokenNo = '" +sTokenNo + "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else{
        qDebug() << "read was successful "<< query.lastQuery(); flag++;
       }
    query.clear();
    query.prepare("update joshjan_transaction set Status='Cancelled'where Slot='" +sSlot+ "' and TokenNo = '" +sTokenNo + "'");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else{
        qDebug() << "read was successful "<< query.lastQuery();flag++;
    }

    if(flag == 2)
    {
        ui->txtTokenNo->clear();
        populateData();
        ui->lblInfo->setText("Slot has been booked!!");
    }
    else
    {
        ui->lblInfo->setText("Error: Try again");
    }

}

void Cancellation::on_btnCancel_clicked()
{

    QString sTokenNo = ui->txtTokenNo->text();
    QString sSlot = ui->cmbSlot->currentText();

    int flag = 0;
    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("update joshjan_booking set Status='Y', TokenNo = '' where Slot='" +sSlot+ "' and TokenNo = '" +sTokenNo + "'");

    if(!query.exec())
    {
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    }
        else{
         if(query.numRowsAffected() >= 1)
         {
        qDebug() << "read was successful "<< query.lastQuery(); flag++;
         }
         else
         {
             qDebug()<<"Warning: Nothing was updated!!";
             ui->lblInfo->setText("Warning: Nothing was updated");
         }
       }
    query.clear();
    query.prepare("update joshjan_transaction set Status='Cancelled' where Slot='" +sSlot+ "' and TokenNo = '" +sTokenNo + "'");

    if(!query.exec()){
        qDebug() << query.lastError().text() << query.lastQuery();
        ui->lblInfo->setText(query.lastError().text());
    }
        else{

        if(query.numRowsAffected() >= 1)
        {
        //qDebug()<< " last id : "<< query.
        qDebug() << "update was successful "<< query.lastQuery();flag++;
        }
        else
        {
            qDebug() << "Warning: Nothing was updated";
            ui->lblInfo->setText("Warning: Nothing was updated");
       }
    }

    if(flag == 2)
    {
        ui->txtTokenNo->clear();
        populateData();
        ui->lblInfo->setText("Booking Cancelled");
    }

}
