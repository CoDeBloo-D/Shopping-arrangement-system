#include "usercreate.h"
#include "ui_usercreate.h"
#include <QMessageBox>

Usercreate::Usercreate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usercreate)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
}

Usercreate::~Usercreate()
{
    delete ui;
}

void Usercreate::on_Confirm_clicked()
{
    if(ui->Username->text().isEmpty()||ui->Password->text().isEmpty())
    {
        QMessageBox::information(this,QString("失败"),QString("信息不完整，请重试！"));
        return;
    }
    std::string str1=ui->Username->text().toStdString();
    std::string str2=ui->Password->text().toStdString();
    char Username[30];
    char Password[30];

    strcpy(Username,str1.c_str());
    strcpy(Password,str2.c_str());

    if(u.createUser(Userhead,Username,Password)==true)
    {
        f.writeUser(Userhead);
        FILE *cre;
        char link[50] = "D:\\Qt_Projects\\Project1_Advanced\\src\\";
        char txt[10] = ".txt\0";
        strcat_s(link, Username);
        strcat_s(link, txt);
        cre = fopen(link, "w+");//此处可能需要调整
        fputs("ID\t名称\t品牌\t价格\t数量\n", cre);
        fclose(cre);
        f.readShoppingCart(SChead,Username);
        emit openusermenucre(ui->Username->text());
        ui->Username->clear();
        ui->Password->clear();
        close();
    }
    else
    {
        ui->Username->clear();
        ui->Password->clear();
        QMessageBox::information(this,QString("失败"),QString("用户名与已有用户重复，请重试！"));
        ui->Username->setFocus();
    }

}

void Usercreate::on_Cancel_clicked()
{
    ui->Username->clear();
    ui->Password->clear();
    emit usercreateclose();
    close();
}
