#include <iostream>

using namespace std;

typedef struct Linked_List_Node
{
	int value;
	Linked_List_Node *next;
} Linked_List_Node;

int main()
{
	Linked_List_Node *n;
	Linked_List_Node *head = new Linked_List_Node();
	Linked_List_Node *second = new Linked_List_Node();
	Linked_List_Node *third = new Linked_List_Node();

	head->value = 1;
	head->next = second;
	second->value = 2;
	second->next = third;
	third->value = 5;
	third->next = NULL;

	n = head;
	
	Linked_List_Node* forth = new Linked_List_Node(); //单链表插入
	forth->value = 56;
	forth->next  = second;
	head->next = forth;

	forth->next = third; //单链表删除
	delete second;

	while (n != NULL) //单链表遍历
	{
		if (n->value == 50) //单链表查询
		{
			cout << "i found the goal!" << endl;
			n = n->next;
		}
		cout << "Inserted Linked list is : " << n->value << endl;
		n = n->next;
	}
	return 0;
}