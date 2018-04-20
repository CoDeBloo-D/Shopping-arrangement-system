#ifndef FILE_H
#define FILE_H
#include "Item.h"
#include "ShoppingCart.h"
#include "History.h"
#include "User.h"
#include "Users.h"

class File {
public:
    void readItem(Item *&h);
    void readUser(Users *&h);
    void readShoppingCart(ShoppingCart *&h,char *username);
    void readHistory(History *&h);
    void writeItem(Item *h);
    void writeUser(Users *h);
    void writeShoppingCart(ShoppingCart *h,char *username);
    void writeHistory(History *h);
};

#endif // FILE_H
