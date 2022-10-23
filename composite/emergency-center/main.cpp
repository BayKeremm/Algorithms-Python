#include <iostream>
#include <vector>
#include <memory>
#include "sensor.h"
#include "node.h"
#include "component.h"
#include "motionsensor.h"
#include "smokesensor.h"
#include "gassensor.h"


int main(){

    // TODO: TESTS
    auto msensor = std::make_unique<MotionSensor>(1,"Bosch",2);
    //auto gsensor = std::make_unique<GasSensor>(2,"imec");
    //auto gsensor = std::make_unique<GasSensor>(2,"imec");

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
    //std::vector<std::unique_ptr<Component>> components;
    //components.push_back(std::make_unique<Sensor>(12,5)); 
    //components.push_back(std::make_unique<MotionSensor>(12,5,"manyak cocuk")); 
    //for(const auto& component : components){
        //component->test();
        //std::cout << component->id() << std::endl;
        //std::cout <<component->generation()<< std::endl;
    //}
    //Node node1{1,"Room 5"};
    //node1.addChild(std::move(std::make_unique<MotionSensor>(12,5,"manyak cocuk")));
    //node1.removeSensor(12);
    // how to pass the MotionSensor object

}