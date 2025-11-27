// (Leetcode)1752. Check if Array Is Sorted and Rotated

// Given an array nums, return true if the array was originally sorted in non-decreasing order,
// then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.
// Note: An array A rotated by x positions results in an array B of the same length such that B[i] == A[(i+x) % A.length] for every valid index i.

// Example 1:
//     Input: nums = [3,4,5,1,2]
//     Output: true
//     Explanation: [1,2,3,4,5] is the original sorted array.
//     You can rotate the array by x = 2 positions to begin on the element of value 3: [3,4,5,1,2].

// Example 2:
//     Input: nums = [2,1,3,4]
//     Output: false
//     Explanation: There is no sorted array once rotated that can make nums.

// Example 3:
//     Input: nums = [1,2,3]
//     Output: true
//     Explanation: [1,2,3] is the original sorted array.
//     You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

#include <iostream>
#include <vector>

using namespace std;

/*
    Function: check
    Purpose : Determines whether an array is sorted and rotated.
              Sorted + Rotated means:
                  - The array was originally sorted in non-decreasing order.
                  - It may have been rotated at most once.

              Example:
                  [3,4,5,1,2] → Valid (sorted rotated)
                  [2,1,3,4]   → Invalid
                  [1,2,3]     → Valid (already sorted, rotation count = 0)

    Params  : nums → reference to input vector.
    Returns : true  → if array is sorted and rotated at most once.
              false → otherwise.

    Logic:
        - Count how many times nums[i] > nums[i+1].
        - If this happens more than once → not sorted+rotated.
        - Also check the rotation boundary: last element > first element.
        - Total decreases (count) must be <= 1.

    Time Complexity:
        O(n) — single traversal.

    Space Complexity:
        O(1).

    Side Effects:
        - None; the function does not modify the array.
*/
bool check(vector<int> &nums)
{
    int count = 0;

    // Count "drops" in the array
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            count++;
            if (count > 1)
            {
                return false;
            }
        }
    }

    // Check boundary: last element > first element → another rotation break
    if (nums[nums.size() - 1] > nums[0])
    {
        count++;
    }

    return count <= 1;
}

int main()
{
    vector<int> nums1 = {3, 4, 5, 1, 2}; // true
    vector<int> nums2 = {2, 1, 3, 4};    // false
    vector<int> nums3 = {1, 2, 3};       // true

    cout << check(nums1) << endl;
    cout << check(nums2) << endl;
    cout << check(nums3) << endl;

    return 0;
}
