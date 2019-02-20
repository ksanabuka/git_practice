#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
	char * r;
	int len = 0;
	int i = 0;
	int minus = 0;

	if(nbr == -2147483648)
		return "-2147483648";
//	if (nbr == 0)
//		return "0";


	if (nbr < 0)
	{	
		minus = 1;
		nbr = -nbr;
		len++;	
	}
	i = nbr;
	while (i != 0)
	{
		i /=10;
		len++;
	}
		len++;
	
	
	if(!(r = (char *)malloc(sizeof(char) * len)))
		return 0;
	
	i = 0;
	if (minus)
	{
		r[i] = '-';
		i++;
	}
	r[len--] = '\0';

	while (nbr != 0 && len--)
	{
		r[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return r;
}

	
int main (int ac, char ** av)
{
	char c;
	c = 'a';
	
	av = 0;
	if (ac == 1)
	{
		printf("%s\n", ft_itoa(atoi(&c)));
	}
	return 0;
}


