// WAP to count vowels and consonants in a string.
#include <iostream>
#include <string>
using namespace std;

pair<int, int> countVowelConsonant(string str, int index, int vowelCounter, int consonantCounter)
{
    if (index >= str.length())
    {
        return {vowelCounter, consonantCounter};
    }

    if (str[index] == 'a' ||
        str[index] == 'e' ||
        str[index] == 'i' ||
        str[index] == 'o' ||
        str[index] == 'u')
    {
        vowelCounter += 1;
    }
    else
    {
        consonantCounter += 1;
    }

    return countVowelConsonant(str, index + 1, vowelCounter, consonantCounter);
}
int main()
{

    string str = "iradri";

    pair<int, int> count = countVowelConsonant(str, 0, 0, 0);

    cout << count.first << " " << count.second << endl;

    return 0;
}