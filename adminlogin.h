#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Adminlogin;
}

class Adminlogin : public QDialog
{
    Q_OBJECT

public:
    explicit Adminlogin(QWidget *parent = 0);
    ~Adminlogin();
signals:
    void openadminmenu();
    void adminloginclose();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();
private:
    Ui::Adminlogin *ui;
    Admin a;
};

#endif // ADMINLOGIN_H
