#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isValidParenthesis(string str)
{
    stack<char> s;

    for (auto &&p : str)
    {
        if (p == '[' || p == '{' || p == '(')
        {
            /* code */
            s.push(p);
        }
        else if (p == ']' || p == '}' || p == ')')
        {
            if (s.empty())
            {
                return false;
            }

            if (s.top() == '[' && p == ']')
            {
                s.pop();
            }
            else if (s.top() == '{' && p == '}')
            {
                s.pop();
            }
            else if (s.top() == '(' && p == ')')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    string parenthesis = "(){[]}";

    if (isValidParenthesis(parenthesis))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}