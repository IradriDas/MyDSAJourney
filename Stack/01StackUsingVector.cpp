// Stack implementation using vector
#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> stk;
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

    void push(int val)
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

    int peek()
    {
        if (!empty())
        {
            return stk[topIndex];
        }
        else
        {
            cout << "Empty Stack" << endl;
            return -1;
        }
    }
};

int main()
{
    vector<int> nums = {11, 22, 33, 44, 55};

    Stack s;

    for (auto &&i : nums)
    {
        s.push(i);
    }

    cout << s.peek() << " ";

    s.pop();
    cout << s.peek() << " ";

    s.pop();
    cout << s.peek() << " ";

    s.pop();
    cout << s.peek() << " ";

    s.pop();
    cout << s.peek() << " ";

    s.pop();
    cout << s.peek() << " ";

    return 0;
}