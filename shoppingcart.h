#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H
struct ShoppingCart {
    char username[30];//用户名
    char id[8]; //商品编号
    char name[30];//商品名称
    char brand[30];//商品品牌
    double price;//精确到小数点后1位
    int numbers;//购买数量
    ShoppingCart *next;//下一件商品
};

extern struct ShoppingCart *SChead;
#endif // SHOPPINGCART_H
