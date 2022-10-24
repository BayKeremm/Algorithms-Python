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
        // problem, when using unique pointers here, ++ operator doesnt work
    //auto msensor2 = std::make_unique<MotionSensor>("IMEC",1);
    //std::cout << "------------------"<<std::endl;
    //std::cout << msensor2 << std::endl;
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

    auto motion = std::make_unique<GasSensor>("imec",2,6);
    //auto uuid = motion->getUuid();
    auto building = std::make_unique<Node>("Group T");
    //auto lab = std::make_unique<Node>("Electronics lab");
    //lab->addChild(std::make_unique<GasSensor>("imec"));
    building->addChild(std::move(motion));
    building->printOverview();
    //building->test();
    //std::cout << "------------------"<<std::endl;
    //building->removeSensor(uuid);
    //building->test();
    //std::cout << "------------------"<<std::endl;
    //building->addChild(std::make_unique<MotionSensor>("imec",3));
    //building->addChild(std::make_unique<SmokeSensor>("Sony"));
    //building->addChild(std::make_unique<Node>(3,"Chemistry lab"));
    //building->addChild(std::move(lab));
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