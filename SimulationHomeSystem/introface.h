#ifndef INTROFACE_H
#define INTROFACE_H

#include <QMainWindow>

class introface : public QMainWindow
{
    Q_OBJECT
public:
    explicit introface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:

};

#endif // INTROFACE_H
