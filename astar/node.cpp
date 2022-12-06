#include "node.hpp"
Node::Node(int x, int y, float w, Node *ptr) : 
w{w}, cost{0}, x{x}, y{y},parent{ptr},
 flag{0}
{
}
Node::Node( const Node & other): w{other.w}, cost{other.cost}, x{other.x}, y{other.y},parent{other.parent},
 flag{other.flag}
{ 
    std::cout << "Copy ructor is called" << std::endl;
}
Node::Node(Node && other) noexcept
{
    std::cout << "Move ructor is called" << std::endl;
    x = other.x;
    y = other.y;
    w = other.w;
    parent = other.parent;
    flag = other.flag;
    cost = other.cost;
}
int Node::getX() 
{
    return x;
}
int Node::getY() 
{
    return y;
}
int Node::getW() 
{
    return w;
}
int Node::getCost() const
{
    return cost;
}
void Node::setCost(int nw)
{
    cost = nw;
}

void Node::setParent(Node *ptr)
{
    parent = ptr;
}
Node *Node::getParent() 
{
    return parent;
}
void Node::setVisited2(char f)
{
    flag = f;
}
char Node::getVisited2() 
{
    return flag;
}

void Node::setDone2(char f)
{
    flag = f;
}
char Node::getDone2() 
{
    return flag;
}

void Node::reset()
{
    flag = 0 ;
    cost = 0;
}
