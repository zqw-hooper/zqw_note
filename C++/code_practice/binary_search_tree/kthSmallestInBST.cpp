// A simple inorder traversal based C++ program
// to find k-th smallest element in a BST.
#include <iostream>
using namespace std;

// A BST node
struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Recursive function to insert an key into BST
Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

// Function to find k'th largest element in BST
// Here count denotes the number of nodes processed so far
void inorder(Node *root, int &k, int &count, int &result)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, k, count, result);
    count++;
    if (count == k)
    {
        result = root->data;
        return;
    }
    inorder(root->right, k, count, result);
}

// Function to find k'th largest element in BST
void printKthSmallest(Node *root, int k)
{
    // maintain index to count number of nodes processed so far
    int count = 0;
    int result = 0;
    inorder(root, k, count, result);
    cout << "K-th Smallest Element is " << result << endl;
}

// main function
int main()
{
    Node *root = NULL;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    for (int x : keys)
        root = insert(root, x);

    int k = 3;
    printKthSmallest(root, k);
    return 0;
}