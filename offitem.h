#ifndef OFFITEM_H
#define OFFITEM_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Offitem;
}

class Offitem : public QDialog
{
    Q_OBJECT

public:
    explicit Offitem(QWidget *parent = 0);
    ~Offitem();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();
private:
    Ui::Offitem *ui;
    Admin a;
};

#endif // OFFITEM_H
