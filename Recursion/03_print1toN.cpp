#include <iostream>
using namespace std;

/*
    Function: print1toN
    Purpose : Prints numbers from 1 to n using recursion.
    Params  : n → the number up to which values should be printed.
    Behavior:
        - Uses a recursive call to first reach the base case (n == 0).
        - After returning from each recursive call, prints the number.
        - This ensures values are printed in increasing order.
*/
void print1toN(int n)
{
    // Base case: stop when n reaches 0
    // (Do not print 0 because the sequence starts from 1)
    if (n == 0)
    {
        return;
    }

    // Recursive call: move toward the base case
    print1toN(n - 1);

    // Printing after recursion ensures ascending order
    cout << n << endl;
}

int main()
{
    // Print numbers from 1 to 5
    print1toN(5);
    return 0;
}
