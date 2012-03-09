// 8.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void swap(int &a, int &b)
{ 
	int tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(int* a, int count)
{
	bool tmp = true;
	while (tmp)
	{
		tmp = false;
		for (int i = 0; i < count - 1; i++)
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				tmp = true;
			}
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input size of array: ");
	int count = 0;
	scanf("%d", &count);

	int *a = new int[count];
	printf("Enter elements:\n");
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &a[i]);
	};
	printf("a[] = ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", a[i]);
	};

	bubbleSort(a, count);

	printf("\n");

	printf("Sort:\n");

	printf("a[] = ");
	for (int i = 0; i < count; i++)
	{
		printf("%d ", a[i]);
	};

	return 0;
}

