#ifndef ASTAR_H_
#define ASTAR_H_
#include <vector>
#include <queue>
#include "node.hpp"
class Astar
{
public:
    Astar(std::vector<Node> &nds, int rs, int cls){

    };
    ~Astar();
    std::vector<Node*> findPath(int sX, int sY, int dX, int dY);
    void resetMap();

private:
    std::vector<Node> nodes;
    int rows;
    int columns;
};
#endif