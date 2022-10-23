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
