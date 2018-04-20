#include "deleteitem.h"
#include "ui_deleteitem.h"
#include <QMessageBox>

DeleteItem::DeleteItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteItem)
{
    ui->setupUi(this);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(Deleteone()));
}

DeleteItem::~DeleteItem()
{
    delete ui;
}

void DeleteItem::Deleteone()
{
    f.readShoppingCart(SChead,Username);
    if(SChead==NULL)
    {
        QMessageBox::information(this,QString("错误"),QString("购物车内没有商品，无法删除！"));
        close();
    }
    if(ui->ID->text().isEmpty()||ui->Num->text().isEmpty())
    {
        QMessageBox::information(this,QString("错误"),QString("信息不全！"));
        return;
    }
    QString strid=ui->ID->text();
    QString Number=ui->Num->text();
    std::string str = strid.toStdString();
    std::string strnum=Number.toStdString();
    char ID[20];
    int num;
    //qDebug
    strcpy(ID,str.c_str());
    num=atoi(strnum.c_str());
    if(u.deleteone(SChead,ID,num,Username))
    {
        f.writeShoppingCart(SChead,Username);
        ui->ID->clear();
        ui->Num->clear();
        close();
    }
    else
    {
        QMessageBox::information(this,QString("错误"),QString("未找到商品或者购物车中该商品数量不足！"));
        ui->ID->clear();
        ui->Num->clear();
        ui->ID->setFocus();
    }
}

void DeleteItem::on_Cancel_clicked()
{
    ui->ID->clear();
    ui->Num->clear();
    close();
}
