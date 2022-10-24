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
bool Sensor::setActive(){
    active = true;
    return active;
}
bool Sensor::unsetActive(){
    active = false;
    return active;
}


Sensor & Sensor::operator++(){
    this->setActive();
    return *this;
}
Sensor & Sensor::operator--(){
    this->unsetActive();
    return *this;
    
}
// sensor++ and ++sensor behave the same.
Sensor & Sensor::operator++(int){
    this->setActive();
    return *this;
}
Sensor & Sensor::operator--(int){
    this->unsetActive();
    return *this;
    
}

