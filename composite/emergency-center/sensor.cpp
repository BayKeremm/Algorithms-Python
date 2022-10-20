#include "sensor.h"
#include<iostream> 

Sensor::Sensor(int id, int gen) : ID{id}, gen{gen}
{
      std::cout << "Sensor constructor" << std::endl;

}

int Sensor::generation(){
    return gen; 
}
int Sensor::id(){
    return ID; 
}
void Sensor::panic(){
    std::cout << "Panic Sensor" << std::endl;
}
void Sensor::test(){
    panic();
    std::cout << "test function of sensor class" << std::endl;
}