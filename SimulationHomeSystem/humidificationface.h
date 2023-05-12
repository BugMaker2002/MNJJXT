#ifndef HUMIDIFICATIONFACE_H
#define HUMIDIFICATIONFACE_H

#include <QMainWindow>
#include "sys.h"
class humidificationface : public QMainWindow
{
    Q_OBJECT
public:
    explicit humidificationface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
    void senthumidity(int);
    void sentPower(int);

};

#endif // HUMIDIFICATIONFACE_H
