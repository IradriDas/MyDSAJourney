#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include <algorithm>

int findMin(int a, string b)
{
    if (a > b.size())
    {
        return b.size();
    }
    else
    {
        return a;
    }
}

string longestCommonPrefix(vector<string> &strs)
{

    string ans = "";
    int Min = 200; // 6

    for (int i = 0; i < strs.size(); i++)
    {

        for (int j = 0; j < strs[i].size(); j++)
        {
            if (i == 0)
            {
                ans = strs[i];
                Min = strs[i].size();
                break;
            }
            else
            {

                if (Min <= j || ans[j] != strs[i][j])
                {
                    Min = j;
                    break;
                }
            }
        }

        Min = findMin(Min, strs[i]);
    }

    return strs[0].substr(0, Min);
}

// string longestCommonPrefix(vector<string> &strs)
// {
//     if (strs.empty())
//         return "";

//     string pre = strs[0];

//     for (int i = 1; i < strs.size(); i++)
//     {
//         while (strs[i].find(pre) != 0)
//         {
//             pre = pre.substr(0, pre.size() - 1);
//             if (pre.empty())
//                 return "";
//         }
//     }
//     return pre;
// }
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};

    cout << longestCommonPrefix(strs);

    return 0;
}