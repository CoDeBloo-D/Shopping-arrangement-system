#ifndef MODIFYITEMPRICE_H
#define MODIFYITEMPRICE_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Modifyitemprice;
}

class Modifyitemprice : public QDialog
{
    Q_OBJECT

public:
    explicit Modifyitemprice(QWidget *parent = 0);
    ~Modifyitemprice();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();
private:
    Ui::Modifyitemprice *ui;
    Admin a;
};

#endif // MODIFYITEMPRICE_H
