#include <iostream>
using namespace std;

/*
    Function: factorial
    Purpose : Computes the factorial of a non-negative integer n using recursion.
    Params  : n → integer whose factorial is to be calculated.
    Returns : n! (factorial of n). For n = 0, returns 1 (base case).
*/
int factorial(int n)
{
    // Base case: factorial of 0 is defined as 1
    if (n == 0)
    {
        return 1;
    }

    // Recursive case: n! = n * (n-1)!
    return n * factorial(n - 1);
}

int main()
{
    // Display factorial of 5
    cout << factorial(5);
    return 0;
}
