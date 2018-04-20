#include "userlogin.h"
#include "ui_userlogin.h"
#include "shoppingcart.h"
#include <string>
#include <QMessageBox>

Userlogin::Userlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Userlogin)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
}

Userlogin::~Userlogin()
{
    delete ui;
}

void Userlogin::on_Confirm_clicked()
{
    std::string str1=ui->Username->text().toStdString();
    std::string str2=ui->Password->text().toStdString();
    char Username[30];
    char Password[30];

    strcpy(Username,str1.c_str());
    strcpy(Password,str2.c_str());

    if(u.loginUser(Username,Password,Userhead)==1)
    {
        emit openusermenu(ui->Username->text());
        ui->Username->clear();
        ui->Password->clear();
        f.readShoppingCart(SChead,Username);
        close();
    }
    else
    {
        ui->Username->clear();
        ui->Password->clear();
        QMessageBox::information(this,QString("登录失败"),QString("请重试"));
        ui->Username->setFocus();
    }

}

void Userlogin::on_Cancel_clicked()
{
    ui->Username->clear();
    ui->Password->clear();
    emit userloginclose();
    close();
}
