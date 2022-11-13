#include <iostream>
#include <vector>
#include "node.h"
#include "dijkstra.h"
std::vector<Node> createMaze(int rows, int cols)
{
    std::vector<Node> map;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map.push_back(Node(i, j, 1));
        }
    }
    return map;
}
void printPath(Node &sol)
{
    if (sol.getParent() != nullptr)
    {
        std::cout << sol.getX() << "," << sol.getY() << "," << sol.getW() << '\n';
        Node *par = sol.getParent();
        printPath(*par);
    }
}
int main()
{
    int rows = 3;
    int cols = 3;
    std::vector<Node> map = createMaze(rows, cols);

    for (auto &n : map)
    {
        if (n.getX() == 1 && n.getY() == 1)
        {
            n.setW(999);
        }
        std::cout << n.getX() << "," << n.getY() << "," << n.getW() << '\n';
    }
    Dijkstra *d = new Dijkstra(map, rows, cols);
    std::vector<Node> sol = d->findPath(0, 0, 2, 2);

    std::cout << "---------------" << '\n';
    // for (auto &n : sol)
    //{
    // std::cout << n.getX() << "," << n.getY() << "," << n.getW() << '\n';
    //}
    Node n = sol[0];
    Node *ptr = n.getParent();
    while (ptr != nullptr)
    {
        std::cout << n.getX() << "," << n.getY() << "," << n.getW() << '\n';
        ptr = n.getParent();
        n = *ptr;
    }

    return 0;
}