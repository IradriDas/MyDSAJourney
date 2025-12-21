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
        return isPalindrome(str, start + 1);
    }
}

int main()
{
    string str = "MAD5DAM";

    cout << isPalindrome(str, 0);
    return 0;
}