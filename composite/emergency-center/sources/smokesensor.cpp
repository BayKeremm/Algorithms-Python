#include "../headers/smokesensor.h"
#include <iostream>

SmokeSensor::SmokeSensor( std::string vendor) :
    Sensor(vendor) 
{
      std::cout << " SmokeSensor constructor" << std::endl;
}

SmokeSensor::SmokeSensor() :
    Sensor() 
{
      std::cout << " SmokeSensor constructor default " << std::endl;
}

void SmokeSensor::panic(){
    std::cout << "Panic smoke sensor" << std::endl;
}
std::string SmokeSensor::getAdditionalInfo(){
    return "SmokeSensor(";
}

//std::ostream& operator<<(std::ostream & os, std::unique_ptr<SmokeSensor> & sensor){
    //// TODO: Add other custom prints for the smoke sensor
    //os <<"ID:" <<  sensor->getUuid() << std::endl;
    //os <<"Vendor:" <<  sensor->getVendor() << std::endl;
    //os <<"Active:" <<  sensor->getActive() << std::endl;
    //return os;
//}
//std::ostream& operator<<(std::ostream & os,SmokeSensor & sensor){
    //// TODO: Add other custom prints for the smoke sensor
    //os <<"ID:" <<  sensor.getUuid() << std::endl;
    //os <<"Vendor:" <<  sensor.getVendor() << std::endl;
    //os <<"Active:" <<  sensor.getActive() << std::endl;
    //return os;
//}