// 9.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	
	FILE * f1 = fopen("1.txt", "r");
	FILE * f2 = fopen("2.txt", "r");
	FILE * f3 = fopen("3.txt", "w");

	printf("Wait...\n");

	char str[100];
	while (fgets(str, 100, f1))
	{
		char str2[100];
		while(fgets(str2, 100, f2))
		{
			if (!strcmp(str, str2))
			{
				fprintf(f3, "%s", str);
				break;
			}
		}
		fseek(f2, 0, SEEK_SET);

	}
	fclose(f1);
	fclose(f2);
	fclose(f3);
	printf("Done!\n");
	return 0;
}

