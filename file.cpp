#include "file.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <QDebug>

void File::readItem(Item *&h) {
    FILE *fp;
    fp = fopen("D:\\Qt_Projects\\Project1_Advanced\\src\\store.txt", "r");
    if (fp == NULL) {
        qDebug() << "无效文件！";
        exit(-1);
    }
    char buf[100] = { '\0' };

    fgets(buf, 100, fp);//用来读取掉第一行
    char id[8];
    char name[30];
    char brand[30];
    double price;
    int num;

    while (fscanf(fp, "%s", &id)!=EOF) {
        fscanf(fp, "%s", &name);
        fscanf(fp, "%s", &brand);
        fscanf(fp, "%lf", &price);
        fscanf(fp, "%d", &num);
        Item *n = new Item;
        strcpy(n->id, id);
        strcpy(n->name, name);
        strcpy(n->brand, brand);
        n->price = price;
        n->numbers = num;
        n->next = NULL;
        if (h == NULL)
            h = n;
        else {
            Item *p = h;
            while (p->next != NULL)
                p = p->next;
            p->next = n;
        }
    }
    fclose(fp);

}

void File::readUser(Users *&h) {
    FILE *fp;
    fp = fopen("D:\\Qt_Projects\\Project1_Advanced\\src\\userdata.txt", "r");
    if (fp == NULL) {
        qDebug() << "无效文件！";
        exit(-1);
    }
    char buf[100] = { '\0' };

    fgets(buf, 100, fp);//用来读取掉第一行
    char username[30];
    char password[30];
    while (fscanf(fp, "%s", &username) != EOF) {
        fscanf(fp, "%s", &password);
        Users *n = new Users;
        strcpy(n->username, username);
        strcpy(n->password, password);
        n->next = NULL;
        if (h == NULL)
            h = n;
        else {
            Users *p = h;
            while (p->next != NULL)
                p = p->next;
            p->next = n;
        }
    }
    fclose(fp);
}

void File::readShoppingCart(ShoppingCart *&h,char *username) {    //读取对应用户的购物车，在查看购物车的同时读取

    if(h!=NULL)
    {
        while(h!=NULL)
        {
            ShoppingCart *del=new ShoppingCart;
            del=h;
            h=h->next;
            delete del;
        }
    }

    FILE *fp;
    char link[100] = "D:\\Qt_Projects\\Project1_Advanced\\src\\";
    char txt[10] = ".txt\0";
    strcat_s(link, username);
    strcat_s(link, txt);

    fp = fopen(link, "r");//此处可能需要调整

    if (fp == NULL) {
        qDebug() << "无效文件！";
        exit(-1);
    }
    char buf[100] = { '\0' };

    fgets(buf,100, fp);//用来读取掉第一行
    char id[8];
    char name[30];
    char brand[30];
    double price;
    int num;

    while (fscanf(fp, "%s", id) != EOF) {
        fscanf(fp,"%s",&name);
        fscanf(fp,"%s",&brand);
        fscanf(fp,"%lf",&price);
        fscanf(fp,"%d",&num);
        //cout << id << "\t" << name << "\t" << brand << "\t" << price << "\t" << num << endl;
        ShoppingCart *n = new ShoppingCart;
        strcpy(n->id, id);
        strcpy(n->name, name);
        strcpy(n->brand, brand);
        n->price = price;
        n->numbers = num;
        strcpy(n->username, username);
        n->next = NULL;

        if (h == NULL)
            h = n;
        else {
            ShoppingCart *p = h;
            while (p->next != NULL)
                p = p->next;
            p->next = n;
        }

    }
    fclose(fp);
}

void File::readHistory(History *&h) {
    FILE *fp;
    fp = fopen("D:\\Qt_Projects\\Project1_Advanced\\src\\historylist.txt", "r");

    char buf[100] = { '\0' };//用来读取掉第一行
    fgets(buf, 100, fp);
    char id[8];
    char name[30];
    char brand[30];
    double price;
    int num;
    char username[30];

    while (fscanf(fp, "%s", id) != EOF) {
        fscanf(fp, "%s", name);
        fscanf(fp, "%s", brand);
        fscanf(fp, "%lf", &price);
        fscanf(fp, "%d", &num);
        fscanf(fp, "%s", &username);
        History *n = new History;
        strcpy(n->id, id);
        strcpy(n->name, name);
        strcpy(n->brand, brand);
        n->price = price;
        n->numbers = num;
        strcpy(n->username, username);
        n->next = NULL;
        if (h == NULL)
            h = n;
        else {
            History *p = h;
            while (p->next != NULL)
                p = p->next;
            p->next = n;
        }

    }
    fclose(fp);
}

void File::writeItem(Item *h) {
    FILE *fp;
    fp=fopen("D:\\Qt_Projects\\Project1_Advanced\\src\\store.txt", "w");
    fputs("ID\t名称\t品牌\t价格\t数量\n",fp);
    for (Item *p = h; p != NULL; p = p->next)
        fprintf(fp, "%s\t%s\t%s\t%.1lf\t%d\n", p->id, p->name, p->brand, p->price, p->numbers);
    fclose(fp);
}

void File::writeUser(Users *h) {
    FILE *fp;
    fp=fopen("D:\\Qt_Projects\\Project1_Advanced\\src\\userdata.txt", "w");
    fputs("用户名\t密码\n", fp);
    for (Users *p = h; p != NULL; p = p->next)
        fprintf(fp, "%s\t%s\n", p->username, p->password);
    fclose(fp);
}

void File::writeShoppingCart(ShoppingCart *h,char *username) {
    FILE *fp;
    char link[50] = "D:\\Qt_Projects\\Project1_Advanced\\src\\";
    char txt[10] = ".txt";
    strcat_s(link, username);
    strcat_s(link, txt);
    fp = fopen(link, "w");//此处可能需要调整
    fputs("ID\t名称\t品牌\t价格\t数量\n", fp);
    for (ShoppingCart *p = h; p != NULL; p = p->next)
        fprintf(fp, "%s\t%s\t%s\t%.1lf\t%d\n", p->id, p->name, p->brand, p->price, p->numbers);
    fclose(fp);

}

void File::writeHistory(History *h) {
    FILE *fp;
    fp = fopen("D:\\Qt_Projects\\Project1_Advanced\\src\\historylist.txt", "w");
    fputs("ID\t名称\t品牌\t价格\t数量\t用户名\n",fp);
    for (History *p = h; p != NULL; p = p->next)
        fprintf(fp, "%s\t%s\t%s\t%.1lf\t%d\t%s\n", p->id, p->name, p->brand, p->price, p->numbers,p->username);
    fclose(fp);
}
