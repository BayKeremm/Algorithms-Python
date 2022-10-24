#include "motionsensor.h"
#include <iostream>

MotionSensor::MotionSensor(int id, std::string vendor, int actRange) :
    Sensor{id,vendor}, activationRange{actRange} 
{
      std::cout << " MotionSensor constructor" << std::endl;
}


void MotionSensor::panic(){
    std::cout << "Panic motion sensor" << std::endl;
}

int MotionSensor::getActivationRange(){
    return activationRange;
}
std::ostream& operator<<(std::ostream & os, std::unique_ptr<MotionSensor> & sensor){
    // problem of dynamic cast
    //MotionSensor * tmp = dynamic_cast<MotionSensor*>(sensor.get());
    //std::unique_ptr<MotionSensor> derivedPointer;
    //if(tmp != nullptr){
        //sensor.release();
        //derivedPointer.reset(tmp);
    //}
    os <<"ID:" <<  sensor->getID() << std::endl;
    os <<"Vendor:" <<  sensor->getVendor() << std::endl;
    os <<"Active:" <<  sensor->getActive() << std::endl;
    os <<"Activation Range:" << sensor->getActivationRange() << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream & os, MotionSensor & sensor){
    // problem of dynamic cast
    //MotionSensor * tmp = dynamic_cast<MotionSensor*>(sensor.get());
    //std::unique_ptr<MotionSensor> derivedPointer;
    //if(tmp != nullptr){
        //sensor.release();
        //derivedPointer.reset(tmp);
    //}
    os <<"ID:" <<  sensor.getID() << std::endl;
    os <<"Vendor:" <<  sensor.getVendor() << std::endl;
    os <<"Active:" <<  sensor.getActive() << std::endl;
    os <<"Activation Range:" << sensor.getActivationRange() << std::endl;
    return os;
}