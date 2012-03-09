// 7.3(+3.3).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct Stack
{
	char value[100];
	int topIndex;
};

void push(Stack *s, char val)
{
	s->value[s->topIndex] = val;
	s->topIndex++;
}

char pop(Stack *s)
{
	if (s->topIndex == 0)
		return 0;
	s->topIndex--;
	return s->value[s->topIndex];
}

char top(Stack *s)
{
	return s->value[s->topIndex - 1];
}

bool number(char c)
{
	return (c >= '0' && c <= '9');
}

bool sign(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

void print(Stack *s)
{
	char c = 0;
	while (true)
	{
		c = pop(s);
		if (c == 0 || c == '(')
			return;
		printf("%c", c);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Iput line: ");
	char s[100];
	gets(s);

	Stack *stack = new Stack;
	stack->topIndex = 0;

	int i = 0;
	char c = 0;
	while (s[i])
	{
		if (number(s[i]))
			printf("%c", s[i]);
		if (s[i] == '+' || s[i] == '-')
			print(stack);

		if (sign(s[i]) || s[i] == '(')
			push(stack, s[i]);

		if (s[i] == ')')
			print(stack);
		i++;
	}
	print(stack);

	delete stack;

	return 0;
}


