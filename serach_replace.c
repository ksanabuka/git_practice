#include <unistd.h>
#include <stdio.h>

int main (int ac, char ** av)
{
	if (ac != 4)
	{
		write(1, "\n", 1);
		return 1;
	}
		
	if (av[2][1] != '\0' && av[3][1] != '\0')
	{
		write (1, "\n", 1);
		return 1;
	}


	while (*av[1] && *av[2] && *av[3])
	{
		if (*av[1] == *av[2])
		{
			write(1, av[3], 1);
			av[1]++;
		}
		else 
		{
			write(1, av[1], 1);
			av[1]++;
		}
	}
return 0;
}
