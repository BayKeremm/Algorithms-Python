#include "sensor.h"
Sensor::Sensor(int id, std::string vendor) : Component(id, vendor)
{
      std::cout << "Sensor constructor" << std::endl;

}

void Sensor::test(){
    panic();
    std::cout << "test function of sensor class" << std::endl;
}


bool Sensor::getActive(){
    return active;
}

//void Sensor::operator++(){
    //active = true;
//}
//void Sensor::operator--(){
    //active = false;
    
//}

