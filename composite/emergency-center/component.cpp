#include "component.h"
Component::Component(int id, int gen) : ID{id}, gen{gen}
{
      std::cout << "Component constructor" << std::endl;

}

int Component::generation(){
    return gen;
}
int Component::id(){
    return ID;
}
