#include <iostream>
#include <vector>
#include <memory>
#include "node.h"
#include "dijkstra.h"
#include "astar.h"
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
            {
                std::cout << "- ";
            }
        }
        std::cout << '\n';
    }
}
int main(int argc, char **argv)
{
    int rows = 3000;
    int cols = 2000;
    time_t current_time;

    std::vector<std::unique_ptr<Tile>> map = createTileMaze(rows, cols);
    std::vector<Node> nodes;
    nodes.reserve(rows * cols);

    for (auto &n : map)
    {
        if (n->getXPos() == 5 && n->getYPos() == 5)
        {
            n->setValue(200);
        }
        if (n->getXPos() == 4 && n->getYPos() == 5)
        {
            n->setValue(200);
        }
        if (n->getXPos() == 5 && n->getYPos() == 4)
        {
            n->setValue(200);
        }
        if (n->getXPos() == 4  && n->getYPos() == 4)
        {
            n->setValue(200);
        }
        if (n->getXPos() ==   n->getYPos() )
        {
            n->setValue(20000);
        }
    }

    for (auto &t : map)
    // TODO: move semantics, the following code copies twice the tiles
    {
        nodes.emplace_back(t->getXPos(),t->getYPos(),t->getValue(),nullptr);
        //nodes.push_back(Node(t->getXPos(), t->getYPos(), t->getValue(), nullptr));
            // when you uncomment the upper version it calls the move constuctor every time.
    }

    //current_time = time(NULL);
    //std::cout << current_time << std::endl;
    //current_time = time(NULL);
    //std::cout << current_time << std::endl;

    std::cout << "---------------solution A*-----------------" << '\n';
    Astar *a = new Astar(nodes, rows, cols);
    current_time = time(NULL);
    std::cout << current_time << std::endl;
    std::vector<Node *> sol = a->findPath(0, 0, 2999, 1999);
    current_time = time(NULL);
    std::cout << current_time << std::endl;
    //printMap(sol, rows, cols);

    //a->resetMap();

    //Dijkstra *d = new Dijkstra(nodes, rows, cols);
    //std::vector<Node *> sol2 = d->findPath(0, 0, 9, 9);

    //std::cout << "---------------solution Dijkstra-----------------" << '\n';
    //printMap(sol2, rows, cols);


    //int size = 0;
    //for (auto &n : sol)
    //{
        //size++;
        //std::cout << n->getX() << "," << n->getY() << "," << n->getW() << "," << n->getCost() << '\n';
    //}
    //printf("%d\n is the size of sol", size);

    return 0;
}
