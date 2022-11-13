#include "../headers/component.h"
Component::Component(std::string vendor, bool comp) : composite{comp},vendor{vendor}{

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
bool Component::isComposite(){
    return composite;
}

std::ostream& operator<<(std::ostream & os, std::shared_ptr<Component> & sensor){
    os << sensor->getSensorInfo()
    <<", ID:" <<  sensor->getUuid()
    <<", Vendor:" <<  sensor->getVendor() << ")";
    return os;
}