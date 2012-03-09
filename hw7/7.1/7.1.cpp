// 7.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *file=fopen("study.txt", "r");
	int num = 0;
	fscanf(file, "%d", &num);
	int *a = new int[num+1];
	for (int i = 0; i++; i <= num)
		a[i] = 0;
	while(!feof(file))
	{
		int st = 0;
		int sp = 0;
		fscanf(file, "%d", &st);
		fscanf(file, "%d", &sp);
		a[st] = sp;
	}
	for (int i = 4; i <= num; i++)
		while (a[i] > 3)
			a[i] = a[a[i]];
	for (int i = 4; i <= num; i++)
	{
		printf ("student #%d ", i);
		if (a[i] > 0)
			printf("handed in the %d variant\n", a[i]);
		else
			printf("must be expelled\n");
			
	}
	delete a;
	fclose(file);
	return 0;
}


