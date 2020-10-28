#include <queue>
#include <cstdio>

struct Binary_Tree_Node
{
    int data;
    Binary_Tree_Node *left;
    Binary_Tree_Node *right;
};

void inorder(Binary_Tree_Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    inorder(node->left);
    printf("data is : %d\n", node->data);
    inorder(node->right);
}

void preorder(Binary_Tree_Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    printf("data is : %d\n", node->data);

    preorder(node->left);
    preorder(node->right);
}

void postorder(Binary_Tree_Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("data is : %d\n", node->data);
}

Binary_Tree_Node *createNode(int data)
{
    Binary_Tree_Node *new_node = new Binary_Tree_Node();

    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    return new_node;
}

Binary_Tree_Node *insertNode(Binary_Tree_Node *root, int data)
{
    if (root == nullptr)
    {
        root = createNode(data);
        return root;
    }

    std::queue<Binary_Tree_Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {
        Binary_Tree_Node *front_node = queue.front();
        queue.pop();

        if (front_node->left != nullptr)
        {
            queue.push(front_node->left);
        }
        else
        {
            front_node->left = createNode(data);
            return root;
        }

        if (front_node->right != nullptr)
        {
            queue.push(front_node->right);
        }
        else
        {
            front_node->right = createNode(data);
            return root;
        }
    }
}

void deletDeepest(Binary_Tree_Node *root, Binary_Tree_Node *deepest_node)
{
    std::queue<Binary_Tree_Node *> queue;
    queue.push(root);
    Binary_Tree_Node *current_node = nullptr;
    while (!queue.empty())
    {
        current_node = queue.front();
        queue.pop();

        if (current_node == deepest_node)
        {
            current_node = nullptr;
            delete deepest_node;
            return;
        }

        if (current_node->left != nullptr)
        {
            if (current_node == deepest_node)
            {
                current_node = nullptr;
                delete deepest_node;
                return;
            }
            else
            {
                queue.push(current_node->left);
            }
        }

        if (current_node->right != nullptr)
        {
            if (current_node == deepest_node)
            {
                current_node = nullptr;
                delete deepest_node;
                return;
            }
            else
            {
                queue.push(current_node->right);
            }
        }
    }
}

Binary_Tree_Node *deletion(Binary_Tree_Node *root, int key)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        if (root->data == key)
        {
            return nullptr;
        }
        else
        {
            return root;
        }
    }

    std::queue<Binary_Tree_Node *> queue;
    queue.push(root);

    Binary_Tree_Node *key_node = nullptr;
    Binary_Tree_Node *current_node = nullptr;

    while (!queue.empty())
    {
        current_node = queue.front();
        queue.pop();

        if (current_node->data == key)
        {
            key_node = current_node;
        }

        if (current_node->left != nullptr)
        {
            queue.push(current_node->left);
        }

        if (current_node->right != nullptr)
        {
            queue.push(current_node->right);
        }
    }

    if (key_node != nullptr)
    {
        int last_node_data = current_node->data;
        deletDeepest(root, current_node);
        key_node->data = last_node_data;
    }
    return root;
}

std::vector<std::vector<int> > levelOrder(Binary_Tree_Node* root) {
        std::vector<std::vector<int> > ret;
        if(root == nullptr)
        {
            return ret;
        }
        std::queue<Binary_Tree_Node*> queue;
        queue.push(root);
        
        while(!queue.empty())
        {
            int nodeCount = queue.size();
            std::vector<int> temp;
            while(nodeCount > 0)
            {
                Binary_Tree_Node* node = queue.front();
                queue.pop();
                if(node->left != nullptr)
                {
                    queue.push(node->left);
                }
                if(node->right != nullptr)
                {
                    queue.push(node->right);
                }
                nodeCount--;
                temp.push_back(node->data);
            }
            ret.push_back(temp);
            temp.clear();
        }
        return ret;
    }

void printLevelOrder(Binary_Tree_Node* root) 
{
    std::queue<Binary_Tree_Node *> queue;
    queue.push(root);
    Binary_Tree_Node * current_node = nullptr;
    while(!queue.empty())
    {
        current_node = queue.front();
        printf("printLevelOrder data is : %d",current_node->data);
        queue.pop();
        if(current_node->left != nullptr)
        {
            queue.push(current_node->left);
        }

        if (current_node->right != nullptr)
        {
            queue.push(current_node->right);
        }
        printf("-------------\n");
    } 
}


int main()
{
    Binary_Tree_Node *root = nullptr;
    // Binary_Tree_Node *root = createNode(1);
    // root->left = createNode(2);
    // root->left->left = createNode(4);
    // root->right = createNode(3);
    // root->left->right = createNode(5);
    // root->right->left = createNode(6);

    // inorder(root);
    // printf("------------------------\n");
    // preorder(root);
    // printf("------------------------\n");
    // postorder(root);
    // printf("------------------------\n");
    // deletion(root, 7);
    // inorder(root);
    // printLevelOrder(root);
    std::vector<std::vector<int> >  result = levelOrder(root);
    for(int i = 0; i < result.size(); i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            printf(" %d",result[i][j]);
        }
        printf(" \n");
    }
    return 0;
}