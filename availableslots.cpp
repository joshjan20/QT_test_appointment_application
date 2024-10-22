#include "availableslots.h"
#include "ui_availableslots.h"

Availableslots::Availableslots(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Availableslots)
{
    ui->setupUi(this);
}

void Availableslots::populateData()
{

    QSqlQuery query(MyDB::getInstance()->getDBInstance());
    query.prepare("select Slot, Status from joshjan_booking");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "read was successful "<< query.lastQuery();
    //db.close();

    //changin default style of seats those are available
    while(query.next())
    {
        QString avail = query.value(1).toString();
        QString lblname = "lbl" + query.value(0).toString();

        QLabel * ptr = this->findChild<QLabel*>(lblname);

        if(ptr)
        {
            if(avail.compare("Y"))
                ptr->setStyleSheet("QLabel { background-color : lightgrey; color : aqua; }");
            else
                ptr->setStyleSheet("QLabel { background-color : grey; color : aqua; }");
        }
     }
}

Availableslots::~Availableslots()
{
    delete ui;
}
