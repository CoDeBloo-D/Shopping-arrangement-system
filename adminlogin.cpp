#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "admin.h"
#include <QMessageBox>

Adminlogin::Adminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminlogin)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
    ui->Confirm->setFocus();
}

Adminlogin::~Adminlogin()
{
    delete ui;
}

void Adminlogin::on_Confirm_clicked()
{
    std::string str1=ui->Username->text().toStdString();
    std::string str2=ui->Password->text().toStdString();
    char Username[30];
    char Password[30];

    strcpy(Username,str1.c_str());
    strcpy(Password,str2.c_str());

    if(a.loginAdmin(Username,Password)==1)
    {
        emit openadminmenu();
        ui->Username->clear();
        ui->Password->clear();
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

void Adminlogin::on_Cancel_clicked()
{
    ui->Username->clear();
    ui->Password->clear();
    emit adminloginclose();
    close();
}
