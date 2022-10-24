#ifndef Component_H_
#define Component_H_
#include <iostream>
#include "uuid.h"
class Component
{
    private:
        Uuid uuid;
        std::string vendor{"no-vendor"};
    public:
        Component(std::string vendor);
        Component();
        virtual ~Component() = default;
        std::string getVendor();

        Uuid getUuid();

        virtual void test() = 0;
};
#endif