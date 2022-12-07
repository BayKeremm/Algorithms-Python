#include <iostream>
#include <vector>
#include <memory>
#include "node.hpp"
#include "astar.hpp"
#include "tile.hpp"

/*
TODO:
-add the cost and do not change anything related to the tile
at the end refresh the data structure and avoid copying.
- Try the Node class which extends the tile class. Compare time


- check if you have enough memory by checking if nullptr is returned
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
    int rows = 30;

    int cols = 30;
    time_t current_time;

    std::vector<std::unique_ptr<Tile>> map = createTileMaze(rows, cols);
    std::vector<Node> nodes;
    nodes.reserve(rows * cols);

    for (auto &n : map)
    {
        //if (n->getXPos() == 5 && n->getYPos() == 5)
        //{
            //n->setValue(200);
        //}
        //if (n->getXPos() == 4 && n->getYPos() == 5)
        //{
            //n->setValue(200);
        //}
        //if (n->getXPos() == 5 && n->getYPos() == 4)
        //{
            //n->setValue(200);
        //}
        //if (n->getXPos() == 4  && n->getYPos() == 4)
        //{
            //n->setValue(200);
        //}
        //if (n->getXPos() ==   n->getYPos() )
        //{
            //n->setValue(1000);
        //}
        if (n->getYPos() == 9 )
        {
            if(n->getXPos() == 0){

            }else{
                n->setValue(2000000);
            }

        }
    }

    for (auto &t : map)
    {
        nodes.emplace_back(t->getXPos(),t->getYPos(),t->getValue(),nullptr);
    }
    std::cout << "---------------solution A*-----------------" << '\n';
    Astar *a = new Astar(nodes, rows, cols);
    std::clock_t c_start = std::clock();
    std::vector<Node *> sol = a->findPath(0, 0, 29, 29);
    std::cout << "after path" << '\n';
    a->resetMap();
    std::cout << "after reset" << '\n';
    std::clock_t c_end = std::clock();
    long time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
    std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";
    std::cout << sol.size() << std::endl;
    printMap(sol, rows, cols);


    return 0;
}
