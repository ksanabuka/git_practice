#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp; 
}

int main (int ac, char ** av)
{
	if (ac == 2)
	{
		ft_putstr(av[1]);
	}
}
