#ifndef ITEM_H
#define ITEM_H
struct Item {
    char id[8]; //商品编号
    char name[30];//商品名称
    char brand[30];//商品品牌
    double price;//精确到小数点后1位
    int numbers;//商品存量，-1表示商品下架（不展示），0表示售罄（展示）
    Item *next;//下一件商品
};

extern struct Item *Itemhead;
#endif // ITEM_H
