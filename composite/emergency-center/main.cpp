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
    MotionSensor msensor("Bosch",2);
    std::cout << msensor << std::endl;
    msensor++;
    std::cout << msensor << std::endl;

    auto smoke = std::make_unique<SmokeSensor>("imec");
    auto uuid = smoke->getUuid();
    auto building = std::make_unique<Node>("Group T");
    auto lab = std::make_unique<Node>("Electronics lab");
    lab->addChild(std::make_unique<GasSensor>("imec"));
    building->addChild(std::move(smoke));
    building->test();
    std::cout << "------------------"<<std::endl;
    building->removeSensor(uuid);
    building->test();
    std::cout << "------------------"<<std::endl;
    building->addChild(std::make_unique<MotionSensor>("imec",3));
    building->addChild(std::make_unique<SmokeSensor>("Sony"));
    //building->addChild(std::make_unique<Node>(3,"Chemistry lab"));
    building->addChild(std::move(lab));
    building->test();
    std::cout << "------------------"<<std::endl;
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