#include "motionsensor.h"
#include <iostream>

MotionSensor::MotionSensor(int id, int gen, std::string vendor) :
    Sensor{id,gen} ,vendor{vendor}{
      std::cout << " MotionSensor constructor" << std::endl;
}


void MotionSensor::panic(){
    std::cout << "Panic motion sensor" << std::endl;
}
