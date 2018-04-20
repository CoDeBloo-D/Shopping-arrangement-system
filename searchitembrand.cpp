#include "searchitembrand.h"
#include "ui_searchitembrand.h"
#include <QMessageBox>

SearchItembrand::SearchItembrand(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchItembrand)
{
    ui->setupUi(this);
    connect(ui->Confirm,SIGNAL(clicked(bool)),this,SLOT(send()));
}

SearchItembrand::~SearchItembrand()
{
    delete ui;
}


void SearchItembrand::send()
{
    if(ui->brand->text().isEmpty())
        QMessageBox::information(this,QString("错误"),QString("您没有输入搜索的内容"));
    else {
        emit senditembrand(ui->brand->text());
        ui->brand->clear();
        close();
    }
}


void SearchItembrand::on_Cancel_clicked()
{
    ui->brand->clear();
    close();
}
