#ifndef USERMENU_H
#define USERMENU_H

#include <QDialog>
#include "user.h"
#include "file.h"
#include <QStandardItem>
#include "searchitemname.h"
#include "searchitembrand.h"
#include "searchitemvague.h"
#include "additem.h"
#include "deleteitem.h"
#include "pay.h"
#include "changepassword.h"

namespace Ui {
class Usermenu;
}

class Usermenu : public QDialog
{
    Q_OBJECT

public:
    explicit Usermenu(QWidget *parent = 0);
    ~Usermenu();
signals:
    void usermenuclose();
public slots:
    void xytimerUpDate();
    void listItem();
    void listShoppingCart();
    void getitemname(QString name);
    void searchItemname();
    void getitembrand(QString brand);
    void searchItembrand();
    void getitemvague(QString word);
    void searchItemvague();
    void addone();
    void deleteone();
    void pay();
    void refreshHistory();
    void changemypassword();
public:
    char Username[30];
private slots:
    void on_Button0_clicked();
private:
    Ui::Usermenu *ui;
    User u;
    File f;
    SearchItemname sIname;
    SearchItembrand sIbrand;
    SearchItemvague sIvague;
    AddItem aI;
    DeleteItem dI;
    Pay pa;
    changepassword ch;
    char Itemname[30];
    char Itembrand[30];
    char Itemmessage[30];
};

#endif // USERMENU_H
