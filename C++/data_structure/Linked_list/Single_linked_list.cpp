#include <cstdio>

struct Single_linked_list
{
    int data;
    Single_linked_list *next;
};

void printLinkedList(Single_linked_list *node)
{
    while (node != nullptr)
    {
        printf("Linked List data is : %d\n", node->data);
        node = node->next;
    }
}

// void insertEnd(Single_linked_list **node, int data)
// {
//     Single_linked_list *new_node = new Single_linked_list();
//     new_node->data = data;
//     new_node->next = nullptr;

//     Single_linked_list * last_node = *node;

//     if(*node == nullptr)
//     {
//         *node = new_node;
//         return;
//     }

//     while(last_node->next != nullptr)
//     {
//         last_node = last_node->next;
//     }
    
//     last_node->next = new_node;
// }

void insertEnd(Single_linked_list *node, int data)
{
    Single_linked_list *new_node = new Single_linked_list();
    new_node->data = data;
    new_node->next = nullptr;

    // Single_linked_list * last_node = *node;

    // if(node == nullptr)
    // {
        // printf("null\n");
    // last_node->data = data;
    // last_node->next = nullptr;
        // printf("1 address in function is :\n");


    while()
    {
        
    }
    node->next = new_node;
    // printf("address in function is :\n");

    // printLinkedList(node);
    // return;
    // }

}

int main()
{
    Single_linked_list *head = nullptr;

    // insertEnd(&head, 4);
    // insertEnd(&head, 5);
    // insertEnd(&head, 6);
    insertEnd(head, 23);

    insertEnd(head, 33);

    insertEnd(head, 43);
    printLinkedList(head);
}