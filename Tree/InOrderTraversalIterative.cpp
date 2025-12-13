#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    // Constructor: create a node with value `data` and null children
    Node(int data)
    {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

static int index = -1;

Node *createBinaryTree(Node *root, vector<int> preorder)
{
    index++;

    if (preorder[index] == -1)
    {
        return nullptr;
    }
    root = new Node(preorder[index]);

    root->left = createBinaryTree(root->left, preorder);
    root->right = createBinaryTree(root->right, preorder);

    return root;
}
/*
Algorithm

    1. Initialize an empty stack.
    2. Set current = root.

    3. While current is not NULL OR stack is not empty:
        1. Go as left as possible, pushing nodes onto stack.
        2. Pop the top node from stack.
        3. Visit the node.
        4. Move to its right child.
*/
vector<int> inorderTraversal(Node *root)
{
    vector<int> inorder;

    if (root == nullptr)
    {
        return inorder;
    }

    stack<Node *> st;
    Node *current = root;

    while (current != nullptr || !st.empty())
    {
        // Going as left as possible
        while (current != nullptr)
        {
            st.push(current);
            current = current->left;
        }
        
        // Traverse the node
        Node *temp = st.top();
        st.pop();
        inorder.push_back(temp->val);
        
        // Move to the right child
        current = temp->right;
    }

    return inorder;
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    vector<int> pre = inorderTraversal(root);
    cout << "In-Order Traversal: ";
    for (int i : pre)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}