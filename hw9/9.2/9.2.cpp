// 9.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

inline int hashf(char c, int last)
{
	return (last * 256 + c) % 17;
}

int checkString(char *s, char *ps, int len)
{ 
	for (int i = 0; i < len; i++)
		if (s[i] != ps[i])
			return false;
	return true;
}

void strFind(char *s, char *ps)
{
	int sChar, psChar;
	sChar = strlen(s);
	psChar = strlen(ps);

	int shash = 0, pshash = 0;
	int k = 1;
	for (int i = 0; i < psChar; i++)
	{
		shash = hashf(s[i], shash);
		pshash = hashf(ps[i], pshash);
		if (i < psChar - 1)
			k = k * 256 % 17;
	}
	for (int i = psChar; i < sChar + 1; i++)
	{
		if (shash == pshash)
			if (checkString(&s[i - psChar], ps, psChar))
			{
				printf("%d ", i - psChar);
			}
		shash = ( 256 * (shash + 17 - (s[i - psChar] * k % 17)) + s[i]) % 17;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	char string[100];
	char string2[10];

	printf("String: ");
	gets(string);
	printf("Substring: ");
	gets(string2);

	printf("Pos: ");

	strFind(string,string2);

	return 0;
}

