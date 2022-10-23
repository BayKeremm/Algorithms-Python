#include "node.h"
#include "sensor.h"

Node::Node(int id, std::string name) : Component(id), name{name}
{
      std::cout << "Node constructor" << std::endl;

}
std::string Node::getName(){
      return name;
}
std::string Node::setName(std::string newName){
      name = newName;
      return name;
}

void Node::addChild(std::unique_ptr<Sensor> sensor){
      sensors.push_back(std::move(sensor));
}
void Node::addChild(std::unique_ptr<Node> node){
      nodes.push_back(std::move(node));
}

bool Node::removeSensor(int id){
      bool removed{false};
      for(auto & sensor : sensors){
            if(sensor->getID() == id){
                 sensors.erase(
                  std::remove(sensors.begin(), sensors.end(),sensor)
                 ,sensors.end()); 
                 removed = true;
            }
      }
      return removed;

}
bool Node::removeNode(int id){
      bool removed{false};
      for(auto & node : nodes){
            if(node->getID() == id){
                 nodes.erase(
                  std::remove(nodes.begin(), nodes.end(),node)
                 ,nodes.end()); 
                 removed = true;
            }
      }
      return removed;
}
void Node::test(){
      for(auto & sensor : sensors){
            sensor->panic();
      }
      for(auto & node : nodes){
            node->test();
      }
      std::cout << "Node test" << std::endl;
}