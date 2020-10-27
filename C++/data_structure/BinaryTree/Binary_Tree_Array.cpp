#include <cstdio>

char tree[10];

void root(char data)
{
    if(tree[0] != '\0')
    {
        printf("Tree already had root\n");
    }
    else
    {
        tree[0] = data;
    }
}

void setLeft(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        printf("Can not set child at %d", 2 * parent + 1);
        printf(" , can not found parent node. \n");
    }
    else
    {
        tree[2 * parent + 1] = key;
    }
}

void setRight(char key, int parent)
{
    if (tree[parent] == '\0')
    {
        printf("Can not set child at %d", 2 * parent + 2);
        printf(" , can not found parent node. \n");
    }
    else
    {
        tree[2*parent + 2] = key;
    }
}

void printTree()
{
    for(int i = 0; i < 10; i++)
    {
        if(tree[i] != '\0')
        {
            printf(" %c", tree[i]);
        }
        else
        {
            printf(" -");
        }
    }
    printf(" \n");
}

int main()
{
    root('z');
    setRight('x',0);
    setLeft('c',0);
    setLeft('v',2);

    printTree();
    return 0;
}