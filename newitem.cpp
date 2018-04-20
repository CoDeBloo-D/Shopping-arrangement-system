#include "newitem.h"
#include "ui_newitem.h"
#include <QMessageBox>

Newitem::Newitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Newitem)
{
    ui->setupUi(this);
}

Newitem::~Newitem()
{
    delete ui;
}

void Newitem::on_Confirm_clicked()
{
    if(ui->Name->text().isEmpty()||ui->Brand->text().isEmpty()||ui->Price->text().isEmpty()||ui->Numbers->text().isEmpty())
    {
         QMessageBox::information(this,QString("错误"),QString("新商品信息不完整！"));
         return;
    }

    std::string str1=ui->Name->text().toStdString();
    std::string str2=ui->Brand->text().toStdString();
    std::string str3=ui->Price->text().toStdString();
    std::string str4=ui->Numbers->text().toStdString();

    char name[30];
    char brand[30];
    double price;
    int numbers;

    strcpy(name,str1.c_str());
    strcpy(brand,str2.c_str());
    price=atof(str3.c_str());
    numbers=atoi(str4.c_str());

    if(numbers<0)
    {
        QMessageBox::information(this,QString("错误"),QString("商品数目不能为负！"));
        ui->Numbers->clear();
        return;
    }

    if(price<=0)
    {
        QMessageBox::information(this,QString("错误"),QString("商品价格应为正数！"));
        ui->Price->clear();
        return;
    }

    if(a.newItem(Itemhead,name,brand,price,numbers)==true)
    {
        QMessageBox::information(this,QString("提示"),QString("添加新商品成功！"));
        ui->Name->clear();
        ui->Brand->clear();
        ui->Price->clear();
        ui->Numbers->clear();
        close();
    }
}

void Newitem::on_Cancel_clicked()
{
    ui->Name->clear();
    ui->Brand->clear();
    ui->Price->clear();
    ui->Numbers->clear();
    close();
}
