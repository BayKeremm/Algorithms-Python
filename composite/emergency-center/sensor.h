#ifndef SENSOR_H_
#define SENSOR_H_
#include "component.h"
#include<iostream> 

class Sensor : public Component
{
    private:
        bool active{false};
    public:
        Sensor(int id, std::string vendor);
        Sensor() = default;
        ~Sensor() = default;
        void test() override; //
        bool getActive();   //
        virtual void panic() = 0;
        //virtual std::ostream& operator<<(std::ostream& os, std::unique_ptr<Sensor> & component)=0; //
        //void operator++(); //
        //void operator--(); //

};
#endif

/*use virtual destructors to avoid static binding to the base class destructor
test calls panic, if you do not define panic as virtual
you will have static binding to the member function of the base class
*/