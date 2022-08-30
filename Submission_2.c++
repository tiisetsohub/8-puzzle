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
            if (digits[counter] == '#'){
                space[0]=i;
                space[1]=j;
            }
            counter++;
        }
    }
}

void makeMove(string grid[3][3], string action, int space[1]){
    int cost = 1;
    if (action == "UP"){
        if (space[0] > 0){
            grid[space[0]][space[1]] = grid[space[0]-1][space[1]];
            grid[space[0]-1][space[1]] = "#";
        }
    }
    else if (action == "DOWN"){
        if (space[0] < 2){
            grid[space[0]][space[1]] = grid[space[0] + 1][space[1]];
            grid[space[0] + 1][space[1]] = "#";
        }
    }
    else if (action == "LEFT"){
        if (space[1] > 0){
            grid[space[0]][space[1]] = grid[space[0]][space[1] - 1];
            grid[space[0]][space[1] - 1] = "#";
        }
    }
    else if (action == "RIGHT"){
        if (space[1] < 2){
            grid[space[0]][space[1]] = grid[space[0]][space[1] + 1];
            grid[space[0]][space[1] + 1] = "#";
        }
    }
    cout<<cost<<endl;
}
int main()
{
    string grid[3][3];
    int space[1];
    string digits;
    string action;
    cin >> digits;
    cin >> action;
    fillGrid(grid, digits, space);

    makeMove(grid, action, space);

    printGrid(grid);

    return 0;
}
