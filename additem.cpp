#include "additem.h"
#include "ui_additem.h"
#include <QMessageBox>

AddItem::AddItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItem)
{
    ui->setupUi(this);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(Addone()));
}

AddItem::~AddItem()
{
    delete ui;
}

void AddItem::Addone()
{
    f.readShoppingCart(SChead,Username);
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
    if(u.addone(SChead,Itemhead,ID,num,Username))
    {
        f.writeShoppingCart(SChead,Username);
        ui->ID->clear();
        ui->Num->clear();
        close();
    }
    else
    {
        QMessageBox::information(this,QString("错误"),QString("未找到商品或者商品存货不足！"));
        ui->ID->clear();
        ui->Num->clear();
        ui->ID->setFocus();
    }
}

void AddItem::on_Cancel_clicked()
{
    ui->ID->clear();
    ui->Num->clear();
    close();
}
