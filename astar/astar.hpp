#ifndef ASTAR_H_
#define ASTAR_H_
#include <vector>
#include <queue>
#include "node.hpp"
class Astar
{
public:
    Astar(std::vector<Node> nds, int rs, int cls);
    std::vector<Node *> findPath(int sX, int sY, int dX, int dY,float pw, float hw);
    void resetMap();

private:
    std::vector<Node>nodes;
    int rows;
    int columns;
};
#endif
