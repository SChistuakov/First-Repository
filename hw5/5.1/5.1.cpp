// 5.1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <string.h>
#include <limits.h>

void qsforindexmass(int a[], int b[], int low, int high) 
{
            int i = low;
            int j = high;
            int x = a[(low + (high-low)/2)];
            do {
              while (a[i] < x)
                ++i;
              while (x < a[j])
                --j;
              if ( i <= j ) {
               if( i < j ) { 
                 int t = a[i];
                 a[i] = a[j];
                 a[j] = t;

				 t = b[i];
                 b[i] = b[j];
                 b[j] = t;
               }
                ++i;
                --j;
               }
            } while (i <= j);
            if (low < j)
             qsforindexmass(a, b, low, j);
            if (i < high)
             qsforindexmass(a, b, i, high);
  }
 

void del(char slovo[], int index)
 { 
	int *mass = new int[index];
	int *indexmass = new int[index];
	int j = 0;
	for (int i = 0; i < index; i++)
		{
			mass[i] = (int)(slovo[i]);
			indexmass[i] = i;
		}
	qsforindexmass(mass, indexmass, 0, index - 1);

	for (int i = 0; i < index - 1; i++)
		{
			if (mass[i] == mass[i+1])
			{
				if (indexmass[i]>indexmass[i+1])
				{
					indexmass[i] = indexmass[i+1];
				}
				else
				{
					indexmass[i+1] = indexmass[i];
				}
			}
	}

	for (int i = index; i > 1; i--)
		{
			if (mass[i] == mass[i-1])
			{
				if (indexmass[i]>indexmass[i-1])
				{
					indexmass[i] = indexmass[i-1];
				}
				else
				{
					indexmass[i-1] = indexmass[i];
				}
			}
	}

	for (int i = 0; i < index - 1; i++)
		{
			if (mass[i] == mass[i+1])
			{
				mass[i] = INT_MIN;
			}
	}
	qsforindexmass(indexmass, mass, 0, index - 1);
	char string = 0;
	for (int i = 0; i < index; i++)
		{
			if (mass[i] != INT_MIN)
			{
				printf("%c", char(mass[i]));
			};
 };
};
int main()
{
	char text[10000];
	char slovo[30];
	int j = 0;

	printf("Input: ");
	gets(text);
	text[strlen(text)]=' ';
	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] == ' ')
		 {
			del(slovo,j);
			printf(" ");
			j=0;
		 }
		else
		 {
			slovo[j] = text[i];
			j++;
		 }
	 }
	return 0;
}
