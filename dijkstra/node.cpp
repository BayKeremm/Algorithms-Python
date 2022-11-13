#include "node.h"
Node::Node(int x, int y, int w) : x{x}, y{y}, w{w}
{
}
Node::Node(int x, int y, int w, Node *ptr) : x{x}, y{y}, w{w}, parent{ptr}
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

void Node::setDone()
{
    done = true;
}
bool Node::getDone()
{
    return done;
}
bool Node::operator<(const Node &b) const
{
    return (*this).w > b.w;
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
