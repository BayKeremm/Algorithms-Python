#ifndef Component_H_
#define Component_H_
#include <iostream>
class Component
{
    protected:
        int  ID;
        int gen;
    public:
        Component(int id, int gen);
        Component()= default;
        virtual ~Component() = default;
        int generation();
        int id();
        virtual void test() = 0;
};
#endif