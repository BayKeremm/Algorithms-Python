#ifndef MOTION_H_
#define MOTION_H_
#include<string> 
#include<memory> 

#include "sensor.h"
class MotionSensor : public Sensor {
    private:
        int activationRange{0};
    public:
        MotionSensor(std::string vendor, int activationRange);
        MotionSensor();
        ~MotionSensor() = default;
        void panic() override ;
        int getActivationRange();
        std::string getAdditionalInfo() override;
};
//std::ostream& operator<<(std::ostream& os, std::unique_ptr<MotionSensor> & sensor); //
//std::ostream& operator<<(std::ostream& os, MotionSensor & sensor); //
#endif