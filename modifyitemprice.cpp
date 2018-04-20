#include "modifyitemprice.h"
#include "ui_modifyitemprice.h"
#include <QMessageBox>

Modifyitemprice::Modifyitemprice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifyitemprice)
{
    ui->setupUi(this);
}

Modifyitemprice::~Modifyitemprice()
{
    delete ui;
}

void Modifyitemprice::on_Confirm_clicked()
{
    if(ui->ID->text().isEmpty()||ui->Price->text().isEmpty())
    {
         QMessageBox::information(this,QString("错误"),QString("信息不全！"));
         return;
    }

    std::string str1=ui->ID->text().toStdString();
    std::string str2=ui->Price->text().toStdString();

    char id[20];
    double price;

    strcpy(id,str1.c_str());
    price=atof(str2.c_str());

    if(price<=0)
    {
        QMessageBox::information(this,QString("错误"),QString("商品价格应为正数！"));
        ui->Price->clear();
        return;
    }

    if(a.modifypriceItem(Itemhead,id,price)==true)
    {
        QMessageBox::information(this,QString("提示"),QString("修改商品价格成功！"));
        ui->ID->clear();
        ui->Price->clear();
        close();
    }

    else if(a.modifypriceItem(Itemhead,id,price)==false)
    {
        QMessageBox::information(this,QString("错误"),QString("修改商品价格失败！"));
        ui->ID->clear();
        ui->Price->clear();
        return;
    }
}

void Modifyitemprice::on_Cancel_clicked()
{
    ui->ID->clear();
    ui->Price->clear();
    close();
}
