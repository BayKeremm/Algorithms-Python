#include <iostream>
#include <vector>
#include <memory>
#include "node.h"
#include "dijkstra.h"
#include "tile.h"

/*
TODO:
-add the cost and do not change anything related to the tile
at the end refresh the data structure and avoid copying.
- Try the Node class which extends the tile class. Compare time
*/

std::vector<std::unique_ptr<Tile>> createTileMaze(int rows, int cols)
{
    std::vector<std::unique_ptr<Tile>> map;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map.push_back(std::make_unique<Tile>(i, j, 1));
        }
    }
    return map;
}
void printMap(std::vector<Node *> sol, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            bool k = false;
            for (auto &p : sol)
            {
                if (p->getX() == i && p->getY() == j)
                {
                    std::cout << "* ";
                    k = true;
                    break;
                }
            }
            if (!k)
                std::cout << "- ";
        }
        std::cout << '\n';
    }
}
int main(int argc, char **argv)
{
    int rows = 3000;
    int cols = 3000;
    time_t current_time;

    std::vector<std::unique_ptr<Tile>> map = createTileMaze(rows, cols);
    std::vector<Node> nodes;

    for (auto &n : map)
    {
        if (n->getYPos() == 3)
        {
            if (n->getXPos() == 0)
            {
                n->setValue(0);
            }
            else
            {
                n->setValue(100);
            }
        }
        if (n->getXPos() == n->getYPos())
        {
            n->setValue(200);
        }
    }

    current_time = time(NULL);
    std::cout << current_time << std::endl;
    for (auto &t : map)
    {
        nodes.push_back(*new Node(t, nullptr));
    }

    Dijkstra *d = new Dijkstra(nodes, rows, cols);
    std::vector<Node *> sol = d->findPath(0, 0, 2999, 2999);

    current_time = time(NULL);
    std::cout << current_time << std::endl;

    std::cout << "---------------solution-----------------" << '\n';
    // printMap(sol, rows, cols);
    std::cout << sol.size() << std::endl;
    for (auto &n : sol)
    {
        std::cout << n->getX() << "," << n->getY() << "," << n->getW() << "," << n->getCost() << '\n';
    }

    return 0;
}
