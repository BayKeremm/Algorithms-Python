#include "node.h"
// Node::Node(std::unique_ptr<Tile> &t) : ptr{t}
//{
// }
// Node::Node(std::unique_ptr<Tile> &t, Node *prev) : ptr{t}, parent{prev}
//{
// }
Node::Node(int x, int y, float w) : x{x}, y{y}, w{w}
{
}
Node::Node(int x, int y, float w, Node *ptr) : x{x}, y{y}, w{w}, parent{ptr}
{
}
Node::Node(const Node & other):
 x{other.x}, y{other.y}, w{other.w}, parent{other.parent},
 visited{other.visited}, done{other.done}, cost{other.cost}
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
    visited = other.visited;
    done = other.done;
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
void Node::setVisited(bool val)
{
    visited = val;
}
bool Node::getVisited()
{
    return visited;
}

void Node::setDone(bool val)
{
    done = val;
}
bool Node::getDone()
{
    return done;
}