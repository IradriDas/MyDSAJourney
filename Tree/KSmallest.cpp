#include <queue>
#include <vector>
#include <iostream>
using namespace std;

vector<int> kSmallest(vector<int> &nums, int k)
{
    priority_queue<int> max_heap;

    for (int i = 0; i < k; i++)
    {
        max_heap.push(nums[i]);
    }

    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] < max_heap.top())
        {
            max_heap.pop();
            max_heap.push(nums[i]);
        }
    }

    vector<int> kSmallestElements;
    kSmallestElements.reserve(max_heap.size());

    while (!max_heap.empty())
    {
        kSmallestElements.push_back(max_heap.top());
        max_heap.pop();
    }

    return kSmallestElements;
}

int main()
{
    return 0;
}