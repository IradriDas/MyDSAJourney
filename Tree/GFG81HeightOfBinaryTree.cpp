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

int height(Node *root)
{
    if (root == nullptr)
    {
        return -1;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    cout << "Height: " << height(root);

    return 0;
}