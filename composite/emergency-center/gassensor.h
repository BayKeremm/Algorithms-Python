#ifndef GAS_H_
#define GAS_H_
#include<string> 

#include "sensor.h"
class GasSensor : public Sensor {
    private:
        int activationRange;
    public:
    GasSensor(int id, std::string vendor);
    ~GasSensor() = default;
    void panic() override ;
};
#endif