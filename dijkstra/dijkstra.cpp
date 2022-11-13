#include "dijkstra.h"
#include "comparator.h"
#include <iostream>
#include <cmath>

Dijkstra::Dijkstra(std::vector<Node> nds, int rs, int cls) : nodes{nds}, rows{rs},
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
bool Dijkstra::relax(Node &successor, Node &old)
{
    if (successor.getW() < old.getW())
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::vector<Node *> Dijkstra::findPath(int sX, int sY, int dX, int dY)
{
    std::vector<Node *> solution;
    std::priority_queue<Node *, std::vector<Node *>, comparator> frontier;
    // find the root node
    // 1D list goes row by row
    // so index = rows*sX + sY
    int index = rows * sX + sY;
    nodes[index].setW(0);
    nodes[index].setParent(nullptr);
    // push the root node to the pq
    frontier.push(&nodes[index]);

    while (!frontier.empty())
    {
        auto currNode = frontier.top();
        frontier.pop();
        currNode->setDone();

        if (currNode->getX() == dX && currNode->getY() == dY)
        {
            // found
            std::cout << "found breaking" << '\n';
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
            std::cout << "finished breaking" << '\n';
            return solution;
        }
        // for each successor
        for (int i = std::max(currNode->getX() - 1, 0); i <= std::min(currNode->getX() + 1, columns - 1); i++)
        {
            for (int j = std::max(currNode->getY() - 1, 0); j <= std::min(currNode->getY() + 1, rows - 1); j++)
            {
                int index = i + columns * j;
                int w = currNode->getW() + 1 + nodes[index].getW();

                if (nodes[index].getDone())
                {
                    continue;
                }
                else if (!nodes[index].getVisited())
                {
                    std::cout << "-----------------" << '\n';
                    nodes[index].setVisited();
                    std::cout << index % rows << "," << index / columns << '\n';
                    frontier.emplace(new Node(index % rows, index / columns, w, currNode));
                }
                else if (w < nodes[index].getW())
                {
                    std::cout << "ooooo" << '\n';
                    nodes[index].setW(w);
                    nodes[index].setParent(currNode);
                }
            }
        }
    }
    return solution;
}
bool Dijkstra::validIndex(int index)
{
    if (index < rows * columns - 1 && index >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Dijkstra::destReached(int x, int y, int dx, int dy)
{
    if (x == dx && y == dy)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
Node currNode = pq.top();
pq.pop();

if (destReached(currNode.getX(), currNode.getY(), dX, dY))
{
    solution.push_back(currNode);
    return solution;
}
// at max 8 neighboring Node
if (validIndex(index + rows))
{
    Node successor(currNode.getX() + 1, currNode.getY(), currNode.getW() + nodes[index + rows].getW());
    successor.setParent(&currNode);
    if (nodes[index + rows].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index + 1))
{
    Node successor(currNode.getX(), currNode.getY() + 1, currNode.getW() + nodes[index + 1].getW());
    successor.setParent(&currNode);
    if (nodes[index + 1].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index + 1 + rows))
{
    Node successor(currNode.getX() + 1, currNode.getY() + 1, currNode.getW() + nodes[index + 1 + rows].getW());
    successor.setParent(&currNode);
    if (nodes[index + 1].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index - 1))
{
    Node successor(currNode.getX(), currNode.getY() - 1, currNode.getW() + nodes[index - 1].getW());
    successor.setParent(&currNode);
    if (nodes[index - 1].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index - rows))
{
    Node successor(currNode.getX() - 1, currNode.getY(), currNode.getW() + nodes[index - rows].getW());
    successor.setParent(&currNode);
    if (nodes[index - rows].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index - rows - 1))
{
    Node successor(currNode.getX() - 1, currNode.getY() - 1, currNode.getW() + nodes[index - rows - 1].getW());
    successor.setParent(&currNode);
    if (nodes[index - rows - 1].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index - rows + 1))
{
    Node successor(currNode.getX() - 1, currNode.getY() + 1, currNode.getW() + nodes[index - rows + 1].getW());
    successor.setParent(&currNode);
    if (nodes[index - rows + 1].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
}
if (validIndex(index + rows - 1))
{
    Node successor(currNode.getX() + 1, currNode.getY() - 1, currNode.getW() + nodes[index + rows - 1].getW());
    successor.setParent(&currNode);
    if (nodes[index + rows - 1].getVisited())
    {
        Node old_node = pq.top();
        if (relax(successor, old_node))
        {
            pq.pop();
        }
    }
    pq.push(successor);
*/