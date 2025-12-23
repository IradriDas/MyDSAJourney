// WAP to find sum of array elements using recursion.
#include <iostream>
#include <vector>
using namespace std;

int arraySum(vector<int> array, int index)
{
    if (index < array.size())
    {
        return array[index] + arraySum(array, index + 1);
    }

    return 0;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    cout << arraySum(nums, 0);

    return 0;
}