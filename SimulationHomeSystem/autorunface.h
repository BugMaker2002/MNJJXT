#ifndef AUTORUNFACE_H
#define AUTORUNFACE_H

#include <QMainWindow>

class autorunface : public QMainWindow
{
    Q_OBJECT
public:
    explicit autorunface(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
signals:
private slots:
    void rectemp(int);
    void rechumidity(int);
};

#endif // AUTORUNFACE_H
