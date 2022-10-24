#ifndef GAS_H_
#define GAS_H_
#include<string> 

#include "sensor.h"
class GasSensor : public Sensor {
    private:
        int minLevel{0};
        int maxLevel{0};
    public:
    GasSensor(std::string vendor,int minLevel, int maxLevel);
    GasSensor();
    ~GasSensor() = default;
    int getMinLevel();
    int getMaxLevel();
    void panic() override ;
    std::string getAdditionalInfo() override;
};
//std::ostream& operator<<(std::ostream& os, std::unique_ptr<GasSensor> & sensor); //
//std::ostream& operator<<(std::ostream& os, GasSensor & sensor); //
#endif