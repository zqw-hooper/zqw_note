#include <cstdio>

struct ListNode
{
    int val;
    ListNode *next;
};

void printFunc(ListNode *node)
{
    while (node != nullptr)
    {
        printf(" %d\n", node->val);
        node = node->next;
    }
}

void reverse(ListNode **head)
{
    ListNode *current_node = *head;
    ListNode *pred_node = nullptr;
    ListNode *next_node = nullptr;

    while (current_node != nullptr)
    {
        next_node = current_node->next;
        current_node->next = pred_node;
        pred_node = current_node;
        current_node = next_node;
    }

    *head = pred_node;
}

void insert(ListNode **node, int val)
{
    ListNode *new_node = new ListNode();
    new_node->val = val;
    new_node->next = nullptr;

    ListNode *last_node = *node;

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
int a;

int main()
{
    ListNode *head = nullptr;

    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);

    printf("The linked list data are : \n");
    printFunc(head);
    reverse(&head);
    printf("The reversed linked list data are : \n");
    printFunc(head);

    return 0;
}