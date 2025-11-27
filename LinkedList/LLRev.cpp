#include <iostream>
#include <vector>
#include <chrono> // Required for std::chrono
using namespace std;
using namespace std::chrono;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};

Node *insertAtFront(Node *head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        /* code */
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

Node *insertAtLast(Node *head, int val)
{
    Node *newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

Node *insertAtMiddle(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        return newNode;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *temp = slow->next;
    slow->next = newNode;
    newNode->next = temp;

    return head;
}

Node *insertAtPosition(Node *head, int position, int value)
{
    Node *newNode = new Node(value);

    if (head == nullptr)
    {
        return newNode;
    }

    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    int count = 0;

    while (temp != nullptr)
    {
        count++;

        if (count == position)
        {
            break;
        }
        prev = temp;

        temp = temp->next;
    }
    prev->next = newNode;
    newNode->next = temp;

    return head;
}

void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty List" << endl;
    }

    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }

    return head;
}

Node *deleteHead(Node *head)
{

    if (head == nullptr)
    {
        cout << "Empty List" << endl;
        return head;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node *deleteTail(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        cout << "Empty List" << endl;
        return nullptr;
    }

    Node *temp = head;

    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

Node *deleteAtPosition(Node *head, int position)
{
    if (head == nullptr)
    {
        return head;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    int count = 0;

    while (temp != nullptr)
    {
        count++;

        if (count == position)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node *deleteValue(Node *head, int value)
{
    if (head == nullptr)
    {
        return head;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;
    // int count = 0;

    while (temp != nullptr)
    {
        // count++;

        if (temp->data == value)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int length(Node *head)
{
    int count = 0;
    Node *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

bool hasLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true; // loop detected
    }

    return false; // no loop
}
Node *mergeSorted(Node *h1, Node *h2)
{
    Node *itr1 = h1;
    Node *itr2 = h2;
    Node *mergedListHead = nullptr;

    // head for the mergedListHead
    if (itr1->data < itr2->data)
    {
        mergedListHead = h1;
        itr1 = itr1->next;
    }
    else
    {
        mergedListHead = h2;
        itr2 = itr2->next;
    }

    Node *mergedList = mergedListHead;

    while (itr1 && itr2)
    {
        if (itr1->data <= itr2->data)
        {
            mergedList = insertAtLast(mergedList, itr1->data);
            itr1 = itr1->next;
        }
        else
        {
            /* code */
            mergedList = insertAtLast(mergedList, itr2->data);
            itr2 = itr2->next;
        }
    }
    if (itr1)
    {
        mergedList->next = itr1;
    }
    if (itr2)
    {
        mergedList->next = itr2;
    }
}

int main()
{

    auto start_time = high_resolution_clock::now(); // Record the starting time point

    // Node *head = new Node(11);
    // Node *head = new Node(5);
    // display(head);

    // head = insertAtLast(head, 12);
    // head = insertAtLast(head, 12);
    // head = insertAtLast(head, 14);
    // head = insertAtFront(head, 20);
    // head = insertAtFront(head, 30);

    // display(head);
    // cout << "Length: " << length(head) << endl;

    vector<int> arr = {10, 11, 22, 33, 44};
    Node *head = convertArr2LL(arr);

    head = insertAtPosition(head, 2, 19);
    display(head);

    auto end_time = high_resolution_clock::now();                              // Record the ending time point
    auto duration = duration_cast<microseconds>(end_time - start_time);        // Calculate the duration
    cout << "Execution time: " << duration.count() << " microseconds" << endl; // Print the execution time
    return 0;
}
