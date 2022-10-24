#include "gassensor.h"
#include <iostream>

GasSensor::GasSensor( std::string vendor) :
    Sensor(vendor){
      std::cout << " GasSensor constructor" << std::endl;
}
GasSensor::GasSensor() :
    Sensor(){
      std::cout << " GasSensor constructor default " << std::endl;
}


void GasSensor::panic(){
    std::cout << "Panic Gas sensor" << std::endl;
}

std::ostream& operator<<(std::ostream & os, std::unique_ptr<GasSensor> & sensor){
    // TODO: Add other custom prints for gas sensor
    os <<"ID:" <<  sensor->getUuid() << std::endl;
    os <<"Vendor:" <<  sensor->getVendor() << std::endl;
    os <<"Active:" <<  sensor->getActive() << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream & os, GasSensor & sensor){
    // TODO: Add other custom prints for gas sensor
    os <<"ID:" <<  sensor.getUuid() << std::endl;
    os <<"Vendor:" <<  sensor.getVendor() << std::endl;
    os <<"Active:" <<  sensor.getActive() << std::endl;
    return os;
}