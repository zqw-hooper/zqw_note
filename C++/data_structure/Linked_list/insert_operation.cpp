#include <iostream>

using namespace std;

#define GREEN "\033[32m" /* Green */
#define WHITE "\033[37m" /* White */
#define RED "\033[31m"   /* Red */

typedef struct SingleLinkListNode
{
  int value;
  SingleLinkListNode *next;
} SingleLinkListNode;

SingleLinkListNode *push_back(SingleLinkListNode *head, int value)
{
  SingleLinkListNode *new_node = new SingleLinkListNode();
  SingleLinkListNode *last_node = new SingleLinkListNode();
  last_node = head;

  while (last_node->next != NULL)
  {
    last_node = last_node->next;
  }

  new_node->value = value;
  new_node->next = NULL;
  last_node->next = new_node;
}

void printList(SingleLinkListNode *node)
{
  while (node != NULL)
  {
    std::cout << " " << node->value << std::endl;

    node = node->next;
  }
}

int main(int argc, char const *argv[])
{
  SingleLinkListNode *head = new SingleLinkListNode();
  head->next = NULL;
  head->value = 1;
  push_back(head, 3);
  push_back(head, 5);
  push_back(head, 99);

  printList(head);
  /* code */
  return 0;
}
