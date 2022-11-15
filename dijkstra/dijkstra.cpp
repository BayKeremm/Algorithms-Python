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
    int index = rows * sX + sY;
    nodes[index].setW(0);
    nodes[index].setParent(nullptr);
    frontier.push(&nodes[index]);

    while (!frontier.empty())
    {
        auto currNode = frontier.top();
        frontier.pop();
        currNode->setDone();
        // PRINT("inside frontier loop with the following currNode");
        // std::cout << currNode->getX() << "," << currNode->getY() << "," << currNode->getW() << '\n';

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
        for (int i = std::max(currNode->getX() - 1, 0); i <= std::min(currNode->getX() + 1, columns - 1); i++)
        {
            for (int j = std::max(currNode->getY() - 1, 0); j <= std::min(currNode->getY() + 1, rows - 1); j++)
            {
                // PRINT("inside successor loop with following successor");
                int index = j + rows * i;
                float factor = 1.f;
                if (std::abs(currNode->getX() - nodes[index].getX()) + std::abs(currNode->getY() - nodes[index].getY()) == 2)
                {
                    factor = std::sqrt(2);
                }
                auto heuristic = std::sqrt((dX - nodes[index].getX()) ^ 2 + (dY - nodes[index].getY()) ^ 2);
                int w = currNode->getW() + nodes[index].getW() * factor + heuristic;

                // std::cout << nodes[index].getX() << "," << nodes[index].getY() << "," << nodes[index].getW() << '\n';
                // std::cout << "calculated weight; ";
                // PRINT(w);

                if (nodes[index].getDone())
                {
                    // PRINT("node is done continue");
                    continue;
                }
                if (!nodes[index].getVisited())
                {
                    // PRINT("adding to frontier");
                    nodes[index].setVisited();
                    nodes[index].setW(w);
                    nodes[index].setParent(currNode);
                    frontier.push(&nodes[index]);
                    // frontier.emplace(new Node(nodes[index].getX(), nodes[index].getY(), w, currNode));
                }
                else if (w < nodes[index].getW())
                {
                    // PRINT("changing the weight");
                    nodes[index].setW(w);
                    nodes[index].setParent(currNode);
                }
            }
        }
    }
    return solution;
}