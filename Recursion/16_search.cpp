// WAP to check whether an element exists in array using recursion.
#include <iostream>
#include <vector>
using namespace std;

bool isExist(vector<int> nums, int key, int index)
{
    if (index >= nums.size())
    {
        return false;
    }

    if (nums[index] == key)
    {
        return true;
    }
    else
    {
        return isExist(nums, key, index + 1);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

    cout << isExist(nums, 5, 0);
    cout << isExist(nums, 7, 0);

    return 0;
}