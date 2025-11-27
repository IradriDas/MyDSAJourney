#include <iostream>
using namespace std;

/*
    Function: power
    Purpose : Computes base^exponent using fast exponentiation (binary exponentiation).
    Params  : base     → the number to be raised.
              exponent → how many times 'base' is multiplied.
    Returns : base raised to the power exponent as long long.

    How it works (Binary Exponentiation):
        - Instead of multiplying 'base' exponent times, it reduces the exponent by half each step.
        - If exponent is even:
              b^e = (b^(e/2)) * (b^(e/2))
        - If exponent is odd:
              b^e = (b^(e/2)) * (b^(e/2)) * b

    Time Complexity:
        - O(log n) — much faster than simple recursive power (O(n)).

    Side Effects:
        - Deep recursion possible if exponent is extremely large (but far less than naive recursion).
        - No overflow handling → results can exceed long long range without warning.
        - For negative exponents, this implementation is undefined (not handled).
*/
long long power(int base, int exponent)
{
    // Base case: anything raised to 0 is 1
    if (exponent == 0)
    {
        return 1;
    }

    // Recursively compute half power
    long long x = power(base, exponent / 2);

    // If exponent is even: b^e = (b^(e/2))^2
    if (exponent % 2 == 0)
    {
        return x * x;
    }
    else
    {
        // If exponent is odd: b^e = (b^(e/2))^2 * b
        return x * x * base;
    }
}

int main()
{
    // Compute 2^5
    cout << power(2, 5);
    return 0;
}
