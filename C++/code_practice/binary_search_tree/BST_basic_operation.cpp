#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == nullptr)
    {
        return new TreeNode(val);
    }

    if (root->val > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

bool helper(TreeNode *root, long long lower, long long upper)
{
    if (root == nullptr)
    {
        return true;
    }
    if (root->val <= lower || root->val >= upper)
    {
        return false;
    }
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}

bool isValidBST(TreeNode *root)
{
    return helper(root, LONG_MIN, LONG_MAX);
}

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == nullptr || root->val == val)
    {
        return root;
    }

    if (val > root->val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return searchBST(root->left, val);
    }
}



/* Given a non-empty binary search tree, return the TreeNode
with minimum key value found in that tree. Note that the
entire tree does not need to be searched. */
struct TreeNode* minValueNode(struct TreeNode* TreeNode)
{
    struct TreeNode* current = TreeNode;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

/* Given a binary search tree and a key, this function
deletes the key and returns the new root */
struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted is 
    // smaller than the root's
    // key, then it lies in left subtree
    if (key < root->val)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then This is the TreeNode
    // to be deleted
    else {
        // TreeNode with only one child or no child
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            delete root;
            return temp;
        }
 
        // TreeNode with two children: Get the inorder successor
        // (smallest in the right subtree)
        struct TreeNode* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this TreeNode
        root->val = temp->val;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}