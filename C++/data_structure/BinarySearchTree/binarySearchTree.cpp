#include <iostream>
using namespace std;

class BST
{
public:
    int data;
    BST *left, *right;

    BST() = default;

    BST(int);
    BST *Insert(BST *, int);

    void Inorder(BST *);
    BST *search(BST *root, int key);
};

BST::BST(int value)
{
    data = value;
    left = right = nullptr;
}

BST *BST::Insert(BST *root, int value)
{
    if (root == nullptr)
    {
        return new BST(value);
    }

    if (value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    return root;
}

void BST::Inorder(BST *root)
{
    if (root == nullptr)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

BST *BST::search(BST *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}

int main()
{
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 30);
    b.Insert(root, 20);
    b.Insert(root, 40);
    b.Insert(root, 70);
    b.Insert(root, 60);
    b.Insert(root, 80);

    b.Inorder(root);

    cout << "search function test : " << b.search(root, 20)->data << "\n";
    return 0;
}