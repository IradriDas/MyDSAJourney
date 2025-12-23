// WAP to print array elements in reverse order using recursion.
#include <iostream>
#include <vector>
using namespace std;

void reverseArrayPrint(vector<int> array, int index)
{
    if (index >= array.size())
    {
        return;
    }

    reverseArrayPrint(array, index + 1);

    cout << array[index] << " ";
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    reverseArrayPrint(nums, 0);

    return 0;
}