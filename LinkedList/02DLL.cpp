#include <iostream>
// #include <iterator>
using namespace std;

class Node
{
public:
    int data;
    Node *nextptr;
    Node *prevptr;

    Node(int value)
    {
        data = value;
        nextptr = nullptr;
        prevptr = nullptr;
    }
};

int main()
{

    return 0;
}