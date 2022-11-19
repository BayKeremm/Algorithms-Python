#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include "tile.h"

class Node
{
public:
    Node(std::unique_ptr<Tile> &t);
    Node(std::unique_ptr<Tile> &t, Node *parent);
    int getX() const;
    int getY() const;
    int getW() const;
    int getCost() const;
    void setCost(int nw);
    void setParent(Node *ptr);
    Node *getParent();
    void setVisited();
    bool getVisited();
    void setDone();
    bool getDone();

private:
    int cost{0};
    std::unique_ptr<Tile> &ptr;
    Node *parent;
    bool visited;
    bool done;
};
#endif