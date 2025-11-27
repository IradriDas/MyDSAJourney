// Given an array of integers nums, return the second-largest element in the array.
// If the second-largest element does not exist, return -1.

// Examples:
/*
    Input: nums = [8, 8, 7, 6, 5]
    Output: 7
    Explanation: The largest value in nums is 8, the second largest is 7

    Input: nums = [10, 10, 10, 10, 10]
    Output: -1
    Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    Function: secondLargestElement
    Purpose : Finds the second largest distinct element in the array.
    Params  : nums → reference to the input vector.
    Returns : The second largest element.
              If no second largest distinct element exists, returns -1.

    Behavior:
        - Tracks the largest and second largest values.
        - Updates them while traversing the array.
        - Duplicate largest values are skipped (ensures distinct second largest).

    Time Complexity:
        O(n) — single pass over the array.

    Space Complexity:
        O(1).

    Side Effects:
        - None. Does not modify the input array.
        - Relies on initial value `secondLarge = -1`, so negative-only arrays
          might produce incorrect results unless adjusted.
*/
int secondLargestElement(vector<int> &nums)
{
    int large = nums[0];
    int secondLarge = -1;

    for (auto i = 1; i < nums.size(); i++)
    {
        if (nums[i] > large)
        {
            secondLarge = large;
            large = nums[i];
        }
        else if (nums[i] < large && nums[i] > secondLarge)
        {
            secondLarge = nums[i];
        }
    }

    return secondLarge;
}

/*
    Function: secondSmallestElement
    Purpose : Finds the second smallest distinct element in the array.
    Params  : nums → reference to the input vector.
    Returns : The second smallest element.
              If no second smallest distinct element exists, returns a large placeholder.

    Behavior:
        - Tracks the smallest and second smallest values.
        - Updates them while iterating through the array.
        - Duplicate smallest values are ignored (ensures distinct second smallest).

    Time Complexity:
        O(n).

    Space Complexity:
        O(1).

    Side Effects:
        - The initial value of secondSmall = 1000000 assumes input range fits under it.
        - If values exceed this bound or are very large negative, adjust placeholder accordingly.
*/
int secondSmallestElement(vector<int> &nums)
{
    int small = nums[0];
    int secondSmall = 1000000; // Placeholder for very large number

    for (auto i = 1; i < nums.size(); i++)
    {
        if (nums[i] < small)
        {
            secondSmall = small;
            small = nums[i];
        }
        else if (nums[i] > small && nums[i] < secondSmall)
        {
            secondSmall = nums[i];
        }
    }

    return secondSmall;
}

int main()
{
    vector<int> nums1 = {8, 8, 7, 6, 5, 60};
    vector<int> nums2 = {10, 10, 11, 10, 10};

    cout << secondLargestElement(nums1) << endl; // Output: 8
    cout << secondLargestElement(nums2) << endl; // Output: 10

    cout << secondSmallestElement(nums1) << endl; // Output: 6
    cout << secondSmallestElement(nums2) << endl; // Output: 11

    return 0;
}
