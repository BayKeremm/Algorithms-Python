#include "gassensor.h"
#include <iostream>

GasSensor::GasSensor(int id, std::string vendor) :
    Sensor{id,vendor}{
      std::cout << " GasSensor constructor" << std::endl;
}


void GasSensor::panic(){
    std::cout << "Panic Gas sensor" << std::endl;
}
