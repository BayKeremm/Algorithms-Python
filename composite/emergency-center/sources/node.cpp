#include "node.h"

Node::Node( std::string name) : Component(), name{name}
{
      std::cout << "Node constructor" << std::endl;

}
Node::Node() : Component(){
      std::cout << "Node constructor default " << std::endl;
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

bool Node::removeSensor(Uuid id){
      bool removed{false};
      for(auto & sensor : sensors){
            if(sensor->getUuid() == id){
                 sensors.erase(
                  std::remove(sensors.begin(), sensors.end(),sensor)
                 ,sensors.end()); 
                 removed = true;
            }
      }
      return removed;

}
bool Node::removeNode(Uuid id){
      bool removed{false};
      for(auto & node : nodes){
            if(node->getUuid() == id){
                 nodes.erase(
                  std::remove(nodes.begin(), nodes.end(),node)
                 ,nodes.end()); 
                 removed = true;
            }
      }
      return removed;
}
void Node::test(){
      std::cout << "inside node: " << getName() << std::endl;
      for(auto & sensor : sensors){
            sensor->panic();
      }
      for(auto & node : nodes){
            node->test();
      }
      std::cout << "Node test" << std::endl;
}
void Node::printOverview(){
      std::cout << "inside node: " << getName() << std::endl;
      for(auto & sensor : sensors){
            std::cout<< sensor << std::endl;
      }
      //for(auto & node : nodes){
            //node->test();
      //}
}