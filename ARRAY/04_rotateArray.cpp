// Given an integer array nums, rotate the array to the left by one.
// Note: There is no need to return anything, just modify the given array.

// Examples:
//     Input: nums = [1, 2, 3, 4, 5]
//     Output: [2, 3, 4, 5, 1]
//     Explanation: Initially, nums = [1, 2, 3, 4, 5]
//     Rotating once to left -> nums = [2, 3, 4, 5, 1]

//     Input: nums = [-1, 0, 3, 6]
//     Output: [0, 3, 6, -1]
//     Explanation: Initially, nums = [-1, 0, 3, 6]
//     Rotating once to left -> nums = [0, 3, 6, -1]

#include <iostream>
#include <vector>
using namespace std;

/*
    Function: rotateArrayByOne
    Purpose : Rotates the array to the left by one position.
              Example: [1, 2, 3, 4] → [2, 3, 4, 1]

    Params  : nums → reference to the vector to be rotated.

    Behavior:
        - Stores the first element temporarily.
        - Shifts all elements one position to the left.
        - Places the original first element at the end.

    Time Complexity:
        O(n) — every element is moved once.

    Space Complexity:
        O(1) — only one temporary variable used.

    Side Effects:
        - Modifies the input vector in-place.
        - If nums is empty, this function will cause undefined behavior
          (accessing nums[0]). Should be guarded in production.
*/
void rotateArrayByOne(vector<int> &nums)
{
    int temporary = nums[0];

    // Shift elements to the left
    for (int i = 0; i < nums.size() - 1; i++)
    {
        nums[i] = nums[i + 1];
    }

    // Move original first element to end
    nums[nums.size() - 1] = temporary;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {-1, 0, 3, 6};

    rotateArrayByOne(nums1);
    rotateArrayByOne(nums2);

    cout << endl
         << "nums1: ";
    for (auto i : nums1)
    {
        cout << i << ", ";
    }

    cout << endl
         << "nums2: ";
    for (auto i : nums2)
    {
        cout << i << ", ";
    }

    return 0;
}
