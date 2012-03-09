// 4.4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>

void hd(int *a, int count, int index)
{
	int max = index;
	while (true)
	{
		int one = index * 2 + 1;
		if (one < count && a[one] > a[max])
			max = one;
		one = one + 1;
		if (one < count && a[one] > a[max])
			max = one;

		if ( max == index)
			break;

		int help = a[max];
		a[max] = a[index];
		a[index] = help;

		index = max;
	}
}

void hs(int *a, const int count)
{
	for (int i = count / 2 - 1; i >= 0; i--)
		hd(a, count, i);

	int j = count;
	while (--j > 0)
	{
		int help = a[0];
		a[0] = a[j];
		a[j] = help;

		hd(a, j, 0);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char st[100];
	printf("Input: ");
    gets_s(st);
	int *a = new int[strlen(st)];
	for (int i = 0; i < strlen(st); i++)
	{
		a[i] = st[i] - '0';
	}
	hs(a, strlen(st));
	if (a[0] == 0) 
	{
	for (int i = 1; i<strlen(st);i++)
	{
		if (a[i] != 0)
		{
			a[0] = a[i];
			a[i] = 0;
			break;
		}
	}
	}
	for (int i = 0; i<strlen(st);i++)
	{
		printf("%d", a[i]);
	}
	return 0;
}

