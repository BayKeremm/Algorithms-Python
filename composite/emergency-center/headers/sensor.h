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
        Sensor& operator++(); 
        Sensor& operator++(int); 
        Sensor& operator--(); 
        Sensor& operator--(int); 
        virtual std::string getAdditionalInfo() = 0;
        friend std::ostream& operator<<(std::ostream& os, std::unique_ptr<Sensor> & sensor); //
        friend std::ostream& operator<<(std::ostream& os, Sensor & sensor); //

};
#endif

/*use virtual destructors to avoid static binding to the base class destructor
test calls panic, if you do not define panic as virtual
you will have static binding to the member function of the base class
*/