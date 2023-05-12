#include "humidificationface.h"
#include "runface.h"
#include "readface.h"
#include <QLineEdit>
#include <QRegExpValidator>
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>
humidificationface::humidificationface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowTitle("编辑加湿系统信息页面");
    this->setWindowIcon(QPixmap(":/image/8.png"));

    //设置字体
    QFont qfont;
    qfont.setFamily("华文彩云");

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
    connect(this,SIGNAL(senthumidity(int)),runface1,SLOT(rechumidity1(int)));
    connect(this,SIGNAL(sentPower(int)),runface1,SLOT(recPower4(int)));

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

    QLabel*label=new QLabel(this);
    label->resize(900,60);
    label->setFont(QFont("Timers",12,QFont::Bold));
    label->setText(QString("当前湿度：%1RH 当前功率：%2W").arg(hum.gethumidity()).arg(hum.getPower()));
    label->move((this->width()-label->width())*3,this->height()*0.12);
    label->show();

    QPushButton*confirmbtn1=new QPushButton(this);
    confirmbtn1->move((this->width()-confirmbtn1->width())*0.8,this->height()*0.32);
    confirmbtn1->setFixedSize(confirmbtn1->width()*0.5,confirmbtn1->height());
    confirmbtn1->setText("确认");
    confirmbtn1->setFont(qfont);
    confirmbtn1->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line1=new QLineEdit(this);
    line1->setFont(QFont("Timers",16,QFont::Bold));
    line1->setFixedSize(380,60);
    line1->setPlaceholderText(tr("请输入想要设定的湿度"));
    //editgamer->setValidator(new QRegExpValidator(QRegExp("[2-6]")));
    line1->move((this->width()-line1->width())*0.5,this->height()*0.3);
    connect(confirmbtn1,&QPushButton::clicked,this,[=](){
        hum.sethumidity(line1->text().toInt());
        qDebug()<<hum.gethumidity();
        QMessageBox message(QMessageBox::Information, "information","成功设置湿度！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 125px;""min-height: 100px; ""}");
        message.show();
        message.exec();
        label->setText(QString("当前湿度：%1RH 当前功率：%2W").arg(hum.gethumidity()).arg(hum.getPower()));
        emit senthumidity(hum.gethumidity());
    });

    QPushButton*confirmbtn2=new QPushButton(this);
    confirmbtn2->move((this->width()-confirmbtn2->width())*0.8,this->height()*0.52);
    confirmbtn2->setFixedSize(confirmbtn2->width()*0.5,confirmbtn2->height());
    confirmbtn2->setText("确认");
    confirmbtn2->setFont(qfont);
    confirmbtn2->setStyleSheet("background-color:rgb(0, 199, 140)");
    QLineEdit*line2=new QLineEdit(this);
    line2->setFont(QFont("Timers",16,QFont::Bold));
    line2->setFixedSize(380,60);
    line2->setPlaceholderText(tr("请输入想要设定的功率"));
    //editgamer->setValidator(new QRegExpValidator(QRegExp("[2-6]")));
    line2->move((this->width()-line2->width())*0.5,this->height()*0.5);
    connect(confirmbtn2,&QPushButton::clicked,this,[=](){
        hum.setPower(line2->text().toInt());
        qDebug()<<hum.getPower();
        QMessageBox message(QMessageBox::Information, "information","成功设置功率！");
        message.setIconPixmap(QPixmap(":/image/2.png"));
        message.setStyleSheet("QLabel{""min-width: 125px;""min-height: 100px; ""}");
        message.show();
        message.exec();
        label->setText(QString("当前湿度：%1RH 当前功率：%2W").arg(hum.gethumidity()).arg(hum.getPower()));
        emit sentPower(hum.getPower());
    });
}
void humidificationface::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/9.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
