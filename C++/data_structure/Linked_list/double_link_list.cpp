#include <cstdio>
#include <iostream>

struct DoubleLinkListNode
{
    int data;
    struct DoubleLinkListNode *next; // Pointer to next node in DLL
    struct DoubleLinkListNode *prev; // Pointer to previous node in DLL
};

void printList(DoubleLinkListNode *node)
{
    while (node != NULL)
    {
        std::cout << " " << node->data << std::endl;
        node = node->next;
    }
}

void push_front(DoubleLinkListNode **head, int value)
{
    DoubleLinkListNode *new_node = new DoubleLinkListNode();
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = *head;
    *head = new_node;
}

void insert(DoubleLinkListNode *pred_node, int value)
{

    DoubleLinkListNode *new_node = new DoubleLinkListNode();
    new_node->data = value;
    new_node->next = pred_node->next;
    pred_node->next->prev = new_node;

    new_node->prev = pred_node;
    pred_node->next = new_node;

}

int main(int argc, char const *argv[])
{
    /* code */
    DoubleLinkListNode *head = NULL;

    push_front(&head, 34);
    push_front(&head, 44);
    insert(head, 54);
    insert(head->next, 64);
    insert(head->next->next, 74);

    printList(head);
    return 0;
}
