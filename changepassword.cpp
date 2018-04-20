#include "changepassword.h"
#include "ui_changepassword.h"
#include "users.h"
#include "user.h"
#include <QMessageBox>

changepassword::changepassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changepassword)
{
    ui->setupUi(this);
    ui->newPassword->setEchoMode(QLineEdit::Password);
    ui->confirmPassword->setEchoMode(QLineEdit::Password);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(change()));
}

changepassword::~changepassword()
{
    delete ui;
}

void changepassword::change()
{
    if(ui->newPassword->text().isEmpty()||ui->confirmPassword->text().isEmpty())
    {
         QMessageBox::information(this,QString("错误"),QString("没有输入新密码或没有确认新密码！"));
         return;
    }
    QString str1=ui->newPassword->text();
    std::string nstr = str1.toStdString();
    char nPassword[30];
    strcpy(nPassword,nstr.c_str());
    QString str2=ui->confirmPassword->text();
    std::string cstr = str2.toStdString();
    char cPassword[30];
    strcpy(cPassword,cstr.c_str());

    if(strcmp(nPassword,cPassword)!=0)
    {
        QMessageBox::information(this,QString("错误"),QString("两次输入的密码不一致！"));
        ui->newPassword->clear();
        ui->confirmPassword->clear();
        return;
    }

    if(u.changethePassword(Userhead,Username,nPassword)==true)
    {
        QMessageBox::information(this,QString("提示"),QString("修改成功！"));
        f.writeUser(Userhead);
        ui->newPassword->clear();
        ui->confirmPassword->clear();
        close();
    }

    else if(u.changethePassword(Userhead,Username,nPassword)==false)
    {
        QMessageBox::information(this,QString("错误"),QString("与您的原密码一致！"));
        ui->newPassword->clear();
        ui->confirmPassword->clear();
        return;
    }
}


void changepassword::on_Cancel_clicked()
{
    ui->newPassword->clear();
    ui->confirmPassword->clear();
    close();
}
