// You are given two strings word1 and word2.
// Merge the strings by adding letters in alternating order, starting with word1.
// If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.
/*
Example 1:
    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
    Explanation: The merged string will be merged as so:
    word1:  a   b   c
    word2:    p   q   r
    merged: a p b q c r

Example 2:
    Input: word1 = "ab", word2 = "pqrs"
    Output: "apbqrs"
    Explanation: Notice that as word2 is longer, "rs" is appended to the end.
    word1:  a   b
    word2:    p   q   r   s
    merged: a p b q   r   s

Example 3:
    Input: word1 = "abcd", word2 = "pq"
    Output: "apbqcd"
    Explanation: Notice that as word1 is longer, "cd" is appended to the end.
    word1:  a   b   c   d
    word2:    p   q
    merged: a p b q c   d
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    int itr1 = 0;
    int itr2 = 0;
    string merged;
    merged.reserve(word1.size() + word2.size());

    while (itr1 < word1.size() || itr2 < word2.size())
    {
        if (itr1 < word1.size())
        {
            merged.push_back(word1[itr1]);
            itr1++;
        }

        if (itr2 < word2.size())
        {
            merged.push_back(word2[itr2]);
            itr2++;
        }
    }

    return merged;
}
int main()
{
    string word1 = "abc", word2 = "pqr";
    string merged = mergeAlternately(word1, word2);

    cout << merged;
    return 0;
}