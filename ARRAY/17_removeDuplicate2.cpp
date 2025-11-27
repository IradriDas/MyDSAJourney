#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    // Handle cases where the array is too small to have a third duplicate.
    if (nums.size() <= 2)
    {
        return nums.size();
    }

    // slow is the write pointer. The first two elements are always valid.
    int slow = 2;

    // fast is the read pointer, starting from the third element.
    for (int fast = 2; fast < nums.size(); fast++)
    {
        // The CORRECTED check:
        // Compare the current element `nums[fast]` with the element
        // two positions before the current write pointer `slow`.
        if (nums[fast] != nums[slow - 2])
        {
            // If it's a new number or just the second occurrence, keep it.
            nums[slow] = nums[fast];
            slow++;
        }
        // If nums[fast] == nums[slow - 2], it means we already have two
        // occurrences of this number ([..., num, num]), so we just
        // increment `fast` to skip this third duplicate.
    }

    return slow;
}

int main()
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    cout << removeDuplicates(nums);

    return 0;
}