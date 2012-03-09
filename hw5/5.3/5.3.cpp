// 5.3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	 FILE * fd = fopen(". . .", "r"); 
	 char c = 0;
	 bool flag = false;
	 while ((c = fgetc(fd)) != EOF)
	 {
		 if (c == '"')
			 flag = !flag;
		 if (c == '/' && fgetc(fd) == '/' && !flag)
		 {
			 while ( c != '\n')
			 {
				  c = fgetc(fd);
				  if (c == EOF) 
					  break;
				  printf("%c", c);
		     }
			 flag = false;
		 }
	 }
	 fclose(fd);

	return 0;
}



