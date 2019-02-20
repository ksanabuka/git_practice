#include <unistd.h>
#include <stdio.h>

char  reverse(char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		return (c + 13);
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		return (c - 13);
	else 
		return c;
}

int main (int ac, char ** av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	if (*av[1] == 0)
	{
		write(1, "\n", 1);
		return 0;
	}

	while (*av[1])
	{
		char c;
		c = reverse(*av[1]);	
		write(1, &c, 1);
		av[1]++;

	}
		return 1;
}


