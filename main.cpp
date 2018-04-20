#include "home.h"
#include <QApplication>
#include "file.h"
#include "item.h"
#include "shoppingcart.h"
#include "history.h"
#include "users.h"

struct Item *Itemhead;
struct ShoppingCart *SChead;
struct History *Historyhead;
struct Users *Userhead;

File f;

int main(int argc, char *argv[])
{
    f.readItem(Itemhead);
    f.readHistory(Historyhead);
    f.readUser(Userhead);
    QApplication a(argc, argv);
    Home w;
    w.setWindowTitle("购物系统");
    w.show();

    return a.exec();
}
