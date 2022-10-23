#ifndef MOTION_H_
#define MOTION_H_
#include<string> 
#include<memory> 

#include "sensor.h"
class MotionSensor : public Sensor {
    private:
        int activationRange;
    public:
    MotionSensor(int id, std::string vendor, int activationRange);
    ~MotionSensor() = default;
    //std::ostream& operator<<(std::ostream&, std::unique_ptr<Sensor> & component) override; //
    void panic() override ;
    int getActivationRange();
};
#endif