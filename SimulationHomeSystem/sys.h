#ifndef SYS_H
#define SYS_H

class sys
{
public:
    sys();
};


//创建空间类
class Space
{
public:
    Space(int = 10, int = 10);
    void setheight(int);
    void setwidth(int);
    int getheight() const;
    int getwidth() const;
private:
    int height;
    int width;
};

//创建空调类
class AirConditional
{
public:
    AirConditional(int = 100, int = 100, int = 0,int=25);
    void setCoolCapacity(int);
    void setHeatCapacity(int);
    void setPower(int);
    void setTemprature(int);
    int getCoolCapacity() const;
    int getHeatCapacity() const;
    int getPower() const;
    int getTemprature() const;
private:
    int CoolCapacity;
    int HeatCapacity;
    int Power;
    int Temprature;
};
static AirConditional air;
//新风系统
class ventilationSystem
{
public:
    ventilationSystem(int = 100, int = 0);
    void setAirVolumn(int);
    void setPower(int);
    int getAirVolumn() const;
    int getPower() const;
private:
    int AirVolumn;
    int Power;
};
static ventilationSystem ven;
//地暖系统
class UnderSystem
{
public:
    UnderSystem(int = 25,int=0);
    void setaveTemprature(int);
    void setPower(int);
    int getaveTemprature() const;
    int getPower() const;
private:
    int aveTemprature;
    int Power;
};
static UnderSystem und;
//加湿系统
class HumidificationSystem
{
public:
    HumidificationSystem(int = 25, int = 0);
    void sethumidity(int);
    void setPower(int);
    int gethumidity() const;
    int getPower() const;
private:
    int humidity;
    int Power;
};
static HumidificationSystem hum;
//除湿系统
class DehumidificationSystem
{
public:
    DehumidificationSystem(int = 25, int = 0);
    void sethumidity(int);
    void setPower(int);
    int gethumidity() const;
    int getPower() const;
private:
    int humidity;
    int Power;
};
static DehumidificationSystem deh;
#endif // SYS_H
