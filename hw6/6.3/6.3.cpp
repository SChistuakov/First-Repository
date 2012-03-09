// 6.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

void degrees(int degree, int *a)
{
	if (degree > 1)
	{
		if (a[degree] == 1)
			printf(" %d", degree);
		else
			if (a[degree] == -1)
				printf("  %d", degree);
			else
			{	
				if (a[degree] < 0)
				printf(" ");
				int count = 1;
				int x = a[degree];
				while ((x >= 10) || (x <= -10))
					{
						x = x / 10;
						count++;
					}

				for (int i = 0; i < count; i++)
					printf(" ");
				printf(" %d", degree);
			}
	}
	for (int i = (degree - 1); i > 1; i--)
	{
		if (a[i] != 0)
		{
			if (a[i] == 1)
				printf("  %d", i);
			else
				if (a[i] == -1)
					printf("  %d", i);
				else
				{
					int count = 1;
					int x = a[i];
					while ((x >= 10) || (x <= -10))
					{
						x = x / 10;
						count++;
					}

					for (int j = 0; j < count; j++)
						printf(" ");
					printf("  %d", i);
				}
		}
	}
	printf("\n");
}
void coefficients(int degree, int *a)
{
	if (a[degree] == 1)
		printf("x");
	else
		if (a[degree] == -1)
			printf("-x");
		else
			printf("%dx", a[degree]);
	for (int i = (degree - 1); i >= 1; i--)
	{
		if (a[i] > 0)
		{
			int count = 1;
			int x = i+1;
			while ((x >= 10) || (x <= -10))
			{
				x = x / 10;
				count++;
			}
			for (int j = 0; j < count; j++)
				printf(" ");
			if (a[i] != 1)
				printf("+%dx", a[i]);
			else 
				printf("+x");
		}
		else
			if (a[i] <0)
			{
				int count = 1;
				int x = i+1;
				while ((x >= 10) || (x <= -10))
				{
					x = x / 10;
					count++;
				}
				for (int j = 0; j < count; j++)
					printf(" ");
				if (a[i] != -1)
					printf("%dx", a[i]);
				else
					printf("-x");
			}
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	printf ("Input degreeree of polynom\n");
	int degree = 0;
	scanf("%d", &degree);
	int *a = new int[degree*4];
	for (int i = degree; i >= 0; i--)
	{
		printf("Coefficient (%d degree)\n", i);
		scanf("%d", &a[i]);
	}

	degrees(degree, a);

	coefficients(degree, a);

	if (a[0] > 0)
		printf(" +%d", a[0]);
	else if (a[0] < 0)
		printf(" %d", a[0]);


	delete a;

	return 0;
}

