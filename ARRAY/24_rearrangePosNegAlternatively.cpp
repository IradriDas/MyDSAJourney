#include <iostream>
#include <vector>
using namespace std;

/*
    Function: rearrange
    Purpose : Rearranges the array such that:
                - All positive (and zero) numbers appear first
                - All negative numbers appear after
                - The original relative order among positives is preserved
                - The original relative order among negatives is preserved
                - Final arrangement alternates elements from pos[] and neg[] 
                  ONLY in output order, not strict alternation requirement.

    Params  : arr → input vector (modified in-place)
    
    Approach:
        1. Traverse the array and separate elements into two lists:
              pos → stores all non-negative elements
              neg → stores all negative elements
        2. Clear the original array.
        3. Push elements back by alternating from pos and neg sequences
           while maintaining their relative order.

    Time Complexity:
        O(n) — single pass to split + single pass to merge.

    Space Complexity:
        O(n) — uses extra arrays pos[] and neg[].

    Side Effects:
        - The original array 'arr' is cleared and rebuilt.
        - Requires additional memory proportional to input size.
        - Ordering within positives and negatives is preserved,
          but overall interleaving depends on the merging loop.
*/
void rearrange(vector<int> &arr)
{
    vector<int> pos, neg;

    // Separate positive (and zero) and negative elements
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }

    int itr1 = 0; // pointer for pos[]
    int itr2 = 0; // pointer for neg[]

    // Clear the original array and prepare capacity
    arr.clear();
    arr.reserve(pos.size() + neg.size());

    // Merge while maintaining relative order
    while (itr1 < pos.size() || itr2 < neg.size())
    {
        if (itr1 < pos.size())
        {
            arr.push_back(pos[itr1]);
            itr1++;
        }

        if (itr2 < neg.size())
        {
            arr.push_back(neg[itr2]);
            itr2++;
        }
    }
}

int main()
{
    vector<int> nums = {9, 4, -2, -1, 5, 0, -5, -3, 2};

    rearrange(nums);

    for (int num : nums)
    {
        cout << num << " ";
    }

    return 0;
}
