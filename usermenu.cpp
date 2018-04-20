#include "usermenu.h"
#include "ui_usermenu.h"
#include "item.h"
#include "shoppingcart.h"
#include "history.h"
#include <QStandardItem>
#include <string>
#include <cstring>
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QtCore>
using namespace std;

QStandardItemModel *model1 = new QStandardItemModel();
QStandardItemModel *model2 = new QStandardItemModel();
QStandardItemModel *model3 = new QStandardItemModel();

Usermenu::Usermenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usermenu)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);   //新建定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(xytimerUpDate()));//关联定时器计满信号和相应的槽函数
    timer->start(1000);//定时器开始计时，其中1000表示1000ms即1秒
    ui->lcdNumber->setDigitCount(28);

    ui->Button0->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button1->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button2->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button3->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button4->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button5->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button6->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button7->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button8->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button9->setFont(QFont("微软雅黑", 10, QFont::Black));
    ui->Button10->setFont(QFont("微软雅黑", 10, QFont::Black));

    connect(ui->Button1,SIGNAL(clicked),this,SLOT(listItem()));
    connect(ui->Button1,SIGNAL(clicked(bool)),this,SLOT(listItem()));
    connect(ui->Button2,SIGNAL(clicked(bool)),this,SLOT(searchItemname()));
    connect(&sIname,SIGNAL(senditemname(QString)),this,SLOT(getitemname(QString)));
    connect(ui->Button3,SIGNAL(clicked(bool)),this,SLOT(searchItembrand()));
    connect(&sIbrand,SIGNAL(senditembrand(QString)),this,SLOT(getitembrand(QString)));
    connect(ui->Button4,SIGNAL(clicked(bool)),this,SLOT(searchItemvague()));
    connect(&sIvague,SIGNAL(senditemword(QString)),this,SLOT(getitemvague(QString)));
    connect(ui->Button5,SIGNAL(clicked(bool)),this,SLOT(listShoppingCart()));
    connect(ui->Button6,SIGNAL(clicked(bool)),this,SLOT(addone()));
    connect(ui->Button7,SIGNAL(clicked(bool)),this,SLOT(deleteone()));
    connect(ui->Button8,SIGNAL(clicked(bool)),&pa,SLOT(getthesum()));
    connect(ui->Button8,SIGNAL(clicked(bool)),this,SLOT(pay()));
    connect(ui->Button9,SIGNAL(clicked(bool)),this,SLOT(refreshHistory()));
    connect(ui->Button10,SIGNAL(clicked(bool)),this,SLOT(changemypassword()));


    model1->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model1->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model1->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model1->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model1->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->Itemtable->setModel(model1);

    ui->Itemtable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->Itemtable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->Itemtable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->Itemtable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->Itemtable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);

    ui->Itemtable->setColumnWidth(0,100);
    ui->Itemtable->setColumnWidth(1,100);
    ui->Itemtable->setColumnWidth(2,100);
    ui->Itemtable->setColumnWidth(3,100);
    ui->Itemtable->setColumnWidth(4,100);

    ui->Itemtable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->Itemtable->setEditTriggers(QAbstractItemView::NoEditTriggers);


    model2->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model2->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model2->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model2->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model2->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    model2->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("提示1")));
    model2->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("提示2")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->SCtable->setModel(model2);

    ui->SCtable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->SCtable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->SCtable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->SCtable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->SCtable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);
    ui->SCtable->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->SCtable->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Fixed);

    ui->SCtable->setColumnWidth(0,100);
    ui->SCtable->setColumnWidth(1,100);
    ui->SCtable->setColumnWidth(2,100);
    ui->SCtable->setColumnWidth(3,100);
    ui->SCtable->setColumnWidth(4,100);
    ui->SCtable->setColumnWidth(5,100);
    ui->SCtable->setColumnWidth(6,100);

    ui->SCtable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->SCtable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    model3->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model3->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model3->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model3->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model3->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->Historytable->setModel(model3);

    ui->Historytable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->Historytable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);
    ui->Historytable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
    ui->Historytable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Fixed);
    ui->Historytable->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Fixed);

    ui->Historytable->setColumnWidth(0,100);
    ui->Historytable->setColumnWidth(1,100);
    ui->Historytable->setColumnWidth(2,100);
    ui->Historytable->setColumnWidth(3,100);
    ui->Historytable->setColumnWidth(4,100);

    ui->Historytable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->Historytable->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Usermenu::~Usermenu()
{
    delete ui;
}

void Usermenu::xytimerUpDate()
 {
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.toString("yyyy-MM-dd hh:mm:ss dddd");//设置系统时间显示格式
    ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
 }

void Usermenu::listItem()
{
    model1->clear();
    model1->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model1->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model1->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model1->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model1->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    u.listItem(Itemhead,model1);
}

void Usermenu::searchItemname()
{
    sIname.setWindowTitle("搜索商品（按名称）");
    sIname.exec();
}

void Usermenu::getitemname(QString name)
{
    std::string str = name.toStdString();
    strcpy(Itemname,str.c_str());
    //qDebug()<<Itemname;
    model1->clear();
    model1->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model1->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model1->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model1->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model1->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    u.searchItem(Itemhead,Itemname,model1);
}

void Usermenu::searchItembrand()
{
    sIbrand.setWindowTitle("搜索商品（按品牌）");
    sIbrand.exec();
}

void Usermenu::getitembrand(QString brand)
{
    std::string str = brand.toStdString();
    strcpy(Itembrand,str.c_str());
    model1->clear();
    model1->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model1->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model1->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model1->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model1->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    u.searchItembrand(Itemhead,Itembrand,model1);
}

void Usermenu::searchItemvague()
{
    sIvague.setWindowTitle("模糊搜索");
    sIvague.exec();
}

void Usermenu::getitemvague(QString word)
{
    std::string str = word.toStdString();
    strcpy(Itemmessage,str.c_str());
    model1->clear();
    model1->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model1->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model1->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model1->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model1->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    u.searchItemvague(Itemhead,Itemmessage,model1);
}

void Usermenu::listShoppingCart()
{
    model2->clear();
    model2->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model2->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model2->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model2->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model2->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    model2->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("提示1")));
    model2->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("提示2")));
    f.readShoppingCart(SChead,Username);
    if(SChead==NULL)
    {
        QMessageBox::information(this,QString("提示"),QString("您的购物车目前没有任何商品！"));
        return;
    }
    u.listShoppingCart(SChead,Itemhead,model2);
}

void Usermenu::addone()
{
    strcpy(aI.Username,Username);
    aI.setWindowTitle("添加商品至购物车");
    aI.exec();
    listShoppingCart();
}

void Usermenu::deleteone()
{
    strcpy(dI.Username,Username);
    dI.setWindowTitle("删除购物车中商品");
    dI.exec();
    listShoppingCart();
}

void Usermenu::pay()
{
    strcpy(pa.Username,Username);
    pa.setWindowTitle("收银台");
    pa.exec();
    listItem();
    listShoppingCart();
    refreshHistory();
}

void Usermenu::on_Button0_clicked()
{
    QMessageBox::information(this,QString("提示"),QString("您已成功注销！"));
    model1->clear();
    model2->clear();
    model3->clear();
    model1->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model1->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model1->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model1->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model1->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    model2->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model2->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model2->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model2->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model2->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    model2->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("提示1")));
    model2->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("提示2")));
    model3->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model3->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model3->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model3->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model3->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    emit usermenuclose();
    close();
}

void Usermenu::refreshHistory()
{
    model3->clear();
    model3->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    model3->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    model3->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    model3->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    model3->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    u.ownHistory(Historyhead,Username,model3);
}

void Usermenu::changemypassword()
{
    strcpy(ch.Username,Username);
    ch.setWindowTitle("修改密码");
    ch.exec();
}
