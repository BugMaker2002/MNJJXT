#include "readface.h"
#include <QFileDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QFile>
#include <QDebug>
#include <QTextCodec>
#include <QPushButton>
readface::readface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowTitle("读取文件");
    this->setWindowIcon(QPixmap(":/image/1.png"));

    QPushButton*openbtn=new QPushButton(this);
    openbtn->setFixedSize(openbtn->width()*2,openbtn->height());
    openbtn->move((this->width()-openbtn->width())*0.9,this->height()*0.12);
    openbtn->setFixedSize(openbtn->width()*0.5,openbtn->height());
    openbtn->setText("导入文件");
    openbtn->setStyleSheet("background-color:rgb(0, 199, 140)");

    QPushButton*confirmbtn=new QPushButton(this);
    confirmbtn->setFixedSize(confirmbtn->width()*2,confirmbtn->height());
    confirmbtn->move((this->width()-confirmbtn->width())*0.9,this->height()*0.35);
    confirmbtn->setFixedSize(confirmbtn->width()*0.5,confirmbtn->height());
    confirmbtn->setText("保存");
    confirmbtn->setStyleSheet("background-color:rgb(0, 199, 140)");

    QLineEdit*lineEdit=new QLineEdit(this);
    lineEdit->move((this->width()-lineEdit->width())*0.3,this->height()*0.1);
    lineEdit->setFixedSize(400,60);

    QTextEdit*textEdit=new QTextEdit(this);
    textEdit->move((this->width()-textEdit->width())*0.3,this->height()*0.25);
    textEdit->setFixedSize(400,250);

    connect(openbtn,&QPushButton::released,this,[=](){
            //文件对话框 -- 返回选中文件的文件路径
            QString path = QFileDialog::getOpenFileName(this,"选取文件","/","Text files (*.txt);;XML files (*.xml)");
            //将路径放入到 LineEdit 控件中
            //一般设置文本的函数都叫做setText
            lineEdit->setText(path);

            //读取内容放到 TextEdit 控件中
            QFile file(path);//参数就是读取文件的路径
            //设置打开方式（读还是写或是其他）
            file.open(QIODevice::ReadOnly);
            //通过readAll函数可以将文件内容都给读出来
            //这个函数返回一个 QByteArray 类类型的值，因此可以去接收这个返回值
            QByteArray bytearray = file.readAll();
            //将读取到的数据放入到 textEdit 中，同样使用 setText 这个函数
            //因为 setText 这个函数所需要的参数是 QString 类型，所以需要进行格式转换
            //但这里在编译的时候会自动进行隐式转换，所以并不需要进行格式转换。
            textEdit->setText(bytearray);
            file.close();
        });
//    QFile file(":/res.txt");
//    QTextStream stream(&file);
//    while(!stream.atEnd())
//    {
//        QString str=stream.readLine();
//        qDebug()<<str;
//    }

    connect(confirmbtn,&QPushButton::clicked,this,[=](){
//        lineEdit->setEnabled(false);
//        textEdit->setEnabled(false);
    });
}
