#include "component.h"
Component::Component(int id, std::string vendor) : ID{id}, vendor{vendor}
{
      std::cout << "Component constructor" << std::endl;

}
Component::Component(int id) : ID{id}{
      std::cout << "Component constructor 2 " << std::endl;

}

std::string Component::getVendor(){
    return vendor;
}
int Component::getID(){
    return ID;
}
int Component::setID(int newID){
    ID = newID;
    return ID;
}
