#ifndef USERCREATE_H
#define USERCREATE_H

#include <QDialog>
#include "user.h"
#include "file.h"

namespace Ui {
class Usercreate;
}

class Usercreate : public QDialog
{
    Q_OBJECT

public:
    explicit Usercreate(QWidget *parent = 0);
    ~Usercreate();
signals:
    void openusermenucre(QString);
    void usercreateclose();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();
private:
    Ui::Usercreate *ui;
    User u;
    File f;
};

#endif // USERCREATE_H
