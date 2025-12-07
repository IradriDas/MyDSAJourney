#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    Simple binary tree implementation with multiple traversal functions.

    Key points / input format:
      - The tree is constructed from a preorder representation where -1
        denotes a null child. Example:
            preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}
        represents the tree:
                  1
                 / \
                2   3
                   / \
                  4   5
      - createBinaryTree uses a static index to walk the vector. Because
        `index` is static, it retains its value between calls — reset it
        to -1 before constructing another tree in the same program run.

    Notes / Side effects:
      - The code allocates nodes with `new` but does not free them (no destructor).
        For production code, add a tree cleanup routine (delete nodes) to avoid leaks.
      - createBinaryTree assumes the preorder vector is well-formed relative
        to the -1 sentinel and that `index` will not exceed vector bounds.
*/

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

// Static index used by createBinaryTree to traverse the preorder vector.
// IMPORTANT: reset to -1 before building a new tree in the same run.
static int index = -1;

/*
    Function: createBinaryTree
    Purpose : Constructs a binary tree from a preorder traversal vector that
              uses -1 to represent null children.

    Params  :
        root     - pointer (unused on entry) that will be set to the new node
        preorder - vector<int> containing preorder values and -1 sentinels

    Returns : pointer to the newly-created subtree root or nullptr for -1.

    Behavior:
        - Increments the static `index` to read the next value from `preorder`.
        - If the current value is -1, returns nullptr (leaf).
        - Otherwise allocates a new Node and recursively builds left and right subtrees.

    Time Complexity: O(n) where n is preorder.size() — visits each entry once.
    Space Complexity: O(h) recursion depth (h = tree height).
    Side Effects:
        - Uses and advances the static `index`. Must be reset (-1) to reuse.
        - Allocates memory with new (caller must eventually delete nodes).
*/
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
    Function: preOrderTraversal
    Purpose : Prints the tree in preorder (root, left, right).

    Params  : root - pointer to subtree root
    Time Complexity: O(n)
    Space Complexity: O(h) recursion stack
    Side Effects: prints node values to stdout separated by spaces
*/
void preOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

/*
    Function: inOrderTraversal
    Purpose : Prints the tree in inorder (left, root, right).

    Params  : root - pointer to subtree root
    Time Complexity: O(n)
    Space Complexity: O(h)
    Side Effects: prints node values to stdout separated by spaces
*/
void inOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

/*
    Function: postOrderTraversal
    Purpose : Prints the tree in postorder (left, right, root).

    Params  : root - pointer to subtree root
    Time Complexity: O(n)
    Space Complexity: O(h)
    Side Effects: prints node values to stdout separated by spaces
*/
void postOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->val << " ";
}

/*
    Function: levelOrderTraversal
    Purpose : Prints the tree level-by-level (breadth-first). Each level
              is printed on its own line.

    Params  : root - pointer to subtree root

    Approach:
      - Uses a queue<Node*> and pushes nullptr as a level delimiter.
      - When nullptr is encountered, a newline is printed. If queue is not empty,
        another nullptr is pushed to mark the next level's end.

    Time Complexity: O(n)
    Space Complexity: O(w) where w is the maximum width of the tree
    Side Effects: prints node values to stdout; expects root != nullptr (but handles it)
*/
void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->val << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Level-Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    // NOTE: nodes are allocated with `new` above. 
    // To avoid memory leaks, add a tree destructor or 
    // traversal that deletes nodes when done.

    return 0;
}
