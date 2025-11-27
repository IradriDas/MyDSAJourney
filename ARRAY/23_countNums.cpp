#include <iostream>
#include <vector>
// #include <iterator>
using namespace std;

int countNums(int num)
{
    int count = 0;

    do
    {
        count++;
        num = num / 10;
    } while (num > 0);

    return count;
}
int main()
{
    // vector<int> nums = {};

    cout << countNums(1230);

    return 0;
}