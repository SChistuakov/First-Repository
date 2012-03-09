// 6.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct Tree
{
	int value;
	Tree *right;
	Tree *left;
};

Tree *create(int x)
{
	Tree *tmp = new Tree;
	tmp->value = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void addEl(Tree *&tr, int x)
{
	if (tr == NULL)
		tr = create(x);
	else
	{
		if(x < tr->value)
			addEl(tr->left, x);
		else if(x > tr->value)
			addEl(tr->right, x);
		else
			return;
	}
}

void delTree(Tree *tr)
{
	if (tr != NULL)
	{
		delTree(tr->left);
		delTree(tr->right);
		delete(tr);
	}
}

void up(Tree *tr)
{
	if(tr != NULL)
	{
		up(tr->left);
		printf("%d ", tr->value);
		up(tr->right);
	}
}

void down(Tree *tr)
{
	if(tr != NULL)
	{
		down(tr->right);
		printf("%d ", tr->value);
		down(tr->left);
	}
}

void isHere(Tree *tr, int x)
{
	if(tr == NULL)
	{
		printf("There is no element\n");
		return;
	}
	if (x == tr->value)
		printf("There is an element\n");
	else
		if (x < tr->value)
			isHere(tr->left, x);
		else
			isHere(tr->right, x);
}

void delEl(Tree *&tr, int x)
{
	if (!tr)
		printf("NO\n");
	else if (x < tr->value)
		delEl(tr->left, x);
	else if (x > tr->value)
		delEl(tr->right, x);
	else
	{
		Tree *tmp = tr;
		if (!tr->right)
			tr = tr->left;
		else if (!tr->left)
			tr = tr->right;
		else
		{
			Tree *v = tr->left;
			if (v->right)
			{
				while (v->right->right)
					v = v->right;
				tr->value = v->right->value;
				tmp = v->right;
				v->right = v->right->left;
			}
			else
			{
				tr->value = v->value;
				tmp = v;
				tr->left=tr->left->left;
			}
	    }
		delete(tmp);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Tree *tree = NULL;
	printf("0 - exit\n1 - add an element\n2 - remove an element\n3 - find an element\n4 - print elements in an increasing order\n5 - print elements in an decreasing order\n\n");
	int answer = -1;
	int x = 0;
	while (answer!=0)
	{
		printf("Command: ");
		scanf("%d", &answer);
		if (answer == 1) 
		{
			printf("Enter an element : ");
			scanf("%d", &x);
			addEl(tree, x);
		}
		else if (answer == 2)
		{
			printf("Enter an element : ");
			scanf("%d", &x);
			delEl(tree, x);
		}
		else if (answer == 3)
		{
			printf("Enter value : ");
			scanf("%d", &x);
			isHere(tree, x);
		}
		else if (answer == 4)
		{
			up(tree);
		}
		else if (answer == 5)
		{
			down(tree);
		}

	printf("\n");
	}
	return 0;

}

