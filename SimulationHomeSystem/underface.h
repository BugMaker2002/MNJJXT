#ifndef UNDERFACE_H
#define UNDERFACE_H

#include <QMainWindow>
#include "sys.h"
class underface : public QMainWindow
{
    Q_OBJECT
public:
    explicit underface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
    void sentaveTemprature(int);
    void sentPower(int);
};

#endif // UNDERFACE_H
