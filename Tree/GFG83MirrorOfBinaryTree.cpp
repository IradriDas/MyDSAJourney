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

// Converts a binary tree into its mirror image.
// For every node, the left and right child pointers are swapped recursively.
void mirror(Node *root)
{
    // Base case: if the current node is null, there is nothing to mirror
    if (root == nullptr)
    {
        return;
    }

    // Swap the left and right children of the current node
    swap(root->left, root->right);

    // Recursively mirror the left subtree (originally the right subtree)
    mirror(root->left);

    // Recursively mirror the right subtree (originally the left subtree)
    mirror(root->right);
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    return 0;
}
