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
            map.push_back(*new Node(i, j, 1));
        }
    }
    return map;
}
void printMap(std::vector<Node> &map)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << '(' << map[i * 3 + j].getX() << "," << map[i * 3 + j].getY() << "," << map[i * 3 + j].getW() << ") ";
        }
        std::cout << '\n';
    }
}

int main()
{
    int rows = 3;
    int cols = 3;
    std::vector<Node> map = createMaze(rows, cols);

    for (auto &n : map)
    {
        if (n.getX() == 1 && n.getY() == 0)
        {
            n.setW(20);
        }
        std::cout << n.getX() << "," << n.getY() << "," << n.getW() << '\n';
    }
    printMap(map);
    Dijkstra *d = new Dijkstra(map, rows, cols);
    std::vector<Node *> sol = d->findPath(0, 0, 0, 2);

    std::cout << "---------------solution-----------------" << '\n';
    for (auto &n : sol)
    {
        std::cout << n->getX() << "," << n->getY() << "," << n->getW() << '\n';
    }

    return 0;
}
