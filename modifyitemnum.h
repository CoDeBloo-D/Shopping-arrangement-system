#ifndef MODIFYITEMNUM_H
#define MODIFYITEMNUM_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Modifyitemnum;
}

class Modifyitemnum : public QDialog
{
    Q_OBJECT

public:
    explicit Modifyitemnum(QWidget *parent = 0);
    ~Modifyitemnum();
private slots:
    void on_Confirm_clicked();
    void on_Cancel_clicked();
private:
    Ui::Modifyitemnum *ui;
    Admin a;
};

#endif // MODIFYITEMNUM_H
