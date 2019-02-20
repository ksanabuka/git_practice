#include<unistd.h>
#include<stdio.h>
//#include<stdlib.h>
//#include <ctype.h>
	
int toupper(int c)
{  
	return ((c >= 97 && c <= 122) ? c - 32 : c);	
}

int tolower(int c)
{  
	return ((c >= 65 && c <= 90) ? c + 32 : c);	
}

int main (int ac, char ** av)
{

	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}

	int i = 0;
	
	while (av[1][i++])
	{
	printf("toupper %c, to lower %c\n", toupper(av[1][i]), tolower(av[1][i]));
	}
	return 0;
}

