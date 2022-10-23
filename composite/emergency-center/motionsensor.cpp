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
//std::ostream& MotionSensor::operator<<(std::unique_ptr<Sensor> & sensor){
    //// problem of dynamic cast
    //MotionSensor * tmp = dynamic_cast<MotionSensor*>(sensor.get());
    //std::unique_ptr<MotionSensor> derivedPointer;
    //if(tmp != nullptr){
        //sensor.release();
        //derivedPointer.reset(tmp);
    //}
    //std::os <<"ID:" <<  derivedPointer->getID() << std::endl;
    //std::cout <<"Vendor:" <<  derivedPointer->getVendor() << std::endl;
    //std::cout <<"Active:" <<  derivedPointer->getActive() << std::endl;
    //std::cout <<"Activation Range:" << derivedPointer->getActivationRange() << std::endl;
    //return "End";
//}