#include "user.h"
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <conio.h>
#include <cstring>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItem>

bool User::createUser(Users *&h,char *name,char *password)
{
    for(Users *q=h;q!=NULL;q=q->next)
    {
        if(!strcmp(q->username,name))
            return false;
    }


    Users *p = h;
    while (p->next != NULL)
        p = p->next;
    Users *n = new Users;
    strcpy_s(n->username, name);
    strcpy_s(n->password, password);
    p->next = n;
    n->next = NULL;
    return true;
}

int User::loginUser(char *a,char *b,Users *h)
{
    bool flag = false;
    for (Users *p = h; p != NULL; p = p->next) {
        if (!strcmp(a, p->username) && !strcmp(b, p->password)) {
            flag = true;
            return 1;
        }
    }
    return 0;
}

void User::listItem(Item *h, QStandardItemModel *&qitem)
{
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

void User::searchItem(Item *h,char Itemname[30], QStandardItemModel *&qitem)
{
    int cnt=0;
    for (Item *p = h; p != NULL; p = p->next) {
        if (strcmp(Itemname, p->name)==0) {
            if (p->numbers != -1) {
                char price[10];
                char numbers[10];
                sprintf(price, "%.1lf",p->price);
                sprintf(numbers,"%d",p->numbers);
                qitem->setItem(cnt,0,new QStandardItem(p->id));
                qitem->item(cnt,0)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,1,new QStandardItem(p->name));
                qitem->item(cnt,1)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,2,new QStandardItem(p->brand));
                qitem->item(cnt,2)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,3,new QStandardItem(price));
                qitem->item(cnt,3)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,4,new QStandardItem(numbers));
                qitem->item(cnt,4)->setTextAlignment(Qt::AlignCenter);
                qitem->item(cnt, 0)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 1)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 2)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 3)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 4)->setFont( QFont( "Times", 10, QFont::Black));
                cnt++;
            }
        }
    }
    return;
}

void User::searchItembrand(Item *h,char Itembrand[30], QStandardItemModel *&qitem)
{
    int cnt=0;
    for (Item *p = h; p != NULL; p = p->next) {
        if (strcmp(Itembrand, p->brand)==0) {
            if (p->numbers != -1) {
                char price[10];
                char numbers[10];
                sprintf(price, "%.1lf",p->price);
                sprintf(numbers,"%d",p->numbers);
                qitem->setItem(cnt,0,new QStandardItem(p->id));
                qitem->item(cnt,0)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,1,new QStandardItem(p->name));
                qitem->item(cnt,1)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,2,new QStandardItem(p->brand));
                qitem->item(cnt,2)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,3,new QStandardItem(price));
                qitem->item(cnt,3)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,4,new QStandardItem(numbers));
                qitem->item(cnt,4)->setTextAlignment(Qt::AlignCenter);
                qitem->item(cnt, 0)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 1)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 2)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 3)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 4)->setFont( QFont( "Times", 10, QFont::Black));
                cnt++;
            }
        }
    }
    return;
}

void User::searchItemvague(Item *h,char Itemword[30], QStandardItemModel *&qitem)
{
    int cnt=0;
    for (Item *p = h; p != NULL; p = p->next) {
        if (strstr(p->name,Itemword)!=NULL||strstr(p->brand,Itemword)!=NULL) {
            if (p->numbers != -1) {
                char price[10];
                char numbers[10];
                sprintf(price, "%.1lf",p->price);
                sprintf(numbers,"%d",p->numbers);
                qitem->setItem(cnt,0,new QStandardItem(p->id));
                qitem->item(cnt,0)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,1,new QStandardItem(p->name));
                qitem->item(cnt,1)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,2,new QStandardItem(p->brand));
                qitem->item(cnt,2)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,3,new QStandardItem(price));
                qitem->item(cnt,3)->setTextAlignment(Qt::AlignCenter);
                qitem->setItem(cnt,4,new QStandardItem(numbers));
                qitem->item(cnt,4)->setTextAlignment(Qt::AlignCenter);
                qitem->item(cnt, 0)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 1)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 2)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 3)->setFont( QFont( "Times", 10, QFont::Black));
                qitem->item(cnt, 4)->setFont( QFont( "Times", 10, QFont::Black));
                cnt++;
            }
        }
    }
    return;
}

bool User::addone(ShoppingCart *&h,Item *l,char id[20],int num,char *a)
{
    bool flag = false;

    for (Item *p = l; p != NULL; p = p->next) {
        if (!strcmp(id, p->id) && p->numbers >= num) {
            flag = true;
            for(ShoppingCart *search=h;search!=NULL;search=search->next)
            {
                if(!strcmp(search->id,id))
                {
                    search->numbers+=num;
                    return flag;
                }
            }
            ShoppingCart *n = new ShoppingCart;
            strcpy_s(n->username, a);
            strcpy_s(n->id, p->id);
            strcpy_s(n->name, p->name);
            strcpy_s(n->brand, p->brand);
            n->price = p->price;
            n->numbers = num;
            n->next = NULL;
            if (h == NULL)
                h = n;
            else {
                ShoppingCart *q = h;
                while (q->next != NULL)
                    q = q->next;
                q->next = n;
            }
            return flag;
        }
        else if (!strcmp(id, p->id) && p->numbers < num) {
            return flag;
        }
    }
}

bool User::deleteone(ShoppingCart *&h,char id[20],int num,char *a)
{
    bool flag = false;

    ShoppingCart *left = h;
    ShoppingCart *now = h->next;
    int n = 1;

    for (ShoppingCart *p = h; p != NULL; p = p->next) {
        if (!strcmp(id, p->id)&&p->numbers>=num) {
            flag = true;
            break;
        }
        n++;
    }
    if(!flag)
        return flag;
    if (n == 1&&now!=NULL)
    {
        if(left->numbers==num)
        {
            strcpy_s(left->username, now->username);
            strcpy_s(left->id, now->id);
            strcpy_s(left->name, now->name);
            strcpy_s(left->brand, now->brand);
            left->price = now->price;
            left->numbers =now->numbers;
            left->next = now->next;
            now = NULL;
            delete now;
            return flag;
        }
        else if(left->numbers>num)
        {
            left->numbers-=num;
            return flag;
        }
    }
    else if (n == 1&&now==NULL) {
        if(h->numbers==num)
        {
            h = NULL;
            return flag;
        }
        else if(h->numbers>num)
        {
            h->numbers-=num;
            h->next=NULL;
            return flag;
        }
    }

    if(n==2&&now->next==NULL)
    {
        if(now->numbers==num)
        {
            left->next=NULL;
            delete now;
            return flag;
        }
        else if(now->numbers>num)
        {
            now->numbers-=num;
            return flag;
        }
    }

    if(n==2&&now->next!=NULL)
    {
        if(now->numbers==num)
        {
            left->next=now->next;
            delete now;
            return flag;
        }
        else if(now->numbers>num)
        {
            now->numbers-=num;
            return flag;
        }
    }

    for (int i = 2; i < n && now->next != NULL; i++) {
        left = now;
        now = left->next;
    }

    if(now->numbers==num)
    {
        left->next = now->next;
        now = NULL;
        delete now;
        return flag;
    }
    else if(now->numbers>num)
    {
        now->numbers-=num;
        return flag;
    }

    return flag;
}

void User::listShoppingCart(ShoppingCart *h, Item *l, QStandardItemModel *&qitem)
{
    if (h == NULL) {
        return;
    }

    int cnt=0;
    for (ShoppingCart *p = h; p != NULL; p = p->next) {
        bool flag = false;
        for (Item *k = l; k != NULL; k = k->next) {
            if (!strcmp(p->id, k->id) && fabs(k->price - p->price) > 0.00001) {
                flag = true;
                p->price = k->price;
            }
        }
        char price[10];
        char numbers[10];
        sprintf(price, "%.1lf",p->price);
        sprintf(numbers,"%d",p->numbers);
        qitem->setItem(cnt,0,new QStandardItem(p->id));
        qitem->item(cnt,0)->setTextAlignment(Qt::AlignCenter);
        qitem->setItem(cnt,1,new QStandardItem(p->name));
        qitem->item(cnt,1)->setTextAlignment(Qt::AlignCenter);
        qitem->setItem(cnt,2,new QStandardItem(p->brand));
        qitem->item(cnt,2)->setTextAlignment(Qt::AlignCenter);
        qitem->setItem(cnt,3,new QStandardItem(price));
        qitem->item(cnt,3)->setTextAlignment(Qt::AlignCenter);
        qitem->setItem(cnt,4,new QStandardItem(numbers));
        qitem->item(cnt,4)->setTextAlignment(Qt::AlignCenter);
        qitem->item(cnt, 0)->setFont( QFont( "Times", 10, QFont::Black));
        qitem->item(cnt, 1)->setFont( QFont( "Times", 10, QFont::Black));
        qitem->item(cnt, 2)->setFont( QFont( "Times", 10, QFont::Black));
        qitem->item(cnt, 3)->setFont( QFont( "Times", 10, QFont::Black));
        qitem->item(cnt, 4)->setFont( QFont( "Times", 10, QFont::Black));
        for (Item *k = l; k != NULL; k = k->next) {
            if (!strcmp(p->id, k->id) && p->numbers > k->numbers) {
                qitem->setItem(cnt,5,new QStandardItem("本条记录已失效"));
                qitem->item(cnt,5)->setTextAlignment(Qt::AlignCenter);
                qitem->item(cnt,5)->setForeground(QBrush(QColor(255, 0, 0)));
                qitem->item(cnt,5)->setFont( QFont( "Times", 10, QFont::Black));
            }
            if (!strcmp(p->id, k->id) && p->numbers <= k->numbers) {
                qitem->setItem(cnt,5,new QStandardItem(" "));
                qitem->item(cnt,5)->setTextAlignment(Qt::AlignCenter);
            }
            if (!strcmp(p->id, k->id) && flag) {
                qitem->setItem(cnt,6,new QStandardItem("价格与添加时不同"));
                qitem->item(cnt,6)->setTextAlignment(Qt::AlignCenter);
                qitem->item(cnt,6)->setForeground(QBrush(QColor(255, 0, 0)));
                qitem->item(cnt,6)->setFont( QFont( "Times", 10, QFont::Black));
            }
            if (!strcmp(p->id, k->id) && !flag) {
                qitem->setItem(cnt,6,new QStandardItem(" "));
                qitem->item(cnt,6)->setTextAlignment(Qt::AlignCenter);
            }
        }
        cnt++;
    }
    return;
}

double User::pay(ShoppingCart *h,Item *k,char *a)
{
    double sum=0;
    for (ShoppingCart *p = h; p != NULL; p = p->next) {
        for (Item *r = k; r != NULL; r = r->next) {
            if (strcmp(p->id, r->id)==0)
                if(p->numbers<=r->numbers)
                    sum += p->price*p->numbers;
        }
    }

    return sum;
}

void User::createHistory(ShoppingCart *&h, History *&l,Item *&k,char *a)
{
    for (ShoppingCart *p = h; p != NULL; p = p->next)
    {
        for (Item *o = k; o != NULL; o = o->next)
        {
                if (!strcmp(o->id, p->id) && p->numbers <= o->numbers)
                {
                    o->numbers -= p->numbers;
                    History *n = new History;
                    strcpy_s(n->id, p->id);
                    strcpy_s(n->name, p->name);
                    strcpy_s(n->brand, p->brand);
                    strcpy_s(n->username, a);
                    n->price = p->price;
                    n->numbers = p->numbers;
                    n->next = NULL;
                    if (l == NULL)
                        l = n;
                    else
                    {
                        History *q = l;
                        while (q->next != NULL)
                            q = q->next;
                        q->next = n;
                    }
                }
        }
    }

    while (h!=NULL)
    {
        ShoppingCart *del = new ShoppingCart;
        del = h;
        h = h->next;
        delete del;
    }
    return;
}

void User::ownHistory(History *h, char *name,QStandardItemModel *&qitem)
{
    int cnt=0;
    for (History *p = h; p!= NULL; p = p->next) {
        if (strcmp(name,p->username)==0)
        {
            char price[10];
            char numbers[10];
            sprintf(price, "%.1lf",p->price);
            sprintf(numbers,"%d",p->numbers);
            qitem->setItem(cnt,0,new QStandardItem(p->id));
            qitem->item(cnt,0)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(cnt,1,new QStandardItem(p->name));
            qitem->item(cnt,1)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(cnt,2,new QStandardItem(p->brand));
            qitem->item(cnt,2)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(cnt,3,new QStandardItem(price));
            qitem->item(cnt,3)->setTextAlignment(Qt::AlignCenter);
            qitem->setItem(cnt,4,new QStandardItem(numbers));
            qitem->item(cnt,4)->setTextAlignment(Qt::AlignCenter);
            qitem->item(cnt, 0)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(cnt, 1)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(cnt, 2)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(cnt, 3)->setFont( QFont( "Times", 10, QFont::Black));
            qitem->item(cnt, 4)->setFont( QFont( "Times", 10, QFont::Black));
            cnt++;
        }
    }
}

bool User::changethePassword(Users *&h,char *name,char *nPassword)
 {

     for(Users *p=Userhead;p!=NULL;p=p->next)
     {
         if(!strcmp(p->username,name))
         {
             if(strcmp(p->password,nPassword)!=0)
             {
                 strcpy(p->password,nPassword);
                 return true;
             }
             else
                 return false;
         }
     }
 }
