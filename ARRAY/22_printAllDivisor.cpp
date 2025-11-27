#include <iostream>
#include <vector>
#include <algorithm>
// #include <iterator>
using namespace std;

vector<int> divisors(int n)
{
    vector<int> result;
    for (int i = 1; i <= n / 2; i++)
    {
        if (n % i == 0 && find(result.begin(), result.end(), i) == result.end())
        {
            result.emplace_back(i);
            result.emplace_back(n / i);
        }
    }

    sort(result.begin(), result.end());

    return result;
}

int main()
{
    vector<int> nums = divisors(20);

    for (auto &&i : nums)
    {
        cout << i << " ";
    }

    return 0;
}