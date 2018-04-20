#include "searchitemvague.h"
#include "ui_searchitemvague.h"
#include <QMessageBox>

SearchItemvague::SearchItemvague(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchItemvague)
{
    ui->setupUi(this);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(send()));
}

SearchItemvague::~SearchItemvague()
{
    delete ui;
}

void SearchItemvague::send()
{
    if(ui->word->text().isEmpty())
        QMessageBox::information(this,QString("错误"),QString("您没有输入搜索的内容"));
    else {
        emit senditemword(ui->word->text());
        ui->word->clear();
        close();
    }
}


void SearchItemvague::on_Cancel_clicked()
{
    ui->word->clear();
    close();
}
