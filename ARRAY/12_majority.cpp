#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Function: majorityElement
    Purpose : Finds the majority element in an array.

              Majority element = the element that appears
              more than ⌊ n/2 ⌋ times.

    Params  : nums → reference to the array.

    Approach:
        1. Sort the array.
        2. The majority element will always occupy the middle position
           after sorting (if it truly exists).
        3. This code instead counts consecutive equal elements and
           tracks the element with highest frequency.

    Behavior:
        - Works correctly if there is guaranteed to be a majority element.
        - Sorting groups identical elements together.
        - Count consecutive duplicates and track the maximum streak.

    Time Complexity:
        O(n log n) — due to sorting.

    Space Complexity:
        O(1) — in-place.

    Side Effects:
        - Modifies the input array because it sorts it.
        - Does NOT validate whether the found element actually exceeds n/2 count.
        - If array has no majority, result is undefined.
        - For input size == 1, it returns the only element.

    NOTE:
        A more efficient approach exists: Moore’s Voting Algorithm (O(n), O(1)).
*/
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int count = 0;
    int maxCount = 0;
    int majority = nums[0];

    if (nums.size() == 1)
    {
        return nums[0];
    }

    // Count consecutive duplicates
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] == nums[i])
        {
            count++;
            if (count > maxCount)
            {
                maxCount = count;
                majority = nums[i];
            }
        }
        else
        {
            count = 0;
        }
    }

    return majority;
}

int main()
{
    vector<int> nums = {6, 6, 6, 7, 7};

    cout << majorityElement(nums);

    return 0;
}
