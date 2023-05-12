#include "introface.h"
#include <QPainter>
introface::introface(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(1000,600);
    this->setWindowIcon(QPixmap(":/image/icon.png"));
    this->setWindowTitle("产品介绍");
}
void introface::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/13.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
