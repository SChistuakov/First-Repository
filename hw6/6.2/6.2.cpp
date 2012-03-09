// 6.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct Tree
{
	char value;
	Tree *right;
	Tree *left;
};

Tree *create(char x)
{
	Tree *tmp = new Tree;
	tmp->value = x;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void addEl(Tree *&tr, char string[], int &count)
{
	if ((string[count] == '(') || (string[count] == ')'))
	{
		addEl(tr, string, ++count);
	}
	else
	{
		if(string[count] != '\0')
		{
			if((string[count] == '+') || (string[count] == '-') || (string[count] == '*') || (string[count] == '/'))
			{
				tr = create(string[count++]);
				addEl(tr->left, string, count);
				addEl(tr->right, string, count);
			}
			else
			{
				tr = create(string[count++]);
			}
		}
		else
			return;
	}
}

void isHere(Tree *tr, char x)
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

void delEl(Tree *&tr, char x)
{
	if (!tr)
		printf("There is no element\n");
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
			Tree *tmp1 = tr->left;
			if (tmp1->right)
			{
				while (tmp1->right->right)
					tmp1 = tmp1->right;
				tr->value = tmp1->right->value;
				tmp = tmp1->right;
				tmp1->right = tmp1->right->left;
			}
			else
			{
				tr->value = tmp1->value;
				tmp = tmp1;
				tr->left=tr->left->left;
			}
	    }
		delete(tmp);
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

int conversion(Tree *tr)
{
	if (tr->value == '+')
	{
		return conversion(tr->left) + conversion(tr->right);
	}
	else if (tr->value == '-')
	{
		return conversion(tr->left) - conversion(tr->right);
	}
	else if (tr->value == '*')
	{
		return conversion(tr->left) * conversion(tr->right);
	}
	else if (tr->value == '/')
	{
		return conversion(tr->left) / conversion(tr->right);
	}
	else
	{
		return tr->value - '0';
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file;
	file = fopen(". . ..txt", "r");
	char string[30];
	fgets(string, 30, file);
	fclose(file);

	Tree *tree = NULL;		
	int x = 0;

	addEl(tree, string, x);

	printf("%d", conversion(tree));

	delTree(tree);

	return 0;
}

