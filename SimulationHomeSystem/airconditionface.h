#ifndef AIRCONDITIONFACE_H
#define AIRCONDITIONFACE_H

#include <QMainWindow>
#include "sys.h"
#include <QLabel>
class airconditionface:public QMainWindow
{
    Q_OBJECT
public:
    explicit airconditionface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);

signals:
    void sentHeatCapacity(int);
    void sentCoolCapacity(int);
    void sentPower(int);
    void sentTemprature(int);
};

#endif // AIRCONDITIONFACE_H
