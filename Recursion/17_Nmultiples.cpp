// WAP to print first N multiples of a given number using recursion
#include <iostream>
using namespace std;

void nMultiple(int num, int N)
{
    if (N == 0)
    {
        /* code */
        return;
    }

    nMultiple(num, N - 1);
    cout << num * N << " ";
}

int main()
{
    nMultiple(4, 5);
    return 0;
}