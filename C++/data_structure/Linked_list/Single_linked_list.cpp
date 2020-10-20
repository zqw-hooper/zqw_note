#include <cstdio>
#include <iostream>
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

void insertEnd(Single_linked_list **node, int data)
{
    Single_linked_list *new_node = new Single_linked_list();
    new_node->data = data;
    new_node->next = nullptr;

    Single_linked_list *last_node = *node;

    if (*node == nullptr)
    {
        *node = new_node;
        return;
    }

    while (last_node->next != nullptr)
    {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void insertHead(Single_linked_list **node, int data)
{
    Single_linked_list *new_node = new Single_linked_list();
    new_node->data = data;
    new_node->next = *node;
    *node = new_node;
}

void insertAfter(Single_linked_list **pred_node, int data)
{
    if (*pred_node == nullptr)
    {
        printf("the given previous node cannot be NULL\n");
        return;
    }

    Single_linked_list *new_node = new Single_linked_list();
    new_node->data = data;
    new_node->next = (*pred_node)->next;
    (*pred_node)->next = new_node;
}

void deleteNodeByValue(Single_linked_list **head, int data)
{
    Single_linked_list *current_node = *head;
    Single_linked_list *pred_node = *head;

    if (current_node != nullptr && current_node->data == data)
    {
        *head = current_node->next;
        return;
    }

    while (current_node != nullptr && current_node->data != data)
    {
        pred_node = current_node;
        current_node = current_node->next;
    }
    pred_node->next = current_node->next;
}

int getLinkedListSize(Single_linked_list **head)
{
    int size = 0;
    Single_linked_list *current_node = *head;

    while (current_node != nullptr)
    {
        current_node = current_node->next;
        size++;
    }
    return size;
}

int getNodeByPosition(Single_linked_list **head, int position)
{
    int size = getLinkedListSize(head);
    int count = 0;
    Single_linked_list *current_node = *head;

    if (size == 0 || position > size || position < 0)
    {
        printf("some error \n");
        return -1;
    }

    while (current_node != nullptr && count != position)
    {
        current_node = current_node->next;
        count++;
    }
    return current_node->data;
}

bool getNodeByValue(Single_linked_list **head, int data)
{
    Single_linked_list *current_node = *head;

    while (current_node != nullptr)
    {
        if (current_node->data == data)
        {
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

void reverseLinkedList(Single_linked_list **head)
{
    Single_linked_list *current_node = *head;
    Single_linked_list *pred_node = nullptr;
    Single_linked_list *next_node = nullptr;

    while(current_node != nullptr)
    {
        next_node = current_node->next;
        current_node->next = pred_node;
        pred_node = current_node;   
        current_node = next_node;
    }

    *head = pred_node;
}

int main()
{
    Single_linked_list *head = nullptr;

    insertHead(&head, 3);
    insertEnd(&head, 4);
    // insertAfter(&(head->next), 7);

    insertEnd(&head, 5);
    insertEnd(&head, 6);
    // insertAfter(&(head->next), 8);
    printLinkedList(head);
    printf("--------------------\n");

    reverseLinkedList(&head);
    printLinkedList(head);

    // printf("getNodeByPosition :%d\n", getNodeByPosition(&head, 4));
    // getNodeByValue(&head, 40) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;
    // deleteNodeByValue(&head, 7);
    // deleteNodeByValue(&head, 8);
    // deleteNodeByValue(&head, 3);
}