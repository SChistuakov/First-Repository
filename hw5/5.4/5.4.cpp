// 5.4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


struct 
{
	int value;
	List1Element * next;
};
List1Element * createList()
{
	List1Element * tmp = new List1Element;
	tmp->value = 0;
	tmp->next =	NULL;
	return tmp;
}
void del(List1Element *&elem)
{
List1Element *tmp = elem->next;
if (tmp->next)
elem->next = tmp->next;
else
elem->next = NULL;
delete tmp;
}

bool isEmpty (List1Element * head)
{
	return head->next == NULL;
}

void delEl (List1Element * head, int x)
{
	List1Element *tmp = head;
	while ((tmp->next) && (tmp->next->value != x))
	tmp = tmp->next;

	if ((!tmp->next->next) && (tmp->next->value != x))
		printf ("Number not found\n");
	else
		del(tmp);
}

void insertEl (List1Element * head, int x)
{
	
	if (isEmpty(head))
	{
		List1Element * tmp = new List1Element;
		head->next = tmp;
		tmp->value = x;
		tmp->next = NULL;
	}
	else
	{
		List1Element * tmp = head;
		while ((tmp->next) && (x > tmp->next->value))
		{
			tmp = tmp->next;
		};
		List1Element * tmpx = new List1Element;
		tmpx->value = x;
		tmpx->next = tmp->next;
		tmp->next = tmpx;
	}
}

void printList (List1Element * head)
{
	List1Element * tmp = head;
	while(tmp = tmp->next)
		printf("%d ", tmp->value);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int answer = -1;
	int x = 0;
	List1Element * head = createList();
	printf("Commands:\n0 - exit\n1 - add value to sorted list\n2 - remove value from list\n3 - print list\n");	
	while (answer!=0)
	{
	printf("Command: ");
	scanf("%d", &answer);
	if (answer == 1) 
	{
		printf("Insert an Element ");
		scanf("%d", &x);
		insertEl(head, x);
	}
	else if (answer == 2)
	{
		printf("Insert an Element ");
		scanf("%d", &x);
		delEl(head, x);
	}
	else if (answer == 3)
	{
		printList(head);
		printf("\n");
	}
	}

	del(head);
	return 0;
}

