#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack
{
    stack<long long> st;
    long long minVal;

public:
    MinStack()
    {
        minVal = LLONG_MAX;
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            minVal = val;
        }
        else
        {
            if (val < minVal)
            {
                // encode and update min
                st.push(2LL * val - minVal);
                minVal = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return;

        long long topVal = st.top();
        st.pop();

        // encoded value → restore old minimum
        if (topVal < minVal)
        {
            minVal = 2LL * minVal - topVal;
        }
    }

    int top()
    {
        long long topVal = st.top();

        if (topVal < minVal)
        {
            // encoded → real top is minVal
            return minVal;
        }
        return topVal;
    }

    int getMin()
    {
        return minVal;
    }
};

int main()
{

    return 0;
}