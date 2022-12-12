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
Astar::Astar(std::vector<Node>nds, int rs, int cls) : nodes{nds}, rows{rs},
                                                        columns{cls}
{
}
constexpr inline float ChebyshevDistance(int sx, int sy, int gx, int gy)
{
    return (std::max(std::abs(gx - sx),
                          std::abs(gy - sy)));
}
//float calculateCost(const Node * const node, float pathWeight, float heuristicWeight, int gx, int gy)
//{
   //return node->getW() + pathWeight*node->getCost() + heuristicWeight*ChebyshevDistance(node,gx,gy);
//}
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
/// @param pw path weight from the ui
/// @param hw heuristic weight from the ui
/// @return vector containing the solution nodes
std::vector<Node *> Astar::findPath(int sX, int sY, int dX, int dY,float pw, float hw)
{

    std::priority_queue<Node*, std::vector<Node*>, std::function<bool(const Node* const, const Node* const)>> frontier;

    //auto compare = [=] (const Node* const left, const Node* const right)
    //{
        //return (calculateCost(left,pw,hw,dX,dY)) > (calculateCost(right,pw,hw,dX,dY));
    //};
    auto compare2 = [=] (const Node* const left, const Node* const right)
    {
        return left->getCost() > right->getCost();
    };

    frontier = std::priority_queue<Node*, std::vector<Node*>, std::function<bool(const Node* const, const Node* const)>>(compare2);

    std::vector<Node *> solution;

    solution.reserve(std::sqrt(rows ^ 2 + columns ^ 2));

    int start_index = columns * sY+ sX;
    nodes[start_index].setCost(0);
    nodes[start_index].setParent(nullptr);
    frontier.push(&nodes[start_index]);

    while (!frontier.empty())
    {
        auto currNode = frontier.top();
        frontier.pop();
        currNode->setFlag(2);
        int curr_x = currNode->getX();
        int curr_y = currNode->getY();
        float curr_cost = currNode->getCost();

        if (curr_x == dX && curr_y == dY)
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
        for (int i = std::max(curr_x - 1, 0); i <= std::min(curr_x + 1, rows - 1); i++)
        {
            for (int j = std::max(curr_y - 1, 0); j <= std::min(curr_y + 1, columns - 1); j++)
            {
                bool add = false;
                int index = i + columns * j;
                float succ_w = nodes[index].getW();
                // 2 is wall
                if(succ_w == 2){
                    continue;
                }
                if (nodes[index].getFlag() == 2)
                {
                    continue;
                }
                float cost =  pw*curr_cost + succ_w + hw*ChebyshevDistance(i,j,dX,dY);
                if (nodes[index].getFlag()  == 0 )
                {
                    nodes[index].setFlag(1);
                    add = true;
                }
                else if (cost < nodes[index].getCost())
                {
                    add = true;
                }
                if(add){
                    nodes[index].setCost(cost);
                    frontier.push(&nodes[index]);
                    nodes[index].setParent(currNode);
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
