#include <iostream>
#include <vector>
#include <algorithm>
// #include <map>
// #include <iterator>
using namespace std;

bool hasDuplicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 3};
    vector<int> nums2 = {1, 2, 3, 4};

    cout << hasDuplicate(nums1);
    cout << hasDuplicate(nums2);
    return 0;
}
