#ifndef AUTOMODEFACE_H
#define AUTOMODEFACE_H

#include <QMainWindow>

class automodeface : public QMainWindow
{
    Q_OBJECT
public:
    explicit automodeface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
    void senttemp(int);
    void senthumidity(int);
};

#endif // AUTOMODEFACE_H
