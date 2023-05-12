#include "autorunface.h"
#include "sys.h"
#include <QLineEdit>
#include <QRegExpValidator>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QFont>
#include <QMessageBox>
#include <QLabel>
autorunface::autorunface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowTitle("智能模式");
    this->setWindowIcon(QPixmap(":/image/1.png"));

    //设置字体
    QFont qfont;
    qfont.setFamily("华文彩云");

    QLabel*label=new QLabel(this);
    label->resize(900,60);
    label->setFont(QFont("Timers",12,QFont::Bold));
    label->setText(QString("请点击刷新按钮生成设备运行信息"));
    label->move((this->width()-label->width())*3,this->height()*0.01);
    label->show();

    QPushButton*refreshbtn=new QPushButton(this);
    refreshbtn->move((this->width()-refreshbtn->width())*0.5,this->height()*0.1);
    refreshbtn->setFixedSize(refreshbtn->width()*0.6,refreshbtn->height());
    refreshbtn->setText("刷新");
//    refreshbtn->setFont(qfont);
    refreshbtn->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLabel*label1=new QLabel(this);
    QLabel*label2=new QLabel(this);
    QLabel*label3=new QLabel(this);
    QLabel*label4=new QLabel(this);
    QLabel*label5=new QLabel(this);
    QLabel*label6=new QLabel(this);
    QLabel*label7=new QLabel(this);
    QLabel*label8=new QLabel(this);

    connect(refreshbtn,&QPushButton::clicked,this,[=](){


        if(air.getPower())
        {
            if(air.getCoolCapacity())
            {
                label6->resize(580,60);
                label6->setFont(QFont("Timers",14,QFont::Bold));
                label6->setStyleSheet("color:red");
                label6->setText(QString("空调制冷功能已为您开启！"));
                label6->move((this->width()-label6->width())*0.8,this->height()*0.3);
                label6->show();
            }
            label1->resize(1000,60);
            label1->setFont(QFont("Timers",14,QFont::Bold));
            label1->setStyleSheet("color:red");
            label1->setText(QString("空调热容量：%1J/K 空调冷容量：%2J/K 空调温度：%3℃ 空调功率：%4W").arg(air.getHeatCapacity()).arg(air.getCoolCapacity()).arg(air.getTemprature()).arg(air.getPower()));
            label1->move((this->width()-label1->width())*0.4,this->height()*0.4);
            label1->show();
        }

        if(und.getPower())
        {
            label2->resize(580,60);
            label2->setFont(QFont("Timers",14,QFont::Bold));
            label2->setStyleSheet("color:red");
            label2->setText(QString("地暖制热功能已为您开启！"));
            label2->move((this->width()-label2->width())*0.8,this->height()*0.3);
            label2->show();
            label3->resize(550,60);
            label3->setFont(QFont("Timers",14,QFont::Bold));
            label3->setStyleSheet("color:red");
            label3->setText(QString(QString("地暖系统温度：%1℃ 地暖系统功率：%2W").arg(und.getaveTemprature()).arg(und.getPower())));
            label3->move((this->width()-label3->width())*0.6,this->height()*0.4);
            label3->show();
        }

        if(hum.getPower())
        {
            label7->resize(580,60);
            label7->setFont(QFont("Timers",14,QFont::Bold));
            label7->setStyleSheet("color:red");
            label7->setText(QString("加湿器已为您开启！"));
            label7->move((this->width()-label7->width())*0.9,this->height()*0.5);
            label7->show();
            label4->resize(550,60);
            label4->setFont(QFont("Timers",14,QFont::Bold));
            label4->setStyleSheet("color:red");
            label4->setText(QString(QString("加湿系统湿度：%1RH 加湿系统功率：%2W").arg(hum.gethumidity()).arg(hum.getPower())));
            label4->move((this->width()-label4->width())*0.5,this->height()*0.6);
            label4->show();
        }

        if(deh.getPower())
        {
            label8->resize(580,60);
            label8->setFont(QFont("Timers",14,QFont::Bold));
            label8->setStyleSheet("color:red");
            label8->setText(QString("除湿器已为您开启！"));
            label8->move((this->width()-label8->width())*0.9,this->height()*0.5);
            label8->show();
            label5->resize(550,60);
            label5->setFont(QFont("Timers",14,QFont::Bold));
            label5->setStyleSheet("color:red");
            label5->setText(QString(QString("除湿系统湿度：%1RH 除湿系统功率：%2W").arg(deh.gethumidity()).arg(deh.getPower())));
            label5->move((this->width()-label5->width())*0.5,this->height()*0.6);
            label5->show();
        }

    });
}
void autorunface::rectemp(int a)
{
    //当外界气温到达28摄氏度时，人体会感觉到炎热，开启空调制冷功能
    if(a>28)
    {
        air.setCoolCapacity(100);
        air.setHeatCapacity(0);
        air.setTemprature(22);
        air.setPower(100);
    }
    //外界气温低于15摄氏度时，人体会感到寒冷，开启地暖制热功能
    if(a<15)
    {
        und.setaveTemprature(25);
        und.setPower(100);
    }
}
void autorunface::rechumidity(int a)
{
    //当外界湿度大于50时，需要除湿
    if(a>50)
    {
        deh.setPower(100);
        deh.sethumidity(35);
    }
    //当外界湿度小于20时，需要加湿
    if(a<20)
    {
        hum.setPower(100);
        hum.sethumidity(35);
    }
}
void autorunface::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/14.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
