#include <iostream>
#include <vector>
using namespace std;

bool isSortedHelper(vector<int> &nums, int n){
    if (n < nums.size()) {
        if (nums[n-1] > nums[n]) {
            return false;
        }
        else {
            return isSortedHelper(nums, ++n);
        }
    }
    else {
        return true;
    }
}

bool isSorted(vector<int> &nums)
{
    int n =1;
    return isSortedHelper(nums , n);

}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {1, 2, 1, 4, 5};

    cout << isSorted(nums1) << endl;
    cout << isSorted(nums2);

    return 0;
}
