#include <iostream>
using namespace std;

/*
    Function: pow
    Purpose : Computes base^exponent using simple recursion.
    Params  : base     → the number to be raised.
              exponent → how many times 'base' is multiplied by itself.
    Returns : base raised to the power exponent.

    Side Effects:
        - Uses deep recursion → large exponents can trigger stack overflow.
        - Extremely slow for large exponent values (O(n) time).
        - No overflow protection → results may exceed int range easily.
        - Will not work with negative exponents
*/
int pow(int base, int exponent)
{
    // Base case: any number raised to 0 is 1
    if (exponent == 0)
    {
        return 1;
    }

    // Recursive case: base^exponent = base * base^(exponent - 1)
    return base * pow(base, exponent - 1);
}

int main()
{
    // Compute 2^10
    cout << pow(2, 10);
    return 0;
}
