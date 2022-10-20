#ifndef MOTION_H_
#define MOTION_H_
#include<string> 

#include "sensor.h"
class MotionSensor : public Sensor {
    using Sensor::Sensor;
    
    public:
    MotionSensor(int id, int gen, std::string vendor);
    ~MotionSensor() = default;
    void panic() override ;

    protected:
        std::string vendor{"kerem"};
};
#endif