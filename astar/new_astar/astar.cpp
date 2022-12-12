#include "astar.hpp"
#include "comparator.hpp"
#include <iostream>
#include <cmath>
Astar::Astar(std::vector<Node> &nds, int rs, int cls) : nodes{nds}, rows{rs},
                                                        columns{cls}
{
}
Astar::~Astar()
{
    for (auto &n : nodes)
    {
        delete &n;
    }
}

std::vector<Node*> Astar::findPath(int sX, int sY, int dX, int dY)
{
    std::vector<Node *> solution;
    solution.reserve(std::sqrt(rows ^ 2 + columns ^ 2));
    std::priority_queue<Node *, std::vector<Node *>, comparator> frontier;
    int start_index = rows * sY+ sX;
    int goal_index = rows * dY + dX;
    nodes[start_index].setCost(1.f - nodes[start_index].getW());
    nodes[start_index].setParent(nullptr);
    frontier.push(&nodes[start_index]);
    while (!frontier.empty()){
        auto curr_node = frontier.top();
        int curr_x = curr_node->getX();
        int curr_y = curr_node->getY();
        int curr_cost = curr_node->getCost();
        // check if we arrived

        if (curr_x == dX && curr_y == dY)
        {
            std::cout << "solution" << std::endl;
            auto n = curr_node;
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
        frontier.pop();
        curr_node->setDone2(2);

        for (int i = std::max(curr_x - 1, 0); i <= std::min(curr_x + 1, rows - 1); i++)
        {
            for (int j = std::max(curr_y - 1, 0); j <= std::min(curr_y + 1, columns - 1); j++)
            {
                if(i==curr_x && j==curr_y){
                    continue;
                }
                auto index = i + columns * j;
                if (nodes[index].getW() == 0){
                    continue;
                }
                else if(nodes[index].getDone2()==2){
                    continue;
                }
                if (nodes[index].getVisited2() == 0){
                    curr_node->setVisited2(1);
                    const auto cost = curr_node->getCost() + (1.f - nodes[index].getW());
                    const auto length = std::abs(curr_node->getX() - i) + std::abs(curr_node->getY() - j);
                    frontier.emplace(&nodes[index]);
                }
            }
        }

    }

}
void Astar::resetMap()
{
    for (auto &n : nodes)
    {
        n.reset();
    }
}