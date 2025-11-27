#include <iostream>
#include <vector>
#include <map>
// #include <iterator>
using namespace std;

int longestSubarray(vector<int> &nums, int k)
{
    map<long, int> prefixSum;
    long sum = 0;
    int length = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum = sum + nums[i];
        if (sum == k)
        {
            length = max(length, i + 1);
        }

        if (prefixSum.find(sum - k) != prefixSum.end())
        {
            length = max(length, (i - prefixSum[sum - k]));
        }

        prefixSum.insert({sum, i});
    }

    return length;
}
int main()
{
    vector<int> nums = {10, 5, 2, 7, 1, 9};

    cout << longestSubarray(nums, 15);

    return 0;
}