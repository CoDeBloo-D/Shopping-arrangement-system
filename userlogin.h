#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>
#include "user.h"
#include "file.h"

namespace Ui {
class Userlogin;
}

class Userlogin : public QDialog
{
    Q_OBJECT

public:
    explicit Userlogin(QWidget *parent = 0);
    ~Userlogin();
signals:
    void openusermenu(QString);
    void userloginclose();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();

private:
    Ui::Userlogin *ui;
    bool correct=0;
    User u;
    File f;
};

#endif // USERLOGIN_H
