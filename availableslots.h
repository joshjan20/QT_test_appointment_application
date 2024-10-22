#ifndef AVAILABLESLOTS_H
#define AVAILABLESLOTS_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class Availableslots;
}

class Availableslots : public QDialog
{
    Q_OBJECT

public:
    explicit Availableslots(QWidget *parent = nullptr);
    ~Availableslots();
    void populateData();

private:
    Ui::Availableslots *ui;
};

#endif // AVAILABLESLOTS_H
