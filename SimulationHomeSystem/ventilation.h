#ifndef VENTILATION_H
#define VENTILATION_H

#include <QMainWindow>
#include "sys.h"
class ventilation : public QMainWindow
{
    Q_OBJECT
public:
    explicit ventilation(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
    void sentAirVolumn(int);
    void sentPower(int);
};

#endif // VENTILATION_H
