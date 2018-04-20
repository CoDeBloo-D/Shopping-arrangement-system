#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QDialog>
#include "user.h"
#include "file.h"

namespace Ui {
class DeleteItem;
}

class DeleteItem : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteItem(QWidget *parent = 0);
    ~DeleteItem();
public:
    char Username [30];
public slots:
    void Deleteone();
private slots:
    void on_Cancel_clicked();
private:
    Ui::DeleteItem *ui;
    User u;
    File f;
};

#endif // DELETEITEM_H
