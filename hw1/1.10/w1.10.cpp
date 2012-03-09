// w1.10.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>


int _tmain(int argc, _TCHAR* argv[])
{
	char string[100];

	printf("Input line - ");
	scanf("%s", &string);

	int len;
	len = strlen(string);

	bool count = false;

	for (int i = 0; i < len / 2 && !count; i++)
	{
		if (string[i] != string[len - i - 1])
		count = true;
	}

	if (!count)
	{
		printf("It's a Palindrome!\n");
	}
	else
	{
	printf("It's not a Palindrome!\n");
	}

	return 0;
}

