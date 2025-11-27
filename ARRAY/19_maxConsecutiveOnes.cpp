#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max = 0;
    int count = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            count = 0;
        }
        else if (nums[i] == 1)
        {
            count++;
            if (count > max)
            {
                max = count;
            }
        }
    }
    return max;
}
int main()
{
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0};

    cout << findMaxConsecutiveOnes(nums);

    return 0;
}
