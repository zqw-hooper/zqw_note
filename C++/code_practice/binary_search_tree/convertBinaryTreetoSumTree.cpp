// C++ program to convert a tree into its sum tree
#include <bits/stdc++.h>
using namespace std;

/* A tree node structure */
class node
{
public:
    int data;
    node *left;
    node *right;
};

// Convert a given tree to a tree where
// every node contains sum of values of
// nodes in left and right subtrees in the original tree
void inorder(node *Node, int &sum)
{
    if (Node == nullptr)
    {
        return;
    }
    inorder(Node->right, sum);
    sum += Node->data;
    Node->data = sum;
    inorder(Node->left, sum);
}

// A utility function to print
// inorder traversal of a Binary Tree
void printInorder(node *Node)
{
    if (Node == NULL)
        return;
    printInorder(Node->left);
    cout << " " << Node->data;
    printInorder(Node->right);
}

/* Utility function to create a new Binary Tree node */
node *newNode(int data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

/* Driver code */
int main()
{
    node *root = NULL;
    int x;

    /* Constructing tree given in the above figure */
    root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);
    int sum = 0;
    inorder(root, sum);

    // Print inorder traversal of the converted
    // tree to test result of toSumTree()
    cout << "Inorder Traversal of the resultant tree is: \n";
    printInorder(root);
    return 0;
}