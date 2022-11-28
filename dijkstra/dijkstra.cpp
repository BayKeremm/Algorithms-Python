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
    PRINT("before the while loop");
    std::vector<Node *> solution;
    std::priority_queue<Node *, std::vector<Node *>, comparator> frontier;
    int start_index = rows * sX + sY;
    int goal_index = rows * dX + dY;
    nodes[start_index].setCost(0);
    nodes[start_index].setParent(nullptr);
    frontier.push(&nodes[start_index]);

    while (!frontier.empty())
    {
        auto currNode = frontier.top();
        frontier.pop();
        currNode->setDone(true);
#ifdef DEBUG
        PRINT("inside frontier loop with the following currNode");
        std::cout << currNode->getX() << "," << currNode->getY() << "," << currNode->getW() << ", " << currNode->getCost() << '\n';
#endif

        if (currNode->getX() == dX && currNode->getY() == dY)
        {
            auto n = currNode;
            while (true)
            {
                solution.push_back(n);
                n = n->getParent();
                if (n == nullptr)
                {
                    break;
                }
            }
            return solution;
        }
        // for each successor
        int curr_x = currNode->getX();
        int curr_y = currNode->getY();
        for (int i = std::max(curr_x - 1, 0); i <= std::min(curr_x + 1, rows - 1); i++)
        {
            for (int j = std::max(curr_y - 1, 0); j <= std::min(curr_y + 1, columns - 1); j++)
            {
                int index = j + columns * i;
                char distance = std::abs(nodes[index].getX() - i) + std::abs(nodes[index].getY() - j);
                int w = currNode->getCost() + nodes[index].getW() + distance;
#ifdef DEBUG
                // std::cout << "i is: " << i << " j is: " << j << " index is: " << index << std::endl;
                // std::cout << "i is: " << index / rows << " j is: " << (index / rows) % columns << " index is: " << index << std::endl;
                PRINT("inside successor loop with following successor");
                std::cout << nodes[index].getX() << "," << nodes[index].getY() << "," << nodes[index].getW() << ", " << nodes[index].getW() << '\n';
                std::cout << "calculated weight; ";
                PRINT(w);
#endif

                if (nodes[index].getDone())
                {
#ifdef DEBUG
                    PRINT("node is done continue");
#endif
                    continue;
                }
                if (!nodes[index].getVisited())
                {
#ifdef DEBUG
                    PRINT("adding to frontier");
#endif
                    nodes[index].setVisited(true);
                    nodes[index].setCost(w);
                    nodes[index].setParent(currNode);
                    frontier.push(&nodes[index]);
                }
                else if (w < nodes[index].getCost())
                {
#ifdef DEBUG
                    PRINT("changing the weight");
#endif
                    nodes[index].setCost(w);
                    nodes[index].setParent(currNode);
                    frontier.push(&nodes[index]);
                }
            }
        }
    }
    return solution;
}
void Dijkstra::resetMap()
{
    std::cout << "size is " << nodes.size() << std::endl;
    for (auto &n : nodes)
    {
        n.setCost(0);
        n.setDone(false);
        n.setVisited(false);
    }
}