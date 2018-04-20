#ifndef USERS_H
#define USERS_H

struct Users {
    char username[30];//用户名
    char password[30];//密码
    Users *next;
};

extern struct Users *Userhead;
#endif // USERS_H
