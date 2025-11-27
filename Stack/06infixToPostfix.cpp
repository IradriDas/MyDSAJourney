#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map<char, int> priority = {
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
    {'^', 3}};

string infixToPostfix(string &s)
{
    stack<char> stk;
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        { // in case of operand
            res = res + s[i];
        }
        else if (s[i] == '+' ||
                 s[i] == '-' ||
                 s[i] == '*' ||
                 s[i] == '/' ||
                 s[i] == '^')
        { // in case of operator
            if (stk.empty() || (priority[s[i]] >= priority[stk.top()]))
            {
                stk.push(s[i]);
            }
            else
            {
                while (
                    priority[s[i]] < priority[stk.top()] &&
                    stk.top() != '(' && stk.top() != ')' &&
                    !stk.empty())
                {
                    char op = stk.top();
                    stk.pop();
                    res = res + op;
                }
                stk.push(s[i]);
            }
        }
        else if (s[i] == '(' || s[i] == ')')
        {

            if (s[i] == '(')
            {
                stk.push(s[i]);
            }
            else
            {
                while (!stk.empty() && stk.top() != '(')
                {
                    char op = stk.top();
                    stk.pop();
                    res = res + op;
                }

                stk.pop();
            }
        }
    }

    while (!stk.empty())
    {
        res = res + stk.top();
        stk.pop();
    }

    return res;
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";

    string res = infixToPostfix(s);

    cout << res;

    return 0;
}