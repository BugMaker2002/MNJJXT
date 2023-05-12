#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sys.h"
#include "airconditionface.h"
#include "ventilation.h"
#include "underface.h"
#include "humidificationface.h"
#include "dehumidification.h"
#include "introface.h"
#include "runface.h"
#include "readface.h"
#include "automodeface.h"
#include <QLineEdit>
#include <QRegExpValidator>
#include <QPushButton>
#include <QPainter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,600);
    this->setWindowTitle("智能家居模拟系统");
    this->setWindowIcon(QPixmap(":/image/icon.png"));


    //创建产品介绍按钮，从而能够让用户查看使用说明
    QPushButton*helpbutton=new QPushButton(this);
    helpbutton->setText("查看介绍信息");
    helpbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    helpbutton->setFocusPolicy(Qt::NoFocus);
    helpbutton->setFixedSize(helpbutton->width()*1.5,helpbutton->height()*1.15);
    helpbutton->move((this->width()-helpbutton->width())*0.5,this->height()*0.1);
    introface*introface1=new introface;
    connect(helpbutton,&QPushButton::clicked,this,[=](){
        introface1->show();
    });

    //创建空调按钮，从而能够修改空调的参数
    QPushButton*airbutton=new QPushButton(this);
    airbutton->setText("修改空调信息");
    airbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    airbutton->setFocusPolicy(Qt::NoFocus);
    airbutton->setFixedSize(airbutton->width()*1.5,airbutton->height()*1.15);
    airbutton->move((this->width()-airbutton->width())*0.5,this->height()*0.2);
    airconditionface*airconditionface1=new airconditionface;
    connect(airbutton,&QPushButton::clicked,this,[=](){
        airconditionface1->show();
    });
    //airbutton->setStyleSheet("QPushButton{border:0px;}");
    //airbutton->setStyleSheet("QPushButton{border-top-left-radius:15px;""border-top-right-radius:5px;}");

    //创建新风按钮，从而能够修改新风的参数
    QPushButton*venbutton=new QPushButton(this);
    venbutton->setText("修改新风系统信息");
    venbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    venbutton->setFocusPolicy(Qt::NoFocus);
    venbutton->setFixedSize(venbutton->width()*1.5,venbutton->height()*1.15);
    venbutton->move((this->width()-venbutton->width())*0.5,this->height()*0.3);
    ventilation*ventilation1=new ventilation;
    connect(venbutton,&QPushButton::clicked,this,[=](){
        ventilation1->show();
    });

    //创建地暖按钮，从而能够修改地暖的参数
    QPushButton*undbutton=new QPushButton(this);
    undbutton->setText("修改地暖系统信息");
    undbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    undbutton->setFocusPolicy(Qt::NoFocus);
    undbutton->setFixedSize(undbutton->width()*1.5,undbutton->height()*1.15);
    undbutton->move((this->width()-undbutton->width())*0.5,this->height()*0.4);
    underface*underface1=new underface;
    connect(undbutton,&QPushButton::clicked,this,[=](){
        underface1->show();
    });

    //创建加湿按钮，从而能够修改加湿的参数
    QPushButton*humbutton=new QPushButton(this);
    humbutton->setText("修改加湿系统信息");
    humbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    humbutton->setFocusPolicy(Qt::NoFocus);
    humbutton->setFixedSize(humbutton->width()*1.5,humbutton->height()*1.15);
    humbutton->move((this->width()-humbutton->width())*0.5,this->height()*0.5);
    humidificationface*humidificationface1=new humidificationface;
    connect(humbutton,&QPushButton::clicked,this,[=](){
        humidificationface1->show();
    });

    //创建除湿按钮，从而能够修改加湿的参数
    QPushButton*dehbutton=new QPushButton(this);
    dehbutton->setText("修改除湿系统信息");
    dehbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    dehbutton->setFocusPolicy(Qt::NoFocus);
    dehbutton->setFixedSize(dehbutton->width()*1.5,dehbutton->height()*1.15);
    dehbutton->move((this->width()-dehbutton->width())*0.5,this->height()*0.6);
    dehumidification*dehumidification1=new dehumidification;
    connect(dehbutton,&QPushButton::clicked,this,[=](){
        dehumidification1->show();
    });

    //创建进入智能控制的界面的按钮
    QPushButton*autobutton=new QPushButton(this);
    autobutton->setText("进入智能模式");
    autobutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    autobutton->setFocusPolicy(Qt::NoFocus);
    autobutton->setFixedSize(autobutton->width()*1.5,autobutton->height()*1.15);
    autobutton->move((this->width()-autobutton->width())*0.5,this->height()*0.7);
    automodeface*automodeface1=new automodeface;
    connect(autobutton,&QPushButton::clicked,this,[=](){
        automodeface1->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/3.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

