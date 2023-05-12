#ifndef DEHUMIDIFICATION_H
#define DEHUMIDIFICATION_H

#include <QMainWindow>
#include "sys.h"
class dehumidification : public QMainWindow
{
    Q_OBJECT
public:
    explicit dehumidification(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
    void senthumidity(int);
    void sentPower(int);
};

#endif // DEHUMIDIFICATION_H
