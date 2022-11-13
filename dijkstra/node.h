#ifndef NODE_H_
#define NODE_H_
#include <iostream>

class Node
{
public:
    Node(int x, int y, int w);
    Node(int x, int y, int w, Node *parent);
    int getX();
    int getY();
    int getW() const;
    void setW(int nw);
    void setParent(Node *ptr);
    Node *getParent();
    void setVisited();
    bool getVisited();
    void setDone();
    bool getDone();
    bool operator<(const Node &b) const;
    bool operator==(const Node &b) const;

private:
    int x;
    int y;
    int w;
    Node *parent;
    bool visited;
    bool done;
};
#endif