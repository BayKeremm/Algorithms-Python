#include <iostream>
#include <vector>
#include <memory>
#include "../headers/sensor.h"
#include "../headers/node.h"
#include "../headers/component.h"
#include "../headers/motionsensor.h"
#include "../headers/smokesensor.h"
#include "../headers/gassensor.h"
// USE PRE INCREMENT, they are more efficient, avoids making a copy of the element

int main(){

    // TODO: TESTS
        // problem, when using unique pointers here, ++ operator doesnt work
    //auto msensor2 = std::make_shared<MotionSensor>("IMEC",1);
    //std::cout << "------------------"<<std::endl;
    //std::cout <<msensor2 << std::endl;
    //msensor2->operator++(); // I could not find another way to call it on the smart pointers 
    //std::cout << msensor2 << std::endl;



    //std::cout << "------------------"<<std::endl;
    //std::cout << "------------------"<<std::endl;
    //std::cout << "------------------"<<std::endl;
    //std::cout << "------------------"<<std::endl;



    //MotionSensor msensor("Bosch",2);
    //std::cout << msensor << std::endl;
    //msensor++;
    //std::cout << msensor << std::endl;
    //std::cout << "------------------"<<std::endl;

    auto motion = std::make_shared<GasSensor>("imec",2,6);
    //auto uuid = motion->getUuid();
    auto building = std::make_shared<Node>("Group T");
    //lab->addChild(std::make_shared<MotionSensor>("KEREM",2));
    //building->addChild(lab);
    building->addChild(motion);
    //building->printOverview();
    building->test();
    std::cout << "------------------"<<std::endl;
    building->printOverview();
    ++(*building);
    std::cout << "------------------"<<std::endl;
    building->printOverview();
    //building->removeComponent(uuid);
    //building->test();
    //std::cout << "------------------"<<std::endl;

    //building->addChild(std::make_shared<MotionSensor>("imec",3));
    //building->addChild(std::make_shared<SmokeSensor>("Sony"));
    //building->addChild(std::make_shared<Node>(3,"Chemistry lab"));

    //building->test();
    //std::cout << "------------------"<<std::endl;
    //std::cout << std::endl;
    //std::cout << std::endl;
    //std::cout << std::endl;
    //building->printOverview();
    /*
                                building
                                *    *   *
                            *        *       *
                        *            *           *
                    Electronics lab  *               MotionSensor + SmokeSensor
                                     *
                                Chemistry lab
*/
}