#include <iostream>

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

BinaryTreeNode *insertNode(int data)
{
    BinaryTreeNode *new_node = new BinaryTreeNode();

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int main(int argc, char const *argv[])
{
    /* code */
    BinaryTreeNode *root = new BinaryTreeNode();

    root = insertNode(1);

    root->left = insertNode(2);
    root->right = insertNode(3);

    return 0;
}
