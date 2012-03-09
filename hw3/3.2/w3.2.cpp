// w3.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct List1Element
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

List1Element * createListCount(int count)
{
	List1Element *head = createList();
	List1Element *tmp = head;
	for (int i = 0; i < count; i++)
	{
		tmp->next = createList();
		tmp = tmp->next;
		tmp->value = i + 1;
	}
	tmp->next = head->next;
	return head;
}


void insertEl (List1Element * head, int x)
{
	List1Element * tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == head->next)
			break;
	}
	List1Element * tmpx = new List1Element;
	tmpx->value = x;
	tmpx->next = head->next;
	tmp->next = tmpx;
}

void printList (List1Element * head)
{
	List1Element * tmp = head;
	while(tmp = tmp->next)
		printf("%d ", tmp->value);
}	
void del(List1Element *elem)
{
	int num = elem->next->value;
	List1Element *tmp = elem->next->next;
	
	delete elem->next;
	elem->value = num;
	elem->next = tmp;
}

void delList(List1Element *l)
{
	List1Element *tmp = l;
	while (tmp && tmp != tmp->next)
	{
		List1Element *t = tmp->next;
		delete tmp;
		tmp = t;
	}
	if (tmp)
		delete tmp;
}

int doCount(List1Element *head, int k, int count)
{
	int j = count;
	List1Element *tmp = head->next;
	while (j > 1)
	{
		for (int i = 0; i < k; i++)
			tmp = tmp->next;
		del(tmp);
		j--;
	}; 

	head->next = tmp;
	return tmp->value;
}
int runCount(List1Element *head, int i, int count)
{
	int k = 0;
	List1Element *h = head;
	while(true)
	{
		delList(h);
		h = NULL;
		h = createListCount(count);
		int j = doCount(h, k, count);

		if (j == i)
		{
			printf("k is %d\n", k);
			break;
		}

		k++;
	}

	return k;
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input count: \n");
	int count = 0;
	scanf("%d", &count);

	printf("Input i\n", count);
	int i = 0;
	scanf("%d", &i);

	List1Element *head = NULL;

	
	int k = runCount(head, i, count);

	delList(head);
	

	return 0;
}

