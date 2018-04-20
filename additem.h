#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include "user.h"
#include "file.h"

namespace Ui {
class AddItem;
}

class AddItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddItem(QWidget *parent = 0);
    ~AddItem();
public:
    char Username [30];
public slots:
    void Addone();
private slots:
    void on_Cancel_clicked();
private:
    Ui::AddItem *ui;
    User u;
    File f;
};

#endif // ADDITEM_H
