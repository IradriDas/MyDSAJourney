// WAP to print sum of first N even numbers using recursion.
#include <iostream>
using namespace std;

int nEvenSum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n * 2 + nEvenSum(n - 1);
}

int main()
{
    cout << nEvenSum(5);

    return 0;
}