#include<unistd.h>
#include<stdio.h>

char *strcpy(char *s1, const char *s2)
{

	char * a;
	char * b;
	
	a = (char *)s1;
	b = (char *)s2;

	while (*a) 
	{
		*a = *b;
		a++;
		b++;
	}

	*a = '\0';
	return s1;
}


int main (int ac, char ** av)
{

	if (ac != 3)
	{
		write(1, "\n", 1);
		return 0;
	}

	printf("%s\n", strcpy(av[1], av[2]));
	return 0;
}

