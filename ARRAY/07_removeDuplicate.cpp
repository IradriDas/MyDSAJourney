#include <iostream>
#include <vector>
using namespace std;

/*
    Function: removeDuplicates
    Purpose : Removes duplicates from a sorted array in-place,
              ensuring each unique element appears only once.

    Params  : nums → reference to a sorted vector (non-decreasing order).

    Returns : The count of unique elements (new length of the array).

    Behavior:
        - Uses the two-pointer technique.
        - Pointer j tracks the position of the last unique element.
        - Pointer i scans the entire list.
        - Whenever nums[i] differs from nums[j], we found a new unique value.
        - It is stored at position ++j.

    Requirements:
        - Input vector MUST be sorted.
          If unsorted, this method will NOT work correctly.

    Time Complexity:
        O(n) — one pass through the array.

    Space Complexity:
        O(1) — in-place, no extra memory.

    Side Effects:
        - Modifies the input vector in-place.
        - Elements after the returned length are irrelevant/leftover old data.
*/
int removeDuplicates(vector<int> &nums)
{
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[j] != nums[i])
        {
            nums[++j] = nums[i];
        }
    }

    return j + 1;
}

int main()
{
    vector<int> nums = {-2, 2, 4, 4, 4, 4, 5, 5};

    int d = removeDuplicates(nums);

    for (int i = 0; i < d; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl
         << "Total Duplicate elements : " << d;

    return 0;
}
