#include <iostream>
#include <vector>
using namespace std;

void generateSubset(vector<int> &arr, int index, vector<int> &currentSubset, vector<vector<int>> &allSubset)
{

    // Base case
    if (index == arr.size())
    {
        allSubset.push_back(currentSubset);
        return;
    }

    // two choices
    // Choice 1: include
    currentSubset.push_back(arr[index]);
    generateSubset(arr, index + 1, currentSubset, allSubset);

    // Backtrack to the stage where you made the decision whether to include or not
    currentSubset.pop_back();

    // Choice 2: exclude
    generateSubset(arr, index + 1, currentSubset, allSubset);
}

vector<vector<int>> allSubset(vector<int> &arr)
{
    vector<int> output;
    vector<vector<int>> powerSet;
    int index = 0;
    generateSubset(arr, index, output, powerSet);

    return powerSet;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> powerSet = allSubset(arr);

    for (auto &&i : powerSet)
    {
        cout << "{ ";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "} " << endl;
    }

    return 0;
}