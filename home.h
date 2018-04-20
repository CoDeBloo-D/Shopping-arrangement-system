#ifndef HOME_H
#define HOME_H

#include <QMainWindow>
#include "userlogin.h"
#include "usercreate.h"
#include "usermenu.h"
#include "adminlogin.h"
#include "adminmenu.h"
#include <QtCore>

namespace Ui {
class Home;
}

class Home : public QMainWindow
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = 0);
    ~Home();
public slots:
    void userlogin();
    void usercreate();
    void enterusermenu(QString name);
    void adminlogin();
    void enteradminmenu();
    void reshow();
    void xytimerUpDate();
private:
    Ui::Home *ui;
    Userlogin ulogin;
    Usercreate ucre;
    Usermenu menu1;
    Adminlogin alogin;
    Adminmenu menu2;
};

#endif // HOME_H
