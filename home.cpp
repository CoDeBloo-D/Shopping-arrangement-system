#include "home.h"
#include "ui_home.h"
#include <QtCore>

Home::Home(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(xytimerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(1000);//定时器开始计时，其中1000表示1000ms即1秒
    ui->lcdNumber->setDigitCount(28);
    ui->label->setFont(QFont("微软雅黑", 15, QFont::Black));
    ui->Button1->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button2->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button3->setFont(QFont("微软雅黑", 10, QFont::Black));
    connect(ui->Button1,SIGNAL(clicked(bool)),this,SLOT(userlogin()));
    connect(ui->Button2,SIGNAL(clicked(bool)),this,SLOT(usercreate()));
    connect(ui->Button3,SIGNAL(clicked(bool)),this,SLOT(adminlogin()));
    connect(&ulogin,SIGNAL(openusermenu(QString)),this,SLOT(enterusermenu(QString)));
    connect(&ucre,SIGNAL(openusermenucre(QString)),this,SLOT(enterusermenu(QString)));
    connect(&alogin,SIGNAL(openadminmenu()),this,SLOT(enteradminmenu()));
    connect(&ulogin,SIGNAL(userloginclose()),this,SLOT(reshow()));
    connect(&ucre,SIGNAL(usercreateclose()),this,SLOT(reshow()));
    connect(&menu1,SIGNAL(usermenuclose()),this,SLOT(reshow()));
    connect(&alogin,SIGNAL(adminloginclose()),this,SLOT(reshow()));
    connect(&menu2,SIGNAL(adminmenuclose()),this,SLOT(reshow()));
}

void Home::userlogin(){
    this->hide();
    ulogin.setWindowTitle("用户登录");
    ulogin.exec();
}

void Home::usercreate(){
    this->hide();
    ucre.setWindowTitle("用户注册");
    ucre.exec();
}

void Home::adminlogin(){
    this->hide();
    alogin.setWindowTitle("管理员登录");
    alogin.exec();
}

void Home::enterusermenu(QString name) {
    std::string str=name.toStdString();
    strcpy(menu1.Username,str.c_str());
    this->show();
    this->hide();
    ulogin.close();
    ucre.close();
    menu1.setWindowTitle("用户菜单");
    menu1.exec();
}

void Home::enteradminmenu() {
    this->show();
    this->hide();
    alogin.close();
    menu2.setWindowTitle("管理员菜单");
    menu2.exec();
}
void Home::reshow()
{
    this->show();
}

Home::~Home()
{
    delete ui;
}

void Home::xytimerUpDate()
 {
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.toString("yyyy-MM-dd hh:mm:ss dddd");//设置系统时间显示格式
    ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
 }
