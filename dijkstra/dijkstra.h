#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include <vector>
#include <queue>
#include "node.h"
class Dijkstra
{
public:
    Dijkstra(std::vector<Node> &nds, int rs, int cls);
    ~Dijkstra();
    std::vector<Node *> findPath(int sX, int sY, int dX, int dY);
    std::vector<Node *> findPathH(int sX, int sY, int dX, int dY);
    void resetMap();

private:
    std::vector<Node> &nodes;
    int rows;
    int columns;
};
#endif