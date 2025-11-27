#include <iostream>
#include <vector>
using namespace std;

int largestElement(vector<int> &nums)
{
    int large = nums[0];
    for (auto i = 0; i < nums.size(); i++)
    {
        if (nums[i] > large)
        {
            large = nums[i];
        }
    }
    return large;
}
int main()
{
    vector<int> nums = {3, 3, 0, -40};
    cout << largestElement(nums);

    return 0;
}