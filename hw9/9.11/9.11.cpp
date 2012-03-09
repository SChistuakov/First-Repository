// 9.11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

struct List1Element
{
	char str[100];
	List1Element * next;
};

List1Element * createList()
{
	List1Element * tmp = new List1Element;
	tmp->str[0] = 0;
	tmp->next =	NULL;
	return tmp;
}

void delList(List1Element *head)
{
	List1Element *tmp = head;
	while (tmp)
	{
		List1Element *t = tmp->next;
		delete tmp;
		tmp = t;
	}
}

struct Hash
{
	List1Element *h[255];
};

Hash *createHash()
{
	Hash *tmp = new Hash;
	for (int i = 0; i < 255; i++)
		tmp->h[i] = NULL;
	return tmp;
}

void delHash(Hash *hash)
{
	for (int i = 0; i < 255; i++)
		delList(hash->h[i]);
	delete hash;
}

int hFunc(char *s)
{
	int tmp = 0;
	int i = 0;
	while (s[i++] && i < 5)
		tmp = (tmp + s[i]) % 255;
	return tmp;
}

void hashAdd(Hash *hash, char *s)
{
	int index = hFunc(s);
	List1Element *tmp = hash->h[index];
	while (tmp)
	{
		if (strcmp(s, tmp->str) == 0)
			return;
		tmp = tmp->next;
	}
	tmp = createList();
	strcpy(tmp->str, s);
	tmp->next = hash->h[index];
	hash->h[index] = tmp;
}

List1Element *hfind(Hash *hash, char *s)
{
	int index = hFunc(s);
	List1Element *tmp = hash->h[index];
	while (tmp)
	{
		if (strcmp(s, tmp->str) == 0)
			break;
		tmp = tmp->next;
	}
	return tmp;
}


int _tmain(int argc, _TCHAR* argv[])
{
	FILE * f1 = fopen("1.txt", "r");
	FILE * f2 = fopen("2.txt", "r");

	char line[100];

	Hash *hash = createHash();

	while (fgets(line, 100, f1))
		hashAdd(hash, line);
	fclose(f1);
	FILE * fileOut = fopen("out.txt", "w");

	printf("Add to out file:\n");
	char line2[100];
	while(fgets(line2, 100, f2))
		if (hfind(hash, line2))
		{
			fprintf(fileOut, "%s", line2);
			printf("%s", line2);
		}
	fclose(fileOut);
	fclose(f2);

	delHash(hash);

	return 0;

}