#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str, int start)
{
    int n = str.length();

    if (start >= n / 2)
    {
        return true;
    }

    if (str[start] != str[n - 1 - start])
    {
        return false;
    }
    else
    {
        
    }
}

int main()
{
    string str = "MADAM";

    return 0;
}