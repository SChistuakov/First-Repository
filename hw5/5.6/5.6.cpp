// 5.6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

typedef unsigned long long ull;

struct Phone
{
	ull number;
	char name[10];
	Phone *next;
	Phone();
};

Phone::Phone()
{
	number = 0;
	next = NULL;
}

void delBook(Phone *head)
{
	Phone *tmp = head;
	while (tmp)
	{
		Phone *t = tmp->next;
		delete tmp;
		tmp = t;
	};
};

int main(void)
{
	Phone *head = new Phone;
	Phone *tmp = head;

	FILE *fd = fopen("book.txt", "r");
	ull num = 0;
	char c[10];
	while(fscanf(fd, "%llu %s", &num, c) != EOF)
	{
		Phone *tt = new Phone;
		tmp->next = tt;
		tmp = tt;
		strcpy(tmp->name, c);
		tmp->number = num;
	}
	fclose(fd);

	 int answer = -1;
	 int x = 0;

	 printf("Commands:\n0 - exit\n"); 
	 printf("1 - add phone\n"); 
	 printf("2 - find number\n"); 
	 printf("3 - find name\n");
	 printf("4 - save phone book\n"); 

	  while (answer!=0)
	 {
		 printf("Command: ");
		 scanf("%d", &answer);
		 if (answer == 1) 
		 {
			 printf("Insert phone number and name\n");
			 scanf("%llu %s", &num, c);
			 Phone *tt = new Phone;
	     	 tmp->next = tt;
		     tmp = tt;
		     strcpy(tmp->name, c);
		     tmp->number = num;
		 }
		 else if (answer == 2)
		 {
			 printf("Insert name\n");
			 scanf("%s", c);
			 Phone *temp = head;
			 while (temp = temp->next)
				 if (strcmp(c, temp->name) == 0)
					 printf("%llu\n", temp->number);
		 }
		 else if (answer == 3)
		 {
			 printf("Insert number\n");
			 scanf("%llu", &num);
			 Phone *temp = head;
			 while (temp = temp->next)
				 if (num == temp->number)
					 printf("%s\n", temp->name);
		 }
		 else if (answer == 4)
		 {	
			 FILE *fw = fopen("book.txt", "w");
			 Phone *temp = head;
			 while (temp = temp->next)
				 fprintf(fw, "%llu %s\n", temp->number, temp->name);
			 fclose(fw);
			 printf("file saved\n");
		 }
	 }

	delBook(head);

	return 0;
}

