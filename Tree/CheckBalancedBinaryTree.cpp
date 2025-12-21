#include <iostream>
#include <vector>

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
    Function: height
    Purpose : Computes the height of the binary tree while simultaneously
              checking whether the tree is height-balanced.

    Params  : root - pointer to the root of the subtree

    Approach:
      - Uses post-order traversal.
      - Recursively computes heights of left and right subtrees.
      - If any subtree is unbalanced, returns -1 immediately.
      - If height difference at current node exceeds 1, returns -1.
      - Otherwise, returns height of the current subtree.

    Time Complexity : O(n), each node is visited once
    Space Complexity: O(h) where h is the height of the tree (recursion stack)
    Side Effects    : None
*/
int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    if (leftHeight == -1)
    {
        return -1;
    }

    int rightHeight = height(root->right);
    if (rightHeight == -1)
    {
        return -1;
    }

    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }

    return max(leftHeight, rightHeight) + 1;
}

/*
    Function: isBalanced
    Purpose : Determines whether the binary tree is height-balanced.

    Params  : root - pointer to the root of the tree

    Approach:
      - Calls the height function.
      - If height returns -1, the tree is unbalanced.
      - Otherwise, the tree is balanced.

    Time Complexity : O(n)
    Space Complexity: O(h) where h is the height of the tree
    Side Effects    : None
*/
bool isBalanced(Node *root)
{
    return height(root) != -1;
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    cout << isBalanced(root);

    return 0;
}
