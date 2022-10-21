#include <iostream>
#include <vector>
#include <memory>
#include "sensor.h"
#include "component.h"
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
    std::vector<std::unique_ptr<Component>> components;
    components.push_back(std::make_unique<Sensor>(12,5)); 
    components.push_back(std::make_unique<MotionSensor>(12,5,"manyak cocuk")); 
    for(const auto& component : components){
        component->test();
        std::cout << component->id() << std::endl;
        std::cout <<component->generation()<< std::endl;
    }
}