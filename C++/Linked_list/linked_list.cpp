#include <iostream>

using namespace std;

#define GREEN "\033[32m" /* Green */
#define WHITE "\033[37m" /* White */
#define RED "\033[31m"   /* Red */

typedef struct Linked_List_Node
{
	int value;
	Linked_List_Node *next;
} Linked_List_Node;

Linked_List_Node *insert_list(Linked_List_Node *insert_list, int value, Linked_List_Node *before, Linked_List_Node *after)
{
	before->next = insert_list;
	insert_list->next = after;
	insert_list->value = value;
}

Linked_List_Node *find_list(int value, Linked_List_Node *ptemp) //单链表查询
{
	while (ptemp != NULL)
	{
		if (ptemp->value == value)
		{
			cout << GREEN << "i found the goal in Linked List!" << WHITE << endl;
			return ptemp;
		}
		ptemp = ptemp->next;
	}
	cout << RED << "i can not found the goal in Linked List!" << WHITE << endl;
}

Linked_List_Node *reverse_list(Linked_List_Node *ptemp)
{
	Linked_List_Node *before = NULL;
	Linked_List_Node *current = ptemp;
	Linked_List_Node *after = ptemp->next;
	while (current != NULL)
	{
		after = current->next;
		current->next = before;
		before = current;
		current = after;
		// if (current != NULL)
		// {
		// 	after = current->next;
		// }
	}
	return before;
}

Linked_List_Node *delete_list(int value, Linked_List_Node *ptemp)
{
	Linked_List_Node *before = NULL;
	Linked_List_Node *current = ptemp;
	Linked_List_Node *after = ptemp->next;
	bool flag = false;
	while (current != NULL)
	{
		if (current->value == value)
		{
			flag = true;
			// if(before == NULL)
			// {
			// 	current->next = NULL;
			// 	cout << RED << "what you want to delete is the head Linked List !" << WHITE << endl;
			// }
			// else
			// {
			before->next = current->next;
			// }
			break;
		}
		before = current;
		current = current->next;
		after = after->next;
	}
	if (flag == true)
	{
		delete current;
		cout << GREEN << "i have delete the goal Linked list !" << WHITE << endl;
	}
	else
	{
		cout << RED << "not find what you want to delete Linked List !" << WHITE << endl;
	}
}

bool hascycle(Linked_List_Node *ptemp)
{
	Linked_List_Node *slow = ptemp;
	Linked_List_Node *fast = ptemp;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}

// Linked_List_Node *oddEvenList(Linked_List_Node *ptemp)
// {
// 	int i;
// 	Linked_List_Node *odd = new Linked_List_Node();
// 	Linked_List_Node *even = new Linked_List_Node();
// 	while (ptemp != NULL)
// 	{
// 		// Linked_List_Node* temp = ptemp;
// 		i++;
// 		// cout << "i is :" << i << endl;
// 		// cout << "list value is : " << ptemp->value << endl;
// 		if (i % 2 != 0)
// 		{
// 			odd->next = ptemp;
// 			odd = odd->next;
// 			odd->next= NULL;

// 			// cout << "odd i is :" << i << endl;
// 			// if (odd == NULL)
// 			// {
// 			// 	odd = ptemp;
// 			// 	cout << "1list odd value is : " << ptemp->value << endl;
// 			// }
// 			// else
// 			// {
// 			// 	cout << "2list odd value is : " << ptemp->value << endl;
// 			// 	odd->next = ptemp;
// 			// 	cout << "3list odd value is : " << odd->value << endl;
// 			// }
// 		}
// 		else
// 		{
// 			// cout << "even i is :" << i << endl;
// 			// if (even == NULL)
// 			// {
// 			// 	even = ptemp->next;
// 			// }
// 			// else
// 			// {
// 			// 	even->next = ptemp;
// 			// }
// 		}
// 		ptemp = ptemp->next;
// 	}
// 	while (odd != NULL)
// 	{
// 		cout << "odd Linked List is :" << odd->value << endl;
// 		odd = odd->next;
// 	}

// 	while (even != NULL)
// 	{
// 		cout << "even Linked List is :" << even->value << endl;
// 		even = even->next;
// 	}
// }

int main()
{
	Linked_List_Node *head = new Linked_List_Node();
	Linked_List_Node *second = new Linked_List_Node();
	Linked_List_Node *third = new Linked_List_Node();
	Linked_List_Node *forth = new Linked_List_Node();
	Linked_List_Node *fivth = new Linked_List_Node();
	Linked_List_Node *sixth = new Linked_List_Node();
	Linked_List_Node *seventh = new Linked_List_Node();
	Linked_List_Node *n = head;

	head->value = 1;
	head->next = second;
	second->value = 2;
	second->next = third;
	third->value = 3;
	third->next = NULL;

	insert_list(forth, 4, third, NULL); //单链表插入
	insert_list(fivth, 5, forth, NULL);
	insert_list(sixth, 6, fivth, NULL);
	// insert_list(seventh, 7, second, third);
	// find_list(44, head); //单链表查找
	// delete_list(3,head); //单链表删除
	// n = reverse_list(head);//单链表逆序

	// sixth->next = second; // 插入链表形成回环链表

	//// oddEvenList(head);
	while (n != NULL) //单链表遍历
	{
		cout << "Linked list value is : " << n->value << endl;
		n = n->next;
	}

	if (hascycle(head))
	{
		cout << GREEN << "The Linked List is a cycle list!" << WHITE << endl;
	}
	else
	{
		cout << RED << "The Lindked List is not a cycle list!" << WHITE << endl;
	}

	

	return 0;
}