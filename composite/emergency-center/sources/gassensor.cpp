#include "../headers/gassensor.h"
#include <iostream>

GasSensor::GasSensor( std::string vendor, int minLevel, int maxLevel) :
    Sensor(vendor), minLevel{minLevel}, maxLevel{maxLevel}{
      std::cout << " GasSensor constructor" << std::endl;
}
GasSensor::GasSensor() :
    Sensor(){
      std::cout << " GasSensor constructor default " << std::endl;
}
int GasSensor::getMaxLevel(){
    return maxLevel;
}
int GasSensor::getMinLevel(){
    return minLevel;
}


void GasSensor::panic(){
    std::cout << "Panic Gas sensor" << std::endl;
}
std::string GasSensor::getAdditionalInfo(){
    return "GasSensor(MinLevel:" + std::to_string(minLevel) +", MaxLevel: "+  std::to_string(maxLevel);
}

//std::ostream& operator<<(std::ostream & os, std::unique_ptr<GasSensor> & sensor){
    //// TODO: Add other custom prints for gas sensor
    //os <<"ID:" <<  sensor->getUuid() << std::endl;
    //os <<"Vendor:" <<  sensor->getVendor() << std::endl;
    //os <<"Active:" <<  sensor->getActive() << std::endl;
    //return os;
//}

//std::ostream& operator<<(std::ostream & os, GasSensor & sensor){
    //// TODO: Add other custom prints for gas sensor
    //os <<"ID:" <<  sensor.getUuid() << std::endl;
    //os <<"Vendor:" <<  sensor.getVendor() << std::endl;
    //os <<"Active:" <<  sensor.getActive() << std::endl;
    //return os;
//}