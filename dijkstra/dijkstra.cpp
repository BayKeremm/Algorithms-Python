#include "dijkstra.h"
#include <iostream>

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

std::vector<Node> Dijkstra::findPath(int sX, int sY, int dX, int dY)
{
    std::vector<Node> explored;
    std::priority_queue<Node> frontier;
    // find the root node
    // 1D list goes row by row
    // so index = rows*sX + sY
    int index = rows * sX + sY;
    std::cout << index << '\n';
    nodes[index].setW(0);
    nodes[index].setParent(nullptr);
    // push the root node to the pq
    frontier.push(nodes[index]);

    while (!frontier.empty())
    {
        std::cout << "inside while" << '\n';
        Node currNode = frontier.top();
        frontier.pop();
        explored.push_back(currNode);
        index = rows * currNode.getX() + currNode.getY();

        std::cout << currNode.getX() << currNode.getY() << '\n'
                  << '\n';

        if (index == rows * dX + sY)
        {
            // found
            std::cout << "found breaking" << '\n';
            break;
        }
        // for each successor
        // down
        if (validIndex(index + rows))
        {
            std::cout << "going down" << '\n';
            if (std::count(explored.begin(), explored.end(), nodes[index + rows]) == 0)
            {
                int w = currNode.getW() + 1 + nodes[index + rows].getW();
                nodes[index + rows].setW(w);

                std::cout << "new node is not in explored, going down" << '\n';

                if (!nodes[index + rows].getVisited())
                {
                    std::cout << "not visited push frontier, down" << '\n';
                    nodes[index + rows].setVisited();
                    frontier.push(nodes[index + rows]);
                    nodes[index + rows].setParent(&currNode);
                }
                else if (w < nodes[index + rows].getW())
                {
                    std::cout << "explored, but relaxing down" << '\n';
                    nodes[index + rows].setW(w);
                    nodes[index + rows].setParent(&currNode);
                }
            }
        }
        // up
        if (validIndex(index - rows))
        {
            std::cout << "going up" << '\n';
            if (std::count(explored.begin(), explored.end(), nodes[index - rows]) == 0)
            {
                int w = currNode.getW() + 1 + nodes[index - rows].getW();
                nodes[index - rows].setW(w);

                std::cout << "new node is not in explored, going up" << '\n';

                if (!nodes[index - rows].getVisited())
                {
                    std::cout << "not visited push frontier, up" << '\n';
                    nodes[index - rows].setVisited();
                    frontier.push(nodes[index - rows]);
                    nodes[index - rows].setParent(&currNode);
                }
                else if (w < nodes[index - rows].getW())
                {
                    std::cout << "explored, but relaxing up" << '\n';
                    nodes[index - rows].setW(w);
                    nodes[index - rows].setParent(&currNode);
                }
            }
        }
        // left
        if (validIndex(index - 1))
        {
            std::cout << "going left" << '\n';
            if (std::count(explored.begin(), explored.end(), nodes[index - 1]) == 0)
            {
                int w = currNode.getW() + 1 + nodes[index - rows].getW();
                nodes[index - 1].setW(w);

                std::cout << "new node is not in explored, going left" << '\n';

                if (!nodes[index - 1].getVisited())
                {
                    std::cout << "not visited push frontier, left" << '\n';
                    nodes[index - 1].setVisited();
                    frontier.push(nodes[index - 1]);
                    nodes[index - 1].setParent(&currNode);
                }
                else if (w < nodes[index - 1].getW())
                {
                    std::cout << "explored, but relaxing left" << '\n';
                    nodes[index - 1].setW(w);
                    nodes[index - 1].setParent(&currNode);
                }
            }
        }
        // right
        if (validIndex(index + 1))
        {
            std::cout << "going right" << '\n';
            if (std::count(explored.begin(), explored.end(), nodes[index + 1]) == 0)
            {
                std::cout << "new node is not in explored, going right" << '\n';
                int w = currNode.getW() + 1 + nodes[index - rows].getW();
                nodes[index + 1].setW(w);
                if (!nodes[index + 1].getVisited())
                {
                    std::cout << "not visited push frontier, right" << '\n';
                    nodes[index + 1].setVisited();
                    frontier.push(nodes[index + 1]);
                    nodes[index + 1].setParent(&currNode);
                }
                else if (w < nodes[index + 1].getW())
                {
                    std::cout << "explored, but relaxing right" << '\n';
                    nodes[index + 1].setW(w);
                    nodes[index + 1].setParent(&currNode);
                }
            }
        }
    }
    std::vector<Node> solution;
    int i = rows * dX + dY;
    Node *n = &nodes[i];
    while (n != nullptr)
    {
        solution.push_back(*n);
        n = n->getParent();
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