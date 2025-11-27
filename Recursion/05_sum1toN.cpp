#include <iostream>
using namespace std;

/*
    Function: sum1toN
    Purpose : Computes the sum of all integers from 1 to n using recursion.
    Params  : n → the number up to which the sum is computed.
    Returns : The total sum (1 + 2 + ... + n).
    Behavior:
        - Uses the base case n == 0, which returns 0.
        - Recursively adds n to the sum of previous numbers.
*/
int sum1toN(int n)
{
    // Base case: sum of numbers up to 0 is 0
    if (n == 0)
    {
        return 0;
    }

    // Recursive case: n + sum of all numbers before it
    return n + sum1toN(n - 1);
}

int main()
{
    // Print the sum of numbers from 1 to 3
    cout << sum1toN(3);
    return 0;
}
