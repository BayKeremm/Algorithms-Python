#ifndef COMP_H_
#define COMP_H_
#include "node.h"
class comparator
{
public:
    bool operator()(const Node *a, const Node *b)
    {
        return a->getW() > b->getW();
    }
};

#endif