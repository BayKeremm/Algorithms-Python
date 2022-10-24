#include "sensor.h"
Sensor::Sensor(std::string vendor) : Component(vendor)
{
      std::cout << "Sensor constructor" << std::endl;

}
Sensor::Sensor() : Component()
{
      std::cout << "Sensor constructor default" << std::endl;

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
std::ostream& operator<<(std::ostream & os, std::unique_ptr<Sensor> & sensor){
    os << sensor->getAdditionalInfo() << std::endl;
    os <<"ID:" <<  sensor->getUuid() << std::endl;
    os <<"Vendor:" <<  sensor->getVendor() << std::endl;
    os <<"Active:" <<  sensor->getActive() << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream & os, Sensor & sensor){
    os << sensor.getAdditionalInfo()<< std::endl;
    os <<"ID:" <<  sensor.getUuid() << std::endl;
    os <<"Vendor:" <<  sensor.getVendor() << std::endl;
    os <<"Active:" <<  sensor.getActive() << std::endl;
    return os;
}

 // OPERATOR OVERLOADS

Sensor&  Sensor::operator++(){
    this->setActive();
    return *this;
}
Sensor& Sensor::operator--(){
    this->unsetActive();
    return *this;
}
// sensor++ and ++sensor behave the same.
Sensor& Sensor::operator++(int){
    this->setActive();
    return *this;
}
Sensor& Sensor::operator--(int){
    this->unsetActive();
    return *this;
}
