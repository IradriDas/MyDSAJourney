#include <queue>
#include <vector>
#include <iostream>
using namespace std;

/*
    Function: kSmallest
    Purpose : Finds the k smallest elements from the given array.

    Params  :
      - nums : reference to the input vector of integers
      - k    : number of smallest elements to extract

    Time Complexity : O(n log k)
    Space Complexity: O(k)
*/
vector<int> kSmallest(vector<int> &nums, int k)
{
    // Max-heap to keep track of the k smallest elements seen so far
    priority_queue<int> max_heap;

    // Insert first k elements into the heap
    for (int i = 0; i < k; i++)
    {
        max_heap.push(nums[i]); // push current element into max-heap
    }

    // Process remaining elements in the array
    for (int i = k; i < nums.size(); i++)
    {
        // If current element is smaller than the largest in heap
        if (nums[i] < max_heap.top())
        {
            max_heap.pop();          // remove the largest element
            max_heap.push(nums[i]);  // insert the smaller element
        }
    }

    // Vector to store the k smallest elements
    vector<int> kSmallestElements;
    kSmallestElements.reserve(max_heap.size()); // reserve space for efficiency

    // Extract elements from the heap
    while (!max_heap.empty())
    {
        kSmallestElements.push_back(max_heap.top()); // add heap top to result
        max_heap.pop();                              // remove extracted element
    }

    // Return the collected k smallest elements (order not guaranteed)
    return kSmallestElements;
}


int main()
{
    return 0;
}