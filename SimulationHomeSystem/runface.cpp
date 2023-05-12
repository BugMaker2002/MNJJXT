#include "runface.h"
#include "runface.h"
#include "sys.h"
#include <QPainter>
#include <QTableWidget>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QMessageBox>
double runface::in_temp=25;
double runface::in_humidity=50;
double runface::air_quality=37;
runface::runface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowIcon(QPixmap(":/image/2.png"));
    this->setWindowTitle("温湿度及空气质量变化");

    QFont qfont;
    qfont.setFamily("华文彩云");

    QLabel*label=new QLabel(this);
    label->resize(900,60);
    label->setFont(QFont("Timers",12,QFont::Bold));
    label->setText(QString("若更新了设备的运行参数，请点击刷新按钮重新生成数据"));
    label->move((this->width()-label->width())*1.5,this->height()*0.01);
    label->show();

    QPushButton*refreshbtn=new QPushButton(this);
    refreshbtn->move((this->width()-refreshbtn->width())*0.8,this->height()*0.12);
    refreshbtn->setFixedSize(refreshbtn->width()*0.5,refreshbtn->height());
    refreshbtn->setText("刷新");
    refreshbtn->setFont(qfont);
    refreshbtn->setStyleSheet("background-color:rgb(0, 199, 140)");
    refreshbtn->move((this->width()-refreshbtn->width())*0.5,this->height()*0.1);

    QTableWidget*tableWidget=new QTableWidget(this);
    tableWidget->setFixedSize(628,300);
    tableWidget->move((this->width()-tableWidget->width())*0.5,this->height()*0.2);
    //tableWidget->move(200,200);

    QTableWidgetItem *headerItem;
    QStringList headerText;
    headerText<<"时间"<<"温度"<<"湿度"<<"空气质量";
    tableWidget->setColumnCount(headerText.count());
    tableWidget->setRowCount(5);

    for(int i=0; i < tableWidget->columnCount(); i++)
    {
         headerItem = new QTableWidgetItem(headerText.at(i));
         headerItem->setTextColor(Qt::blue);
         tableWidget->setHorizontalHeaderItem(i,headerItem);
    }

    QTime current_time=QTime::currentTime();
    int hour=current_time.hour();
    int minute=current_time.minute();
    int second=current_time.second();

    //第一次的时间
    tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute).arg(second)));
    tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(in_temp)));
    tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(in_humidity)));
    tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(air_quality)));

    //第二次的时间
    tableWidget->setItem(1,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+1).arg(second)));
    tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(in_temp)));
    tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(in_humidity)));
    tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(air_quality)));

    //第三次的时间
    tableWidget->setItem(2,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+2).arg(second)));
    tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(in_temp)));
    tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(in_humidity)));
    tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(air_quality)));

    //第四次的时间
    tableWidget->setItem(3,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+3).arg(second)));
    tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(in_temp)));
    tableWidget->setItem(3,2,new QTableWidgetItem(QString::number(in_humidity)));
    tableWidget->setItem(3,3,new QTableWidgetItem(QString::number(air_quality)));

    //第五次的时间
    tableWidget->setItem(4,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+4).arg(second)));
    tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(in_temp)));
    tableWidget->setItem(4,2,new QTableWidgetItem(QString::number(in_humidity)));
    tableWidget->setItem(4,3,new QTableWidgetItem(QString::number(air_quality)));

    //设置单元格水平居中、竖直居中
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            QTableWidgetItem*item=tableWidget->item(j,i);
            item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        }
    }

    connect(refreshbtn,&QPushButton::clicked,this,[=](){

        //仅供测试
//        qDebug()<<air.getHeatCapacity();
//        qDebug()<<air.getCoolCapacity();
//        qDebug()<<air.getPower();
//        qDebug()<<air.getTemprature();
//        qDebug()<<ven.getAirVolumn();
//        qDebug()<<ven.getPower();
//        qDebug()<<und.getaveTemprature();
//        qDebug()<<und.getPower();
//        qDebug()<<hum.gethumidity();
//        qDebug()<<hum.getPower();
//        qDebug()<<deh.gethumidity();
//        qDebug()<<deh.getPower();

        //根据空调设备调整屋内温湿度及空气质量
        judgeair();
        //根据新风系统调整屋内温湿度及空气质量
        judgeven();
        //根据地暖系统调整屋内温湿度及空气质量
        judgeund();
        //根据加湿系统调整屋内温湿度及空气质量
        judgehum();
        //根据除湿系统调整屋内温湿度及空气质量
        judgedeh();

        warning();
        QTableWidgetItem *headerItem;
        QStringList headerText;
        headerText<<"时间"<<"温度"<<"湿度"<<"空气质量";
        tableWidget->setColumnCount(headerText.count());
        tableWidget->setRowCount(5);

        for(int i=0; i < tableWidget->columnCount(); i++)
        {
             headerItem = new QTableWidgetItem(headerText.at(i));
             headerItem->setTextColor(Qt::blue);
             tableWidget->setHorizontalHeaderItem(i,headerItem);
        }

        QTime current_time=QTime::currentTime();
        int hour=current_time.hour();
        int minute=current_time.minute();
        int second=current_time.second();

        //空调开启了制冷模式
        if((air.getCoolCapacity()>=air.getHeatCapacity())&&(air.getPower()>0))
        {
        //第一次的时间
        tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute).arg(second)));
        tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(in_temp)));
        tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(in_humidity)));
        tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(air_quality*0.996)));

        //第二次的时间
        tableWidget->setItem(1,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+1).arg(second)));
        tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(in_temp-0.2)));
        tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(in_humidity*0.98)));
        tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(air_quality*0.998)));

        //第三次的时间
        tableWidget->setItem(2,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+2).arg(second)));
        tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(in_temp-0.4)));
        tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(in_humidity*0.99)));
        tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(air_quality*0.991)));

        //第四次的时间
        tableWidget->setItem(3,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+3).arg(second)));
        tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(in_temp-0.8)));
        tableWidget->setItem(3,2,new QTableWidgetItem(QString::number(in_humidity*0.995)));
        tableWidget->setItem(3,3,new QTableWidgetItem(QString::number(air_quality*0.99)));

        //第五次的时间
        tableWidget->setItem(4,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+4).arg(second)));
        tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(in_temp-1.6)));
        tableWidget->setItem(4,2,new QTableWidgetItem(QString::number(in_humidity*0.996)));
        tableWidget->setItem(4,3,new QTableWidgetItem(QString::number(air_quality)));
        }
        //空调开启了制热模式或地暖系统开启
        else if(((air.getCoolCapacity()<air.getHeatCapacity())&&(air.getPower()>0))||(und.getPower()>0))
        {
        //第一次的时间
        tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute).arg(second)));
        tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(in_temp)));
        tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(in_humidity*0.993)));
        tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(air_quality*0.997)));

        //第二次的时间
        tableWidget->setItem(1,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+1).arg(second)));
        tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(in_temp+0.1)));
        tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(in_humidity*0.983)));
        tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(air_quality*0.993)));

        //第三次的时间
        tableWidget->setItem(2,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+2).arg(second)));
        tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(in_temp+0.3)));
        tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(in_humidity*0.988)));
        tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(air_quality*0.996)));

        //第四次的时间
        tableWidget->setItem(3,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+3).arg(second)));
        tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(in_temp+0.6)));
        tableWidget->setItem(3,2,new QTableWidgetItem(QString::number(in_humidity*0.989)));
        tableWidget->setItem(3,3,new QTableWidgetItem(QString::number(air_quality*0.992)));

        //第五次的时间
        tableWidget->setItem(4,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+4).arg(second)));
        tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(in_temp+1.2)));
        tableWidget->setItem(4,2,new QTableWidgetItem(QString::number(in_humidity*0.997)));
        tableWidget->setItem(4,3,new QTableWidgetItem(QString::number(air_quality)));
        }
        //判断是否开启了新风系统
        else if(ven.getPower()>0)
        {

            //第一次的时间
            tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute).arg(second)));
            tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(in_temp+0.5)));
            tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(in_humidity*0.993)));
            tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(air_quality*0.997)));

            //第二次的时间
            tableWidget->setItem(1,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+1).arg(second)));
            tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(in_temp-0.6)));
            tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(in_humidity*0.983)));
            tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(air_quality*0.993)));

            //第三次的时间
            tableWidget->setItem(2,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+2).arg(second)));
            tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(in_humidity*0.988)));
            tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(air_quality*0.996)));

            //第四次的时间
            tableWidget->setItem(3,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+3).arg(second)));
            tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(in_temp+0.4)));
            tableWidget->setItem(3,2,new QTableWidgetItem(QString::number(in_humidity*0.989)));
            tableWidget->setItem(3,3,new QTableWidgetItem(QString::number(air_quality*0.992)));

            //第五次的时间
            tableWidget->setItem(4,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+4).arg(second)));
            tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(in_temp-1.4)));
            tableWidget->setItem(4,2,new QTableWidgetItem(QString::number(in_humidity*0.997)));
            tableWidget->setItem(4,3,new QTableWidgetItem(QString::number(air_quality)));

        }
        //如果开启了加湿/除湿器，则湿度、空气质量会在5分钟内发生波动
        else if(hum.getPower()>0)
        {
            //第一次的时间
            tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute).arg(second)));
            tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(in_humidity+0.5)));
            tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(air_quality*0.997)));

            //第二次的时间
            tableWidget->setItem(1,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+1).arg(second)));
            tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(in_humidity+0.9)));
            tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(air_quality*0.993)));

            //第三次的时间
            tableWidget->setItem(2,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+2).arg(second)));
            tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(in_humidity+1.3)));
            tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(air_quality*0.996)));

            //第四次的时间
            tableWidget->setItem(3,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+3).arg(second)));
            tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(3,2,new QTableWidgetItem(QString::number(in_humidity+1.7)));
            tableWidget->setItem(3,3,new QTableWidgetItem(QString::number(air_quality*0.992)));

            //第五次的时间
            tableWidget->setItem(4,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+4).arg(second)));
            tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(4,2,new QTableWidgetItem(QString::number(in_humidity+2)));
            tableWidget->setItem(4,3,new QTableWidgetItem(QString::number(air_quality)));
        }
        else if(deh.getPower()>0)
        {
            //第一次的时间
            tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute).arg(second)));
            tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(in_humidity-0.5)));
            tableWidget->setItem(0,3,new QTableWidgetItem(QString::number(air_quality*0.997)));

            //第二次的时间
            tableWidget->setItem(1,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+1).arg(second)));
            tableWidget->setItem(1,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(1,2,new QTableWidgetItem(QString::number(in_humidity-0.9)));
            tableWidget->setItem(1,3,new QTableWidgetItem(QString::number(air_quality*0.993)));

            //第三次的时间
            tableWidget->setItem(2,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+2).arg(second)));
            tableWidget->setItem(2,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(2,2,new QTableWidgetItem(QString::number(in_humidity-1.3)));
            tableWidget->setItem(2,3,new QTableWidgetItem(QString::number(air_quality*0.996)));

            //第四次的时间
            tableWidget->setItem(3,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+3).arg(second)));
            tableWidget->setItem(3,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(3,2,new QTableWidgetItem(QString::number(in_humidity-1.7)));
            tableWidget->setItem(3,3,new QTableWidgetItem(QString::number(air_quality*0.992)));

            //第五次的时间
            tableWidget->setItem(4,0,new QTableWidgetItem(QString("%1:%2:%3").arg(hour).arg(minute+4).arg(second)));
            tableWidget->setItem(4,1,new QTableWidgetItem(QString::number(in_temp)));
            tableWidget->setItem(4,2,new QTableWidgetItem(QString::number(in_humidity-2)));
            tableWidget->setItem(4,3,new QTableWidgetItem(QString::number(air_quality)));
        }
        //设置单元格水平居中、竖直居中
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                QTableWidgetItem*item=tableWidget->item(j,i);
                item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }
        }
    });
}

void runface::judgeair()
{
   //首先得判断空调是否打开，即判断功率是否为0
   if(air.getPower())
    {
        //只要空调打开了，即功率不为0，空气湿度、空气质量就会下降
        in_humidity*=0.9;
        air_quality*=0.9;
        if(air.getTemprature())
        {
            in_temp=air.getTemprature()*0.95;
        }
        if(air.getHeatCapacity()>50)
        {
            in_temp+=2;
        }
        if(air.getCoolCapacity()>50)
        {
            in_temp-=1;
        }

    }
}
void runface::judgeven()
{
    //首先得判断新风系统是否开启，即判断功率是否为0
    if(ven.getPower())
    {
        //使用新风系统可以改良空气质量
        double x=ven.getAirVolumn()*0.01;
        air_quality+=x;
        //判断此时室内温度是大于还是小于室外温度，从而利用公式计算下降的温度
        if(in_temp>=20)
        {
            double a=ven.getAirVolumn()*0.05;
            in_temp-=a;
        }
        if(in_temp<20)
        {
            double a=ven.getAirVolumn()*0.05;
            in_temp+=a;
        }
        //判断此时室内湿度是大于还是小于室外湿度，从而利用公式计算下降的湿度
        if(in_humidity>=25)
        {
            double a=ven.getAirVolumn()*0.04;
            in_humidity-=a;
        }
        if(in_humidity<25)
        {
            double a=ven.getAirVolumn()*0.04;
            in_humidity+=a;
        }
    }
}
void runface::judgeund()
{
    //首先得判断地暖系统是否开启
    if(und.getPower())
    {
        double a=und.getPower()*0.02;
        in_temp+=a;
        double b=und.getPower()*0.01;
        air_quality-=b;
    }
}
void runface::judgehum()
{
    if(hum.getPower())
    {
        in_humidity=hum.gethumidity()*0.99;
        double b=hum.getPower()*0.01;
        air_quality-=b;
    }
}
void runface::judgedeh()
{
    if(deh.getPower())
    {
        in_humidity=deh.gethumidity()*0.99;
        double b=deh.getPower()*0.01;
        air_quality-=b;
    }
}
void runface::warning()
{
    if(air.getPower()+ven.getPower()+und.getPower()+hum.getPower()+deh.getPower()>4000)
    {
        QMessageBox message(QMessageBox::Warning, "警告","所有设备的总功率将超过4000W造成危险，您确定要这么做吗？");
        message.setStyleSheet("QLabel{""min-width: 245px;""min-height: 100px; ""}");
        message.show();
        message.exec();
    }
}
void runface::paintEvent(QPaintEvent*)
{
    QPainter painer(this);
    QPixmap pix;
    pix.load(":/image/14.png");
    painer.drawPixmap(0,0,this->width(),this->height(),pix);
}
void runface::recHeatCapacity(int a)
{
    air.setHeatCapacity(a);
}
void runface::recCoolCapacity(int a)
{
    air.setCoolCapacity(a);
}
void runface::recPower1(int a)
{
    air.setPower(a);
}
void runface::recTemprature(int a)
{
    air.setTemprature(a);
}
void runface::recAirVolumn(int a)
{
    ven.setAirVolumn(a);
}
void runface::recPower2(int a)
{
    ven.setPower(a);
}
void runface::recaveTemprature(int a)
{
    und.setaveTemprature(a);
}
void runface::recPower3(int a)
{
    und.setPower(a);
}
void runface::rechumidity1(int a)
{
    hum.sethumidity(a);
}
void runface::recPower4(int a)
{
    hum.setPower(a);
}
void runface::rechumidity2(int a)
{
    deh.sethumidity(a);
}
void runface::recPower5(int a)
{
    deh.setPower(a);
}
