#include <iostream>
#include <queue>
using namespace std;

struct Node  
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
}; 
  
/* Helper function that allocates a new node with  
the given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
    struct Node* node = new Node(); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
      
    return(node); 
} 

void inOrder(struct Node* node)  
{ 
    if (node == NULL)  
        return; 
      
    inOrder(node->left); 
    cout << node->data << " "; 
    inOrder(node->right); 
}  

#if 0 // recursive
void mirror(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    mirror(node->left);
    mirror(node->right);

    Node *temp = node->left;
    node->left = node->right;
    node->right = temp;
}
#elif 1 // iterator
void mirror(Node* node)
{
    if(node == nullptr)
    {
        return;
    }

    queue<Node*> q;
    q.push(node);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();

        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;

        if(node->left != nullptr)
        {
            q.push(node->left);
        }
        if(node->right != nullptr)
        {
            q.push(node->right);
        }
    }
} 
#endif

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5);  
      
    /* Print inorder traversal of the input tree */
    // cout << "Inorder traversal of the constructed"
    //      << " tree is" << endl; 
    // inOrder(root); 
      
    /* Convert tree to its mirror */
    mirror(root);  
    inOrder(root); 
    return 0;
}