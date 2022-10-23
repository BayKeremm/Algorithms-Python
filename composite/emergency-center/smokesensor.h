#ifndef SMOKE_H_
#define SMOKE_H_
#include<string> 

#include "sensor.h"
class SmokeSensor : public Sensor {

    public:
    SmokeSensor(int id, std::string vendor);
    ~SmokeSensor() = default;
    void panic() override ;
};
#endif