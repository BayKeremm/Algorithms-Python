#ifndef NODE_H_
#define NODE_H_
#include<string>
#include "component.h"
#include "sensor.h"
#include "uuid.h"
#include <vector>

class Node : public Component
{
    private:
        std::string name{"missing name"};
        std::vector<std::shared_ptr<Component>> components;

    public:
        void printOverview();
        Node( std::string name);
        Node();
        ~Node() = default; // gives error saying this has no definition

        void addChild(std::shared_ptr<Component> component);
        bool removeComponent(Uuid id);

        std::string getName();
        std::string setName(std::string newName);

        void  operator++()override; 
        void  operator--()override; 

        void test() override;
        std::string getSensorInfo() override;
};
#endif