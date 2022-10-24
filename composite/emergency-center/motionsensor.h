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
        void panic() override ;
        int getActivationRange();
};
std::ostream& operator<<(std::ostream& os, std::unique_ptr<MotionSensor> & sensor); //
std::ostream& operator<<(std::ostream& os, MotionSensor & sensor); //
#endif