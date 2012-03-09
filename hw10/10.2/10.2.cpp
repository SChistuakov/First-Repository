// 10.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

bool numb(char c)
{
	return (c <= '9' && c >= '0');
}

bool check(char *p)
{
	int state = -1;
	char *c = p;

	if (numb(*c))
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
				if (numb(*c))
				{
					c++;
					state = 0;
				}
				else
					state = -1;
				break;
	    	case 0: 
				if (numb(*c))
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
					state = -1;
				break;
			case 1:
				if (*c == 0)
					state = -1;
				else if (numb(*c))
				{
					state = 2;
					c++;
				} else
					state = -1;
				break;
			case 2:
				if (*c == 0)
					return true;
				else if (numb(*c))
					c++;
				else if (*c == 'e')
				{
					state = 3;
					c++;
				} else
					state = -1;
				break;
		    case 3:
				if (*c == 0)
					state = -1;
				else if (*c == '+' || *c == '-')
				{
					state = 4;
					c++;
				} else if (numb(*c))
				{
					state = 5;
					c++;
				} else
					state = -1;
				break;
		  	case 4:
				if (*c == 0)
					state = -1;
				else if (numb(*c))
				{
					state = 5;
					c++;
				} else 
					state = -1;
				break;
		  	case 5:
				if (*c == 0)
					return true;
				else if (numb(*c))
					c++;
				else 
					state = -1;
				break;
	  	case -1:
				return false;
		}
	}
}




int _tmain(int argc, _TCHAR* argv[])
{
	printf("Input: ");
	char s[50];
	scanf("%s", s);

	if (check(s) == true) 
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
	return 0;
}


