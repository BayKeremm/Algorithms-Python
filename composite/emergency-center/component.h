#ifndef Component_H_
#define Component_H_
#include <iostream>
class Component
{
    private:
        int  ID{0};
        std::string vendor{"no-vendor"};
    public:
        Component(int id, std::string vendor);
        Component(int id);
        Component()= default;
        virtual ~Component() = default;
        std::string getVendor();
        int getID();
        int setID(int newID);
        virtual void test() = 0;
};
#endif