#include "astar.hpp"
#include "comparator.hpp"
#include <iostream>
#include <cmath>

#ifdef DEBUG
#define PRINT(str) std::cout << str << std::endl
#else
#define PRINT(str)
#endif

/// @brief 
/// @param nds vector of nodes, created in the main and then passed to the Astar class, which will keep them
///             until the end of its lifetime. So only one copy is made.
/// @param rs number of rows 
/// @param cls  number of columns
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

/// @brief constant expression to calculate herustic 
/// @param cX current X 
/// @param cY current Y 
/// @param gX goal X
/// @param gY goal Y
/// @return 
constexpr inline float heuristic2(int cX, int cY, int gX, int gY)
{
    return std::abs(gX - cX) +
           std::abs(gY - cY);
}

/// @brief 
///        step 1: initialize solution, priority queue (pq) 
///        step 2: add the start node to the pq 
///        step 2: while pq is not empty 
///        step 3: pop the pq 
///        step 4: set the popped to Done 
///        check : check if we are at destination, if we are populate the solution vector 
///        step 6: for each succesor, which are the basically the neighbors
///        step 7: calculate the distance to the neighbor, 
///        step 8: calculate the cost to travel to that neighbor
///        check : check ig the node is done, if it is continue with the next neighbor
///        check : check if the node is visited, if it is not add it to the frontier and update its fields
///        check : if node is visited and the calculated cost for the same node is lower,
///                update its fields and add it to the frontier again
/// @param sX source X 
/// @param sY source U
/// @param dX destination X, same as goal X
/// @param dY destination Y, same as goal Y
/// @return 
std::vector<Node *> Astar::findPath(int sX, int sY, int dX, int dY)
{
    PRINT("before the while loop");
    std::vector<Node *> solution;
    solution.reserve(std::sqrt(rows ^ 2 + columns ^ 2));
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
        currNode->setDone2(2);
        int curr_x = currNode->getX();
        int curr_y = currNode->getY();
        int curr_cost = currNode->getCost();
#ifdef DEBUG
        PRINT("inside frontier loop with the following currNode");
        std::cout << currNode->getX() << "," << currNode->getY() << "," << currNode->getW() << ", " << currNode->getCost() << '\n';
#endif

        if (curr_x == dX && curr_y == dY)
        {
            std::cout << "solution" << std::endl;
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
        for (int i = std::max(curr_x - 1, 0); i <= std::min(curr_x + 1, rows - 1); i++)
        {
            for (int j = std::max(curr_y - 1, 0); j <= std::min(curr_y + 1, columns - 1); j++)
            {
                bool add = false;
                int index = j + columns * i;
                char distance = std::abs(nodes[index].getX() - i) + std::abs(nodes[index].getY() - j);
                // TODO: Add the slider value
                int cost = curr_cost + nodes[index].getW() + distance + heuristic2(curr_x, curr_y, dX, dY);
#ifdef DEBUG
                PRINT("inside successor loop with following successor");
                std::cout << nodes[index].getX() << "," << nodes[index].getY() << "," << nodes[index].getW() << ", " << nodes[index].getW() << '\n';
                std::cout << "calculated weight; ";
                PRINT(w);
#endif

                // flag == 2
                if (nodes[index].getDone2())
                {
#ifdef DEBUG
                    PRINT("node is done continue");
#endif
                    continue;
                }
                // flag = 0 
                else if (!nodes[index].getVisited2())
                {
#ifdef DEBUG
                    PRINT("adding to frontier");
#endif
                    nodes[index].setVisited2(1);
                    nodes[index].setCost(cost);
                    nodes[index].setParent(currNode);
                    add = true;
                }
                // flag == 1 
                else if (cost < nodes[index].getCost())
                {
#ifdef DEBUG
                    PRINT("changing the weight");
#endif
                    nodes[index].setCost(cost);
                    nodes[index].setParent(currNode);
                    add = true;
                }
                if(add){
                    frontier.push(&nodes[index]);
                }
            }
        }
    }
    return solution;
}
/// @brief reset the cost, done, and visited fields of the nodes in the map
void Astar::resetMap()
{
    for (auto &n : nodes)
    {
        n.reset();
    }
}