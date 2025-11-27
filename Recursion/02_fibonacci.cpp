#include <iostream>
using namespace std;

/*
    Function: fibonacci
    Purpose : Computes the nth Fibonacci number using recursion.
    Params  : n → the position in the Fibonacci sequence.
              (Using 1-based indexing: F(1) = 1, F(2) = 1)
    Returns : The nth Fibonacci number.

    Note    : This is a basic recursive implementation.
              Time complexity grows exponentially (O(2^n)).
*/
int fibonacci(int n)
{
    // Base cases for 1-based Fibonacci sequence:
    // F(1) = 1, F(2) = 1
    if (n == 1 || n == 2)
    {
        return 1;
    }

    // Recursive case: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    // Print the 5th Fibonacci number
    cout << fibonacci(5);
    return 0;
}
