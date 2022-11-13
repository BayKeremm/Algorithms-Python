#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include <vector>
#include <queue>
#include "node.h"
class Dijkstra
{
public:
    Dijkstra(std::vector<Node> nds, int rs, int cls);
    ~Dijkstra();
    std::vector<Node *> findPath(int sX, int sY, int dX, int dY);

private:
    std::vector<Node> nodes;
    int rows;
    int columns;
    bool validIndex(int index);
    bool destReached(int x, int y, int dx, int dy);
    bool relax(Node &succesor, Node &old);
};
#endif