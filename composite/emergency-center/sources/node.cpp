#include "../headers/node.h"

Node::Node( std::string name) : Component("no-vendor",true), name{name}
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

void Node::addChild(std::shared_ptr<Component> component){
      components.push_back(component);
}

bool Node::removeComponent(Uuid id){
      bool removed{false};
      for(auto & component : components){
            if(component->getUuid() == id){
                 components.erase(
                  std::remove(components.begin(), components.end(), component)
                 ,components.end()); 
                 removed = true;
            }
      }
      return removed;
}

void Node::test(){
      std::cout << "inside component: " << getName() << std::endl;
      for(auto & component : components){
            component->test();
      }
      std::cout << "end component: " << getName() << std::endl;
}
void Node::printOverview(){
      std::cout << "inside component: " << getName() << std::endl;
      for(auto & sensor : components){
            if(!sensor->isComposite()){
                  std::cout<< sensor << std::endl;
            }
      }
}
void  Node::operator++(){
      for(auto  & component: components){
            ++(*component);
      }
}
void  Node::operator--(){
      for(auto  & component: components){
            --(*component);
      }
}
std::string  Node::getSensorInfo(){
      return "";
}