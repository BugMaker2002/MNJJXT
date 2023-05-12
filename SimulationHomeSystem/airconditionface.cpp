#include "airconditionface.h"
#include "mainwindow.h"
#include "runface.h"
#include "readface.h"
#include <QLineEdit>
#include <QRegExpValidator>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QFont>
#include <QMessageBox>
airconditionface::airconditionface(QWidget *parent): QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowTitle("编辑空调信息页面");
    this->setWindowIcon(QPixmap(":/image/4.png"));

    //创建查看设备运行情况按钮
    QPushButton*runbutton=new QPushButton(this);
    runbutton->setText("查看运行情况");
    runbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    runbutton->setFocusPolicy(Qt::NoFocus);
    runbutton->setFixedSize(runbutton->width()*1.5,runbutton->height()*1.15);
    runbutton->move((this->width()-runbutton->width())*0.6,this->height()*0.85);
    runface*runface1=new runface;
    connect(runbutton,&QPushButton::clicked,this,[=](){
        runface1->show();
    });

    //连接信号量
    connect(this,SIGNAL(sentHeatCapacity(int)),runface1,SLOT(recHeatCapacity(int)));
    connect(this,SIGNAL(sentCoolCapacity(int)),runface1,SLOT(recCoolCapacity(int)));
    connect(this,SIGNAL(sentPower(int)),runface1,SLOT(recPower1(int)));
    connect(this,SIGNAL(sentTemprature(int)),runface1,SLOT(recTemprature(int)));

    //创建读取文件按钮，从而能够修改参数
    QPushButton*readbutton=new QPushButton(this);
    readbutton->setText("读取文件");
    readbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    readbutton->setFocusPolicy(Qt::NoFocus);
    readbutton->setFixedSize(readbutton->width()*1.5,readbutton->height()*1.15);
    readbutton->move((this->width()-readbutton->width())*0.4,this->height()*0.85);
    readface*readface1=new readface;
    connect(readbutton,&QPushButton::clicked,this,[=](){
        readface1->show();
    });



    //设置字体
    QFont qfont;
    qfont.setFamily("华文彩云");

    QLabel*label=new QLabel(this);
    label->resize(900,60);
    label->setFont(QFont("Timers",12,QFont::Bold));
    label->setText(QString("当前热容量：%1J/K 当前冷容量：%2J/K 当前温度：%3℃ 当前功率：%4W").arg(air.getHeatCapacity()).arg(air.getCoolCapacity()).arg(air.getTemprature()).arg(air.getPower()));
    label->move((this->width()-label->width())*0.8,this->height()*0.005);
    label->show();



    QPushButton*confirmbtn1=new QPushButton(this);
    confirmbtn1->move((this->width()-confirmbtn1->width())*0.8,this->height()*0.12);
    confirmbtn1->setFixedSize(confirmbtn1->width()*0.5,confirmbtn1->height());
    confirmbtn1->setText("确认");
    confirmbtn1->setFont(qfont);
    confirmbtn1->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line1=new QLineEdit(this);
    line1->setFont(QFont("Timers",16,QFont::Bold));
    line1->setFixedSize(380,60);
    line1->setPlaceholderText(tr("请输入想要设定的热容量"));
    line1->move((this->width()-line1->width())*0.5,this->height()*0.1);
    connect(confirmbtn1,&QPushButton::clicked,this,[=](){
        air.setHeatCapacity(line1->text().toInt());
        qDebug()<<air.getHeatCapacity();
        QMessageBox message(QMessageBox::Information, "information","成功设置热容量！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 125px;""min-height: 100px; ""}");
        message.show();
        message.exec();
        label->setText(QString("当前热容量：%1J/K 当前冷容量：%2J/K 当前温度：%3℃ 当前功率：%4W").arg(air.getHeatCapacity()).arg(air.getCoolCapacity()).arg(air.getTemprature()).arg(air.getPower()));
        emit sentHeatCapacity(air.getHeatCapacity());
    });

    QPushButton*confirmbtn2=new QPushButton(this);
    confirmbtn2->move((this->width()-confirmbtn2->width())*0.8,this->height()*0.32);
    confirmbtn2->setFixedSize(confirmbtn2->width()*0.5,confirmbtn2->height());
    confirmbtn2->setText("确认");
    confirmbtn2->setFont(qfont);
    confirmbtn2->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line2=new QLineEdit(this);
    line2->setFont(QFont("Timers",16,QFont::Bold));
    line2->setFixedSize(380,60);
    line2->setPlaceholderText(tr("请输入想要设定的冷容量"));
    line2->move((this->width()-line2->width())*0.5,this->height()*0.3);
    connect(confirmbtn2,&QPushButton::clicked,this,[=](){
        air.setCoolCapacity(line2->text().toInt());
        qDebug()<<air.getCoolCapacity();
        QMessageBox message(QMessageBox::Information, "information","成功设置冷容量！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 125px;""min-height: 100px; ""}");
        message.show();
        message.exec();
        label->setText(QString("当前热容量：%1J/K 当前冷容量：%2J/K 当前温度：%3℃ 当前功率：%4W").arg(air.getHeatCapacity()).arg(air.getCoolCapacity()).arg(air.getTemprature()).arg(air.getPower()));
        emit sentCoolCapacity(air.getCoolCapacity());
    });

    QPushButton*confirmbtn3=new QPushButton(this);
    confirmbtn3->move((this->width()-confirmbtn3->width())*0.8,this->height()*0.52);
    confirmbtn3->setFixedSize(confirmbtn3->width()*0.5,confirmbtn3->height());
    confirmbtn3->setText("确认");
    confirmbtn3->setFont(qfont);
    confirmbtn3->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line3=new QLineEdit(this);
    line3->setFont(QFont("Timers",16,QFont::Bold));
    line3->setFixedSize(380,60);
    line3->setPlaceholderText(tr("请输入想要设定的功率"));
    line3->move((this->width()-line3->width())*0.5,this->height()*0.5);
    connect(confirmbtn3,&QPushButton::clicked,this,[=](){
        air.setPower(line3->text().toInt());
        qDebug()<<air.getPower();
        QMessageBox message(QMessageBox::Information, "information","成功设置功率！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 125px;""min-height: 100px; ""}");
        message.show();
        message.exec();
        label->setText(QString("当前热容量：%1J/K 当前冷容量：%2J/K 当前温度：%3℃ 当前功率：%4W").arg(air.getHeatCapacity()).arg(air.getCoolCapacity()).arg(air.getTemprature()).arg(air.getPower()));
        emit sentPower(air.getPower());
    });

    QPushButton*confirmbtn4=new QPushButton(this);
    confirmbtn4->move((this->width()-confirmbtn4->width())*0.8,this->height()*0.72);
    confirmbtn4->setFixedSize(confirmbtn4->width()*0.5,confirmbtn4->height());
    confirmbtn4->setText("确认");
    confirmbtn4->setFont(qfont);
    confirmbtn4->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line4=new QLineEdit(this);
    line4->setFont(QFont("Timers",16,QFont::Bold));
    line4->setFixedSize(380,60);
    line4->setPlaceholderText(tr("请输入想要设定的温度"));
    line4->move((this->width()-line4->width())*0.5,this->height()*0.7);
    connect(confirmbtn4,&QPushButton::clicked,this,[=](){
        air.setTemprature(line4->text().toInt());
        qDebug()<<air.getTemprature();
        QMessageBox message(QMessageBox::Information, "information","成功设置温度！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 125px;""min-height: 100px; ""}");
        message.show();
        message.exec();
        label->setText(QString("当前热容量：%1J/K 当前冷容量：%2J/K 当前温度：%3℃ 当前功率：%4W").arg(air.getHeatCapacity()).arg(air.getCoolCapacity()).arg(air.getTemprature()).arg(air.getPower()));
        emit sentTemprature(air.getTemprature());
    });



}
void airconditionface::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/4.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
