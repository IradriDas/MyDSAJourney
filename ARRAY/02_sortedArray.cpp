#include <iostream>
#include <vector>
using namespace std;

/*
    Function: isSorted
    Purpose : Checks whether a given vector is sorted in non-decreasing order.
    Params  : nums → reference to the vector being checked.
    Returns : true  → if the vector is sorted.
              false → if any element is greater than the next.

    Behavior:
        - Iterates through the vector and compares each element with the next one.
        - If any nums[i] > nums[i+1], the array is not sorted.

    Time Complexity:
        O(n) — single pass through the array.

    Space Complexity:
        O(1) — uses constant extra space.

    Side Effects:
        - None. The function does not modify the input vector.
*/
bool isSorted(vector<int> &nums)
{
    bool result = true;

    for (auto i = 0; i < (nums.size() - 1); i++)
    {
        if (nums[i] > nums[i + 1])
        {
            result = false;
            break;
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 1, 4, 5};

    cout << isSorted(nums1) << endl; // Should output 1 (true)
    cout << isSorted(nums2);         // Should output 0 (false)

    return 0;
}
