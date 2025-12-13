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

vector<int> preorderTraversal(Node* root) {
    vector<int> preorder;
    if(root == nullptr){
        return preorder;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        preorder.push_back(temp->val);

        if(temp->right != nullptr){
            st.push(temp->right);
        }

        if(temp->left != nullptr){
            st.push(temp->left);
        }
    }

    return preorder; 
}

int main()
{
    // Example preorder vector using -1 as null markers
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = nullptr;
    root = createBinaryTree(root, preorder);
    
    vector<int> pre = preorderTraversal(root);
    cout << "Pre-Order Traversal: ";
    for (int i : pre) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}