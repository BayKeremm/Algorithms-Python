#ifndef Component_H_
#define Component_H_
#include <iostream>
#include "uuid.h"
class Component
{
    private:
        Uuid uuid;
        std::string vendor;
        bool composite;
    public:
        Component(std::string vendor, bool comp);
        Component();
        virtual ~Component() = default;
        std::string getVendor();
        bool isComposite();

        Uuid getUuid();


        virtual void  operator++() = 0; 
        virtual void  operator--() = 0; 

        virtual void test() = 0;
        friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Component> & component); //
        virtual std::string getSensorInfo() = 0;
        //friend std::ostream& operator<<(std::ostream& os, Sensor & sensor); //
};
#endif