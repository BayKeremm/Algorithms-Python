#include "dijkstra.h"
#include "comparator.h"
#include <iostream>
#include <cmath>

#ifdef DEBUG
#define PRINT(str) std::cout << str << std::endl
#else
#define PRINT(str)
#endif

Dijkstra::Dijkstra(std::vector<Node> &nds, int rs, int cls) : nodes{nds}, rows{rs},
                                                              columns{cls}
{
}
Dijkstra::~Dijkstra()
{
    for (auto &n : nodes)
    {
        delete &n;
    }
}

std::vector<Node *> Dijkstra::findPath(int sX, int sY, int dX, int dY)
{
    std::vector<Node *> solution;
    std::priority_queue<Node *, std::vector<Node *>, comparator> frontier;
    int start_index = rows * sX + sY;
    nodes[start_index].setW(0);
    nodes[start_index].setParent(nullptr);
    frontier.push(&nodes[start_index]);

    while (!frontier.empty())
    {
        auto currNode = frontier.top();
        frontier.pop();
        currNode->setDone();
#ifdef DEBUG
        PRINT("inside frontier loop with the following currNode");
        std::cout << currNode->getX() << "," << currNode->getY() << "," << currNode->getW() << '\n';
#endif

        if (currNode->getX() == dX && currNode->getY() == dY)
        {
            auto n = currNode;
            int cost = 0;
            while (true)
            {
                solution.push_back(n);
                cost += n->getW();
                n = n->getParent();
                if (n == nullptr)
                {
                    break;
                }
            }
#ifdef DEBUG
            std::cout << "THE TOTAL COST: " << cost << '\n';
#endif
            return solution;
        }
        // for each successor
        int curr_x = currNode->getX();
        int curr_y = currNode->getY();
        for (int i = std::max(curr_x - 1, 0); i <= std::min(curr_x + 1, rows - 1); i++)
        {
            for (int j = std::max(curr_y - 1, 0); j <= std::min(curr_y + 1, columns - 1); j++)
            {
#ifdef DEBUG
                std::cout << "i is: " << i << " j is: " << j << " index is: " << index << std::endl;
                std::cout << "i is: " << index / rows << " j is: " << (index / rows) % columns << " index is: " << index << std::endl;
                PRINT("inside successor loop with following successor");
                std::cout << nodes[index].getX() << "," << nodes[index].getY() << "," << nodes[index].getW() << '\n';
                std::cout << "calculated weight; ";
                PRINT(w);
#endif
                int index = j + columns * i;

                if (nodes[index].getDone())
                {
                    PRINT("node is done continue");
                    continue;
                }
                int w = currNode->getW() + nodes[index].getW();
                if (!nodes[index].getVisited())
                {
#ifdef DEBUG
                    PRINT("adding to frontier");
#endif
                    nodes[index].setVisited();
                    nodes[index].setW(w);
                    nodes[index].setParent(currNode);
                    frontier.push(&nodes[index]);
                }
                else if (w < nodes[index].getW())
                {
#ifdef DEBUG
                    PRINT("changing the weight");
#endif
                    nodes[index].setW(w);
                    nodes[index].setParent(currNode);
                }
            }
        }
    }
    return solution;
}