// WAP to merge two sorted arrays.

#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrayHelper(
    vector<int> &arr1,
    vector<int> &arr2,
    int idx1,
    int idx2,
    vector<int> &result,
    int idx3)
{

    if (idx1 == arr1.size() && idx2 == arr2.size())
    {
        return;
    }

    if (idx1 >= arr1.size())
    {
        result[idx3] = arr2[idx2];
        mergeSortedArrayHelper(arr1, arr2, idx1, idx2 + 1, result, idx3 + 1);
        return;
    }

    if (idx2 >= arr2.size())
    {
        result[idx3] = arr1[idx1];
        mergeSortedArrayHelper(arr1, arr2, idx1 + 1, idx2, result, idx3 + 1);
        return;
    }

    if (arr1[idx1] <= arr2[idx2])
    { // chota pehle insert hoga
        result[idx3] = arr1[idx1];
        mergeSortedArrayHelper(arr1, arr2, idx1 + 1, idx2, result, idx3 + 1);
    }
    else
    {
        result[idx3] = arr2[idx2];
        mergeSortedArrayHelper(arr1, arr2, idx1, idx2 + 1, result, idx3 + 1);
    }
}

vector<int> mergeSortedArray(vector<int> &arr1, vector<int> &arr2)
{

    vector<int> sorted;
    sorted.resize(arr1.size() + arr2.size());

    int idx1 = 0;
    int idx2 = 0;
    int idx3 = 0;

    mergeSortedArrayHelper(arr1, arr2, idx1, idx2, sorted, idx3);

    return sorted;
}
int main()
{
    vector<int> nums1 = {1, 3, 5, 7, 8, 9};
    vector<int> nums2 = {2, 4, 5, 6, 8};

    vector<int> num3 = mergeSortedArray(nums1, nums2);

    for (auto &&i : num3)
    {
        cout << i << " ";
    }

    return 0;
}