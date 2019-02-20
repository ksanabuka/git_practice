#include <unistd.h>
#include <stdio.h>

char  reverse(char c)
{
	if ((c >= 'A' && c <= 'Y') || (c >= 'a' && c <= 'Y'))
		return (c + 1);
	else if ((c == 'Z') || (c == 'z'))
		return (c - 25);
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


