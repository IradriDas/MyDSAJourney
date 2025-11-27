
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Stack
{
private:
    vector<char> stk;
    int topIndex = -1;

public:
    bool empty()
    {
        if (topIndex == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push(char val)
    {
        stk.push_back(val);
        topIndex++;
    }

    void pop()
    {
        if (!empty())
        {
            stk.pop_back();
            topIndex--;
        }
        else
        {
            cout << "Empty Stack" << endl;
        }
    }

    char peek()
    {
        if (!empty())
        {
            return stk[topIndex];
        }
        else
        {
            // cout << "Empty Stack" << endl;
            return ' ';
        }
    }
};

bool isValidParenthesis(string str)
{
    Stack *s = new Stack();

    for (auto &&p : str)
    {
        if (p == '[' || p == '{' || p == '(')
        {
            /* code */
            s->push(p);
        }
        else if (p == ']' || p == '}' || p == ')')
        {
            if (s->empty())
            {
                return false;
            }

            if (s->peek() == '[' && p == ']')
            {
                s->pop();
            }
            else if (s->peek() == '{' && p == '}')
            {
                s->pop();
            }
            else if (s->peek() == '(' && p == ')')
            {
                s->pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s->empty())
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
    string parenthesis = "[]()}";

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