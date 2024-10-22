#ifndef CANCELLATION_H
#define CANCELLATION_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class Cancellation;
}

class Cancellation : public QDialog
{
    Q_OBJECT

public:
    explicit Cancellation(QWidget *parent = nullptr);
    ~Cancellation();
    void populateData();

private slots:
    void on_btnBook_clicked();

    void on_btnCancel_clicked();

private:
    Ui::Cancellation *ui;
};

#endif // CANCELLATION_H
