#ifndef NODE_H_
#define NODE_H_
class Node
{
public:
    Node(int x, int y, int w);
    int getX();
    int getY();
    int getW();
    void setW(int nw);
    void setParent(Node *ptr);
    Node *getParent();
    void setVisited();
    bool getVisited();
    bool operator<(const Node &b) const;
    bool operator==(const Node &b) const;

private:
    int x;
    int y;
    int w;
    Node *parent;
    bool visited;
};
#endif