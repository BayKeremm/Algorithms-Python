#include <iostream>
#include <vector>
#include <memory>
#include "sensor.h"
#include "motionsensor.h"


int main(){

    //Sensor sensor1{0,3};
    //MotionSensor msensor1{1,4,"polat alemdar"};
    //sensor1.test();
    //msensor1.test();

    //std::cout << std::endl;
    //std::cout << std::endl;
    //msensor1.panic();
    //Sensor * sensor {&msensor1};
    //sensor->panic();
    //std::cout << std::endl;
    //std::cout << std::endl;
    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.push_back(std::make_unique<Sensor>(12,5)); 
    sensors.push_back(std::make_unique<MotionSensor>(12,5,"manyak cocuk")); 
    for(const auto& sensor : sensors){
        sensor->test();
        std::cout << std::endl;
        std::cout << std::endl;
    }
}