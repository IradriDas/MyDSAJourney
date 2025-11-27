// Given an integer array nums, rotate the array to the right by k steps,
// where k is non-negative.

// Example 1:
//     Input: nums = [1,2,3,4,5,6,7], k = 3
//     Output: [5,6,7,1,2,3,4]
//     Explanation:
//         rotate 1 steps to the right: [7,1,2,3,4,5,6]
//         rotate 2 steps to the right: [6,7,1,2,3,4,5]
//         rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
//     Input: nums = [-1,-100,3,99], k = 2
//     Output: [3,99,-1,-100]
//     Explanation:
//         rotate 1 steps to the right: [99,-1,-100,3]
//         rotate 2 steps to the right: [3,99,-1,-100]

// Given an integer array nums, rotate the array to the right by k steps.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Function: rotate
    Purpose : Rotates the vector to the RIGHT by k positions.

              Example:
                nums = [1,2,3,4,5,6,7], k = 3
                Output = [5,6,7,1,2,3,4]

    Params  : nums → reference to the vector to rotate.
              k    → number of steps to rotate to the right.

    Approach (Reversal Algorithm):
        To rotate RIGHT by k:
            1. Reverse entire array
            2. Reverse first k elements
            3. Reverse elements from k to end

        Why it works:
            Right rotation by k means the last k elements should come first.
            The 3-step reversal technique achieves this efficiently.

    Time Complexity:
        O(n) — each element is swapped a constant number of times.

    Space Complexity:
        O(1) — in-place rotation.

    Side Effects:
        - Modifies the input vector directly.
        - If k >= vector size, using k % n prevents extra rotations.
        - This version assumes caller ensures k is in valid range.
*/
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return;

    k = k % n; // Handle k greater than size

    // Step 1: Reverse whole array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse remaining elements
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums2 = {-1, -100, 3, 99};

    rotate(nums1, 3); // Expected: [5,6,7,1,2,3,4]
    rotate(nums2, 2); // Expected: [3,99,-1,-100]

    cout << endl
         << "nums1: ";
    for (int i : nums1)
        cout << i << ", ";

    cout << endl
         << "nums2: ";
    for (int i : nums2)
        cout << i << ", ";

    return 0;
}
