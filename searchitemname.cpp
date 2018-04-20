#include "searchitemname.h"
#include "ui_searchitemname.h"
#include <QMessageBox>

SearchItemname::SearchItemname(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchItemname)
{
    ui->setupUi(this);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(send()));
}

SearchItemname::~SearchItemname()
{
    delete ui;
}

void SearchItemname::send()
{
    if(ui->name->text().isEmpty())
        QMessageBox::information(this,QString("错误"),QString("您没有输入搜索的内容"));
    else {
        emit senditemname(ui->name->text());
        ui->name->clear();
        close();
    }
}


void SearchItemname::on_Cancel_clicked()
{
    ui->name->clear();
    close();
}
