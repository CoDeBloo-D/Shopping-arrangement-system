#include "offitem.h"
#include "ui_offitem.h"
#include <QMessageBox>

Offitem::Offitem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Offitem)
{
    ui->setupUi(this);
}

Offitem::~Offitem()
{
    delete ui;
}

void Offitem::on_Confirm_clicked()
{
    if(ui->ID->text().isEmpty())
    {
         QMessageBox::information(this,QString("错误"),QString("未填写商品ID！"));
         return;
    }

    std::string str1=ui->ID->text().toStdString();

    char id[20];

    strcpy(id,str1.c_str());

    if(a.deleteItem(Itemhead,id)==true)
    {
        QMessageBox::information(this,QString("提示"),QString("下架商品成功！"));
        ui->ID->clear();
        close();
    }

    else if(a.deleteItem(Itemhead,id)==false)
    {
        QMessageBox::information(this,QString("提示"),QString("下架商品失败！"));
        ui->ID->clear();
        return;
    }
}

void Offitem::on_Cancel_clicked()
{
    ui->ID->clear();
    close();
}
