// WAP to count elements of an array using recursion.
#include <iostream>
#include <vector>
using namespace std;

int countElements(vector<int> array, int index)
{
    if (array.size() == index)
    {
        return 0;
    }

    return 1 + countElements(array, index + 1);
}

int main()
{
    vector<int> nums = {};

    return 0;
}