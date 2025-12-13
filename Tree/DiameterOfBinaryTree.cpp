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

// Computes the height of the binary tree while simultaneously updating the diameter.
// The diameter is defined as the maximum number of edges between any two nodes.
int height(Node *root, int &diameter)
{
    // Base case: an empty subtree has height 0
    if (root == nullptr)
    {
        return 0;
    }

    // Recursively compute the height of the left subtree
    int leftHeight = height(root->left, diameter);

    // Recursively compute the height of the right subtree
    int rightHeight = height(root->right, diameter);

    // Update the diameter using the longest path passing through the current node
    // (left subtree height + right subtree height)
    diameter = max(leftHeight + rightHeight, diameter);

    // Return the height of the current node
    // Height = 1 (current node) + max(left subtree height, right subtree height)
    return max(leftHeight, rightHeight) + 1;
}

// Calculates the diameter of a binary tree.
// The diameter represents the maximum number of edges between any two nodes in the tree.
int diameterOfBinaryTree(Node *root)
{

    // Stores the maximum diameter found during recursive traversal
    int width = 0;

    // Compute heights and update diameter through recursive calls
    height(root, width);

    // Return the final diameter
    return width;
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    int diameter = diameterOfBinaryTree(root);
    cout << "Diameter of the tree: " << diameter << endl;
    return 0;
}
