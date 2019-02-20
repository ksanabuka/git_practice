#include <stdio.h>

int ft_atoi(const char *str)
{
	long r;
	int sign = 1;
//	if (str == "-2147483648")
//		return (-2147483638);
	
	sign = (*str == '-') ? -1 : 1;
   while ( *str == 32 || (*str >= 9 && *str <= 13) )
   		str++;
	r = 0;
	(*str == '+' || *str == '-') ? str++: str;
	while (*str)
	{
		r = r * 10 + *str - '0';
		str++;
	}	
	return (int) r * sign; 
}

int main (int ac, char ** av)
{
	ac = 0;

	printf("%d \n", ft_atoi(av[1]));
	return 0;
}

