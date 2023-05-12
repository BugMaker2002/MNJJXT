#ifndef RUNFACE_H
#define RUNFACE_H

#include <QMainWindow>

class runface : public QMainWindow
{
    Q_OBJECT
public:
    explicit runface(QWidget *parent = nullptr);
    void judgeair();
    void judgeven();
    void judgeund();
    void judgehum();
    void judgedeh();
    void warning();
    void paintEvent(QPaintEvent*);
private slots:

    //空调
    void recHeatCapacity(int);
    void recPower1(int);
    void recCoolCapacity(int);
    void recTemprature(int);

    //新风
    void recAirVolumn(int);
    void recPower2(int);

    //地暖系统
    void recaveTemprature(int);
    void recPower3(int);

    //加湿系统
    void rechumidity1(int);
    void recPower4(int);

    //除湿系统
    void rechumidity2(int);
    void recPower5(int);

signals:
private:
    static double in_temp;
    static double in_humidity;
    static double air_quality;

};

#endif // RUNFACE_H
