// w3.4.cpp: определяет точку входа для консольного приложения.
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
void insertEl (List1Element * head, int x)
{
	List1Element * tmp = head;
	while (tmp->next)
		tmp = tmp->next;


	List1Element * tmpx = createList();
	tmpx->value = x;

	tmp->next = tmpx;
}
void printList (List1Element * head)
{
	List1Element * tmp = head;
	while(tmp = tmp->next)
		printf("%d ", tmp->value);
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

void delList(List1Element *l)
{
	List1Element *tmp = l;
	while (tmp)
	{
		List1Element *t = tmp->next;
		delete tmp;
		tmp = t;
	}
}

List1Element *merge(List1Element *l, List1Element *r)
{
	if (l->value < r->value)
		if (!l->next)
		{
			l->next = r;
			return l;
		} else
		{
			l->next = merge(l->next, r);
			return l;
		}
	else
		if (!r->next)
		{
			r->next = l;
			return r;
		} else
		{
			r->next = merge(l, r->next);
			return r;
		}
}


List1Element *mergeSort(List1Element *l)
{
	if (!l || !l->next)
		return l;

	List1Element *u = l;
	List1Element *t = l->next->next;

	while (t && t->next)
	{
		u = u->next;
		t = t->next->next;
	}
	t = u->next;
	u->next = NULL;
	return merge(mergeSort(l), mergeSort(t));
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
	printf("Enter twenty numbers which you want to sort:\n");
	List1Element *head = createList();
	for (int i = 0; i < 20; i++)
	{
		scanf("%d", &a);
		insertEl(head, a);
	}
	head->next = mergeSort(head->next);
	printf("Sorted: ");
	printList(head);
	delList(head);

	return 0;
}

