#include <iostream>
using namespace std;

void printGrid(string grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        string line = "";
        for (int j = 0; j < 3; j++)
        {
            line = line + grid[i][j] + " ";
        }
        line.pop_back();
        cout << line << endl;
    }
}

void fillGrid(string grid[3][3], string digits, int space[1])
{
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = digits[counter];
            if (digits[counter] == '#')
            {
                space[0] = i;
                space[1] = j;
            }
            counter++;
        }
    }
}

void makeMove(string grid[3][3], string action, int space[1])
{
    int cost = 1;
    if (action == "UP")
    {
        if (space[0] > 0)
        {
            grid[space[0]][space[1]] = grid[space[0] - 1][space[1]];
            grid[space[0] - 1][space[1]] = "#";
        }
    }
    else if (action == "DOWN")
    {
        if (space[0] < 2)
        {
            grid[space[0]][space[1]] = grid[space[0] + 1][space[1]];
            grid[space[0] + 1][space[1]] = "#";
        }
    }
    else if (action == "LEFT")
    {
        if (space[1] > 0)
        {
            grid[space[0]][space[1]] = grid[space[0]][space[1] - 1];
            grid[space[0]][space[1] - 1] = "#";
        }
    }
    else if (action == "RIGHT")
    {
        if (space[1] < 2)
        {
            grid[space[0]][space[1]] = grid[space[0]][space[1] + 1];
            grid[space[0]][space[1] + 1] = "#";
        }
    }
    cout << cost << endl;
}

void availableMove(string grid[3][3], int space[1]){
    if (space[0] > 0){
        cout<<"UP"<<endl;
    }
    if (space[0] < 2){
        cout<<"DOWN"<<endl;
    }
    if (space[1] > 0){
        cout<<"LEFT"<<endl;
    }
    if (space[1] < 2){
        cout<<"RIGHT"<<endl;
    }
}

int main()
{
    string grid[3][3];
    int space[1];
    string digits;
    string action;
    cin >> digits;
    //cin >> action;
    fillGrid(grid, digits, space);

    //makeMove(grid, action, space);

    availableMove(grid, space);
    //printGrid(grid);

    return 0;
}


////////////////////////////////////////////////////////////////

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

int possibleActions(Node currentNode, queue<Node> &frontier, unordered_set<string> &explored, unordered_set<string> &tracker, string finalState)
{
    int hashpos = currentNode.state.find("#");
    string up, down, left, right;

    // up
    if (hashpos - 3 >= 0)
    {
        up = currentNode.state;
        swap(up[hashpos], up[hashpos - 3]);
        if (explored.find(up) == explored.end() && tracker.find(up) == tracker.end())
        {
            Node upChild(up, currentNode.cost + 1);
            if (checkGoal(upChild.state, finalState))
            {
                return upChild.cost;
            }
            frontier.push(upChild);
            tracker.insert(up);
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
    unordered_set<string> tracker;
    tracker.insert(firstNode.state);

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
            tracker.erase(tracker.find(currentNode.state));
            frontier.pop();
            explored.insert(currentNode.state);
            cost = possibleActions(currentNode, frontier, explored, tracker, finalState);
            if (cost != -1)
            {
                cout << cost << endl;
                break;
            }
        }
    }
    return 0;
}
