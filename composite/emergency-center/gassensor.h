#ifndef GAS_H_
#define GAS_H_
#include<string> 

#include "sensor.h"
class GasSensor : public Sensor {
    private:
        int activationRange;
    public:
    GasSensor(std::string vendor);
    GasSensor();
    ~GasSensor() = default;
    void panic() override ;
};
std::ostream& operator<<(std::ostream& os, std::unique_ptr<GasSensor> & sensor); //
std::ostream& operator<<(std::ostream& os, GasSensor & sensor); //
#endif