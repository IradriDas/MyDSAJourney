#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextptr;

    Node(int value)
    {
        data = value;
        nextptr = nullptr;
    }

    Node(int value, Node *ptr)
    {
        data = value;
        nextptr = ptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    LinkedList(int val)
    {
        head->data = val;
        head->nextptr = nullptr;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *temp = head;

        while (temp != nullptr)
        {
            Node *next = temp->nextptr;
            temp->nextptr = prev;
            prev = temp;
            temp = next;
        }

        head = prev;
    }

    Node *nthFromLast(int n)
    {
        // nth node from last means (length() - n + 1)th node from the front
        Node *itr = head;
        int reqiredIndex = length() - n + 1;
        int count = 1;

        while (itr != nullptr && count != reqiredIndex)
        {
            itr = itr->nextptr;
            count++;
        }

        return itr;
    }

    Node *middle()
    {
        Node *fast = head;
        Node *slow = head;

        while (fast != nullptr && fast->nextptr != nullptr)
        {
            slow = slow->nextptr;
            fast = fast->nextptr->nextptr;
        }

        return slow;
    }

    int length()
    {
        int count = 0;

        Node *itr = head;
        while (itr != nullptr)
        {
            count++;
            itr = itr->nextptr;
        }
        return count;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
        }

        Node *itr = head;
        while (itr != nullptr)
        {
            cout << itr->data << " ";
            itr = itr->nextptr;
        }
        cout << endl;
    }

    void insertNodeAtFirst(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->nextptr = head;
            head = newNode;
        }
    }

    void insertNodeAtLast(int val)
    {
        if (head == nullptr)
        {
            insertNodeAtFirst(val);
        }
        else
        {
            Node *lastNode = head;
            while (lastNode->nextptr != nullptr)
            {
                lastNode = lastNode->nextptr;
            }

            Node *newNode = new Node(val);
            lastNode->nextptr = newNode;
        }
    }

    void insertNodeAtPlace(int val, int index)
    {
        if (index >= length())
        {
            cout << "Invalid Index";
            return;
        }

        if (index == 0)
        {
            insertNodeAtFirst(val);
        }
        else if (index == length() - 1)
        {
            insertNodeAtLast(val);
        }
        else
        {
            Node *newNode = new Node(val);
            Node *curr = head;
            int count = 1;
            while (curr != nullptr)
            {
                curr = curr->nextptr;
                if (count == index)
                {
                    break;
                }
                count++;
            }
            Node *temp = curr->nextptr;
            curr->nextptr = newNode;
            newNode->nextptr = temp;

            delete newNode;
            delete curr;
        }
    }

    void deleteNodeAtFirst()
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
        }
        else
        {
            head = head->nextptr;
        }
    }

    void deleteNodeAtLast()
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
        }
        else
        {
            Node *lastNode = head;
            while (lastNode->nextptr->nextptr != nullptr)
            {
                lastNode = lastNode->nextptr;
            }
            lastNode->nextptr = nullptr;
        }
    }

    void deleteNodeAtPlace(int index)
    {
        if (index >= length())
        {
            cout << "Invalid Index";
            return;
        }

        if (index == 0)
        {
            deleteNodeAtFirst();
        }
        else if (index == length() - 1)
        {
            deleteNodeAtLast();
        }
        else
        {
            // Node *newNode = new Node(val);
            Node *curr = head;
            int count = 1;
            while (curr != nullptr)
            {
                curr = curr->nextptr;
                if (count == index - 1)
                {
                    break;
                }
                count++;
            }
            curr->nextptr = curr->nextptr->nextptr;
        }
    }
};

LinkedList *addTwoNums(LinkedList l1, LinkedList l2)
{
    Node *itr1 = l1.head;
    Node *itr2 = l2.head;

    LinkedList *dummy = new LinkedList();
    int carry = 0;

    while (itr1 != nullptr || itr2 != nullptr)
    {
        int sum = carry;

        if (itr1 != nullptr)
        {
            sum = sum + itr1->data;
            itr1 = itr1->nextptr;
        }

        if (itr2 != nullptr)
        {
            sum = sum + itr2->data;
            itr2 = itr2->nextptr;
        }

        dummy->insertNodeAtLast(sum % 10);
        carry = sum / 10;
    }
    if (carry != 0)
    {
        dummy->insertNodeAtLast(carry);
    }

    return dummy;
}

int main()
{
    LinkedList *ll = new LinkedList();
    LinkedList *l2 = new LinkedList();
    // ll->insertNodeAtFirst(11);
    // ll->insertNodeAtFirst(22);
    // ll->insertNodeAtFirst(33);
    // ll->insertNodeAtFirst(44);
    // ll->insertNodeAtFirst(55);

    ll->insertNodeAtLast(10);
    ll->insertNodeAtLast(20);
    ll->insertNodeAtLast(30);
    ll->insertNodeAtLast(40);

    ll->display();

    // l3->reverse();
    // l3->display();

    return 0;
}