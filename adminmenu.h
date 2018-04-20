#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>
#include "admin.h"
#include "file.h"
#include "newitem.h"
#include "offitem.h"
#include "modifyitemnum.h"
#include "modifyitemprice.h"

namespace Ui {
class Adminmenu;
}

class Adminmenu : public QDialog
{
    Q_OBJECT

public:
    explicit Adminmenu(QWidget *parent = 0);
    ~Adminmenu();
public slots:
    void xytimerUpDate();
    void listItem();
    void listHistory();
    void newItem();
    void offItem();
    void mItemnum();
    void mItemprice();
signals:
    void adminmenuclose();
private slots:
    void on_Button0_clicked();
private:
    Ui::Adminmenu *ui;
    Admin a;
    File f;
    Newitem nItem;
    Offitem oItem;
    Modifyitemnum mIn;
    Modifyitemprice mIp;
};

#endif // ADMINMENU_H
