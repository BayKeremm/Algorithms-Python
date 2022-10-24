#include "component.h"
Component::Component(std::string vendor) : vendor{vendor}{

    uuid = Uuid();
    std::cout << "Component constructor with vendor " << std::endl;

}
Component::Component() {

    uuid = Uuid();
    std::cout << "Component constructor default " << std::endl;

}

std::string Component::getVendor(){
    return vendor;
}
Uuid Component::getUuid(){
    return uuid;
}