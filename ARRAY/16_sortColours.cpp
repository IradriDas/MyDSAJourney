#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortColors(vector<int> &nums)
{
    // int count0 = 0;
    // int count1 = 0;
    // int count2 = 0;

    // for (int num : nums) {
    //     if (num == 0) {
    //         count0++;
    //     } else if (num == 1) {
    //         count1++;
    //     } else if (num == 2) {
    //         count2++;
    //     }
    // }

    // for (int i = 0; i < count0; i++) {
    //     nums[i] = 0;
    // }

    // for (int i = count0; i < count0 + count1; i++) {
    //     nums[i] = 1;
    // }

    // for (int i = count0 + count1; i < count0 + count1 + count2; i++) {
    //     nums[i] = 2;
    // }

    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else if ((nums[mid] == 2))
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    for (int i : nums)
    {
        cout << i << " ";
    }

    return 0;
}