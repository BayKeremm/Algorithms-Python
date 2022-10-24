#ifndef SENSOR_H_
#define SENSOR_H_
#include "component.h"
#include<iostream> 

class Sensor : public Component
{
    private:
        bool active{false};
    public:
        Sensor(std::string vendor);
        Sensor();
        ~Sensor() = default;
        bool setActive();
        bool unsetActive();
        void test() override; 
        bool getActive();   
        virtual void panic() = 0;
        virtual Sensor & operator++(); 
        virtual Sensor & operator++(int); 
        virtual Sensor & operator--(); 
        virtual Sensor & operator--(int); 

};
#endif

/*use virtual destructors to avoid static binding to the base class destructor
test calls panic, if you do not define panic as virtual
you will have static binding to the member function of the base class
*/