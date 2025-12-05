#include <iostream>
#include <vector>
#include <queue>

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
    Function: levelOrderTraversal
    Purpose : Returns the level-order (breadth-first) traversal of a binary tree
              as a vector of vectors, where each inner vector contains the nodes
              of one level.

    Params  :
        root → pointer to the root of the binary tree

    Behavior:
        - Uses a queue and a sentinel nullptr to mark level boundaries.
        - Maintains a temporary 'level' vector to collect values for
          each depth of the tree.
        - When nullptr is encountered:
              → push completed 'level' into bfs
              → clear 'level'
              → push another nullptr if more nodes remain

    Output Format:
        For a tree like:
                1
               / \
              2   3
                 / \
                4   5

        The function returns:
            {
                {1},
                {2, 3},
                {4, 5}
            }

    Time Complexity:
        O(n) — every node is processed once.

    Space Complexity:
        O(n) — queue + result storage.

    Side Effects:
        - Does not modify the tree.
        - Uses nullptr as a level delimiter (standard BFS trick).
*/
vector<vector<int>> levelOrderTraversal(Node *root)
{
    vector<vector<int>> bfs;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    vector<int> level;

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            bfs.push_back(level);
            level.clear();

            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            level.push_back(temp->val);

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

    return bfs;
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);

    cout << "Level-Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}