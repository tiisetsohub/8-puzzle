#include <iostream>
using namespace std;

void printGrid(string grid[3][3]){
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

void fillGrid(string grid[3][3], string digits){
    int counter = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = digits[counter];
            counter++;
        }
    }
    printGrid(grid);
}

int main()
{
    string grid[3][3];
    string digits;
    cin >> digits;
    fillGrid(grid, digits);

    

    return 0;
}
