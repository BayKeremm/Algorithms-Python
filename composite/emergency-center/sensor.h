#ifndef SENSOR_H_
#define SENSOR_H_
#include "component.h"
#include<iostream> 

class Sensor : public Component
{
    public:
        Sensor(int id, int gen);
        Sensor() = default;
        ~Sensor() = default;
        void test() override;
        virtual void panic();
};
#endif

/*use virtual destructors to avoid static binding to the base class destructor
test calls panic, if you do not define panic as virtual
you will have static binding to the member function of the base class
*/