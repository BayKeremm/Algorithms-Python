#include "../headers/sensor.h"
Sensor::Sensor(std::string vendor) : Component(vendor, false)
{
      std::cout << "Sensor constructor" << std::endl;

}
Sensor::Sensor() : Component()
{
      std::cout << "Sensor constructor default" << std::endl;

}

void Sensor::test(){
    panic();
    //std::cout << "test function of sensor class" << std::endl;
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
std::ostream& operator<<(std::ostream & os, std::shared_ptr<Sensor> & sensor){
    os << sensor->getAdditionalInfo();
    os <<", ID:" <<  sensor->getUuid();
    os <<", Vendor:" <<  sensor->getVendor();
    os <<", Active:" <<  sensor->getActive() << ")"<< std::endl;
    return os;
}
//std::ostream& operator<<(std::ostream & os, Sensor & sensor){
    //os << sensor.getAdditionalInfo();
    //os <<", ID:" <<  sensor.getUuid();
    //os <<", Vendor:" <<  sensor.getVendor();
    //os <<", Active:" <<  sensor.getActive() << ")"<< std::endl;
    //return os;
//}


 // OPERATOR OVERLOADS
void  Sensor::operator++(){
    this->setActive();
}
void  Sensor::operator--(){
    this->unsetActive();
}
std::string Sensor::getSensorInfo(){
    return getAdditionalInfo() + ", Active:" + std::to_string(getActive());
}