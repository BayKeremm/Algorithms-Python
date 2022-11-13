#include "node.h"
Node::Node(int x, int y, int w) : x{x}, y{y}, w{w}, parent{nullptr}
{
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
void Node::setW(int nw)
{
    w = nw;
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
bool Node::operator<(const Node &b) const
{
    return w > const_cast<Node *>(&b)->getW();
}
bool Node::operator==(const Node &b) const
{
    if (x == b.x && y == b.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
