#ifndef HISTORY_H
#define HISTORY_H
struct History {
    char username[30];//用户名
    char id[8]; //商品编号
    char name[30];//商品名称
    char brand[30];//商品品牌
    double price;//精确到小数点后1位
    int numbers;//售出数量
    History *next;//下一条记录
};

extern struct History *Historyhead;

#endif // HISTORY_H
