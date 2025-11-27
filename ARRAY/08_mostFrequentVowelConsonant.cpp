// 3541.Find Most Frequent Vowel and Consonant
// You are given a string s consisting of lowercase English letters ('a' to 'z').
// Your task is to:    Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
//                     Find the consonant (all other letters excluding vowels) with the maximum frequency.
//                     Return the sum of the two frequencies.

//         Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them.
//         If there are no vowels or no consonants in the string, consider their frequency as 0.
// The frequency of a letter x is the number of times it occurs in the string.

// Example 1:
//     Input: s = "successes"
//     Output: 6

//     Explanation:
//     The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
//     The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
//     The output is 2 + 4 = 6.

// Example 2:
//     Input: s = "aeiaeia"
//     Output: 3

//     Explanation:
//     The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
//     There are no consonants in s.
//     Hence, maximum consonant frequency = 0.
//     The output is 3 + 0 = 3.

#include <iostream>
#include <string>
using namespace std;

/*
    Function: maxFreqSum
    Purpose : Returns the sum of:
                  - the highest frequency among vowels in the string
                  - the highest frequency among consonants in the string

              Example:
                  "aeiaeia" → vowels: a=4, e=3 → maxVowel = 4
                               consonants: none → maxConsonant = 0
                               result = 4 + 0 = 4

    Params  : s → lowercase alphabetic string.

    Behavior:
        - Builds a frequency array of size 26 for 'a' to 'z'.
        - Checks vowels separately: a, e, i, o, u
        - Finds:
              * maxVowel     → highest vowel frequency
              * maxConsonant → highest consonant frequency
        - Returns their sum.

    Time Complexity:
        O(n + 26) → effectively O(n)
        (n = string length)

    Space Complexity:
        O(1) — fixed 26-element array.

    Side Effects:
        - Assumes input string contains only lowercase letters.
        - If vowels do not appear, maxVowel remains 0.
        - If consonants do not appear, maxConsonant remains 0.
*/
int maxFreqSum(string s)
{
    int frequency[26] = {0};

    // Count frequency of each character
    for (char c : s)
    {
        frequency[c - 'a'] += 1;
    }

    int maxVowel = 0;
    int maxConsonant = 0;

    // Vowel indexes: a=0, e=4, i=8, o=14, u=20
    for (int i = 0; i < 26; i++)
    {
        // Check vowels
        if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
        {
            if (frequency[i] > maxVowel)
            {
                maxVowel = frequency[i];
            }
        }
        // Check consonants
        else
        {
            if (frequency[i] > maxConsonant)
            {
                maxConsonant = frequency[i];
            }
        }
    }

    return maxVowel + maxConsonant;
}

int main()
{
    string s1 = "aeiaeia";
    string s2 = "successes";

    cout << maxFreqSum(s1);
    cout << maxFreqSum(s2);

    return 0;
}
