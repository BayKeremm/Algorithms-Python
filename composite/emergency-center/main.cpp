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
    MotionSensor msensor(1,"Bosch",2);
    std::cout << msensor << std::endl;
    msensor++;
    std::cout << msensor << std::endl;

    auto building = std::make_unique<Node>(2,"Group T");
    auto lab = std::make_unique<Node>(2,"Electronics lab");
    lab->addChild(std::make_unique<GasSensor>(4,"imec"));
    building->addChild(std::make_unique<MotionSensor>(2,"imec",3));
    building->addChild(std::make_unique<SmokeSensor>(3,"Sony"));
    //building->addChild(std::make_unique<Node>(3,"Chemistry lab"));
    building->addChild(std::move(lab));
    building->test();
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