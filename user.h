#ifndef USER_H
#define USER_H

#include "Item.h"
#include "ShoppingCart.h"
#include "History.h"
#include "Users.h"
#include <string>
#include <QStandardItem>

class User {
public:
    bool createUser(Users *&h, char *name, char *password);
    int loginUser(char *a,char *b,Users *h);
    void listItem(Item *h, QStandardItemModel *&qitem);
    void searchItem(Item *h,char Itemname[30], QStandardItemModel *&qitem);
    void searchItembrand(Item *h,char Itembrand[30], QStandardItemModel *&qitem);
    void searchItemvague(Item *h,char Itemword[30], QStandardItemModel *&qitem);
    bool addone(ShoppingCart *&h,Item *l,char id[20],int num,char *a);
    bool deleteone(ShoppingCart *&h,char id[20],int num,char *a);
    void listShoppingCart(ShoppingCart *h,Item *l,QStandardItemModel *&qitem);
    double pay(ShoppingCart *h,Item *k,char *a);
    void createHistory(ShoppingCart *&h, History *&l,Item *&k,char *a);
    void ownHistory(History *h, char *name,QStandardItemModel *&qitem);
    bool changethePassword(Users *&h,char *name,char *nPassword);
};

#endif // USER_H
