#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            if (i != j)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
            j++;
        }
    }
}
int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

    removeElement(nums, 2);

    cout << "OUTPUT : ";
    for (int it : nums)
    {
        cout << it << " ";
    }

    return 0;
}