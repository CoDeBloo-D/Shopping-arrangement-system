#include "modifyitemnum.h"
#include "ui_modifyitemnum.h"
#include <QMessageBox>

Modifyitemnum::Modifyitemnum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modifyitemnum)
{
    ui->setupUi(this);
}

Modifyitemnum::~Modifyitemnum()
{
    delete ui;
}

void Modifyitemnum::on_Confirm_clicked()
{
    if(ui->ID->text().isEmpty()||ui->Num->text().isEmpty())
    {
         QMessageBox::information(this,QString("错误"),QString("信息不全！"));
         return;
    }

    std::string str1=ui->ID->text().toStdString();
    std::string str2=ui->Num->text().toStdString();

    char id[20];
    int num;

    strcpy(id,str1.c_str());
    num=atoi(str2.c_str());

    if(num<0)
    {
        QMessageBox::information(this,QString("错误"),QString("商品数目不能为负！"));
        ui->Num->clear();
        return;
    }

    if(a.deleteItem(Itemhead,id)==true)
    {
        QMessageBox::information(this,QString("提示"),QString("修改商品数量成功！"));
        ui->ID->clear();
        ui->Num->clear();
        close();
    }

    else if(a.deleteItem(Itemhead,id)==false)
    {
        QMessageBox::information(this,QString("错误"),QString("修改商品数量失败！"));
        ui->ID->clear();
        ui->Num->clear();
        return;
    }
}

void Modifyitemnum::on_Cancel_clicked()
{
    ui->ID->clear();
    close();
}
