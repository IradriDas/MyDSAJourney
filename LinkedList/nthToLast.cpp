#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextptr;

    Node()
    {
        nextptr = nullptr;
    }

    Node(int val)
    {
        data = val;
        nextptr = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    LinkedList(int val)
    {
        Node *newNode = new Node(val);
        head = newNode;
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

    void printReverse(Node *node)
    {
        if (node == nullptr)
            return;

        printReverse(node->nextptr); // go deeper
        cout << node->data << " ";   // print while returning
    }

    void displayReverse()
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }
        printReverse(head);
        cout << endl;
    }

    Node *nthFromLast(int n)
    {
        // nth node from last means (length() - n + 1)th node from the front
        Node *fast = head;
        Node *slow = head;

        for (size_t i = 0; i < n; i++)
        {
            if (fast == nullptr)
            {
                return nullptr;
            }
            fast = fast->nextptr;
        }

        while (fast != nullptr)
        {
            fast = fast->nextptr;
            slow = slow->nextptr;
        }

        return slow;
    }
};

int main()
{
    LinkedList *ll = new LinkedList(1);

    ll->insertNodeAtLast(10);
    ll->insertNodeAtLast(20);
    ll->insertNodeAtLast(30);
    ll->insertNodeAtLast(40);

    ll->display();

    ll->printInReverse();

    return 0;
}

// int main()
// {

//     LinkedList *l1 = new LinkedList(11);
//     l1->insertNodeAtLast(22);
//     l1->insertNodeAtLast(33);
//     l1->insertNodeAtLast(44);
//     l1->insertNodeAtLast(55);

//     l1->display();

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *nextptr;

//     Node(int value)
//     {
//         data = value;
//         nextptr = nullptr;
//     }

//     Node(int value, Node *ptr)
//     {
//         data = value;
//         nextptr = ptr;
//     }
// };

// class LinkedList
// {
// public:
//     Node *head;

//     LinkedList()
//     {
//         head = nullptr;
//     }

//     LinkedList(int val)
//     {
//         head->data = val;
//         head->nextptr = nullptr;
//     }

//     void reverse()
//     {
//         Node *prev = nullptr;
//         Node *temp = head;

//         while (temp != nullptr)
//         {
//             Node *next = temp->nextptr;
//             temp->nextptr = prev;
//             prev = temp;
//             temp = next;
//         }

//         head = prev;
//     }

//     Node *nthFromLast(int n)
//     {
//         // nth node from last means (length() - n + 1)th node from the front
//         Node *fast = head;
//         Node *slow = head;

//         for (size_t i = 0; i < n; i++)
//         {
//             if (fast == nullptr)
//             {
//                 return nullptr;
//             }
//             fast = fast->nextptr;
//         }

//         while (fast != nullptr)
//         {
//             fast = fast->nextptr;
//             slow = slow->nextptr;
//         }
//     }

//     Node *middle()
//     {
//         Node *fast = head;
//         Node *slow = head;

//         while (fast != nullptr && fast->nextptr != nullptr)
//         {
//             slow = slow->nextptr;
//             fast = fast->nextptr->nextptr;
//         }

//         return slow;
//     }

//     int length()
//     {
//         int count = 0;

//         Node *itr = head;
//         while (itr != nullptr)
//         {
//             count++;
//             itr = itr->nextptr;
//         }
//         return count;
//     }

//     void display()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty List" << endl;
//         }

//         Node *itr = head;
//         while (itr != nullptr)
//         {
//             cout << itr->data << " ";
//             itr = itr->nextptr;
//         }
//         cout << endl;
//     }

//     void insertNodeAtFirst(int val)
//     {
//         Node *newNode = new Node(val);

//         if (head == nullptr)
//         {
//             head = newNode;
//         }
//         else
//         {
//             newNode->nextptr = head;
//             head = newNode;
//         }
//     }

//     void insertNodeAtLast(int val)
//     {
//         if (head == nullptr)
//         {
//             insertNodeAtFirst(val);
//         }
//         else
//         {
//             Node *lastNode = head;
//             while (lastNode->nextptr != nullptr)
//             {
//                 lastNode = lastNode->nextptr;
//             }

//             Node *newNode = new Node(val);
//             lastNode->nextptr = newNode;
//         }
//     }

//     void insertNodeAtPlace(int val, int index)
//     {
//         if (index >= length())
//         {
//             cout << "Invalid Index";
//             return;
//         }

//         if (index == 0)
//         {
//             insertNodeAtFirst(val);
//         }
//         else if (index == length() - 1)
//         {
//             insertNodeAtLast(val);
//         }
//         else
//         {
//             Node *newNode = new Node(val);
//             Node *curr = head;
//             int count = 1;
//             while (curr != nullptr)
//             {
//                 curr = curr->nextptr;
//                 if (count == index)
//                 {
//                     break;
//                 }
//                 count++;
//             }
//             Node *temp = curr->nextptr;
//             curr->nextptr = newNode;
//             newNode->nextptr = temp;

//             delete newNode;
//             delete curr;
//         }
//     }

//     void deleteNodeAtFirst()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty List" << endl;
//         }
//         else
//         {
//             head = head->nextptr;
//         }
//     }

//     void deleteNodeAtLast()
//     {
//         if (head == nullptr)
//         {
//             cout << "Empty List" << endl;
//         }
//         else
//         {
//             Node *lastNode = head;
//             while (lastNode->nextptr->nextptr != nullptr)
//             {
//                 lastNode = lastNode->nextptr;
//             }
//             lastNode->nextptr = nullptr;
//         }
//     }

//     void deleteNodeAtPlace(int index)
//     {
//         if (index >= length())
//         {
//             cout << "Invalid Index";
//             return;
//         }

//         if (index == 0)
//         {
//             deleteNodeAtFirst();
//         }
//         else if (index == length() - 1)
//         {
//             deleteNodeAtLast();
//         }
//         else
//         {
//             // Node *newNode = new Node(val);
//             Node *curr = head;
//             int count = 1;
//             while (curr != nullptr)
//             {
//                 curr = curr->nextptr;
//                 if (count == index - 1)
//                 {
//                     break;
//                 }
//                 count++;
//             }
//             curr->nextptr = curr->nextptr->nextptr;
//         }
//     }
// };

// int main()
// {
//     LinkedList *ll = new LinkedList();

//     ll->insertNodeAtLast(10);
//     ll->insertNodeAtLast(20);
//     ll->insertNodeAtLast(30);
//     ll->insertNodeAtLast(40);

//     ll->display();

//     LinkedList *l2 = new LinkedList();
//     l2->insertNodeAtLast(ll->nthFromLast(2)->data);
//     l2->display();

//     return 0;
// }