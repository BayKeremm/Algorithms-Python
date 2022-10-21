#include "sensor.h"
Sensor::Sensor(int id, int gen) : Component(id, gen)
{
      std::cout << "Sensor constructor" << std::endl;

}

void Sensor::panic(){
    std::cout << "Panic Sensor" << std::endl;
}
void Sensor::test(){
    panic();
    std::cout << "test function of sensor class" << std::endl;
}