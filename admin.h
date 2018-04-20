#ifndef ADMIN_H
#define ADMIN_H
#include "Item.h"
#include "History.h"
#include <QStandardItem>

class Admin {
public:
    int loginAdmin(char *a,char *b);
    void listItem(Item *h, QStandardItemModel *&qitem);
    bool newItem(Item *&h,char *name,char *brand,double price,int num);
    bool deleteItem(Item *&h,char *id);
    bool modifynumItem(Item *&h,char *id,int num);
    bool modifypriceItem(Item *&h,char *id,double price);
    void printHistory(History *h,Item *l,QStandardItemModel *&qitem);
};
#endif // ADMIN_H
