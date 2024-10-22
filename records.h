#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include <QDialog>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mydb.h"

namespace Ui {
class Records;
}

class Records : public QDialog
{
    Q_OBJECT

public:
    explicit Records(QWidget *parent = nullptr);
    ~Records();
    void populateData();

private:
    Ui::Records *ui;
    void getRecords();
};

#endif // RECORDS_H
