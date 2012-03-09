#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int a[27];
	for (int i = 0; i < 28; i++)
		a[i] = 0;

	int summ = 0;
	for (int i = 1; i < 1000; i++)
	{
		summ = i / 100 + i % 10 + (i % 100) / 10;
		a[summ]++;
	}

	summ = 0;
	for (int i = 0; i < 28; i++)
		summ += a[i] * a[i];

	printf("Count of winning ticket - %d", summ);
	return 0;
}


