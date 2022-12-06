#ifndef NODE_H_
#define NODE_H_
#include <iostream>
#include "tile.hpp"

/// @brief Node class to keep track of the tiles and extra fields for the path planner
class Node
{
public:
    Node(int x, int y, float w);
    Node(int x, int y, float w, Node *parent);
    ~Node() = default;
    Node(const Node & other);
    Node(Node && other) noexcept;

    int getX() const;
    int getY() const;
    int getW() const;
    int getCost() const;
    void setCost(int nw);
    void setParent(Node *ptr);
    Node *getParent();
    //void setVisited(bool val);
    //bool getVisited();
    //void setDone(bool val);
    //bool getDone();

    void setVisited2(char f);
    char getVisited2();

    void setDone2(char f);
    char getDone2();


private:
    float w; // pixel weight, copied from the tiles
    int cost; // calculated cost to travel to the given node from the source node
    int x, y; // x and y coordinates in the image
    Node *parent; // for the associated cost the parent node to back track the cost, each node has a parent exxcept the start node which has a nullptr as parent
    //bool visited; // if the node is visited, it means through some other node we have checked the cost of to travel through it.
    //bool done; // done means the node entered the priority queue, all of its neighbors are checked and popped from the pq
    char flag; // flag = 0, not visited
                // flag = 1, visited
                // flag = 2, done
};
#endif


/*
float + 2 * ints = 12bytes
6M * 12 bytes  = 72MB copied memory
*/