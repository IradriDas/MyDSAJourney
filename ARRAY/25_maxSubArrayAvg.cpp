#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

/*
    Function: findMaxAverage
    Purpose : Finds the maximum average value of any contiguous subarray
              of length k in the given array.

    Params  :
        nums → reference to the input integer vector.
        k    → size of the sliding window (length of subarray).

    Behavior:
        - Uses the sliding window technique:
            * Compute the sum of the first k elements.
            * Slide the window one element at a time by subtracting the outgoing
              element and adding the incoming one.
            * Track the maximum subarray sum seen so far.
        - Convert the maximum sum to a double average and return.

    Example:
        nums = [1,12,-5,-6,50,3], k = 4
        Subarrays of size 4:
            [1,12,-5,-6]  → avg = 0.5
            [12,-5,-6,50] → avg = 12.75
            [-5,-6,50,3]  → avg = 10.5
            Max = 12.75

    Time Complexity:
        O(n) — each element is visited once.

    Space Complexity:
        O(1) — uses only a few variables.

    Side Effects:
        - Does not modify the input vector.
        - Assumes nums.size() >= k.
*/
double findMaxAverage(vector<int> &nums, int k)
{
    int subArraySum = 0;

    // Compute initial sum for first window of size k
    for (int i = 0; i < k; i++)
    {
        subArraySum += nums[i];
    }

    int maxSubArraySum = subArraySum;

    // Slide window over the rest of the array
    int start = 0;
    for (int end = k; end < nums.size(); end++)
    {
        subArraySum = subArraySum - nums[start]; // remove outgoing element
        start++;
        subArraySum = subArraySum + nums[end]; // add incoming element

        if (subArraySum > maxSubArraySum)
        {
            maxSubArraySum = subArraySum;
        }
    }

    // Convert max sum to average
    return double(maxSubArraySum) / double(k);
}

int main()
{
    vector<int> nums = {1, 12, -5, -6, 50, 3};

    cout << findMaxAverage(nums, 4);

    return 0;
}