/* C++ program to construct tree using 
inorder and preorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree TreeNode has data, pointer to left child 
and a pointer to right child */
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
};

/* Prototypes for utility functions */
// int search(char arr[], int strt, int end, char value);
TreeNode *newTreeNode(int data)
{
    TreeNode *node = new TreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode *buildTree(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd)
{
    if (preStart > preEnd)
    {
        return nullptr;
    }

    // root 节点对应的值就是前序遍历数组的第一个元素
    int rootVal = preorder[preStart];
    // rootVal 在中序遍历数组中的索引
    int index = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if (inorder[i] == rootVal)
        {
            index = i;
            break;
        }
    }

    int leftSize = index - inStart;

    // 先构造出当前根节点
    TreeNode *root = newTreeNode(rootVal);
    // 递归构造左右子树
    root->left = buildTree(preorder, preStart + 1, preStart + leftSize,
                           inorder, inStart, index - 1);

    root->right = buildTree(preorder, preStart + leftSize + 1, preEnd,
                            inorder, index + 1, inEnd);
    return root;
}

/* This funtcion is here just to test buildTree() */
void printInorder(TreeNode *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

/* Driver code */
int main()
{
    int in[] = {3, 9, 20, 15, 7};
    int pre[] = {9, 3, 15, 20, 7};
    int len = sizeof(in) / sizeof(in[0]);
    TreeNode *root = buildTree(in, 0, len - 1, pre, 0, len - 1);

    /* Let us test the built tree by 
    printing Insorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
}