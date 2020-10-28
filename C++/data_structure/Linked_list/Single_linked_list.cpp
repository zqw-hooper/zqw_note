#include <cstdio>
#include <iostream>
#include <vector>
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

    while (current_node != nullptr)
    {
        next_node = current_node->next;
        current_node->next = pred_node;
        pred_node = current_node;
        current_node = next_node;
    }

    *head = pred_node;
}

// int getMiddle(Single_linked_list **head)
// {
//     Single_linked_list *current_node = *head;
//     int size = getLinkedListSize(head);
//     int middle = size / 2;
//     int count = 0;
//     while(current_node != nullptr)
//     {
//         if(middle == count)
//         {
//             return current_node->data;
//         }
//         count++;
//         current_node = current_node->next;
//     }
// }

int getMiddle(Single_linked_list **head)
{
    Single_linked_list *slow_node = *head;
    Single_linked_list *fast_node = *head;

    while (fast_node != nullptr && fast_node->next != nullptr)
    {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
    }
    return slow_node->data;
}

int count(Single_linked_list **head, int search_for)
{
    Single_linked_list *current_node = *head;
    int count = 0;
    while (current_node != nullptr)
    {
        if (current_node->data == search_for)
        {
            count++;
        }
        current_node = current_node->next;
    }

    return count;
}

bool detectLoop(Single_linked_list **head)
{
    Single_linked_list *slow_node = *head;
    Single_linked_list *fast_node = (*head)->next;

    while(slow_node != fast_node)
    {
        if (fast_node == nullptr || fast_node->next == nullptr)
        {
            return false;
        }
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
    }
    return true;
}

int countNodesinLoop(Single_linked_list **head)
{
    Single_linked_list *slow_node = *head;
    Single_linked_list *fast_node = (*head)->next;

    while(slow_node != nullptr)
    {
        slow_node = slow_node->next;
        fast_node = fast_node->next->next;
        if (slow_node == fast_node)
        {
            Single_linked_list *temp = slow_node;
            int count = 1;
            while(temp->next != slow_node)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
}

// void removeDuplicates(Single_linked_list **head)
// {
//     Single_linked_list *current_node = *head;
//     Single_linked_list *pred_node = nullptr;

//     while(current_node != nullptr)
//     {
//         Single_linked_list *temp_node = *head;
//         int search_data = current_node->data;
//         while(temp_node != nullptr)
//         {

//             temp_node = temp_node->next;
//         }
//         current_node = current_node->next;
//     }
// }

void moveToFront(Single_linked_list **head)
{
    Single_linked_list *current_node = *head;
    Single_linked_list *last_node = nullptr;

    while(current_node != nullptr)
    {
        if(current_node->next->next == nullptr)
        {
            last_node = current_node->next;
            current_node->next = nullptr;
            last_node->next = *head;
            *head = last_node;
            return;
        }

        current_node = current_node->next;
    }
}

Single_linked_list *removeSortedDuplicates(Single_linked_list **head)
{
    if (*head == nullptr || (*head)->next == nullptr)
    {
        return *head;
    }

    Single_linked_list *current_node = *head;

    Single_linked_list *first_ptr = *head;

    while (current_node != nullptr)
    {
        if (current_node->data == first_ptr->data)
        {
            current_node = current_node->next;
        }
        else
        {
            first_ptr->next = current_node;
            first_ptr = current_node;
        }
    }
    first_ptr->next = nullptr;
    return *head;
}

// void removeUnsortedDuplicates(Single_linked_list **head)
// {
//     Single_linked_list *current_node = *head;
//     // Single_linked_list *current_node1 = *head;
//     Single_linked_list *prev_node = *head;

//     while (current_node != nullptr && current_node->next != nullptr)
//     {
//         printLinkedList(*head);
//         printf("-------------------\n");

//         Single_linked_list *current_node1 = current_node->next;
//         while(current_node1 != nullptr)
//         {
//             if(current_node->data == current_node1->data)
//             {
//                 prev_node->next = current_node1->next;
//             }
//             prev_node = current_node1;
//             current_node1 = current_node1->next;

//         }
//         current_node = current_node->next;
//     }
// }

Single_linked_list *sortedIntersect(Single_linked_list **head_a, Single_linked_list **head_b)
{
    Single_linked_list *current_node_a = *head_a;
    Single_linked_list *new_node = nullptr;
    Single_linked_list *ret_node = nullptr;

    while(current_node_a != nullptr)
    {
        Single_linked_list *current_node_b = *head_b;

        while (current_node_b != nullptr)
        {
            if(current_node_b->data == current_node_a->data)
            {
                // printf(" current_node_a->data :%d\n",  current_node_a->data);
                if(new_node == nullptr)
                {
                    new_node = current_node_a;
                    ret_node = new_node;
                }
                else
                {
                    new_node->next = current_node_a;
                    new_node = new_node->next;
                }
            }
            current_node_b = current_node_b->next;
        }
        current_node_a = current_node_a->next;
    }
    new_node->next = nullptr;
    return ret_node;
}

void swapNodes(Single_linked_list **head, int first, int second)
{
    Single_linked_list *current_node = *head;
    Single_linked_list *first_prev = nullptr;
    Single_linked_list *second_prev = nullptr;
    Single_linked_list *first_next = nullptr;
    Single_linked_list *second_next = nullptr;
    // Single_linked_list *prev_node = nullptr;

    while(current_node != nullptr && current_node->next != nullptr)
    {
        if(current_node->next->data == first)
        {
            first_prev = current_node;
            first_next = current_node->next->next;
        }

        if (current_node->next->data == second)
        {
            second_prev = current_node;
            second_next = current_node->next->next;
        }



        // prev_node = current_node;
        current_node = current_node->next;

    }
}

bool isPalindrome(Single_linked_list **head)
{
    Single_linked_list *current_node1 = *head;
    std::vector<int> list1, list2;
    while(current_node1 != nullptr)
    {
        list1.push_back(current_node1->data);
        current_node1 = current_node1->next;
    }

    Single_linked_list *current_node2 = *head;
    Single_linked_list *prev_node = nullptr;
    Single_linked_list *next_node = nullptr;

    // reverse linked list
    while(current_node2 != nullptr)
    {
        next_node = current_node2->next;
        current_node2->next = prev_node;
        prev_node = current_node2;
        current_node2 = next_node;
    }

    while(prev_node != nullptr)
    {
        list2.push_back(prev_node->data);
        prev_node = prev_node->next;
    }

    int size = list1.size();

    for(int i = 0; i < size; i++)
    {
        if(list1[i] != list2[i])
        {
            return false;
        }
    }
    return true;
}

Single_linked_list * reverse(Single_linked_list **head, int k)
{
    Single_linked_list *current_node = *head;
    Single_linked_list *prev_node = nullptr;
    Single_linked_list *next_node = nullptr;
    int count = 0;

    while(current_node != nullptr && count < k)
    {
        next_node = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = next_node;
        count++;
    }
    if (current_node != nullptr)
    {
        (*head)->next = reverse(&current_node, k);
    }
    return prev_node;
}

int main()
{
    Single_linked_list *head1 = nullptr;
    Single_linked_list *head2 = nullptr;
    Single_linked_list *new_head = nullptr;

    // insertHead(&head, 3);
    // insertEnd(&head, 4);
    // insertAfter(&(head->next), 7);
    // insertAfter(&(head->next), 8);

    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);

    insertEnd(&head1, 4);
    insertEnd(&head1, 5);
    insertEnd(&head1, 6);
    insertEnd(&head1, 7);

    Single_linked_list * ret = reverse(&head1, 3);
    // printf("isPalindrome : %d\n",isPalindrome(&head1));
    // insertEnd(&head2, 2);
    // insertEnd(&head2, 3);
    // insertEnd(&head2, 4);
    // new_head = sortedIntersect(&head1, &head2);

    // insertEnd(&head, 9);
    // insertEnd(&head, 10);
    // insertEnd(&head, 11);
    // removeUnsortedDuplicates(&head);
    // moveToFront(&head);
    // head->next->next->next->next = head;
    // printf("detectLoop :%d\n", detectLoop(&head));
    // printf("countNodesinLoop :%d\n", countNodesinLoop(&head));

    // printLinkedList(new_head);
    // printf("--------------------\n");

    // reverseLinkedList(&head1);
    printLinkedList(ret);
    // printf("count :%d\n", count(&head, 3));
    // printf("getMiddle :%d\n", getMiddle(&head));

    // printf("getNodeByPosition :%d\n", getNodeByPosition(&head, 4));
    // getNodeByValue(&head, 40) ? std::cout << "Yes" << std::endl : std::cout << "No" << std::endl;
    // deleteNodeByValue(&head, 7);
    // deleteNodeByValue(&head, 8);
    // deleteNodeByValue(&head, 3);
}