#include <iostream>
#include <vector>
#include <memory>
#include "node.h"
#include "dijkstra.h"
#include "tile.h"

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
    // std::cout << argc << "\n";
    // std::cout << argv[0] << " " << *argv[1] << " " << *argv[2] << " " << *argv[3] << '\n';
    // 3000x3000 = 9,000,000 tiles
    int rows = 100;
    int cols = 100;
    time_t current_time;

    std::vector<std::unique_ptr<Tile>> map = createTileMaze(rows, cols);
    std::vector<Node> nodes;

    for (auto &n : map)
    {
        if (n->getXPos() == n->getYPos())
        {
            n->setValue(20);
        }
        if (n->getYPos() == 5)
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
    }

    current_time = time(NULL);
    std::cout << current_time << std::endl;
    for (auto &t : map)
    {
        nodes.push_back(*new Node(t, nullptr));
    }

    Dijkstra *d = new Dijkstra(nodes, rows, cols);
    std::vector<Node *> sol = d->findPath(0, 0, 99, 99);

    current_time = time(NULL);
    std::cout << current_time << std::endl;

    std::cout << "---------------solution-----------------" << '\n';
    printMap(sol, rows, cols);
    // std::cout << sol.size() << std::endl;
    // for (auto &n : sol)
    //{
    // std::cout << n->getX() << "," << n->getY() << "," << n->getW() << '\n';
    //}

    return 0;
}
