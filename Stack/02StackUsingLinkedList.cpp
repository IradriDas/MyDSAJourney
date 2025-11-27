// Stack implementation using Linked List

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);

        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Empty" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete (temp);
        }
    }

    bool empty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int peek()
    {
        if (!empty())
        {
            return top->data;
        }
    }
};

int main()
{
    // vector<int> nums = {};
    Stack *s = new Stack();

    s->push(11);
    s->push(12);
    s->push(13);
    s->push(14);

    cout << s->peek() << endl;

    s->pop();
    cout << s->peek() << endl;

    s->pop();
    cout << s->peek() << endl;

    s->pop();
    cout << s->peek() << endl;

    s->pop();
    s->pop();

    return 0;
}