#include "sys.h"

sys::sys()
{

}
Space::Space(int height, int width)
{
    setheight(height);
    setwidth(width);
}
void Space::setheight(int height)
{
    this->height = height;
}
void Space::setwidth(int width)
{
    this->width = width;
}
int Space::getheight() const
{
    return height;
}
int Space::getwidth() const
{
    return width;
}
//实现空调类
AirConditional::AirConditional(int CoolCapacity, int HeatCapacity, int Power,int Temprature)
{
    setCoolCapacity(CoolCapacity);
    setHeatCapacity(HeatCapacity);
    setPower(Power);
    setTemprature(Temprature);
}
void AirConditional::setCoolCapacity(int CoolCapacity)
{
    this->CoolCapacity = CoolCapacity;
}
void AirConditional::setHeatCapacity(int HeatCapacity)
{
    this->HeatCapacity = HeatCapacity;
}
void AirConditional::setPower(int Power)
{
    this->Power = Power;
}
void AirConditional::setTemprature(int Temprature)
{
    this->Temprature = Temprature;
}
int AirConditional::getCoolCapacity() const
{
    return CoolCapacity;
}
int AirConditional::getHeatCapacity() const
{
    return HeatCapacity;
}
int AirConditional::getPower() const
{
    return Power;
}
int AirConditional::getTemprature() const
{
    return Temprature;
}

//实现新风系统
ventilationSystem::ventilationSystem(int AirVolumn, int Power)
{
    setAirVolumn(AirVolumn);
    setPower(Power);
}
void ventilationSystem::setAirVolumn(int AirVolumn)
{
    this->AirVolumn = AirVolumn;
}
void ventilationSystem::setPower(int Power)
{
    this->Power = Power;
}
int ventilationSystem::getAirVolumn() const
{
    return AirVolumn;
}
int ventilationSystem::getPower() const
{
    return Power;
}
//实现地暖系统
UnderSystem::UnderSystem(int aveTemprature,int power)
{
    setaveTemprature(aveTemprature);
    setPower(power);
}
void UnderSystem::setaveTemprature(int aveTemprature)
{
    this->aveTemprature = aveTemprature;
}
void UnderSystem::setPower(int power)
{
    this->Power=power;
}
int UnderSystem::getaveTemprature() const
{
    return aveTemprature;
}
int UnderSystem::getPower() const
{
    return Power;
}
//实现加湿系统
HumidificationSystem::HumidificationSystem(int humidity, int Power)
{
    sethumidity(humidity);
    setPower(Power);
}
void HumidificationSystem::sethumidity(int humidity)
{
    this->humidity = humidity;
}
void HumidificationSystem::setPower(int Power)
{
    this->Power = Power;
}
int HumidificationSystem::gethumidity() const
{
    return humidity;
}
int HumidificationSystem::getPower() const
{
    return Power;
}
//实现除湿系统
DehumidificationSystem::DehumidificationSystem(int humidity, int Power)
{
    sethumidity(humidity);
    setPower(Power);
}
void DehumidificationSystem::sethumidity(int humidity)
{
    this->humidity = humidity;
}
void DehumidificationSystem::setPower(int Power)
{
    this->Power = Power;
}
int DehumidificationSystem::gethumidity() const
{
    return humidity;
}
int DehumidificationSystem::getPower() const
{
    return Power;
}
