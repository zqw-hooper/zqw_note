#include <iostream>
#include <cstdio>

using namespace std;

#define GREEN "\033[32m" /* Green */
#define WHITE "\033[37m" /* White */
#define RED "\033[31m"   /* Red */

typedef struct SingleLinkListNode
{
  int value;
  SingleLinkListNode *next;
} SingleLinkListNode;

void printList(SingleLinkListNode *node)
{
  while (node != NULL)
  {
    std::cout << " " << node->value << std::endl;
    node = node->next;
  }
}

void delete_node(SingleLinkListNode **head, int value)
{
  SingleLinkListNode *pred_node = new SingleLinkListNode();
  SingleLinkListNode *current_node = new SingleLinkListNode();
  current_node = *head;

  if (current_node != NULL && current_node->value == value)
  {
    *head = current_node->next;
    delete (current_node);
    return;
  }

  while (current_node != NULL && current_node->value != value)
  {
    pred_node = current_node;
    current_node = current_node->next;
  }

  pred_node->next = current_node->next;
  delete (current_node);
}

void push_front(SingleLinkListNode **head, int value)
{
  SingleLinkListNode *new_node = new SingleLinkListNode();
  new_node->value = value;
  new_node->next = *head;
  *head = new_node;
}

void insert(SingleLinkListNode *pred_node, int value)
{
  SingleLinkListNode *new_node = new SingleLinkListNode();
  new_node->value = value;
  new_node->next = pred_node->next;
  pred_node->next = new_node;
}

void push_back(SingleLinkListNode **head, int value)
{
  SingleLinkListNode *new_node = new SingleLinkListNode();
  SingleLinkListNode *temp_node = *head;

  new_node->value = value;
  new_node->next = NULL;

  if (*head == NULL)
  {
    *head = new_node;
    return;
  }

  while (temp_node->next != NULL)
  {
    temp_node = temp_node->next;
  }
  temp_node->next = new_node;
}

int get_size(SingleLinkListNode *head)
{
  int count = 0;
  while (head != NULL)
  {
    count++;
    head = head->next;
  }
  return count;
}

bool find_element(SingleLinkListNode *head, int value)
{
  while (head != NULL)
  {
    if (head->value == value)
    {
      return true;
    }
    head = head->next;
  }
  return false;
}

void print_middle_node(SingleLinkListNode *head)
{
  SingleLinkListNode *fast_node = head;
  SingleLinkListNode *slow_node = head;
  while (fast_node->next != NULL)
  {
    slow_node = slow_node->next;
    fast_node = fast_node->next->next;
    // head = head->next;
  }
  printf("The middle element is: %d\n", slow_node->value);
}

// void push_back(SingleLinkListNode *head, int value)
// {
//   SingleLinkListNode *new_node = new SingleLinkListNode();

//   new_node->value = value;
//   new_node->next = NULL;

//   if (head == NULL)
//   {
//     head = new_node;
//     return;
//   }

//   while (head != NULL)
//   {
//     head = head->next;
//   }
//   head->next = new_node;
// }

int main(int argc, char const *argv[])
{
  SingleLinkListNode *head = NULL;

  push_back(&head, 1);
  insert(head, 2);
  insert(head->next, 3);

  push_front(&head, 4);
  push_front(&head, 5);
  printf("size of link list is: %d\n", get_size(head));
  // delete_node(&head, 4);
  // delete_node(&head, 1);
  // printf("size of link list is: %d\n", get_size(head));
  printList(head);
  printf("find element in link list result is: %d\n", find_element(head, 22));
  printf("find element in link list result is: %d\n", find_element(head, 2));
  print_middle_node(head);
  return 0;
}
