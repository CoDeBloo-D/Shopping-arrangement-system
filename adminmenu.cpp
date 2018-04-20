#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "item.h"
#include "shoppingcart.h"
#include "history.h"
#include "admin.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <string>
#include <cstring>
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <Qtcore>

QStandardItemModel *modela = new QStandardItemModel();
QStandardItemModel *modelb = new QStandardItemModel();
Adminmenu::Adminmenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminmenu)
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

    connect(ui->Button1,SIGNAL(clicked(bool)),this,SLOT(listItem()));
    connect(ui->Button2,SIGNAL(clicked(bool)),this,SLOT(newItem()));
    connect(ui->Button3,SIGNAL(clicked(bool)),this,SLOT(offItem()));
    connect(ui->Button4,SIGNAL(clicked(bool)),this,SLOT(mItemnum()));
    connect(ui->Button5,SIGNAL(clicked(bool)),this,SLOT(mItemprice()));
    connect(ui->Button6,SIGNAL(clicked(bool)),this,SLOT(listHistory()));


    modela->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modela->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    modela->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    modela->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    modela->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->Itemtable->setModel(modela);

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


    modelb->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modelb->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    modelb->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    modelb->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    modelb->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->Historytable->setModel(modelb);

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

Adminmenu::~Adminmenu()
{
    delete ui;
}

void Adminmenu::xytimerUpDate()
 {
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString strTime = time.toString("yyyy-MM-dd hh:mm:ss dddd");//设置系统时间显示格式
    ui->lcdNumber->display(strTime);//在lcdNumber上显示时间
 }

void Adminmenu::listItem()
{
    modela->clear();
    modela->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modela->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    modela->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    modela->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    modela->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    a.listItem(Itemhead,modela);
}

void Adminmenu::listHistory()
{
    modelb->clear();
    modelb->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modelb->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    modelb->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    modelb->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    modelb->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    a.printHistory(Historyhead,Itemhead,modelb);
}

void Adminmenu::newItem()
{
    nItem.setWindowTitle("添加新商品");
    nItem.exec();
    f.writeItem(Itemhead);
    listItem();
    return;
}

void Adminmenu::offItem()
{
    oItem.setWindowTitle("下架商品");
    oItem.exec();
    f.writeItem(Itemhead);
    listItem();
    return;
}

void Adminmenu::mItemnum()
{
    mIn.setWindowTitle("修改商品数量");
    mIn.exec();
    f.writeItem(Itemhead);
    listItem();
    return;
}

void Adminmenu::mItemprice()
{
    mIp.setWindowTitle("修改商品价格");
    mIp.exec();
    f.writeItem(Itemhead);
    listItem();
    return;
}

void Adminmenu::on_Button0_clicked()
{
    QMessageBox::information(this,QString("提示"),QString("您已成功注销！"));
    emit adminmenuclose();
    modela->clear();
    modela->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modela->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    modela->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    modela->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    modela->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    modelb->clear();
    modelb->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("ID")));
    modelb->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("名称")));
    modelb->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("品牌")));
    modelb->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("价格")));
    modelb->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("数量")));
    close();
}
