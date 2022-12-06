#ifndef COMP_H_
#define COMP_H_
#include "node.hpp"
class comparator
{
public:
    bool operator()(const Node *a, const Node *b)
    {
        return a->getCost() > b->getCost();
    }
};

#endif