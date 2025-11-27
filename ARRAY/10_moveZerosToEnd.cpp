#include <iostream>
#include <vector>
using namespace std;

/*
    Function: moveZeroes
    Purpose : Moves all zeroes in the array to the END while preserving
              the relative order of all non-zero elements.

              Example:
                Input : [0,1,4,0,5,2]
                Output: [1,4,5,2,0,0]

    Params  : nums → reference to the input vector.

    Approach (Two-Pointer / Stable Partition):
        - Pointer j marks the position where the next non-zero should go.
        - Pointer i scans through the array.
        - Whenever nums[i] is non-zero:
              - swap nums[i] with nums[j] (only if i != j)
              - increment j
        - All zeros naturally shift to the end.

    Time Complexity:
        O(n) — single pass through the array.

    Space Complexity:
        O(1) — done in-place.

    Side Effects:
        - Modifies the input vector directly.
        - Maintains the order of non-zero elements.
        - Uses swaps, but unnecessary swaps are avoided due to (i != j).
*/
void moveZeroes(vector<int> &nums)
{
    int j = 0; // position to place the next non-zero

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            if (i != j)
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
            j++;
        }
    }
}

int main()
{
    vector<int> nums1 = {0, 1, 4, 0, 5, 2};
    vector<int> nums2 = {0, 0, 0, 1, 3, -2};

    moveZeroes(nums2);

    cout << "OUTPUT : ";
    for (int it : nums2)
    {
        cout << it << " ";
    }

    return 0;
}
