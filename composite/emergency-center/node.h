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
        std::vector<std::unique_ptr<Sensor>> sensors;
        std::vector<std::unique_ptr<Node>> nodes;

    public:
        Node( std::string name);
        Node();
        ~Node() = default; // gives error saying this has no definition
        void addChild(std::unique_ptr<Sensor> sensor);
        void addChild(std::unique_ptr<Node> node);
        bool removeSensor(Uuid id);
        bool removeNode(Uuid id);
        std::string getName();
        std::string setName(std::string newName);
        void test() override;
};
#endif