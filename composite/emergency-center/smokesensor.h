#ifndef SMOKE_H_
#define SMOKE_H_
#include<string> 

#include "sensor.h"
class SmokeSensor : public Sensor {

    public:
    SmokeSensor(std::string vendor);
    SmokeSensor();
    ~SmokeSensor() = default;
    void panic() override ;
};
std::ostream& operator<<(std::ostream& os, std::unique_ptr<SmokeSensor> & sensor); //
std::ostream& operator<<(std::ostream& os, SmokeSensor & sensor); //
#endif