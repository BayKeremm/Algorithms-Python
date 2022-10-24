#include "uuid.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <iomanip>

Uuid::Uuid(){
    srand(time(NULL));
    for(int i=0; i< 16; i++){
        id.c[i]=rand();
    }
    id.c[7] &= 0x4F;
    id.c[9] &= 0xBF;
}


bool Uuid::operator==(Uuid &other){
    return other.id.val == id.val;
}


std::ostream& operator<<(std::ostream& os, const Uuid& obj){
    for(int i=0; i<16; i++){
        os << std::setfill('0') << std::setw(2) << std::hex << (unsigned int) obj.id.c[i];
        if(i >=3 && i%2 && i<=10) os << "-";
    }
    return os;
}
