#include <iostream>
#include <string.h>
#include <iterator>
#include <unordered_set>
#include <queue>
#include <deque>
#include <vector>
#include <set>

using namespace std;

class Node
{
public:
    string state;
    int cost;
    Node(string nodeState, int nodeCost)
    {
        state = nodeState;
        cost = nodeCost;
    }
};

bool checkGoal(string currentState, string goalState)
{
    return currentState == goalState;
}

int possibleActions(Node currentNode, queue<Node> &frontier, unordered_set<string> &explored, string finalState)
{
    int hashpos = currentNode.state.find("#");
    string up, down, left, right;

    // left
    if (hashpos % 3 > 0)
    {
        left = currentNode.state;
        swap(left[hashpos], left[hashpos - 1]);
        if (explored.find(left) == explored.end())
        {
            Node leftChild(left, currentNode.cost + 1);
            if (checkGoal(leftChild.state, finalState))
            {
                return leftChild.cost;
            }
            frontier.push(leftChild);
        }
    }

    // right
    if (hashpos % 3 < 2)
    {
        right = currentNode.state;
        swap(right[hashpos], right[hashpos + 1]);
        if (explored.find(right) == explored.end())
        {
            Node rightChild(right, currentNode.cost + 1);
            if (checkGoal(rightChild.state, finalState))
            {
                return rightChild.cost;
            }
            frontier.push(rightChild);
        }
    }

    // up
    if (hashpos - 3 >= 0)
    {
        up = currentNode.state;
        swap(up[hashpos], up[hashpos - 3]);
        if (explored.find(up) == explored.end())
        {
            Node upChild(up, currentNode.cost + 5);
            if (checkGoal(upChild.state, finalState))
            {
                return upChild.cost;
            }
            frontier.push(upChild);
        }
    }

    // down
    if (hashpos + 3 < 9)
    {
        down = currentNode.state;
        swap(down[hashpos], down[hashpos + 3]);
        if (explored.find(down) == explored.end())
        {
            Node downChild(down, currentNode.cost + 1);
            if (checkGoal(downChild.state, finalState))
            {
                return downChild.cost;
            }
            frontier.push(downChild);
        }
    }

    return -1;
}

int main()
{
    int cost = -1;
    string firstSate;
    string finalState;
    cin >> firstSate;
    cin >> finalState;

    Node firstNode(firstSate, 0);
    queue<Node> frontier;
    unordered_set<string> explored;
    frontier.push(firstNode);

    if (checkGoal(firstNode.state, finalState))
    {
        cout << firstNode.cost << endl;
    }
    else
    {
        Node currentNode = firstNode;
        while (!frontier.empty())
        {
            currentNode = frontier.front();
            frontier.pop();
            explored.insert(currentNode.state);
            cost = possibleActions(currentNode, frontier, explored, finalState);
            if (cost != -1)
            {
                cout << cost << endl;
                break;
            }
        }
    }
    return 0;
}
