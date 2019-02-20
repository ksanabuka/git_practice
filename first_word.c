#include <unistd.h>

int isSpace (char c)
  {
  return (c == ' ' || c == '\t') ? 1 : 0;
  }	

int main (int ac, char ** av)
{
	int i = 0;
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 1;
	}
	
	while (*av[1] && isSpace(*av[1]))
		av[1]++;
	
	while (*av[1] && !isSpace(*av[1]))
	{
		write(1, av[1], 1);
		av[1]++;
		i = 1;
	}
	

		write(1, "\n", 1);
		return 1;
}
