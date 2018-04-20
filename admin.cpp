#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include "admin.h"
#include <QDebug>
#include <QStandardItem>


int Admin::loginAdmin(char *a,char *b) {
    char name[8]="admin";
    if (!strcmp(a,name)&&!strcmp(b,name))
        return 1;
    else
        return 0;
}

void Admin::listItem(Item *h, QStandardItemModel *&qitem) {
    if (h == NULL) {
        return;
    }
    int line=0;
    for (Item *p = h; p != NULL; p = p->next) {
        if (p->numbers != -1) {
            char price[10];
            char numbers[10];
            sprintf(price, "%.1lf",p->price);
            sprintf(numbers,"%d",p->numbers);
            qitem->setItem(line,0,new QStandardItem(p->id));
            qitem->item(line,0)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(line,1,new QStandardItem(p->name));
            qitem->item(line,1)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(line,2,new QStandardItem(p->brand));
            qitem->item(line,2)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(line,3,new QStandardItem(price));
            qitem->item(line,3)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(line,4,new QStandardItem(numbers));
            qitem->item(line,4)->setTextAlignment(Qt::AlignCenter);
            qitem->item(line, 0)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(line, 1)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(line, 2)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(line, 3)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(line, 4)->setFont( QFont( "Times", 10, QFont::Black));
            line++;
        }
    }
    return;
}

bool Admin::newItem(Item *&h,char *name,char *brand,double price,int num)
{
    Item *p=h;
    if (h == NULL) {
        return false;
    }
    while(p->next!=NULL)
        p=p->next;

    Item *n = new Item;
    char id_ch[7] = {'\0'};

    id_ch[0] = p->id[1];
    id_ch[1] = p->id[2];
    id_ch[2] = p->id[3];
    id_ch[3] = p->id[4];

    id_ch[3] += (int)1;
    if (id_ch[3] == '9'+(int)1) {
        id_ch[3] = '0';
        id_ch[2] = id_ch[2] +1;
        if (id_ch[2] == '9' + (int)1) {
            id_ch[2] = '0';
            id_ch[1] = id_ch[1] +1;
            if (id_ch[1] == '9' + (int)1) {
                id_ch[1] = '0';
                id_ch[0] = id_ch[0] +1;
            }
        }
    }

    char id[10] = {"F"};
    strcat_s(id, id_ch);

    strcpy_s(n->id,id);
    strcpy_s(n->name, name);
    strcpy_s(n->brand, brand);
    n->price = price;
    n->numbers = num;
    p->next = n;
    n->next = NULL;
    return true;
}

bool Admin::deleteItem(Item *&h,char *id) {
    bool flag = false;
    for (Item *p = h; p != NULL; p = p->next) {
        if (!strcmp(p->id, id)) {
            flag = true;
            p->numbers = -1;
            return flag;
        }
    }
    return flag;
}

bool Admin::modifynumItem(Item *&h,char *id,int num)
{
    bool flag=false;
    for (Item *p = h; p != NULL; p = p->next) {
        if (!strcmp(p->id, id)) {
            flag = true;
            p->numbers = num;
            return flag;
        }
    }
    return flag;
}

bool Admin::modifypriceItem(Item *&h,char *id,double price)
{
    bool flag = false;
    for (Item *p = h; p != NULL; p = p->next) {
        if (!strcmp(p->id, id)) {
            flag = true;
            p->price = price;
            return flag;
        }
    }
    return flag;
}
void Admin::printHistory(History *h,Item *l,QStandardItemModel *&qitem) {
    if (h == NULL) {
        return;
    }

    double price[30];//记载同一商品的不同价格
    int num[30];     //对不同的价格，分别计算售出的数目
    int cnt;
    int line=0;
    for (Item *q = l; q != NULL; q = q->next) {
        for (int i = 0; i < 30; i++) {
            num[i] = 0;
            price[i] = 0;
        }
        cnt = 0;//清零
        price[0] = q->price;//优先展示当前价格的历史记录,历史价格的历史记录按次序排列

        for (History *p = h; p != NULL; p = p->next) {
            if (!strcmp(q->id, p->id)) {
                if (fabs(price[0] - p->price) < 0.00001)
                    num[0] += p->numbers;

                if(fabs(price[0] - p->price) > 0.00001){
                    bool flag = false;
                    if (cnt == 0) {
                        cnt=1;
                        num[1] = p->numbers;
                        price[1] = p->price;
                    }

                    else {
                        for (int j = 1; j <= cnt; j++) {
                            if (fabs(price[j] - p->price) < 0.00001) {
                                num[j] += p->numbers;
                                flag = true;
                                break;
                            }
                            if (cnt == 1) break;
                        }
                        if(!flag) {
                                cnt=cnt+1;
                                num[cnt] += p->numbers;
                                price[cnt] = p->price;
                        }

                    }
                }
            }
        }

        for (int k = 0; k <= cnt; k++) {
            if (num[k] != 0) {
                char price_s[10];
                char numbers[10];
                sprintf(price_s, "%.1lf",price[k]);
                sprintf(numbers,"%d",num[k]);
                qitem->setItem(line,0,new QStandardItem(q->id));
                qitem->item(line,0)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(line,1,new QStandardItem(q->name));
                qitem->item(line,1)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(line,2,new QStandardItem(q->brand));
                qitem->item(line,2)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(line,3,new QStandardItem(price_s));
                qitem->item(line,3)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(line,4,new QStandardItem(numbers));
                qitem->item(line,4)->setTextAlignment(Qt::AlignCenter);
                qitem->item(line, 0)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(line, 1)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(line, 2)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(line, 3)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(line, 4)->setFont( QFont( "Times", 10, QFont::Black));
                line++;
            }
        }
    }
    return;
}
