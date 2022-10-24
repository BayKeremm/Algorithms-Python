#include "smokesensor.h"
#include <iostream>

SmokeSensor::SmokeSensor(int id, std::string vendor) :
    Sensor{id,vendor} 
{
      std::cout << " SmokeSensor constructor" << std::endl;
}


void SmokeSensor::panic(){
    std::cout << "Panic smoke sensor" << std::endl;
}

std::ostream& operator<<(std::ostream & os, std::unique_ptr<SmokeSensor> & sensor){
    // TODO: Add other custom prints for the smoke sensor
    os <<"ID:" <<  sensor->getID() << std::endl;
    os <<"Vendor:" <<  sensor->getVendor() << std::endl;
    os <<"Active:" <<  sensor->getActive() << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream & os,SmokeSensor & sensor){
    // TODO: Add other custom prints for the smoke sensor
    os <<"ID:" <<  sensor.getID() << std::endl;
    os <<"Vendor:" <<  sensor.getVendor() << std::endl;
    os <<"Active:" <<  sensor.getActive() << std::endl;
    return os;
}