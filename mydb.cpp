#include "mydb.h"

MyDB* MyDB::instance = nullptr;

MyDB::MyDB()
{
    init();
}
void MyDB::init()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "Data");
    db.setDatabaseName("/Users/john/Documents/db/joshjan_doctor_appointment.sqlite");


    if(QFile::exists("/Users/john/Documents/db/joshjan_doctor_appointment.sqlite"))
            qDebug() << "DB file exist";
        else
           qDebug() << "DB file doesn't exists";

        if (!db.open())
            qDebug() << db.lastError().text();
        else
            qDebug() << "Database loaded successfull!";

}

MyDB *MyDB::getInstance()
{
    qDebug() << "in MyDB::getInstance()";

    if(instance == nullptr)
        instance = new MyDB();

    return instance;

}

QSqlDatabase MyDB::getDBInstance()
{
    return db;
}

void MyDB::ResetInstance()
   {
      delete instance;
      instance = nullptr;
   }

MyDB::~MyDB()
{
   db.close();
}
