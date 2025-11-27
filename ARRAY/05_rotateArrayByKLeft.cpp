#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Function: rotateByKLeft
    Purpose : Rotates the array to the LEFT by k positions.

              Example:
                nums = [1, 2, 3, 4, 5], k = 2
                Output = [3, 4, 5, 1, 2]

    Params  : nums → reference to the vector to rotate.
              k    → number of left rotations.

    Approach (Reversal Algorithm):
        To rotate LEFT by k:
            1. Reverse first k elements
            2. Reverse remaining n - k elements
            3. Reverse entire array

        Why this works:
            - Left rotation by k is equivalent to moving the first k elements
              to the end while keeping order intact.
            - Three reversals achieve this efficiently.

    Time Complexity:
        O(n) — three reversals over the array.

    Space Complexity:
        O(1) — in-place rotation.

    Side Effects:
        - Modifies the input vector.
        - If nums is empty, function returns safely.
        - For very large k, `k = k % n` prevents unnecessary rotations.
*/
void rotateByKLeft(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0 || k == 0)
        return;

    k = k % n;

    // Reverse first k elements
    reverse(nums.begin(), nums.begin() + k);

    // Reverse remaining n-k elements
    reverse(nums.begin() + k, nums.end());

    // Reverse entire array
    reverse(nums.begin(), nums.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    rotateByKLeft(nums1, 2); // Expected: {3,4,5,1,2}

    vector<int> nums2 = {-1, 0, 3, 6};
    rotateByKLeft(nums2, 3); // Expected: {6,-1,0,3}

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
