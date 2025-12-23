// WAP to print array elements using recursion.
#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> nums, int index)
{
    if (nums.size() == index)
    {
        return;
    }

    cout << nums[index] << " ";
    printArray(nums, index + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArray(nums, 0);

    return 0;
}