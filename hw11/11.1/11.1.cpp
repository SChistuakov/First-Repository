// 11.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool number(char c)
{
	return (c <= '9' && c >= '0');
}

bool check(char *&c)
{
	int state = -1;
	if (number(*c))
		state = 0;
	else if (*c == '-')
		state = 10;
	else
		return false;
	c++;
	while (true)
	{
		switch (state)
		{
		    case 10:
				if (number(*c))
				{
					c++;
					state = 0;
				}
				else
					state = -1;
				break;
	    	case 0: 
				if (number(*c))
					c++;
				else if (*c == '.')
				{
					state = 1;
					c++;
				} else if (*c == 'e')
				{
					state = 3;
					c++;
				} else if (*c == 0)
					return true;
				else
					return true;
				break;
			case 1:
				if (*c == 0)
					state = -1;
				else if (number(*c))
				{
					state = 2;
					c++;
				} else
					state = -1;
				break;
			case 2:
				if (*c == 0)
					return true;
				else if (number(*c))
					c++;
				else if (*c == 'e')
				{
					state = 3;
					c++;
				} else
					return true;
				break;
		    case 3:
				if (*c == 0)
					state = -1;
				else if (*c == '+' || *c == '-')
				{
					state = 4;
					c++;
				} else if (number(*c))
				{
					state = 5;
					c++;
				} else
					state = -1;
				break;
		  	case 4:
				if (*c == 0)
					state = -1;
				else if (number(*c))
				{
					state = 5;
					c++;
				} else 
					state = -1;
				break;
		  	case 5:
				if (*c == 0)
					return true;
				else if (number(*c))
					c++;
				else 
					return true;
				break;
		  	case -1:
				return false;
		}
	}
}

bool sign(char *&c);



bool brackets(char *&c)
{
	
	if (*c == '(')
	{
		c++;
		if (!sign(c))
			return false;
		if (*c != ')')
			return false;
		c++;
		return true;
	} else
		return check(c);

}

bool sign(char *&c)
{
	if (!brackets(c))
		return false;

	while (*c == '*' || *c == '/' || *c == '+' || *c == '-')
	{
		c++; 
		if (!brackets(c))
			return false;
	}
	return true;
}

bool checkStr(char *c)
{
	char *tmp = c;
	return sign(tmp);
}

int _tmain(int argc, _TCHAR* argv[])
{
	char s[100];
	printf("Input: ");

	gets(s);

	if (checkStr(s) == true) 
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}

