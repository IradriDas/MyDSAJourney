#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Function: reverse
    Purpose : Recursively reverses a portion of the array in-place.

    Params  :
        arr   → reference to the vector to reverse
        left  → starting index of the segment
        right → ending index of the segment

    Behavior:
        - Base case: if left >= right, recursion stops.
        - Swap arr[left] and arr[right].
        - Recursively reverse the inner sub-array: (left+1, right-1).

    Example:
        arr = [1,2,3,4,5,6]
        After reverse(arr, 0, 5):
        arr = [6,5,4,3,2,1]

    Time Complexity:
        O(n) — each swap moves inward by one pair.

    Space Complexity:
        O(n) due to recursion stack depth.

    Side Effects:
        - Modifies the original vector.
        - Deep recursion for very large arrays may cause stack overflow.
*/

void reverseHelper(vector<int> &arr, int start)
{
    int n = arr.size();
    if (start >= n / 2)
    {
        return;
    }

    swap(arr[start], arr[n-1-start]);

    reverseHelper(arr, start + 1);
}

void reverse(vector<int> &arr)
{
    reverseHelper(arr, 0);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    reverse(arr);

    cout << "Reversed Array: ";
    for (auto &&i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
