#include "automodeface.h"
#include "autorunface.h"
#include "sys.h"
#include <QLineEdit>
#include <QRegExpValidator>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QFont>
#include <QMessageBox>
automodeface::automodeface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowTitle("智能模式");
    this->setWindowIcon(QPixmap(":/image/1.png"));

    //设置字体
    QFont qfont;
    qfont.setFamily("华文彩云");

    //连接信号量
    autorunface*autorunface1=new autorunface;
    connect(this,SIGNAL(senttemp(int)),autorunface1,SLOT(rectemp(int)));
    connect(this,SIGNAL(senthumidity(int)),autorunface1,SLOT(rechumidity(int)));

    //设置外界温度
    QPushButton*confirmbtn1=new QPushButton(this);
    confirmbtn1->move((this->width()-confirmbtn1->width())*0.8,this->height()*0.32);
    confirmbtn1->setFixedSize(confirmbtn1->width()*0.5,confirmbtn1->height());
    confirmbtn1->setText("确认");
    confirmbtn1->setFont(qfont);
    confirmbtn1->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line1=new QLineEdit(this);
    line1->setFont(QFont("Timers",16,QFont::Bold));
    line1->setFixedSize(380,60);
    line1->setPlaceholderText(tr("请输入外界温度"));
    line1->move((this->width()-line1->width())*0.5,this->height()*0.3);
    connect(confirmbtn1,&QPushButton::clicked,this,[=](){
        emit senttemp(line1->text().toInt());
        QMessageBox message(QMessageBox::Information, "information","成功设置外界温度！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 150px;""min-height: 100px; ""}");
        message.show();
        message.exec();
    });

    //设置外界湿度
    QPushButton*confirmbtn2=new QPushButton(this);
    confirmbtn2->move((this->width()-confirmbtn2->width())*0.8,this->height()*0.52);
    confirmbtn2->setFixedSize(confirmbtn2->width()*0.5,confirmbtn2->height());
    confirmbtn2->setText("确认");
    confirmbtn2->setFont(qfont);
    confirmbtn2->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line2=new QLineEdit(this);
    line2->setFont(QFont("Timers",16,QFont::Bold));
    line2->setFixedSize(380,60);
    line2->setPlaceholderText(tr("请输入外界湿度"));
    line2->move((this->width()-line2->width())*0.5,this->height()*0.5);
    connect(confirmbtn2,&QPushButton::clicked,this,[=](){
        emit senthumidity(line2->text().toInt());
        QMessageBox message(QMessageBox::Information, "information","成功设置外界湿度！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 150px;""min-height: 100px; ""}");
        message.show();
        message.exec();
    });

    //生成运行指令按钮
    QPushButton*runbutton=new QPushButton(this);
    runbutton->setText("生成运行指令，运行设备");
    runbutton->setStyleSheet("background-color:rgb(0, 199, 140)");
    runbutton->setFocusPolicy(Qt::NoFocus);
    runbutton->setFixedSize(runbutton->width()*2,runbutton->height()*1.15);
    runbutton->move((this->width()-runbutton->width())*0.5,this->height()*0.75);
    connect(runbutton,&QPushButton::clicked,this,[=](){
        autorunface1->show();
    });
}
void automodeface::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/6.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
