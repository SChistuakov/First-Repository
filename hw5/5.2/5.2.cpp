// 5.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input double\n");
	double a = 0;
	scanf("%lf", &a);
	const int count = sizeof(double) * 8;
	char byteNumber[count];
	
	unsigned __int64 mask = 1;
	unsigned __int64 *b = (unsigned __int64 *)(&a);
	unsigned __int64 mant = 0;
	unsigned __int64 d = 1;

	for (int i = 0; i < count; i++)
	{
		byteNumber[count - i - 1] = (mask & *b) ? 1 : 0;
		mask = mask << 1;
	}; 

	if (byteNumber[0] == 1)
		putchar('-');

	int pow = 0;

	int res = 0;
	int count1 = 1;
	char *c = &byteNumber[1];
	for (int i = 10; i > -1; i--)
	{
		res += count1 * c[i];
		count1 *= 2;
	}

	pow = res;

	int help = count - 12;

	char *c1 = &byteNumber[12];
	while (!c1[help-1])
		help--;

	for (int i = 0; i < help; i++)
	{
		if (i <= 18)
		{
			mant *= 10;
			d *= 5;
		}
		else
			d /= 2;

		if (c1[i])
			mant += d;
	}

	printf("1.%llu", mant);
	printf("*2^(%d)", pow - 1023);

	return 0;
}

