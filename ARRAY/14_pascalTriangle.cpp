#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; i++)
    {
        // Each row has i+1 elements
        vector<int> row(i + 1, 1); // initialize with 1s

        // Fill the middle elements using previous row
        for (int j = 1; j < i; j++)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        // Push completed row into triangle
        triangle.push_back(row);
    }

    return triangle;
}
int main()
{
    vector<vector<int>> pascal = generate(5);

    for (auto &&i : pascal)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}