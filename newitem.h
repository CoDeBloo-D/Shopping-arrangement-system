#ifndef NEWITEM_H
#define NEWITEM_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Newitem;
}

class Newitem : public QDialog
{
    Q_OBJECT

public:
    explicit Newitem(QWidget *parent = 0);
    ~Newitem();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();
private:
    Ui::Newitem *ui;
    Admin a;
};

#endif // NEWITEM_H
