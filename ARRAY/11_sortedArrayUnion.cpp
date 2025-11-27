// Union of two sorted arrays
// Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays.
// The elements in the union must be in ascending order.

// The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

// Examples:

// Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
// Output: [1, 2, 3, 4, 5, 7]
// Explanation:
//     The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

// Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
// Output: [1, 3, 4, 5, 6, 7, 8, 9]
// Explanation:
//     The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2

#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
    Function: unionArray
    Purpose : Computes the union of two arrays and returns
              all unique elements in sorted order.

              Example:
                nums1 = {3,4,6,7,9,9}
                nums2 = {1,5,7,8,8}
                Output = {1,3,4,5,6,7,8,9}

    Params  : nums1, nums2 → input vectors.

    Behavior:
        - Inserts all elements of both arrays into a std::set.
        - std::set automatically:
              * removes duplicates
              * stores elements in sorted ascending order
        - Converts the set into a result vector and returns it.

    Time Complexity:
        O((n + m) log(n + m))
        - Each insertion into a set is O(log n).

    Space Complexity:
        O(n + m)
        - Set and result vector store unique elements.

    Side Effects:
        - Does NOT modify input arrays.
        - Ordering is ascending because std::set uses sorted order.
*/
vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
{
    set<int> s;
    vector<int> result;

    // Insert all elements from nums1
    for (int i = 0; i < nums1.size(); i++)
    {
        s.insert(nums1[i]);
    }

    // Insert all elements from nums2
    for (int i = 0; i < nums2.size(); i++)
    {
        s.insert(nums2[i]);
    }

    // Move set elements into result vector
    for (auto it : s)
    {
        result.push_back(it);
    }

    return result;
}

int main()
{
    vector<int> nums1 = {3, 4, 6, 7, 9, 9};
    vector<int> nums2 = {1, 5, 7, 8, 8};

    vector<int> result = unionArray(nums1, nums2);

    cout << "nums1: ";
    for (int i : nums1)
        cout << i << " ";
    cout << endl;

    cout << "nums2: ";
    for (int i : nums2)
        cout << i << " ";
    cout << endl;

    cout << "Union: ";
    for (int i : result)
        cout << i << " ";
    cout << endl;

    return 0;
}
