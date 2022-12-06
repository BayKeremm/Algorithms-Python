#include "node.hpp"
Node::Node(int x, int y, float w) : x{x}, y{y}, w{w}, cost{0}, flag{0}
{
}
Node::Node(int x, int y, float w, Node *ptr) : x{x}, y{y}, w{w}, parent{ptr}, cost{0},flag{0}
{
}
Node::Node(const Node & other):
 x{other.x}, y{other.y}, w{other.w}, parent{other.parent},
 flag{other.flag}, cost{other.cost}
{ 
    std::cout << "Copy constructor is called" << std::endl;
}
Node::Node(Node && other) noexcept
{
    std::cout << "Move constructor is called" << std::endl;
    x = other.x;
    y = other.y;
    w = other.w;
    parent = other.parent;
    flag = other.flag;
    cost = other.cost;
}
int Node::getX() const
{
    return x;
}
int Node::getY() const
{
    return y;
}
int Node::getW() const
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
//void Node::setVisited(bool val)
//{
    //visited = val;
//}
//bool Node::getVisited()
//{
    //return visited;
//}

//void Node::setDone(bool val)
//{
    //done = val;
//}
//bool Node::getDone()
//{
    //return done;
//}

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