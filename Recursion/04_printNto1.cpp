#include <iostream>
using namespace std;

/*
    Function: printNto1
    Purpose : Prints numbers from n down to 1 using recursion.
    Params  : n → the starting number to print downward.
    Behavior:
        - Prints the current value of n first.
        - Recursively calls the function with n-1.
        - Stops when n reaches 0 (base case).
*/
void printNto1(int n)
{
    // Base case: stop recursion when n becomes 0
    if (n == 0)
    {
        return;
    }

    // Print first to maintain descending order
    cout << n << endl;

    // Recursive call to continue decreasing
    printNto1(n - 1);
}

int main()
{
    // Print numbers from 5 down to 1
    printNto1(5);
    return 0;
}
