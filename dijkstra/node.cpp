#include "node.h"
Node::Node(std::unique_ptr<Tile> &t) : ptr{t}
{
}
Node::Node(std::unique_ptr<Tile> &t, Node *prev) : ptr{t}, parent{prev}
{
}
int Node::getX()
{
    return ptr->getXPos();
}
int Node::getY()
{
    return ptr->getYPos();
}
int Node::getW() const
{
    return ptr->getValue();
}
void Node::setW(int nw)
{
    ptr->setValue(nw);
}

void Node::setParent(Node *ptr)
{
    parent = ptr;
}
Node *Node::getParent()
{
    return parent;
}
void Node::setVisited()
{
    visited = true;
}
bool Node::getVisited()
{
    return visited;
}

void Node::setDone()
{
    done = true;
}
bool Node::getDone()
{
    return done;
}