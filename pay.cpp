#include "pay.h"
#include "ui_pay.h"
#include <QMessageBox>
#include <cmath>
#include <string>

Pay::Pay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pay)
{
    ui->setupUi(this);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(Paythebill()));
    ui->Summary->setFont(QFont("微软雅黑", 15, QFont::Black));
}

Pay::~Pay()
{
    delete ui;
}
void Pay::getthesum()
{
    double summary=u.pay(SChead,Itemhead,Username);
    char mid[30];
    sprintf(mid,"%.1lf",summary);
    ui->Summary->setText(mid);
}

void Pay::Paythebill()
{
    if(fabs(u.pay(SChead,Itemhead,Username))>1E-7)
    {
        u.createHistory(SChead,Historyhead,Itemhead,Username);
        QMessageBox::information(this,QString("提示"),QString("交易成功！"));
        f.writeHistory(Historyhead);
        f.writeShoppingCart(SChead,Username);
        f.writeItem(Itemhead);
        ui->Summary->clear();
        close();
    }
    else
    {
        QMessageBox::information(this,QString("错误"),QString("没有有效的记录！请返回添加有效的记录！"));
        close();
    }
}
void Pay::on_Cancel_clicked()
{
    ui->Summary->clear();
    close();
}
